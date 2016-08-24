//
//  SecKeyWrapper.h
//  PayNow
//
//  Created by Subramanian Lakshmanan on 3/7/14.
//  Copyright (c) 2014 Subramanian Lakshmanan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Security/Security.h>
#import <CommonCrypto/CommonDigest.h>
#import <CommonCrypto/CommonCryptor.h>

#define KeyTypePrivate 0
#define KeyTypePublic 1

#define kChosenDigestLength     CC_SHA1_DIGEST_LENGTH
#define kTypeOfSigPadding       kSecPaddingPKCS1SHA1

@interface SecKeyWrapper : NSObject
{
    SecKeyRef publicKeyRef;
    SecKeyRef privateKeyRef;
}

@property NSData *privateTag;
@property NSData *publicTag;
@property NSMutableDictionary *privateKeyAttr;
@property NSMutableDictionary *publicKeyAttr;
@property NSMutableDictionary *keyPairAttr;

- (void) deleteKeyPair;
- (int) generateKeyPair;
- (SecKeyRef) getKeyRef: (int) keyType;
- (int) initWithKeyPair:(BOOL)forceNew;
- (NSData *) getPublicKeyBits;
- (NSData *) getSignatureBytes:(NSData *)plainText;
- (NSData *) getHashBytes:(NSData *)plainText;

+ (NSString *)getAsciiEncodingForBinaryData:(const unsigned char *)bytes withLength:(unsigned int)length;

+ (NSString *)getHexEncodingForBinaryData:(const unsigned char *)bytes withLength:(unsigned int)length;

+ (NSString *)getPublicKeyInPemFormat: (NSData *)pub_key;

@end
