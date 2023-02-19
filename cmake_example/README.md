# This example shows debug with backtrace-cpp in pybind11

No matter APIs in `package` as a shared lib or just a func in `main.cpp` can be backtraced.

Running `bash run.sh` prompts backtrace information successfully
```
Stack trace (most recent call last):
#21   Object "", at 0xffffffffffffffff, in
#20   Object "/usr/bin/python3.10", at 0xaaaab504886f, in _start
#19   Source "./csu/../csu/libc-start.c", line 381, in __libc_start_main_impl [0xffffba8c7857]
#18   Source "./csu/../sysdeps/nptl/libc_start_call_main.h", line 58, in __libc_start_call_main [0xffffba8c777f]
#17   Object "/usr/bin/python3.10", at 0xaaaab5048987, in Py_BytesMain
#16   Object "/usr/bin/python3.10", at 0xaaaab507a90b, in Py_RunMain
#15   Object "/usr/bin/python3.10", at 0xaaaab508bea3, in _PyRun_AnyFileObject
#14   Object "/usr/bin/python3.10", at 0xaaaab508c203, in _PyRun_SimpleFileObject
#13   Object "/usr/bin/python3.10", at 0xaaaab508d11b, in PyUnicode_Tailmatch
#12   Object "/usr/bin/python3.10", at 0xaaaab5084b33, in PyInit__collections
#11   Object "/usr/bin/python3.10", at 0xaaaab508d48b, in PyUnicode_Tailmatch
#10   Object "/usr/bin/python3.10", at 0xaaaab5057353, in PyEval_EvalCode
#9    Object "/usr/bin/python3.10", at 0xaaaab5057443, in PyEval_EvalCode
#8    Object "/usr/bin/python3.10", at 0xaaaab4f633fb, in _PyEval_EvalFrameDefault
#7    Object "/usr/bin/python3.10", at 0xaaaab4f6b31b, in _PyObject_MakeTpCall
#6    Object "/usr/bin/python3.10", at 0xaaaab4f73c4f, in PyObject_CallFunctionObjArgs
#5    Source "/work/cmake_example/pybind11/include/pybind11/pybind11.h", line 934, in pybind11::cpp_function::dispatcher(_object*, _object*, _object*) [0xffffba54c8b3]
        931:                 // 6. Call the function.
        932:                 try {
        933:                     loader_life_support guard{};
      > 934:                     result = func.impl(call);
        935:                 } catch (reference_cast_error &) {
        936:                     result = PYBIND11_TRY_NEXT_OVERLOAD;
        937:                 }
#4    Source "/work/cmake_example/pybind11/include/pybind11/pybind11.h", line 224, in pybind11::cpp_function::initialize<void (*&)(int), void, int, pybind11::name, pybind11::scope, pybind11::sibling, char [11]>(void (*&)(int), void (*)(int), pybind11::name const&, pybind11::scope const&, pybind11::sibling const&, char const (&) [11])::{lambda(pybind11::detail::function_call&)#3}::_FUN(pybind11::detail::function_call&) [0xffffba55c207]
        221:             "The number of argument annotations does not match the number of function arguments");
        222:
        223:         /* Dispatch code which converts function arguments and performs the actual function call */
      > 224:         rec->impl = [](function_call &call) -> handle {
        225:             cast_in args_converter;
        226:
        227:             /* Try to cast the function arguments into the C++ domain */
#3    Source "/work/cmake_example/pybind11/include/pybind11/pybind11.h", line 249, in pybind11::cpp_function::initialize<void (*&)(int), void, int, pybind11::name, pybind11::scope, pybind11::sibling, char [11]>(void (*&)(int), void (*)(int), pybind11::name const&, pybind11::scope const&, pybind11::sibling const&, char const (&) [11])::{lambda(pybind11::detail::function_call&)#3}::operator()(pybind11::detail::function_call&) const [0xffffba55c193]
        247:             /* Perform the function call */
        248:             handle result
      > 249:                 = cast_out::cast(std::move(args_converter).template call<Return, Guard>(cap->f),
        250:                                  policy,
        251:                                  call.parent);
#2    Source "/work/cmake_example/pybind11/include/pybind11/cast.h", line 1415, in std::enable_if<std::is_void<void>::value, pybind11::detail::void_type>::type pybind11::detail::argument_loader<int>::call<void, pybind11::detail::void_type, void (*&)(int)>(void (*&)(int)) && [0xffffba56222b]
       1413:     template <typename Return, typename Guard, typename Func>
       1414:     enable_if_t<std::is_void<Return>::value, void_type> call(Func &&f) && {
      >1415:         std::move(*this).template call_impl<remove_cv_t<Return>>(
       1416:             std::forward<Func>(f), indices{}, Guard{});
       1417:         return void_type();
       1418:     }
#1    Source "/work/cmake_example/pybind11/include/pybind11/cast.h", line 1441, in void pybind11::detail::argument_loader<int>::call_impl<void, void (*&)(int), 0ul, pybind11::detail::void_type>(void (*&)(int), std::integer_sequence<unsigned long, 0ul>, pybind11::detail::void_type&&) && [0xffffba5659cb]
       1439:     template <typename Return, typename Func, size_t... Is, typename Guard>
       1440:     Return call_impl(Func &&f, index_sequence<Is...>, Guard &&) && {
      >1441:         return std::forward<Func>(f)(cast_op<Args>(std::move(std::get<Is>(argcasters)))...);
       1442:     }
       1443:
       1444:     std::tuple<make_caster<Args>...> argcasters;
#0    Source "/work/cmake_example/package/src/op.cc", line 7, in set(int) [0xffffba4e1574]
          5: void set(int n){
          6: 	std::vector<int> A;
      >   7: 	A[n] = -1;
          8: 	std::cout<< A[n] << std::endl;
          9:
         10: }
Segmentation fault (Address not mapped to object [0x190])
```

checklist if such info doesn't show up:
- `set(CMAKE_BUILD_TYPE Debug)` in [CMakeLists.txt](./CMakeLists.txt) 
