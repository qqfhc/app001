//
// Created by Administrator on 2016/6/13.
//
#include "com_fhc_myapplication_Jni.h"
#include "string.h"
char* _JString2CStr(JNIEnv* env, jstring jstr) {

    char* rtn;
    jclass clsstring = (*env)->FindClass(env, "java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env,"GB2312");
    jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid, strencode); // String .getByte("GB2312");
    jsize alen = (*env)->GetArrayLength(env, barr);
    jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
    if(alen > 0) {
        rtn = (char*)malloc(alen+1); //"\0"
        memcpy(rtn, ba, alen);
        rtn[alen]=0;
    }
    (*env)->ReleaseByteArrayElements(env, barr, ba,0);
    return rtn;
}
JNIEXPORT jint JNICALL Java_com_fhc_myapplication_Jni_sum
        (JNIEnv *env, jobject jobj, jint x, jint y){
    return x+y;
}
JNIEXPORT jstring JNICALL Java_com_fhc_myapplication_Jni_sayHello
        (JNIEnv *env, jobject jobj, jstring str){
//    1. 将jstring类型的js转换为char*类型数据
    char *p=_JString2CStr(env,str);
//2. 指定另一部分字符串
    char *q="yangyue";
//3. 将拼接两个char*类型字符串拼接在第一个上
    //string.h---char* strcat(char *, const char *);
            char *result=strcat(p,q);

//4. 将结果转换为jstring类型返回
    //jstring
    // (*NewStringUTF)(JNIEnv*, const char*)
    return (*env)->NewStringUTF(env,result);
}
 jintArray  Java_com_fhc_myapplication_Jni_increaseArrayEles
        (JNIEnv *env, jobject jobj, jintArray jarr){
    //1. 得到数组的长度
    //jsize (*GetArrayLength)(JNIEnv*, jarray);
    jsize length=(*env)->GetArrayLength(env,jarr);

//2. 得到数组
    //jint* (*GetIntArrayElements)(JNIEnv*, jintArray, jboolean*);
   jint* pArr= (*env)->GetIntArrayElements(env,jarr,JNI_FALSE);


//3. 遍历数组, 并将每个元素+10
    int i;
    for ( i = 0; i<length;i++) {
        *(pArr+i)+=11;
    }
//4. 返回数组
    return jarr;
}