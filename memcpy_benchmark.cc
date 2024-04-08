#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <assert.h>

#include <sys/time.h>
#include <unistd.h>

#define MAX_TIMES 10000000
const uint64_t DATA_SIZE = (uint64_t)512 * 1024 * 1024;
const uint64_t TEST_SIZE = (uint64_t)2 * 1024 * 1024 * 1024;

char *ALIGN1;
char *ALIGN2;

unsigned int gettime_us()
{
  static struct timezone tz={ 0,0 };
  struct timeval time;
  gettimeofday(&time,&tz);
  return (time.tv_sec * 1000000 + time.tv_usec);
}

void sleepms(unsigned int millisec)
{
  usleep(millisec * 1000);
}

void rand_bytes(char *src, size_t size) {
  size_t i;
  uint64_t* src_8B = (uint64_t*)src;
  for (i=0; i * 8 + 8 < size; i++) {
    src_8B[i] = rand();
  }
}

void memcpy_bench(bool dstalign, bool srcalign, int step, bool random, size_t datasize, size_t copysize, size_t times)
{
  times = times < MAX_TIMES ? times : MAX_TIMES;
  assert(datasize <= DATA_SIZE);
  assert(copysize <= datasize);

  char *dst;
  char *src;
  static char* dst_que[MAX_TIMES];
  static char* src_que[MAX_TIMES];
  uint64_t offset;

  unsigned int t1, t2;
  int i, k;

  if (random) {
    for (i = 0; i < times; i++) {
      offset = rand() % (datasize - copysize + 1);
      if (dstalign) {
        offset = offset & (~0x3f);
      }
      dst_que[i] = ALIGN2 + offset;
    }

    for (i = 0; i < times; i++) {
      offset = rand() % (datasize - copysize + 1);
      if (srcalign) {
        offset = offset & (~0x3f);
      }
      src_que[i] = ALIGN1 + offset;
    }
  } else {
    offset = DATA_SIZE + 1;
    for (i = 0; i < times; i++) {
      if (offset + copysize > datasize + 64) {
        offset = dstalign ? 0 : rand() % 64;
      }

      if (dstalign) {
        offset = offset & (~0x3f);
      }

      dst_que[i] = ALIGN2 + offset;

      offset = offset + step;
    }

    offset = DATA_SIZE + 1;
    for (i = 0; i < times; i++) {
      if (offset + copysize > datasize + 64) {
        offset = srcalign ? 0 : rand() % 64;
      }

      if (srcalign) {
        offset = offset & (~0x3f);
      }

      src_que[i] = ALIGN1 + offset;

      offset = offset + step;
    }
  }

  sleepms(100);
  t1 = gettime_us();
  for (k = 0; k < times; k++) {
    memcpy(dst_que[k], src_que[k], copysize);
  }
  t1 = gettime_us() - t1;
  sleepms(100);

  double lat1 = (double)t1 * 1000 / times;

  double bw1 = (double)copysize * times / 1024 / 1024 / 1024 * 1000000 / t1;

  printf("copysize:%12d , latency:%12.2lfns , bandwith:%12.2lfGB/s\n", copysize, lat1, bw1);
}

void benchmark(bool dstalign, bool srcalign, bool random, size_t datasize) {
  printf("\n");
  printf("memcopy benchmark pattern:%s src:%s dst:%s dataset:%dB\n",
      random ? "Random" : "Sequential",
      dstalign? "aligned" : "unalign",
      srcalign? "aligned" : "unalign",
      datasize
  );

  int copysize;
  int step;

  for (copysize = 1; copysize <= datasize; copysize *= 2) {
    step = copysize;
    memcpy_bench(dstalign, srcalign, step, random, datasize, copysize, TEST_SIZE / copysize);
  }
}


int main(void)
{
  char *DATA1 = (char*)malloc(DATA_SIZE + 64 + 64);
  char *DATA2 = (char*)malloc(DATA_SIZE + 64 + 64);
  size_t LINEAR1 = ((size_t)DATA1);
  size_t LINEAR2 = ((size_t)DATA2);
  ALIGN1 = (char*)(((64 - (LINEAR1 & 63)) & 63) + LINEAR1);
  ALIGN2 = (char*)(((64 - (LINEAR2 & 63)) & 63) + LINEAR2);
  rand_bytes(ALIGN1, DATA_SIZE);
  rand_bytes(ALIGN2, DATA_SIZE);

  for (int random = 0; random <= 1; random++) {
    for (int align = 0; align <=1; align ++) {
      // half of L1 cache
      benchmark(align, align, random, 16 * 1024);
      // half of L2 cache
      benchmark(align, align, random, 512 * 1024);
      // half of L3 cache
      benchmark(align, align, random, 16 * 1024 * 1024);
      // Large dataset
      benchmark(align, align, random, 512 * 1024 * 1024);
    }
  }

  free(DATA1);
  free(DATA2);

  return 0;
}
