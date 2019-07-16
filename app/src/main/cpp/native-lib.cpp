#include <jni.h>
//#include <>
//日志库
#include <android/log.h>

#define TAG "Native-lib"

//常用的一种方式
#define LOGE(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)

/**
 * 自动生成的方法
 */
extern "C"
JNIEXPORT jint JNICALL
Java_shixin_ndkdemo_MainActivity_intFromJni(JNIEnv *env, jobject instance) {

    jint age = 5;
    return age;
}


#include <string>
//android日志库
#include <android/log.h>

extern "C" JNIEXPORT jstring
JNICALL
Java_shixin_ndkdemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    __android_log_print(ANDROID_LOG_INFO, "nate", "C 打印日志了");
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_shixin_ndkdemo_MainActivity_stringFromJNI__Ljava_lang_String_2(JNIEnv *env, jobject instance,
                                                                    jstring string_) {
    const char *string = env->GetStringUTFChars(string_, 0);

    // TODO

    std::string hello = "Hello from C++";
    env->ReleaseStringUTFChars(string_, string);

    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_shixin_ndkdemo_MainActivity_callStaticNative__Ljava_lang_String_2(JNIEnv *env, jclass type,
                                                                       jstring string_) {
    const char *string = env->GetStringUTFChars(string_, 0);

    // TODO

    env->ReleaseStringUTFChars(string_, string);
}

extern "C"
JNIEXPORT void JNICALL
Java_shixin_ndkdemo_MainActivity_callStaticNative__Ljava_lang_String_2I(JNIEnv *env, jclass type,
                                                                        jstring string_, jint age) {
    const char *string = env->GetStringUTFChars(string_, 0);

    // TODO

    env->ReleaseStringUTFChars(string_, string);
}