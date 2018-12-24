#include "me_j360_jni_bridge_ImageBridge.h"

JNIEXPORT void JNICALL Java_me_j360_jni_bridge_ImageBridge_filter
  (JNIEnv *env, jobject obj, jstring localUrl, jint id) {
    printf("开始执行filter:%d\n", id);
}