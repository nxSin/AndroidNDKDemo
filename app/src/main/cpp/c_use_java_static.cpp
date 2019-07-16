//
// Created by 石鑫 on 2018/11/24.
//
#include <jni.h>
//#include <>
//日志库
#include <android/log.h>
#include <stdio.h>
#include <iostream>

#define TAG "Native-lib"

//常用的一种方式
#define LOGE(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)


/**
 * 测试静态方法调用
 */
extern "C"
JNIEXPORT void JNICALL
Java_shixin_ndkdemo_MainActivity_testStaticMethodUse(JNIEnv *env, jobject instance) {

//1. 使用FindClass方法找到类,参数：全路径
    jclass class_static = env->FindClass("shixin/ndkdemo/static_test/StaticClassTest");

    if (class_static == NULL) {
        LOGE("没找到StaticClassTest");
        return;
    }

//2. 找到方法,无参数，无返回。参数：class、方法名称、方法签名
    jmethodID jme_staticMethodTest = env->GetStaticMethodID(class_static, "staticMethodTest",
                                                            "()V");
    if (jme_staticMethodTest == NULL) {
        LOGE("没找到jme_staticMethodTest");
        return;
    }

//3. 开始调用,因为是返回void的，所以调用CallStaticVoidMethod
    env->CallStaticVoidMethod(class_static, jme_staticMethodTest);


//带参数和返回值的静态方法
    jmethodID jme_staticMethodTest_Have_Back = env->GetStaticMethodID(class_static,
                                                                      "staticMethodTest",
                                                                      "(Ljava/lang/String;)I");
    if (jme_staticMethodTest_Have_Back == NULL) {
        LOGE("没找到jme_staticMethodTest_Have_Back");
        return;
    }


//4. 在调用带参数方法前，我们试着修改下fild，即静态类中的age
    jfieldID jfieldID_age = env->GetStaticFieldID(class_static, "age", "I");
    if (jfieldID_age == NULL) {
        LOGE("没找到age字段");
        return;
    }

//给age字段赋值为7
    env->SetStaticIntField(class_static, jfieldID_age, 7);

    jstring string_para = env->NewStringUTF("北鼻");
    int a = env->CallStaticIntMethod(class_static, jme_staticMethodTest_Have_Back, string_para);
    LOGE("调用后返回: %d", a);

//使用完，释放本地变量,这里有两个，class和后面用到的string字符串
    env->DeleteLocalRef(class_static);
    env->DeleteLocalRef(string_para);
}