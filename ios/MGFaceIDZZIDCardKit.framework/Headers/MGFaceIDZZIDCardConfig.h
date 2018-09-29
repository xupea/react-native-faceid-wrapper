//
//  MGFaceIDZZIDCardConfig.h
//  CocoaPods
//
//  Created by MegviiDev on 2018/5/28.
//  Copyright © 2018年 Megvii. All rights reserved.
//

#ifndef MGFaceIDZZIDCardConfig_h
#define MGFaceIDZZIDCardConfig_h
@class MGFaceIDZZIDCardDetectItem;
@class MGFaceIDZZIDCardErrorItem;

//  身份证检测错误类型
typedef enum : NSUInteger {
    MGFaceIDZZIDCardErrorOCRSuccess = 1001,                     //  识别出身份证正反面均没有问题
    MGFaceIDZZIDCardErrorOCRSuccessBackSide = 1001,             //  只需识别国徽面时识别成功
    MGFaceIDZZIDCardErrorOCRSuccessFrontSide = 1001,            //  只需识别人像面时识别成功
    MGFaceIDZZIDCardErrorSuccessAlmostBothSide = 1002,          //  识别出身份证正反面内容上均存在没有识别出来、或者出来的内容存在逻辑问题、识别出来的内容存在质量问题
    MGFaceIDZZIDCardErrorSuccessAlmostBackSide = 1002,          //  识别出身份证正面没有问题，身份证反面内容上存在没有识别出来、或者出来的内容存在逻辑问题、识别出来的内容存在质量问题
    MGFaceIDZZIDCardErrorSuccessAlmostFrontSide = 1002,         //  识别出身份证反面没有问题，身份证正面内容上存在没有识别出来、或者出来的内容存在逻辑问题、识别出来的内容存在质量问题
    MGFaceIDZZIDCardErrorSuccessAlmostBackSideSignle = 1002,    //  只需识别国徽面时内容上存在没有识别出来、或者出来的内容存在逻辑问题、识别出来的内容存在质量问题
    MGFaceIDZZIDCardErrorSuccessAlmostFrontSideSignle = 1002,   //  只需识别人像面时内容上存在没有识别出来、或者出来的内容存在逻辑问题、识别出来的内容存在质量问题
    MGFaceIDZZIDCardErrorNoIDCardBothSide = 2001,               //  没有检测到身份证正反面照片
    MGFaceIDZZIDCardErrorNoIDCardBackSide = 2001,               //  没有检测到身份证反面照片
    MGFaceIDZZIDCardErrorNoIDCardFrontSide = 2001,              //  没有检测到身份证正面照片
    MGFaceIDZZIDCardErrorNoIDCardBackSideSingle = 2001,         //  只需识别国徽面时没有检测到国徽面照片
    MGFaceIDZZIDCardErrorNoIDCardFrontSideSingle = 2001,        //  只需识别人像面时没有检测到人像面照片
    MGFaceIDZZIDCardErrorBizTokenDenied = 4200,                 //  传入的 biz_token 不符合要求
    MGFaceIDZZIDCardErrorAuthenticationFail = 4200,             //  鉴权失败
    MGFaceIDZZIDCardErrorMobilePhoneNotSupport = 4200,          //  手机在不支持列表里
    MGFaceIDZZIDCardErrorSDKTooOld = 4200,                      //  SDK版本过旧，已经不被支持
    
    MGFaceIDZZIDCardErrorSignInvalid = 5000,                     //  传入 sign 不符合要求
    MGFaceIDZZIDCardErrorSignVesionInvalid = 5000,               //  传入 signVersion 不符合要求
    MGFaceIDZZIDCardErrorSignExpired = 5000,                     //  传入 sign 过期
    MGFaceIDZZIDCardErrorSignReplayAttack= 5000,                 //  重放攻击，单次有效的签名被多次使用
    MGFaceIDZZIDCardErrorApiKeyBeDiscontinued = 5000,            //  api_key被停用
    MGFaceIDZZIDCardErrorIPNotAllowed = 5000,                    //  不允许访问的IP
    MGFaceIDZZIDCardErrorNonEnterpriseCertification = 5000,      //  客户未进行企业认证
    MGFaceIDZZIDCardErrorBalanceNotEnough = 5000,                //  余额不足
    MGFaceIDZZIDCardErrorMoreRetryTimes = 5000,                  //  超过重试次数
    MGFaceIDZZIDCardErrorAccountDiscontinued = 5000,             //  用户帐号已停用
    MGFaceIDZZIDCardErrorOCRFailure = 5000,                      //  身份证OCR检测失败
    
    MGFaceIDZZIDCardErrorUserCancel  = 6000,                     //  用户取消
    MGFaceIDZZIDCardErrorNoCameraPermission = 6000,              //  没有打开相机的权限，请开启权限后重试
    MGFaceIDZZIDCardErrorIllegalParameter = 6000,                //  传入参数不合法
    MGFaceIDZZIDCardErrorNotModel = 6000,                        //  未找到指定的模型资源
    MGFaceIDZZIDCardErrorDeviceNotSupport = 6000,                //  手机没有打开摄像头或者硬件不支持
    MGFaceIDZZIDCardErrorBundleId = 6000,                        //  此 APP 的bundle_id 在系统的黑名单库里
    MGFaceIDZZIDCardErrorNoNetPermission = 6000,                 //  网络出错或者连不上互联网，请连接上互联网后重试
    MGFaceIDZZIDCardErrorInitFailed = 6000,                      //  SDK 初始化失败
    
    MGFaceIDZZIDCardErrorUnknown = 6100,                         //  未知错误，错误原因查看error_message信息
} MGFaceIDZZIDCardErrorType;

/**
 身份证五种分类类型，默认为MGFaceIDZZIDCardLegalityIDPhoto
 *  MGFaceIDZZIDCardLegalityIDPhoto：正式身份证
 *  MGFaceIDZZIDCardLegalityTemporaryIDPhoto：临时身份证
 *  MGFaceIDZZIDCardLegalityPhotocopy：正式身份证的复印件
 *  MGFaceIDZZIDCardLegalityScreen：手机或者其他屏幕翻拍
 *  MGFaceIDZZIDCardLegalityEdited：用工具何种或者编辑过得身份证
 */
typedef enum : NSUInteger {
    MGFaceIDZZIDCardLegalityIDPhoto,
    MGFaceIDZZIDCardLegalityTemporaryIDPhoto,
    MGFaceIDZZIDCardLegalityPhotocopy,
    MGFaceIDZZIDCardLegalityScreen,
    MGFaceIDZZIDCardLegalityEdited,
} MGFaceIDZZIDCardLegalityType;

/**
 身份证照片完整性，默认为MGFaceIDZZIDCardComplete
 *  MGFaceIDZZIDCardComplete  完整
 *  MGFaceIDZZIDCardCompleteAllIn  不完整，但是内容区域全部在图片内
 *  MGFaceIDZZIDCardCompletePartIn 不完整，且部分内容在区域外
 */
typedef enum : NSUInteger {
    MGFaceIDZZIDCardComplete = 0,
    MGFaceIDZZIDCardCompleteAllIn,
    MGFaceIDZZIDCardCompletePartIn,
} MGFaceIDZZIDCardCompleteType;

/**
 拍摄模式，默认为MGFaceIDZZIDCardScreenOrientationVertical
 *  MGFaceIDZZIDCardScreenOrientationVertical    竖屏模式
 *  MGFaceIDZZIDCardScreenOrientationLandscape   横屏模式
 */
typedef enum : NSUInteger {
    MGFaceIDZZIDCardScreenOrientationVertical,
    MGFaceIDZZIDCardScreenOrientationLandscape,
} MGFaceIDZZIDCardScreenOrientation;

/**
 拍摄页面，默认为MGFaceIDZZIDCardShootPageDouble
 *  MGFaceIDZZIDCardShootPageDouble              双面拍摄
 *  MGFaceIDZZIDCardShootPagePortrait            人像面
 *  MGFaceIDZZIDCardShootPageNationalEmblem      国徽面
 */
typedef enum : NSUInteger {
    MGFaceIDZZIDCardShootPageDouble,
    MGFaceIDZZIDCardShootPagePortrait,
    MGFaceIDZZIDCardShootPageNationalEmblem,
} MGFaceIDZZIDCardShootPage;

typedef void(^FaceIDZZIDCardDetectResultBlock)(MGFaceIDZZIDCardErrorItem* errorItem, MGFaceIDZZIDCardDetectItem* detectItem, NSString* bizTokenStr, NSString* bizNumberStr, NSDictionary* extraOutDataDict);

#endif /* MGFaceIDZZIDCardConfig_h */

