#include <jni.h>
#include <sys/socket.h>
#include <android/log.h>
#include <net/if.h>
#include <string>
#include <unistd.h>
//
// Created by 石鑫 on 2021/8/17.
//
#define TAG "udptest"
#define LOGE(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)


extern "C"
JNIEXPORT void JNICALL
Java_shixin_ndkdemo_MainActivity_testUDPMethod(JNIEnv *env, jobject thiz) {
    // TODO: implement testUDPMethod()

    int socketHandle = socket(AF_INET, SOCK_DGRAM, 0);
    if (socketHandle == -1) {
        LOGE("hand is error");
        return;
    }

    ifreq ifreqT;
    memset(&ifreqT, 0, sizeof(ifreq));
    strncpy(ifreqT.ifr_ifrn.ifrn_name, "eth1", strlen("eth1"));
    if ((setsockopt(socketHandle, SOL_SOCKET, SO_BINDTODEVICE, (char *) &ifreqT, sizeof(ifreqT))) <
        0) {
        LOGE("SO_BINDTODEVICE is error");
        close(socketHandle);
        socketHandle = -1;
        return;
    }

    int broadcast = 1;
    int error;
    error = setsockopt(socketHandle, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(int));
    if (error == -1) {
        LOGE("SO_BROADCAST is error ");
        close(socketHandle);
        return;
    }

    int nEnable = 1;
    error = setsockopt(socketHandle, SOL_SOCKET, SO_REUSEADDR, &nEnable, sizeof(int));
    if (error == -1) {
        LOGE("SO_REUSEADDR is error ");
        close(socketHandle);
        return;
    }

    int flags = fcntl(socketHandle, F_GETFL, 0);
    fcntl(socketHandle, F_SETFL, flags | O_NONBLOCK);
}