//
// Created by 石鑫 on 2018/12/5.
//测试修改传入字段的值
//
#include <jni.h>
#include <cstdlib>
#include <android/log.h>
#include <cstring>

#define TAG "set_in_value"

//常用的一种方式
#define LOGE(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)

/**
 * 测试修改传入值
 * 1. bytes 从java传入一个长度为5的byte数组
 */
extern "C"
JNIEXPORT jint JNICALL
Java_shixin_ndkdemo_MainActivity_testSetInField(JNIEnv *env, jobject instance, jbyteArray bytes_) {
    jbyte *bytes = env->GetByteArrayElements(bytes_, NULL);

    //分配一个和java传下来长度一样的字符串
    char *charP = (char *) malloc(8);
    int size = sizeof(charP);
    memset(charP,0, size);
    LOGE("size %d", size);
    /*给字符组赋值*/
    charP = "12345";
    //利用SetByteArrayRegion方法来给传入的byte数组对象赋值，参数：要赋值的byte组，其实点，长度，数据来源指针
    env->SetByteArrayRegion(bytes_, 0, 5, (jbyte *) charP);

    //释放，free为什么会崩溃？
    free(charP);
    //如果传的对象下来，之后还需要使用，那么就不要做释放了，不然在上层使用的时候，值就没了，比如这里的byte数组
//    env->ReleaseByteArrayElements(bytes_, bytes, 0);
    return 1;
}