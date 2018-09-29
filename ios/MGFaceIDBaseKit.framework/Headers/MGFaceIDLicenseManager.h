//
//  MGFaceIDLicenseManager.h
//  MGFaceIDGeneralModule
//
//  Created by MegviiDev on 2018/5/18.
//  Copyright © 2018年 Megvii. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MGFaceIDLicenseManager : NSObject

/**
 判断SDK是否已经授权

 @param faceIDSDKVersion SDK的版本信息
 @return SDK授权状态。默认值为NO(没有授权),YES(已授权).
 */
+ (BOOL)isLicense:(NSString *)faceIDSDKVersion;


/**
 获取SDK授权截止日期

 @param faceIDSDKVersion SDK的版本信息
 @return SDK授权禁止日期，如果没有经过授权，则为时间戳为0的时间
 */
+ (NSDate *)getLicenseData:(NSString *)faceIDSDKVersion;


/**
 进行SDK自动联网授权

 @param result block返回联网授权结果。如果授权成功，则isLicense = YES，默认为NO.
 @param faceIDSDKVersion SDK的版本信息
 */
+ (void)licenseForNetworkWithVersion:(NSString *)faceIDSDKVersion result:(void(^)(BOOL isLicense))result;


/**
 获取SDK-Auth信息

 @param faceIDSDKVersion SDK的版本信息
 @return 用于SDK联网授权的验证字符串信息。该信息可以通过FaceID鉴权接口解密
 */
+ (NSString *)getLicenseAuthMsgStr:(NSString *)faceIDSDKVersion;


/**
 使用已鉴权的解密信息进行SDK授权

 @param licenseData 通过FaceID鉴权接口获取的解密信息
 @return SDK授权状态。默认值为NO(没有授权),YES(已授权).
 */
+ (BOOL)licenseForLicenseInfo:(NSData *)licenseData;

@end
