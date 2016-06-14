//
// Created by Administrator on 2016/6/13.
//
#include "com_fhc_myapplication_JNIS.h"
JNIEXPORT jstring JNICALL Java_com_fhc_myapplication_JNIS_helloJNI
        (JNIEnv * env, jobject jobj){
    return (*env)->NewStringUTF(env, "Hello from C");
}

