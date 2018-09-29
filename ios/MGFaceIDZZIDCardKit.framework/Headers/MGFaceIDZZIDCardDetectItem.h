//
//  MGFaceIDZZIDCardDetectItem.h
//  CocoaPods
//
//  Created by MegviiDev on 2018/5/28.
//  Copyright © 2018年 Megvii. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MGFaceIDZZIDCardConfig.h"

//  身份证五种分类结果，五种可信度value总和为1
@interface MGFaceIDZZIDCardDetectLegalityItem : NSObject

@property (nonatomic, assign) MGFaceIDZZIDCardLegalityType idcardLegality;
///  正式身份证照片可信度
@property (nonatomic, assign) CGFloat IDPhoto;
///  临时身份证照片可信度
@property (nonatomic, assign) CGFloat TemporaryIDPhoto;
///  正式身份证复印件可信度
@property (nonatomic, assign) CGFloat Photocopy;
///  屏幕翻拍身份证照片可信度
@property (nonatomic, assign) CGFloat Screen;
///  编辑后的身份证照片可信度
@property (nonatomic, assign) CGFloat Edited;
///  正式身份证照片阈值，如果`IDPhoto`的值不低于该阈值，可以认定为真实身份证
@property (nonatomic, assign) CGFloat IDPhotoTreshold;

@end

@interface MGFaceIDZZIDCardDetectDetailItem : NSObject

///  指定区域识别内容
@property (nonatomic, strong) NSString* resultStr;
///  指定区域识别可信度，如果该值低于0.73，则图片存在质量问题，可信度较低
@property (nonatomic, assign) float qualityF;
///  指定区域内容的四点坐标, 顺序-lt:左上，rt:右上，rb:右下，lb:左下。
@property (nonatomic, strong) NSDictionary* rect;
///  指定区域是否存在逻辑问题(如果存在逻辑问题，则识别出的结果是不可信)，默认值为YES，存在逻辑问题。
@property (nonatomic, assign) BOOL logic;

@end

@interface MGFaceIDZZIDCardDetectItem : NSObject

///  身份证图片OCR结果是否可信
@property (nonatomic, assign) BOOL isDetect;
///  身份证图片OCR失败错误类型
@property (nonatomic, assign) NSUInteger errorCode;
///  身份证图片OCR失败错误信息
@property (nonatomic, strong) NSString* errorMessage;

///  身份证信息-姓名
@property (nonatomic, strong) MGFaceIDZZIDCardDetectDetailItem* userIDCardName;
///  身份证信息-性别
@property (nonatomic, strong) MGFaceIDZZIDCardDetectDetailItem* userIDCardGender;
///  身份证信息-民族
@property (nonatomic, strong) MGFaceIDZZIDCardDetectDetailItem* userIDCardNationality;
///  身份证信息-出生年份
@property (nonatomic, strong) MGFaceIDZZIDCardDetectDetailItem* userBirthYear;
///  身份证信息-出生月数
@property (nonatomic, strong) MGFaceIDZZIDCardDetectDetailItem* userBirthMonth;
///  身份证信息-出生日
@property (nonatomic, strong) MGFaceIDZZIDCardDetectDetailItem* userBirthDay;
///  身份证信息-身份证号
@property (nonatomic, strong) MGFaceIDZZIDCardDetectDetailItem* userIDCardNumber;
///  身份证信息-住址
@property (nonatomic, strong) MGFaceIDZZIDCardDetectDetailItem* userAddress;
///  身份证信息-签发机关
@property (nonatomic, strong) MGFaceIDZZIDCardDetectDetailItem* userIssuedBy;
///  身份证信息-有效日期的起始时间
@property (nonatomic, strong) MGFaceIDZZIDCardDetectDetailItem* userValidDateStart;
///  身份证信息-有效日期的结束时间
@property (nonatomic, strong) MGFaceIDZZIDCardDetectDetailItem* userValidDateEnd;
///  身份证信息-头像图片
@property (nonatomic, strong) UIImage* idcardFaceImage;
///  身份证信息-头像区域
@property (nonatomic, strong) NSDictionary* idcardFaceRect;

///  身份证信息-人像面图片
@property (nonatomic, strong) UIImage* idcardPortraitImage;
///  身份证信息-人像面证件区域
@property (nonatomic, strong) NSDictionary* idcardPortraitRect;
///  身份证信息-人像面完整性
@property (nonatomic, assign) MGFaceIDZZIDCardCompleteType idcardPortraitCompleteType;
///  身份证信息-人像面五种分类结果
@property (nonatomic, strong) MGFaceIDZZIDCardDetectLegalityItem* idcardPortraitLegalityItem;
///  身份证信息-国徽面图片
@property (nonatomic, strong) UIImage* idcardEmblemImage;
///  身份证信息-国徽面证件区域
@property (nonatomic, strong) NSDictionary* idcardEmblemRect;
///  身份证信息-国徽面完整性
@property (nonatomic, assign) MGFaceIDZZIDCardCompleteType idcardEmblemCompleteType;
///  身份证信息-国徽面五种分类结果
@property (nonatomic, strong) MGFaceIDZZIDCardDetectLegalityItem* idcardEmblemLegalityItem;

@end
