Compiles debug mode by default.

Boot in vagrant.

To build and run performance benchmarks:

```
cd ~/map_trap
mkdir build
cd build
cmake ..
make
```

To build an optimized version:
```
cd ~/map_trap
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

Binaries are located in the build directory.
