package com.reactlibrary;

import android.support.annotation.Nullable;

import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactContext;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.modules.core.DeviceEventManagerModule;
import com.megvii.faceidiol.sdk.manager.IDCardDetectListener;
import com.megvii.faceidiol.sdk.manager.IDCardInfo;
import com.megvii.faceidiol.sdk.manager.IDCardResult;
import com.facebook.react.bridge.Callback;

public class DummyCardDetectListener implements IDCardDetectListener {

    private ReactContext reactContext;

    public DummyCardDetectListener(ReactContext reactContext) {
        super();
        this.reactContext = reactContext;
    }

    private void sendEvent(ReactContext reactContext,
                           String eventName,
                           @Nullable WritableMap params) {
        reactContext
                .getJSModule(DeviceEventManagerModule.RCTDeviceEventEmitter.class)
                .emit(eventName, params);
    }

    @Override
    public void onIdCardDetectFinish(IDCardResult result) {
        if (result.getResultCode() == 1001 || result.getResultCode() == 1002) {
            IDCardInfo info = result.getIdCardInfo();
            IDResultInfo resultInfo = new IDResultInfo();
            resultInfo.realName = info.getName().getText();
            resultInfo.imageFront = info.getImageFrontside();
            resultInfo.imageBack = info.getImageBackside();
            WritableMap params = Arguments.createMap();
            params.putString("realName", info.getName().getText());
            params.putString("country", info.getNationality().getText());
            params.putInt("cardType", 0);
            params.putString("cardId", info.getIdcardNumber().getText());
            sendEvent(reactContext, "faceIDResultEvent", params);
        }
    }
}
