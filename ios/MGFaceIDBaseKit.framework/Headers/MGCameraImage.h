//
//  MGCameraImage.h
//  MGFaceIDGeneralModule
//
//  Created by MegviiDev on 2018/5/18.
//  Copyright © 2018年 Megvii. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreMedia/CoreMedia.h>

@interface MGCameraImage : NSObject

/**
 *  裁剪图片
 *
 *  @param image  原始图片
 *  @param bounds 裁剪的区域
 *
 *  @return 裁剪后的图片
 */
UIImage* MGCameraCroppedImage(UIImage* image, CGRect bounds);

/**
 *  修正图片方向
 *
 *  @param image 原始图片
 *
 *  @return 修正完成的图片
 */
UIImage* MGCameraFixOrientationWithImage(UIImage* image);

/**
 *  把sampleBuffer转化为图片
 *
 *  @param sampleBuffer sampleBuffer
 *  @param orientation  图片的方向
 *
 *  @return 转化完成的图片
 */
UIImage* MGCameraImageFromSampleBuffer(CMSampleBufferRef sampleBuffer, UIImageOrientation orientation);

/*视频角度转化为数值*/
CGFloat MGCameraAngleOffsetFromPortraitOrientationToOrientation(AVCaptureVideoOrientation orientation);

unsigned char* MGCameraImageRGBABufferWithImage(UIImage* image);

@end
