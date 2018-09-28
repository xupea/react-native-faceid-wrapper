package com.reactlibrary;

import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;

import com.facebook.react.bridge.WritableMap;
import com.megvii.faceidiol.sdk.manager.IDCardDetectListener;
import com.megvii.faceidiol.sdk.manager.IDCardManager;
import com.megvii.faceidiol.sdk.manager.UserDetectConfig;

import com.megvii.faceid.zzplatform.sdk.listener.FaceIdDetectListener;
import com.megvii.faceid.zzplatform.sdk.listener.FaceIdInitListener;
import com.megvii.faceid.zzplatform.sdk.manager.FaceIdManager;

public class ReactNativeFaceIDWrapperModule extends ReactContextBaseJavaModule {

  private final ReactApplicationContext reactContext;
  private UserDetectConfig config;
  private String bizToken;
  private String mSign;

  public ReactNativeFaceIDWrapperModule(ReactApplicationContext reactContext) {
    super(reactContext);
    this.reactContext = reactContext;
    FaceIdManager.getInstance(reactContext).setFaceIdInitListener(mInitListener);
    FaceIdManager.getInstance(reactContext).setFaceIdDetectListener(mDetectListener);
  }

  @Override
  public String getName() {
    return "ReactNativeFaceIDWrapper";
  }

  @ReactMethod
  public void startDetectID(String apiKey, String secret) {
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

  @ReactMethod
  public void startDetectFace(String bizToken, Promise promise) {
    this.bizToken = bizToken;
    detectPromise = promise;
    enterNextPage();
  }

  @ReactMethod
  public void getAppSign(String apiKey, String secret, Promise promise) {
    long currtTime = System.currentTimeMillis() / 1000;
    long expireTime = System.currentTimeMillis() / 1000 + 60 * 60 * 24;
    mSign = GenerateSign.appSign(apiKey, secret, currtTime, expireTime).replaceAll("[\\s*\t\n\r]", "");
    WritableMap map = Arguments.createMap();
    map.putString("sign", mSign);
    promise.resolve(map);
  }

  private void enterNextPage(){
    FaceIdManager.getInstance(reactContext).init(bizToken);
  }

  private FaceIdInitListener mInitListener = new FaceIdInitListener() {
    @Override
    public void onSuccess() {
      FaceIdManager.getInstance(reactContext).startDetect();
    }

    @Override
    public void onFailed(int code, String msg) {
    }
  };

  private Promise detectPromise;

  private FaceIdDetectListener mDetectListener = new FaceIdDetectListener() {
    @Override
    public void onSuccess(int code, String msg) {
      WritableMap map = Arguments.createMap();
      map.putInt("code", code);
      map.putString("msg", msg);
      detectPromise.resolve(map);
    }

    @Override
    public void onFailed(int code, String msg) {
      detectPromise.reject(String.format("%d", code), msg);
    }
  };
}