package com.reactlibrary;

import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.Callback;

import com.megvii.faceidiol.sdk.manager.IDCardDetectListener;
import com.megvii.faceidiol.sdk.manager.IDCardManager;
import com.megvii.faceidiol.sdk.manager.UserDetectConfig;

public class ReactNativeFaceIDWrapperModule extends ReactContextBaseJavaModule {

  private final ReactApplicationContext reactContext;
  private UserDetectConfig config;

  public ReactNativeFaceIDWrapperModule(ReactApplicationContext reactContext) {
    super(reactContext);
    this.reactContext = reactContext;
  }

  @Override
  public String getName() {
    return "ReactNativeFaceIDWrapper";
  }

  @ReactMethod
  public void startDetectID(String apiKey, String secret, Promise promise) {
    config = new UserDetectConfig();
    beginDetect(apiKey, secret);
  }

  private void beginDetect(final String apiKey, final String secret) {
    new Thread(new Runnable() {
      @Override
      public void run() {
        long currtTime = System.currentTimeMillis() / 1000;
        long expireTime = System.currentTimeMillis() / 1000 + 60 * 60 * 24;
        String sign = GenerateSign.appSign(apiKey, secret, currtTime, expireTime);

        config.setScreenDirection(0);
        config.setCaptureImage(0);

        IDCardManager.getInstance().init(reactContext, sign, "hmac_sha1", config, new IDCardManager.InitCallBack() {
          @Override
          public void initSuccess(String bizToken) {
            IDCardDetectListener cardDetectListener = new DummyCardDetectListener(reactContext);
            IDCardManager.getInstance().setIdCardDetectListener(cardDetectListener);
            IDCardManager.getInstance().startDetect(reactContext, bizToken, "");
          }

          @Override
          public void initFailed(int resultCode, String resultMessage) {
//            errorCallback.invoke(resultCode, resultMessage);
          }
        });
      }
    }).start();
  }
}