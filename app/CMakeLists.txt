# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

#指定需传入三个参数（准备打包生成so函数库名称，库类型，依赖源文件相对路径即代码路径）
add_library( # Sets the name of the library.
        my_native_lib

        # SHARED 动态链接库  STATIC 静态链接库
        SHARED

        # Provides a relative path to your source file(s).
        src/main/cpp/native-lib.cpp src/main/cpp/androidLog.cpp
        src/main/cpp/c_use_java_static.cpp
        src/main/cpp/c_use_java_obj.cpp
        src/main/cpp/crash_test.cpp
        src/main/cpp/c_call_super_method.cpp
        src/main/cpp/set_in_value.cpp)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

# 用于定位NDK中的库，通过find来找到，并取个path变量
# 需要传入两个参数（path变量、ndk库名称）
find_library( # Sets the name of the path variable.
        #变量名取为log-lib
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        #找ndk中的log库，即找ndk中的包为liblog.so
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

# 指定关联到原生库的库
target_link_libraries( # Specifies the target library.
        #我们的库,与前面的name保持一致
        my_native_lib

        # Links the target library to the log library
        # included in the NDK.
        #要链接进来的库，如上面指定的path
        ${log-lib})