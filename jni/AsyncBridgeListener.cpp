#include <jni.h>

#include "pthread.h"
#include "unistd.h"
#include "me_j360_jni_bridge_BridgeListener.h"
#include "me_j360_jni_bridge_AsyncBridgeService.h"
JavaVM* jvm;

CommonListener::CommonListener(JavaVM *vm, JNIEnv *env, jobject obj) {
    jvm = vm;
    jenv = env;
    jobj = obj;
    jclass clz = env->GetObjectClass(jobj);
    if(!clz)
    {
        return;
    }
    jmid = env->GetMethodID(clz, "onProgress", "(ILjava/lang/String;)V");
    if(!jmid)
    {
        return;
    }
}

/**
 *
 * @param type  0：env线程 1：子线程
 * @param code
 * @param msg
 */
void CommonListener::onProgress(int type, int code, const char *msg) {
    if(type == 0)
    {
        jstring jmsg = jenv->NewStringUTF(msg);
        jenv->CallVoidMethod(jobj, jmid, code, jmsg);
        jenv->DeleteLocalRef(jmsg);
    }
    else if(type == 1)
    {
        JNIEnv *env;
        jvm->AttachCurrentThread((void **) &env, 0);

        jstring jmsg = env->NewStringUTF(msg);
        env->CallVoidMethod(jobj, jmid, code, jmsg);
        env->DeleteLocalRef(jmsg);

        jvm->DetachCurrentThread();
    }
}

extern "C"
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm,void* reserved){
    JNIEnv *env;
    jvm = vm;

    printf("onload\n");
    return JNI_VERSION_1_8;
}
extern "C"
JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved) {
    printf("onunload\n");
}

extern "C"
JNIEXPORT void JNICALL Java_me_j360_jni_bridge_AsyncBridgeService_call
  (JNIEnv *env, jobject jobj) {
    printf("call\n");

    //start thread
    jclass thisClass = env->GetObjectClass(jobj);
    jmethodID callId = env->GetMethodID(thisClass, "getBridgeListener", "()Lme/j360/jni/bridge/BridgeListener;");
    jobject listener = env->CallObjectMethod(jobj, callId);

    CommonListener *cListener = new CommonListener(jvm, env, listener);


  }
