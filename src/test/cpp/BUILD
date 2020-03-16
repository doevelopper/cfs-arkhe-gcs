
load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")
load("@rules_pkg//:pkg.bzl", "pkg_tar", "pkg_deb")

licenses(["notice"])  # Apache License

cc_test(

    name = "cfs-arkhe-gcs-unit-test.bin",

    srcs = [
        "cfs/arkhe/gcs/unitTest.cpp",
        "cfs/arkhe/gcs/Test.cpp",
        "cfs/arkhe/gcs/Test.hpp",
    ],

    includes = [
        ".",
    ],

    copts = [
       "-std=c++17",
       "-DLOG_LEVEL=1",
       #"-lapr-1",
       #"-laprutil-1",
       #"-llog4cxx",
       #"-lgtest",
       "-D_REENTRANT",
       "-I/usr/local/include/",
    ],

    linkopts = [
       "-L/usr/local/lib",
       "-lapr-1",
       "-laprutil-1",
       "-llog4cxx",
       "-lgtest",
       "-lgmock",
     ],


    deps = [
        "//src/main/cpp:cfs-arkhe-gcs-main",
    ],

    data = [
        "//src/main/resources/configs:log4cxx.xml",
    ],

)

