

add_library(${PROJECT_NAME}.main)
add_executable(${PROJECT_NAME}.main.bin)

apply_style_targets_command (${PROJECT_NAME}.main ${CMAKE_CURRENT_SOURCE_DIR})

option(EXCLUDE_DEPRECATED "Exclude deprecated parts of the library" TRUE)
if (EXCLUDE_DEPRECATED)
    set(NO_BUILD_DEPRECATED DEFINE_NO_DEPRECATED)
endif()

target_sources(${PROJECT_NAME}.main
    PUBLIC
        cfs/arkhe/gcs/app/LoggingService
        cfs/arkhe/gcs/EnvironmentVariablesManager
        #cfs/arkhe/gcs/app/GCSApplication
        #		cfs/arkhe/gcs/app/internal/GCSApplicationPrivate
    # cfs/arkhe/gcs/app/appenders/GCSSocketAppender
    #cfs/arkhe/gcs/widgets/splashscreen
    #    cfs/arkhe/gcs/app/appenders/QtAppender
    #cfs/arkhe/gcs/app/qtsingleapplication/qtlocalpeer
    #    cfs/arkhe/gcs/app/qtsingleapplication/qtsingleapplication
    #    cfs/arkhe/gcs/app/qtsingleapplication/qtlockedfile
    #    cfs/arkhe/gcs/app/qtsingleapplication/qtsinglecoreapplication
        #$<$<PLATFORM_ID:Linux>:<SOURCE_DIR>/srs/main/cpp/cfs/arkhe/gcs/app/qtsingleapplication/qtlockedfile_unix.cpp>
        #$<$<PLATFORM_ID:Windows>:<SOURCE_DIR>/srs/main/cpp/cfs/arkhe/gcs/app/qtsingleapplication/qtlockedfile_win.cpp>
        #$<$<PLATFORM_ID:Android>:
        #$<IF:$<CONFIG:Debug>:helper_debug.cpp,helper_release.cpp>

        #~cfs/arkhe/gcs/app/GCSApplication
)

target_sources(${PROJECT_NAME}.main.bin
    PRIVATE
        main
)

target_compile_features(${PROJECT_NAME}.main
    PUBLIC
        cxx_std_17
    PRIVATE
        cxx_lambdas
        cxx_range_for
        $<$<CXX_COMPILER_ID:GNU>:cxx_attributes>
)

target_compile_options(${PROJECT_NAME}.main
    PUBLIC
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>: -W -Wextra -Weffc++ -Wall -pedantic-errors -Wconversion -Wsign-conversion>
)

target_compile_definitions(${PROJECT_NAME}.main
    PUBLIC
	    "LOG_LEVEL=$<IF:$<BOOL:${LOG_ALL}>,true,false>"
    PRIVATE
        "VERBOSITY=$<IF:$<BOOL:${VERBOSE}>,30,10>"

)
target_include_directories(${PROJECT_NAME}.main
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/cfs/arkhe/gcs>
        $<INSTALL_INTERFACE:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cfs/arkhe/gcs>
)

target_link_libraries(${PROJECT_NAME}.main
    PUBLIC
        $<$<PLATFORM_ID:Linux>:rt>
        $<$<PLATFORM_ID:Linux>:pthread>
        $<$<CONFIG:Coverage>:${CPP_COVERAGE_FLAGS}>
        Qt5::Gui
        Qt5::Qml
        Qt5::Quick
        Qt5::Core
        Qt5::Network
        Qt5::Widgets
        LOG4CXX::LOG4CXX
)

target_link_libraries(${PROJECT_NAME}.main.bin
    PUBLIC
        ${PROJECT_NAME}.main
        LOG4CXX::LOG4CXX
)

include(GenerateExportHeader)
generate_export_header(${PROJECT_NAME}.main
    EXPORT_FILE_NAME "${CMAKE_CURRENT_BINARY_DIR}/cfs/arkhe/gcs/GCSExport.hpp"
    INCLUDE_GUARD_NAME GCS_EXPORT_HPP
    # EXPORT_MACRO_NAME API_DECLS
    BASE_NAME GCS_MAIN
    PREFIX_NAME GCS_
    #STATIC_DEFINE BUILT_AS_STATIC
    DEPRECATED_MACRO_NAME GCS_DEPRECATED
    ${NO_BUILD_DEPRECATED}
)

add_dependencies(compile ${PROJECT_NAME}.main.bin)

#add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/levitics/arkhe/gcs/app/qtsingleapplication)

#qt5_add_resources(resource_headers
#    ${CMAKE_CURRENT_LIST_DIR}/../resources/resources.qrc
#)

#qt5_wrap_ui(resource_headers_forms
#    ${CMAKE_CURRENT_LIST_DIR}/../resources/uis/connectionnotificationwidget.ui
#)

# qt5_wrap_cpp
# qt5_wrap_ui
# qt5_add_big_resources
# qt5_generate_moc
# qt5_import_plugins
# qt5_add_binary_resources
# qt5_add_resources
# qt5_create_translation
# qt5_add_translation

#set(SOURCE_FILES
#	${CMAKE_BINARY_DIR}/levitics/app/Version
#    levitics/arkhe/gcs/app/GCSApplication
#    levitics/arkhe/gcs/app/private/GCSApplicationPrivate
#    # levitics/app/View
#    # levitics/app/mainwindow
#    levitics/arkhe/gcs/app/MultiScreenManagement
#    levitics/arkhe/gcs/app/ScreensDimensions
#    # levitics/arkhe/gcs/app/private/MainWindowPrivate
#    # levitics/arkhe/gcs/EnvironmentVariablesManager
#	${resource_headers_forms}
#	${resource_headers}
#)

# qt5_add_resources(resource_headers ${SRC_DIR}/src/main/resources/resources.qrc)

#add_library(${PROJECT_NAME}.main

#)

#target_link_libraries(${PROJECT_NAME}.main
#	qtsingleapplication
#    Qt5::Concurrent Qt5::Core Qt5::Charts
#	Qt5::DataVisualization
#	Qt5::Gui
#	# Qt5::Gamepad
#	# Qt5::Help
#	Qt5::Location
#	Qt5::Network Qt5::NetworkAuth
#	Qt5::Multimedia	Qt5::MultimediaWidgets
#	Qt5::OpenGL Qt5::OpenGLExtensions
#	Qt5::Positioning #Qt5::Purchasing
#	Qt5::Quick Qt5::Qml Qt5::Quick Qt5::QuickControls2 Qt5::QuickWidgets
#	Qt5::Svg
#	Qt5::WebKit Qt5::WebKitWidgets Qt5::Widgets
#    Qt5::Xml
#)

#add_executable(${PROJECT_NAME}.main.bin
#    main.cpp
#)

#target_link_libraries(${PROJECT_NAME}.main.bin
#    #    ${PROJECT_NAME}.main
#    Qt5::Core
#	Qt5::Gui
#    Qt5::Widgets
#)


#https://cmake.org/Wiki/CMake/Tutorials/Object_Library
## A/CMakeLists.txt
# add_library(A OBJECT ${A_srcs})
## B/CMakeLists.txt
# add_library(B OBJECT ${B_srcs})
## CMakeLists.txt
# add_subdirectory(A)
# add_subdirectory(B)
# add_library(big ${other_srcs} $<TARGET_OBJECTS:A> $<TARGET_OBJECTS:B>)

# set_target_properties(${PROJECT_NAME}.bin PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
# target_link_libraries(${PROJECT_NAME}.bin ${PROJECT_NAME} ${TEST_THIRD_PARTY_LIB})
# target_link_libraries(${PROJECT_NAME}.bin ${PROJECT_NAME} )
# target_compile_definitions(${PROJECT_NAME}.bin PRIVATE "EXPORT_API=Q_DECL_EXPORT")

#add_library(${PROJECT_NAME}-osgi STATIC ${cppsrc})
#target_link_libraries( ${PROJECT_NAME}-osgi ${THIRD_PARTY_LIB}
#    Qt5::Network Qt5::Core Qt5::Widgets Qt5::Svg
#    Qt5::Quick Qt5::Xml Qt5::OpenGL Qt5::WebKit Qt5::WebKitWidgets
#)

