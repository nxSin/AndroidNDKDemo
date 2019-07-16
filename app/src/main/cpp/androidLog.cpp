//
// Created by 石鑫 on 2018/11/16.
//

#include <jni.h>
//日志库
#include <android/log.h>

#define TAG "LogTest"

//常用的一种方式
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)

extern "C"
JNIEXPORT void JNICALL
Java_shixin_ndkdemo_MainActivity_testAndroidLog(JNIEnv *env, jobject instance) {

    // 打印日志: 参数：日志级别、TAG、内容，内容中的值
    __android_log_print(ANDROID_LOG_VERBOSE, TAG, "C 打印日志了");
    __android_log_print(ANDROID_LOG_INFO, TAG, "11 %d ", 1);
    __android_log_print(ANDROID_LOG_WARN, TAG, "%s", "what");
    __android_log_print(ANDROID_LOG_ERROR, TAG, "%d", 2);

    //使用定义方式来输出
    LOGI("11111 %d", 344);
    LOGI("11111 ");
}
