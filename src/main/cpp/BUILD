
package(default_visibility = ["//visibility:public"])

load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("@rules_pkg//:pkg.bzl", "pkg_tar", "pkg_deb")

cc_library(

    name = "cfs-arkhe-gcs-main",

    srcs = [
        "cfs/arkhe/gcs/EnvironmentVariablesManager.cpp",
    ],

    hdrs = [
        "cfs/arkhe/gcs/EnvironmentVariablesManager.hpp",
    ],

    copts = [
        "-std=c++17",
        "-DLOG_LEVEL=1",
        "-lapr-1",
        "-laprutil-1",
        "-llog4cxx",
		"-D_REENTRANT",
        "-I/usr/local/include/",
        '-fpic',
    ],

    linkopts = [
        "-L/usr/local/lib",
		"-pthread",
        "-lapr-1",
        "-laprutil-1",
        "-llog4cxx",
	],

	includes = [
		".",
	],

    #visibility = ["//visibility:public"],
    #visibility = ["//main:__pkg__"],
)

cc_binary(
    name = "cfs-arkhe-gcs-main.bin",
    srcs = ["main.cpp"],
    copts = [
       "-std=c++17",
       '-fpic',
    ],

    deps = [
        ":cfs-arkhe-gcs-main",
    ],
)

pkg_tar(
    name = "cfs-arkhe-gcs-main-libs",
    strip_prefix = "/src/main/cpp/cpp",
    package_dir = "/opt/lib",
    srcs = ["//src/main/cpp:cfs-arkhe-gcs-main"],
    mode = "0755",
)

pkg_tar(
    name = "cfs-arkhe-gcs-main-hdrs-pkg",
#    testonly = True,
    srcs = glob([
        "**/*.hpp",
    ]),
    # extension = "tar.gz",
    package_dir = "/opt/include",
    strip_prefix = "/src/main/cpp",
    tags = ["manual"],
    visibility = ["//visibility:public"],
    mode = "0644",
)

pkg_tar(
    name = "cfs-arkhe-gcs-main-bin-pkg",
#    testonly = True,
    srcs = [
        # ":cfs-algo-main",
        ":cfs-arkhe-gcs-main.bin",
    ],
    # extension = "tar.gz",
    package_dir = "/opt/bin",
    strip_prefix = "/src/main/cpp",
    tags = ["manual"],
)

pkg_tar(
    name = "cfs-arkhe-gcs",
    extension = "tar.gz",
    deps = [
        ":cfs-arkhe-gcs-main-libs",
        ":cfs-arkhe-gcs-main-hdrs-pkg",
        ":cfs-arkhe-gcs-main-bin-pkg",
    ],
)

pkg_deb(
    name = "cfs-arkhe-gcs-main-deb-pkg",
    testonly = True,
    architecture = "amd64",
    data = ":cfs-arkhe-gcs",
    description = "Core Flight System Ground Control Station",
    homepage = "https://gitlab.com/doevelopper/cfs-algo",
    maintainer = "Adrien H.",
    package = "CFSGCS",
    tags = ["manual"],
    version = "0.0.1",
    visibility = ["//visibility:public"],
)

