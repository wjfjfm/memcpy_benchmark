# Memcpy Benchmark

## quick start

``` bash
make
./benchmark
```

## Sample Output

```
memcopy benchmark pattern:Random src:aligned dst:aligned dataset:536870912B
copysize:           1 , latency:       41.53ns , bandwith:        0.02GB/s
copysize:           2 , latency:       41.35ns , bandwith:        0.05GB/s
copysize:           4 , latency:       41.25ns , bandwith:        0.09GB/s
copysize:           8 , latency:       41.33ns , bandwith:        0.18GB/s
copysize:          16 , latency:       43.81ns , bandwith:        0.34GB/s
copysize:          32 , latency:       50.85ns , bandwith:        0.59GB/s
copysize:          64 , latency:       70.49ns , bandwith:        0.85GB/s
copysize:         128 , latency:      128.48ns , bandwith:        0.93GB/s
copysize:         256 , latency:      222.44ns , bandwith:        1.07GB/s
copysize:         512 , latency:      343.87ns , bandwith:        1.39GB/s
copysize:        1024 , latency:      532.28ns , bandwith:        1.79GB/s
copysize:        2048 , latency:      714.88ns , bandwith:        2.67GB/s
copysize:        4096 , latency:     1150.40ns , bandwith:        3.32GB/s
copysize:        8192 , latency:     2017.40ns , bandwith:        3.78GB/s
copysize:       16384 , latency:     4944.53ns , bandwith:        3.09GB/s
copysize:       32768 , latency:     9635.25ns , bandwith:        3.17GB/s
copysize:       65536 , latency:    18877.53ns , bandwith:        3.23GB/s
copysize:      131072 , latency:    52533.69ns , bandwith:        2.32GB/s
copysize:      262144 , latency:   104818.48ns , bandwith:        2.33GB/s
copysize:      524288 , latency:   175833.25ns , bandwith:        2.78GB/s
copysize:     1048576 , latency:   276103.03ns , bandwith:        3.54GB/s
copysize:     2097152 , latency:   474432.62ns , bandwith:        4.12GB/s
copysize:     4194304 , latency:   786386.72ns , bandwith:        4.97GB/s
copysize:     8388608 , latency:  1564011.72ns , bandwith:        5.00GB/s
copysize:    16777216 , latency:  3121187.50ns , bandwith:        5.01GB/s
copysize:    33554432 , latency:  6228921.88ns , bandwith:        5.02GB/s
copysize:    67108864 , latency: 12586593.75ns , bandwith:        4.97GB/s
copysize:   134217728 , latency: 24825250.00ns , bandwith:        5.04GB/s
copysize:   268435456 , latency: 50637500.00ns , bandwith:        4.94GB/s
copysize:   536870912 , latency: 98799000.00ns , bandwith:        5.06GB/s
```
