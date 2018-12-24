package me.j360.jni;

import me.j360.jni.bridge.ImageBridge;
import me.j360.jni.bridge.ImageBridgeCallback;

/**
 * @author: min_xu
 * @date: 2018/12/24 6:24 PM
 * 说明：
 */
public class Bootstarp {

    public static void main(String[] args) {
        ImageBridge bridge = new ImageBridge();

        //Samples
        bridge.filter("/sample1.png", 1);
        bridge.filter("/sample2.png", 2);
        bridge.filter("/sample3.png", 3);

        ImageBridgeCallback callback = ImageBridgeCallback.getInstance();
        callback.call("/usr/local/");
    }
}
