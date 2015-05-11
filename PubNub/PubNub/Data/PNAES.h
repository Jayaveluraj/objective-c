#import <Foundation/Foundation.h>
#import "PNStructures.h"


/**
 @brief      Class which allow to perform AES based encryption/descryption on provided data.
 @discussion Encryption works with native Foundation objects which internally will be translated
             to JSON object. Decryption process will return Foundation object in response on
             Base64 encoded string.
 
 @author Sergey Mamontov
 @since 4.0
 @copyright © 2009-2015 PubNub, Inc.
 */
@interface PNAES : NSObject


///------------------------------------------------
/// @name Data encryption
///------------------------------------------------

/**
 @brief      Encrypt \c data content and encode into Base64 string.
 @discussion Input \c data for example can be output of \a NSJSONSerialization or data created from
             \a NSString with UTF-8 encoding.
 
 @param data  Reference on \a NSData object which should be encrypted.
 @param key   Reference on key which should be used to encrypt data basing on it.
 @param error Reference on pointer into which encryption error will be stored in case of encryption
              failure. Error can be related to JSON string serialization as well as encryption 
              itself.
 
 @return Encrypted Base64-encoded string received from Foundation object. \c nil will be returned
         in case of failure.
 
 @since 4.0
 */
+ (NSString *)encrypt:(NSData *)data withKey:(NSString *)key andError:(NSError **)error;


///------------------------------------------------
/// @name Data decryption
///------------------------------------------------

/**
 @brief      Transform encrypted Base64 encoded string to \a NSData instance.
 @discussion Received data for example can be used with \a NSJSONSerialization to convert it's 
             content to Foundation objects.
 
 @param object Reference on previously encrypted Base64-encoded string which should be decrypted.
 @param key    Reference on key which should be used to decrypt data.
 @param error  Reference on pointer into which decryption error will be stored in case of decryption 
               failure. Error can be related to JSON string deserialization as well as decryption
               itself.
 
 @return Initial \a NSData which has been encrypted earlier. \c nil will be returned in case of 
         decryption error.
 
 @since 4.0
 */
+ (NSData *)decrypt:(NSString *)object withKey:(NSString *)key andError:(NSError **)error;

#pragma mark -


@end
