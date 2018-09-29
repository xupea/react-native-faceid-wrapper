//
//  MGCameraDeviceSupport.h
//  MGFaceIDGeneralModule
//
//  Created by MegviiDev on 2017/7/18.
//  Copyright © 2017年 megvii. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MGCameraDeviceSupport : NSObject

+ (BOOL)isCameraAvailable;

+ (BOOL)isCameraPermissions;

@end
