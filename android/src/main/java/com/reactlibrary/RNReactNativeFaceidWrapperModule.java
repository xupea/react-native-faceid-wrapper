package com.reactlibrary;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;

import com.megvii.faceidiol.sdk.manager.IDCardDetectListener;
import com.megvii.faceidiol.sdk.manager.IDCardManager;
import com.megvii.faceidiol.sdk.manager.IDCardResult;
import com.megvii.faceidiol.sdk.manager.UserDetectConfig;

import static android.os.Build.VERSION_CODES.M;

public class RNReactNativeFaceidWrapperModule extends ReactContextBaseJavaModule {

  private final ReactApplicationContext reactContext;
  private UserDetectConfig config;

  public RNReactNativeFaceidWrapperModule(ReactApplicationContext reactContext) {
    super(reactContext);
    this.reactContext = reactContext;
  }

  @Override
  public String getName() {
    return "RNReactNativeFaceidWrapper";
  }

  @ReactMethod
  public void showFaceID() {
    config = new UserDetectConfig();
    beginDetect();
  }

  private void beginDetect() {
    new Thread(new Runnable() {
      @Override
      public void run() {
        String apiKey = "rnEgefPhNcKNF1lkpOYeDBFCnn5t8wkH";
        String secret = "Wt34-cc0pADqGz-GqyvOxx3-RgOsIpPb";
        long currtTime = System.currentTimeMillis() / 1000;
        long expireTime = System.currentTimeMillis() / 1000 + 60 * 60 * 24;
        String sign = GenerateSign.appSign(apiKey, secret, currtTime, expireTime);

        config.setScreenDirection(0);
        config.setCaptureImage(0);

        IDCardManager.getInstance().init(reactContext, sign, "hmac_sha1", config, new IDCardManager.InitCallBack() {
          @Override
          public void initSuccess(String bizToken) {
            IDCardDetectListener cardDetectListener = new MyReactApplicationContext();
            IDCardManager.getInstance().setIdCardDetectListener(cardDetectListener);
            IDCardManager.getInstance().startDetect(reactContext, bizToken, "");
          }

          @Override
          public void initFailed(int resultCode, String resultMessage) {

          }
        });
      }
    }).start();
  }
}