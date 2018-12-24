package me.j360.jni.bridge;

/**
 * @author: min_xu
 * @date: 2018/12/24 6:34 PM
 * 说明：
 */
public class ImageBridgeCallback {

    private String localUrl;

    public ImageBridgeCallback(String localUrl) {
        this.localUrl = localUrl;
    }

    public void call() {
        //TODO
        System.out.println("---------");
        System.out.println(localUrl);
        System.out.println("---------");
    }


    public String getLocalUrl() {
        return localUrl;
    }

    public void setLocalUrl(String localUrl) {
        this.localUrl = localUrl;
    }
}
