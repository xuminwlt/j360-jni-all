package me.j360.jni.bridge;

/**
 * @author: min_xu
 * @date: 2018/12/25 10:55 AM
 * 说明：
 */
public class AsyncBridgeService {


    static {
        System.loadLibrary("AsyncBridgeService");
    }

    private  static AsyncBridgeService asyncBridgeService = null;
    private BridgeListener bridgeListener;

    private AsyncBridgeService(){

    }

    public static AsyncBridgeService getInstances(){
        if(asyncBridgeService == null){
            asyncBridgeService = new AsyncBridgeService();
        }
        return  asyncBridgeService;
    }

    //回调线程
    public native void call();

    public void setBridgeListener(BridgeListener bridgeListener) {
        this.bridgeListener = bridgeListener;
    }

    public BridgeListener getBridgeListener() {
        return bridgeListener;
    }
}
