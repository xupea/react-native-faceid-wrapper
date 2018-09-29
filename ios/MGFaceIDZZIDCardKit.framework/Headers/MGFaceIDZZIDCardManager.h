//
//  MGFaceIDZZIDCardManager.h
//  CocoaPods
//
//  Created by MegviiDev on 2018/5/28.
//  Copyright © 2018年 Megvii. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MGFaceIDZZIDCardConfig.h"
#import "MGFaceIDZZIDCardErrorItem.h"

@interface MGFaceIDZZIDCardManager : NSObject

/**
 初始化FaceID自助接入身份证检测
 由于bizToken的唯一性，每一个token仅可以调用一次startMGFaceIDZZIDcardDetect:bizToken:bizNumber:callback:检测方法
 @param signStr 身份签名
 @param signVersionStr 签名算法版本
 @param bizTokenStr 业务串号
 @param extraDict 预留信息。非必选参数，可以为nil
 @param error 错误类型
 @return 初始化对象
 */

- (instancetype _Nullable)initMGFaceIDZZIDCardManagerWithSign:(NSString *__nonnull)signStr
                                                  signVersion:(NSString *__nonnull)signVersionStr
                                                     bizToken:(NSString **__nonnull)bizTokenStr
                                                    extraData:(NSDictionary *__nullable)extraDict
                                                        error:(MGFaceIDZZIDCardErrorItem **__nullable)error;



/**
 开始身份证检测

 @param detectVC 启动检测的当前页面
 @param bizTokenStr 当前启动检测的业务串号
 @param bizNumberStr 客户业务流水号，建议设置为业务相关流水串号并且唯一，用于与客户业户数据关联。非必选参数，可以为nil
 @param screenOrientation 设备拍摄横竖屏模式
 @param shootPage 身份证拍摄页面
 @param block 检测结果
 */

- (void)startMGFaceIDZZIDcardDetect:(UIViewController *__nonnull)detectVC
                           bizToken:(NSString *__nonnull)bizTokenStr
                          bizNumber:(NSString * __nullable)bizNumberStr
                  screenOrientation:(MGFaceIDZZIDCardScreenOrientation)screenOrientation
                          shootPage:(MGFaceIDZZIDCardShootPage)shootPage
                           callback:(FaceIDZZIDCardDetectResultBlock __nullable)block;

/**
 获取SDK版本号信息

 @return SDK版本号
 */
+ (NSString *_Nonnull)getSDKVersion;

/**
 获取SDK构建信息

 @return SDK构建号
 */
+ (NSString *_Nonnull)getSDKBuild;

@end
