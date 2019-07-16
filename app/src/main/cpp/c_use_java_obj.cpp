//
// Created by 石鑫 on 2018/11/24.
//实例方法调用
//
#include <jni.h>
//#include <>
//日志库
#include <android/log.h>
#include <iostream>

#define TAG "Native-lib"

//常用的一种方式
#define LOGE(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)


/**
 * 实例方法调用测试
 */
extern "C"
JNIEXPORT void JNICALL
Java_shixin_ndkdemo_MainActivity_testObjectMethodUse(JNIEnv *env, jobject instance, jint age,
                                                     jstring name_) {

    //1. 利用FindClass，找到jclass
    jclass class_Objtest = env->FindClass("shixin/ndkdemo/obj_test/ObjectTest");
    if (class_Objtest == NULL) {
        LOGE("没找到类");
        return;
    }
    //2. 利用GetMethodID，找到方法id
    jmethodID meth_id_logInfo = env->GetMethodID(class_Objtest, "logInfo", "()V");

    /*3. 创建实例对象，由于jni没有直接方法创建java对象，所以通过构造方法来创建*/
    //3.1 获取构造方法，这里使用的是无参构造方法
    jmethodID mtheod_construct_init = env->GetMethodID(class_Objtest, "<init>", "()V");
    //3.2 创建实例Object,NewObject,参数：类、构造方法id
    jobject object_ = env->NewObject(class_Objtest, mtheod_construct_init);
    if (object_ == NULL) {
        LOGE("创建对象失败");
        return;
    }

    LOGE("准备执行loginfo");
    //4. 调用方法,CallVoidMethod,参数:实例、要调用的方法id
    env->CallVoidMethod(object_, meth_id_logInfo);
    if (env->ExceptionOccurred()) {
        //打印异常
        env->ExceptionDescribe();
        //clear方法执行了后，应用就不会因为这个异常而崩溃
        env->ExceptionClear();
        LOGE("出现异常");
        jclass clss_excep = env->FindClass("java/lang/Exception");
        char *errorMessage = "这是一个异常";
        //咱们试试手动抛出一个异常
        env->ThrowNew(clss_excep, errorMessage);
        return;
    }
    LOGE("执行完loginfo");

    /*5. 试试修改字段.这里我们利用java调用传进来的age和name值来修改ObjectTest中的age和name*/
    //5.1 先找到字段的id,参数：类、字段名、字段的签名，这里age是int的，所以是I
    jfieldID f_id_age = env->GetFieldID(class_Objtest, "age", "I");
    if (f_id_age == NULL) {
        LOGE("没找到age字段");
        return;
    }
    //5.2 设置age值,参数：实例对象、字段id、值
    env->SetIntField(object_, f_id_age, age);
    //5.3 同样的方式，获取name的字段id和设置值
    jfieldID f_id_name = env->GetFieldID(class_Objtest, "name", "Ljava/lang/String;");
    if (f_id_name == NULL) {
        LOGE("没找到name字段");
        return;
    }
    //因为String是Object类型，所以使用SetObjectField
    env->SetObjectField(object_, f_id_name, name_);
    //5.4 修改了值之后，再来验证调用一次logInfo，查看打印
    env->CallVoidMethod(object_, meth_id_logInfo);


    /*6. 测试下带参数的构造方法，传入性别，再调用打印性别的方法*/
    jmethodID mtheod_construct_init_sex = env->GetMethodID(class_Objtest, "<init>",
                                                           "(Ljava/lang/String;)V");
    jstring string_sex = env->NewStringUTF("女");
    jobject object_sex = env->NewObject(class_Objtest, mtheod_construct_init_sex, string_sex);
    if (object_sex == NULL) {
        LOGE("带参构造方法创建对象失败");
        return;
    }
    //6.1 找到打印性别的方法id
    jmethodID mid_log_sex = env->GetMethodID(class_Objtest, "logSex", "()V");
    if (mid_log_sex == NULL) {
        LOGE("没找到打印性别这个方法");
        return;
    }
    //6.2 开始调用
    env->CallVoidMethod(object_sex, mid_log_sex);


    /*释放类和对象*/
    env->DeleteLocalRef(class_Objtest);
    env->DeleteLocalRef(object_);

    env->DeleteLocalRef(string_sex);
}
