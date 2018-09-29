
#import "ReactNativeFaceIDWrapper.h"
#import <React/RCTLog.h>
#import <Masonry/Masonry.h>
#import <MGFaceIDZZIDCardKit/MGFaceIDZZIDCardKit.h>
#import <CommonCrypto/CommonHMAC.h>
#import <CommonCrypto/CommonCryptor.h>
#import <math.h>

#define kApiKey @"rnEgefPhNcKNF1lkpOYeDBFCnn5t8wkH"
#define kApiSecret @"Wt34-cc0pADqGz-GqyvOxx3-RgOsIpPb"

@implementation ReactNativeFaceIDWrapper

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}
RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(startDetectID:(NSString *)apiKey secret:(NSString *)secret)
{
    [self startIDCardDetect:apiKey withSecret:secret];
}

- (NSString *)getSignStr {
    int valid_durtion = 100;
    long int current_time = [[NSDate date] timeIntervalSince1970];
    long int expire_time = current_time + valid_durtion;
    long random = abs(arc4random() % 100000000000);
    NSString* str = [NSString stringWithFormat:@"a=%@&b=%ld&c=%ld&d=%ld", kApiKey, expire_time, current_time, random];
    const char *cKey  = [kApiSecret cStringUsingEncoding:NSUTF8StringEncoding];
    const char *cData = [str cStringUsingEncoding:NSUTF8StringEncoding];
    char cHMAC[CC_SHA1_DIGEST_LENGTH];
    CCHmac(kCCHmacAlgSHA1, cKey, strlen(cKey), cData, strlen(cData), cHMAC);
    
    NSData *HMAC = [[NSData alloc] initWithBytes:cHMAC length:sizeof(cHMAC)];
    
    NSData* sign_raw_data = [str dataUsingEncoding:NSUTF8StringEncoding];
    NSMutableData* data = [[NSMutableData alloc] initWithData:HMAC];
    [data appendData:sign_raw_data];
    NSString* sign = [data base64EncodedStringWithOptions:0];
    return sign;
}

- (void)errorAlertWithCurrentVC:(UIViewController *)currentVC
                  withErrorItem:(MGFaceIDZZIDCardErrorItem *)errorItem {
    UIAlertController* alertC = [UIAlertController alertControllerWithTitle:@"OCR检测失败"
                                                                    message:[NSString stringWithFormat:@"ErrorCode:%d, ErrorMessage:%@", (int)errorItem.errorType, errorItem.errorMessage]
                                                             preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction* cancelAction = [UIAlertAction actionWithTitle:@"确定"
                                                           style:UIAlertActionStyleCancel
                                                         handler:nil];
    [alertC addAction:cancelAction];
    [currentVC presentViewController:alertC animated:YES completion:nil];
}

#pragma mark - Detect
- (void)startIDCardDetect:(NSString *)apiKey withSecret:(NSString *)secret {
    MGFaceIDZZIDCardErrorItem* errorItem;
    NSString* bizTokenStr;
    
    MGFaceIDZZIDCardManager* idcardManager = [[MGFaceIDZZIDCardManager alloc] initMGFaceIDZZIDCardManagerWithSign:[self getSignStr]
                                                                                                      signVersion:@"hmac_sha1"
                                                                                                         bizToken:&bizTokenStr
                                                                                                        extraData:nil
                                                                                                            error:&errorItem];
//    __weak ViewController* weakSelf = self;
//    UIViewController *rootVC = (UIViewController *)[[[UIApplication sharedApplication] keyWindow] rootViewController];
    
//    [idcardManager startMGFaceIDZZIDcardDetect:rootVC
//                                      bizToken:bizTokenStr
//                                     bizNumber:nil
//                             screenOrientation:MGFaceIDZZIDCardScreenOrientationVertical
//                                     shootPage:MGFaceIDZZIDCardShootPageDouble
//                                      callback:^(MGFaceIDZZIDCardErrorItem *errorItem, MGFaceIDZZIDCardDetectItem *detectItem, NSString *bizTokenStr, NSString *bizNumberStr, NSDictionary *extraOutDataDict) {
//                                          if ((errorItem.errorType == MGFaceIDZZIDCardErrorOCRSuccess || errorItem.errorType == MGFaceIDZZIDCardErrorSuccessAlmostBothSide) && detectItem) {
//
//                                              MGFaceIDZZIDCardDetectItem *theDetectItem = detectItem;
//
//                                              NSData *faceImage = UIImageJPEGRepresentation(theDetectItem.idcardFaceImage, 0.3f);
//                                              NSData * emblemImage = UIImageJPEGRepresentation(theDetectItem.idcardEmblemImage, 0.3f);
//                                              NSString *faceImageBase64Str = [faceImage base64EncodedStringWithOptions:NSDataBase64EncodingEndLineWithLineFeed];
//                                              NSString *emblemImageBase64Str = [emblemImage base64EncodedStringWithOptions:NSDataBase64EncodingEndLineWithLineFeed];
//
//                                              NSDictionary * list = @{@"real_name":theDetectItem.userIDCardName.resultStr,@"country":theDetectItem.userIDCardNationality.resultStr,@"card_type":@0,@"card_id":theDetectItem.userIDCardNumber.resultStr,@"image_from":faceImageBase64Str,@"image_to":emblemImageBase64Str,@"image_hold":@""};
//
//
//                                          } else {
//                                              dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//                                                  [self errorAlertWithCurrentVC:rootVC withErrorItem:errorItem];
//                                              });
//                                          }
//                                      }];
}

@end
  
