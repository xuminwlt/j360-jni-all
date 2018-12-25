#include "me_j360_jni_bridge_AsyncBridgeService.h"
#include "me_j360_jni_bridge_BridgeListener.h"

JavaVM* jvm;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm,void* reserved){
    JNIEnv *env;
    jvm = vm;

    printf("onload\n");
    return JNI_VERSION_1_8;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved) {
    printf("onunload\n");
}

JNIEXPORT void JNICALL Java_me_j360_jni_bridge_AsyncBridgeService_call
  (JNIEnv *env, jobject jobj) {
    printf("call\n");

    jclass thisClass = (*env)->GetObjectClass(env, jobj);
    jmethodID callId = (*env)->GetMethodID(env, thisClass, "getBridgeListener", "()Lme/j360/jni/bridge/BridgeListener;");
    jobject listener = (*env)->CallObjectMethod(env, jobj, callId);

    //enter thread

    jclass callbackClass = (*env)->GetObjectClass(env, listener);
    jstring jmsg = (*env)->NewStringUTF(env, "");
    jmethodID callbackId = (*env)->GetMethodID(env, callbackClass, "onProgress", "(ILjava/lang/String;)V");
    (*env)->CallVoidMethod(env, listener, callbackId, 0, jmsg);
  }

