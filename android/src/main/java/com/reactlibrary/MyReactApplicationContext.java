package com.reactlibrary;

import android.content.Context;
import android.widget.Toast;
import com.facebook.react.bridge.ReactContext;
import com.megvii.faceidiol.sdk.manager.IDCardDetectListener;
import com.megvii.faceidiol.sdk.manager.IDCardResult;

public class MyReactApplicationContext implements IDCardDetectListener {

    public MyReactApplicationContext() {
        super();
    }

    @Override
    public void onIdCardDetectFinish(IDCardResult result) {
        System.out.print(result);
    }
}
