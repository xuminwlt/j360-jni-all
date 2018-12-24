package me.j360.jni.bridge;

/**
 * @author: min_xu
 * @date: 2018/12/24 6:34 PM
 * 说明：
 */
public class ImageBridgeCallback {

    static {
        System.loadLibrary("ImageBridgeCallback");
    }

    private String cid;

    private ImageBridgeCallback(String cid) {
        this.cid = cid;
    }

    public static native ImageBridgeCallback getInstance();

    public void call(String localUrl) {
        //TODO
        System.out.println("---------");
        System.out.println("cid:" + cid + " localUrl:" + localUrl);
        System.out.println("---------");
    }

}
