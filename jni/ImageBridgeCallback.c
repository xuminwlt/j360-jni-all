#include "me_j360_jni_bridge_ImageBridgeCallback.h"

JNIEXPORT jobject JNICALL Java_me_j360_jni_bridge_ImageBridgeCallback_getInstance
  (JNIEnv *env, jclass thisClass) {

        jclass cls = (*env)->FindClass(env, "me/j360/jni/bridge/ImageBridgeCallback");
        //获取构造函数的ID
        jmethodID midInit = (*env)->GetMethodID(env, cls, "<init>", "(Ljava/lang/String;)V");
        if (NULL == midInit) return NULL;
        //调用构造函数
        jstring cid = (*env)->NewStringUTF(env, "watermark");
        jobject newObj = (*env)->NewObject(env, cls, midInit, cid);

        //callback
        jmethodID callId = (*env)->GetMethodID(env, thisClass, "call", "(Ljava/lang/String;)V");
        (*env)->CallVoidMethod(env, newObj, callId, cid);
        return newObj;
}