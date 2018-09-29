//
//  MGCameraConfig.h
//  MGFaceIDGeneralModule
//
//  Created by MegviiDev on 2018/5/18.
//  Copyright © 2018年 Megvii. All rights reserved.
//

#ifndef MGCameraConfig_h
#define MGCameraConfig_h

#import <UIKit/UIKit.h>

/* 屏幕宽度 （区别于viewcontroller.view.fream）*/
#define MG_WIN_WIDTH  [UIScreen mainScreen].bounds.size.width

/* 屏幕高度 （区别于viewcontroller.view.fream）*/
#define MG_WIN_HEIGHT [UIScreen mainScreen].bounds.size.height

/* 手机系统版本 */
#define MG_IOS_SysVersion [[UIDevice currentDevice] systemVersion].floatValue

/* rgb颜色转换（16进制->10进制）*/
#define MGColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

/* rgba颜色 */
#define MGColorWithRGB(R, G, B, A) [UIColor colorWithRed:R/255.0f green:G/255.0f blue:B/255.0f alpha:A]

/* 判断是否为 iPhone X */
#define IS_IPHONE_X     (( fabs((double)[[UIScreen mainScreen] bounds].size.height - (double)812) < DBL_EPSILON ) || (fabs((double)[[UIScreen mainScreen] bounds].size.width - (double)812) < DBL_EPSILON ))

#ifdef DEBUG
#define MGLog(...) NSLog(__VA_ARGS__)
#else
#define MGLog(...)
#endif

#endif /* MGCameraConfig_h */
