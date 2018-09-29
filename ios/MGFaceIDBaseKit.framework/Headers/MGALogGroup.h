//
//  LogGroup.h
//  AliyunLogObjc
//
//  Created by 陆家靖 on 2016/10/27.
//  Copyright © 2016年 陆家靖. All rights reserved.
//

#import <UIKit/UIKit.h>
@class MGAlog;

@interface MGALogGroup : NSObject
{
    NSString *_mTopic;
    NSString *_mSource;
    NSMutableArray<NSDictionary<NSString*,NSObject*>*> *_mContent;
}

- (instancetype)initWithTopic:(NSString *)topic
                    andSource:(NSString *)source;

- (void)PutTopic:(NSString *)topic;
- (void)PutSource:(NSString *)source;
- (void)PutLog:(MGAlog *)log;
- (NSString *)GetJsonPackage;

@end

