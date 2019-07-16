//
// Created by 石鑫 on 2018/11/28.
//异常分析
//

#include <jni.h>
//#include <>
//日志库
#include <android/log.h>

#define TAG "Native-lib"

//常用的一种方式
#define LOGE(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)

/**
 * 空指针
 */
void crashNull() {
    //0为其实地址，是不可读写的，会立即崩溃
//    int *p = 0;
//    //判断不为空再进行执行
//    if (*p != NULL) {
//        *p = 1;
//        LOGE("p:%d", *p);
//    }
}

/**
 * 野指针
 */
void wildPointer() {
    int o;
    //初始化,指向给o的地址
    int *p = &o;
    //中途使用赋值，就是给o赋值了
    *p = 1;
    LOGE("o:%d", *p);
    //用完后指向NULL
    *p = NULL;
}

/**
 * 数组越界
 */
void arrayPointer() {
    int data[10];
    //越界赋值
    int sizeData = sizeof(data);
    for (int i = 0; i < 17; ++i) {
//        if (sizeData <= 17) {
        data[i] = 15;
//        }
    }
    LOGE("data[11]:%d", data[11]);
}

/**
 * 内存泄漏
 */
void memeryLeak(JNIEnv *env) {

    jstring str = env->NewStringUTF("哈哈哈哈");
    if (str == NULL) {
        LOGE("str is null");
        return;
    }
    const char *stringChar = env->GetStringUTFChars(str, 0);
    LOGE("str:%s", stringChar);

    //用完后进行释放
    env->DeleteLocalRef(str);
    env->ReleaseStringUTFChars(str, stringChar);
}

/**
 * 除以0
 */
void zeroDiv() {
    int a = 1;
    //将分母给拿出来判断，运行时很可能是某个计算值
    int c = 0;
    int b = 1;
    if (c != 0) {
        //判断下
        b = a / c;
    } else {
        b = a;
    }
    LOGE("b:%d", b);
}

extern "C"
JNIEXPORT void JNICALL
Java_shixin_ndkdemo_MainActivity_testCrash(JNIEnv *env, jobject instance) {

    // TODO
//    crashNull();
    arrayPointer();
//    wildPointer();

    //除以0
//    zeroDiv();

    //内存泄漏
    memeryLeak(env);
}