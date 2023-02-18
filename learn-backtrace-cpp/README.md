# Learn backtrace-cpp

On ubuntu 20.04, by installing
```bash
apt-get install binutils-dev -y
```

Then run test code
```bash
./run.sh
```

Got result:
```
Stack trace (most recent call last):
#4    Object "", at 0xffffffffffffffff, in
#3    Object "/work/build/maindebug", at 0xaaaabc4494af, in _start
#2    Object "/lib/aarch64-linux-gnu/libc.so.6", at 0xffff945e7857, in __libc_start_main
#1    Object "/lib/aarch64-linux-gnu/libc.so.6", at 0xffff945e777f, in __libc_init_first
#0    Source "/work/main.cpp", line 8, in main [0xaaaabc4495d0]
          5: int main()
          6: {
          7: 	std::vector<int32_t> A;
      >   8: 	A[1] = 1;
          9: 	for (auto i = A.begin(); i != A.end(); ++i) {
         10: 		std::cout << *i << std::endl;
         11: 	}
Segmentation fault (Address not mapped to object [0x4])
run.sh: line 9:  4527 Segmentation fault      ./maindebug
```

I also installed `binutils` by `brew install binutils` on Macbook M2, but no line numbers show up:

```
Stack trace (most recent call last):
#6    Object "maindebug", at 0x1028fb4a7, in main + 39
#5    Object "libsystem_platform.dylib", at 0x18d2582a3, in _sigtramp + 55
#4    Object "maindebug", at 0x1028fd3bb, in backward::SignalHandling::sig_handler(int, __siginfo*, void*) + 39
#3    Object "maindebug", at 0x1028fd65b, in backward::SignalHandling::handleSignal(int, __siginfo*, void*) + 99
#2    Object "maindebug", at 0x1028fd773, in backward::StackTraceImpl<backward::system_tag::darwin_tag>::load_from(void*, unsigned long, void*, void*) + 59
#1    Object "maindebug", at 0x1028fd8d3, in backward::StackTraceImpl<backward::system_tag::darwin_tag>::load_here(unsigned long, void*, void*) + 123
#0    Object "maindebug", at 0x1028ff26b, in unsigned long backward::details::unwind<backward::StackTraceImpl<backward::system_tag::darwin_tag>::callback>(backward::StackTraceImpl<backward::system_tag::darwin_tag>::callback, unsigned long) + 39
run.sh: line 9: 88413 Segmentation fault: 11  ./maindebug
```
