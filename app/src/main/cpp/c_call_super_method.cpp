//
// Created by 石鑫 on 2018/12/6.
//
//


#include <jni.h>
//日志库
#include <android/log.h>

#define TAG "jni_call_super"

//常用的一种方式
#define LOGE(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)

/**
 *测试调用父类方法
 */
extern "C"
JNIEXPORT jint JNICALL
Java_shixin_ndkdemo_MainActivity_testCallSuperMethod(JNIEnv *env, jobject instance, jint age_,
                                                     jstring name_) {

    //1. 找Beibi的class
    jclass class_beibi = env->FindClass("shixin/ndkdemo/supermethod/Beibi");
    if (class_beibi == NULL) {
        LOGE("beibi class 寻找失败");
        return 1;
    }

    //2. 找Beibi的构造方法id
    jmethodID jmethodID_init = env->GetMethodID(class_beibi, "<init>",
                                                "(ILjava/lang/String;)V");

    if (jmethodID_init == NULL) {
        LOGE("beibi 构造方法 寻找失败");
        return 1;
    }

    //3. 创建Beibi对象
    jobject obj_beibi = env->NewObject(class_beibi, jmethodID_init, age_, name_);
    if (obj_beibi == NULL) {
        LOGE("beibi 对象创建失败");
        return 1;
    }

    //4. 调用Beibi的say方法
    jmethodID jmethodID1_say = env->GetMethodID(class_beibi, "say", "()V");
    if (jmethodID1_say == NULL) {
        LOGE("beibi say方法寻找失败");
        return 1;
    }
    env->CallVoidMethod(obj_beibi, jmethodID1_say);

    /*···········下面来调用父类方法··········*/
    //5. 找到父类，People的class
    jclass class_people = env->FindClass("shixin/ndkdemo/supermethod/People");
    if (class_people == NULL) {
        LOGE("People class 寻找失败");
        return 1;
    }

    //6. 找到People的say方法id
    jmethodID jmethodID1_people_say = env->GetMethodID(class_people, "say", "()V");
    if (jmethodID1_people_say == NULL) {
        LOGE("people say方法 寻找失败");
        return 1;
    }

    //7. 调用父类方法 使用 CallNonvirtualVoidMethod 方法，参数：实例对象，class，方法id
    env->CallNonvirtualVoidMethod(obj_beibi, class_people, jmethodID1_people_say);

    //释放
    env->DeleteLocalRef(class_beibi);
    env->DeleteLocalRef(class_people);
    env->DeleteLocalRef(obj_beibi);
    return 0;
}
