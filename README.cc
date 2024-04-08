# Memcpy Benchmark

## quick start

``` bash
make
./benchmark
```

## Sample Output

```
memcopy benchmark pattern:Random src:aligned dst:aligned dataset:536870912B
copysize:         1 , latency:     41.17ns , bandwith:      0.02GB/s
copysize:         2 , latency:     40.97ns , bandwith:      0.05GB/s
copysize:         4 , latency:     40.87ns , bandwith:      0.09GB/s
copysize:         8 , latency:     41.00ns , bandwith:      0.18GB/s
copysize:        16 , latency:     43.52ns , bandwith:      0.34GB/s
copysize:        32 , latency:     50.63ns , bandwith:      0.59GB/s
copysize:        64 , latency:     70.06ns , bandwith:      0.85GB/s
copysize:       128 , latency:    127.28ns , bandwith:      0.94GB/s
copysize:       256 , latency:    219.91ns , bandwith:      1.08GB/s
copysize:       512 , latency:    340.36ns , bandwith:      1.40GB/s
copysize:      1024 , latency:    527.20ns , bandwith:      1.81GB/s
copysize:      2048 , latency:    708.33ns , bandwith:      2.69GB/s
copysize:      4096 , latency:   1138.66ns , bandwith:      3.35GB/s
copysize:      8192 , latency:   1989.80ns , bandwith:      3.83GB/s
copysize:     16384 , latency:   4873.94ns , bandwith:      3.13GB/s
copysize:     32768 , latency:   9467.22ns , bandwith:      3.22GB/s
copysize:     65536 , latency:  18553.96ns , bandwith:      3.29GB/s
copysize:    131072 , latency:  52208.92ns , bandwith:      2.34GB/s
copysize:    262144 , latency: 104212.89ns , bandwith:      2.34GB/s
copysize:    524288 , latency: 174706.79ns , bandwith:      2.79GB/s
copysize:   1048576 , latency: 273097.66ns , bandwith:      3.58GB/s
copysize:   2097152 , latency: 469441.41ns , bandwith:      4.16GB/s
copysize:   4194304 , latency: 769152.34ns , bandwith:      5.08GB/s
copysize:   8388608 , latency:1526273.44ns , bandwith:      5.12GB/s
copysize:  16777216 , latency:3057406.25ns , bandwith:      5.11GB/s
copysize:  33554432 , latency:6148984.38ns , bandwith:      5.08GB/s
copysize:  67108864 , latency:12274781.25ns , bandwith:      5.09GB/s
copysize: 134217728 , latency:24945500.00ns , bandwith:      5.01GB/s
copysize: 268435456 , latency:50083000.00ns , bandwith:      4.99GB/s
copysize: 536870912 , latency:93388000.00ns , bandwith:      5.35GB/s
```
