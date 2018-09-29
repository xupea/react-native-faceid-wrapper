//
//  MGFaceIDZZIDCardErrorItem.h
//  CocoaPods
//
//  Created by MegviiDev on 2018/5/28.
//  Copyright © 2018年 Megvii. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MGFaceIDZZIDCardConfig.h"

@interface MGFaceIDZZIDCardErrorItem : NSObject

//  身份证检测错误类型
@property (nonatomic, assign) MGFaceIDZZIDCardErrorType errorType;
//  身份证检测错误信息
@property (nonatomic, strong) NSString* errorMessage;

@end
