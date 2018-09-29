//
//  LogClient.h
//  AliyunLogObjc
//
//  Created by 陆家靖 on 2016/10/27.
//  Copyright © 2016年 陆家靖. All rights reserved.
//

#import <UIKit/UIKit.h>
@class MGALogGroup;

#ifndef LogClient_h
#define LogClient_h

@interface MGLogClient : NSObject {
    NSString *_mEndPoint;
    NSString *_mAccessKeyID;
    NSString *_mAccessKeySecret;
    NSString *_mProject;
    NSString *_mAccessToken;
}

- (instancetype _Nullable )initWithApp:(NSString *_Nullable)endPoint
                accessKeyID:(NSString *_Nullable)ak
            accessKeySecret:(NSString *_Nullable)as
                projectName:(NSString *_Nullable)name;

- (void)SetToken:(NSString *_Nullable) token;
- (NSString *_Nullable)GetToken;
- (NSString *_Nullable)GetEndPoint;
- (NSString *_Nullable)GetKeyID;
- (NSString *_Nullable)GetKeySecret;
- (void)PostLog:(MGALogGroup *_Nullable)logGroup
   logStoreName:(NSString *_Nullable)name
           call:(void (^_Nullable)(NSURLResponse* _Nullable response, NSError* _Nullable error) )errorCallback;
@end

#endif /* LogClient_h */
