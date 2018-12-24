package me.j360.jni.bridge;

/**
 * @author: min_xu
 * @date: 2018/12/24 6:25 PM
 * 说明：
 */

public class ImageBridge {

    static {
        System.loadLibrary("ImageBridge");
    }

    public native void filter(String localUrl, int filterId);

}
