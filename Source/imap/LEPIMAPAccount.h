#import <Foundation/Foundation.h>
#import "LEPConstants.h"

@class LEPIMAPRequest;
@class LEPIMAPSession;
@class LEPIMAPFetchFoldersRequest;
@class LEPIMAPFolder;

@interface LEPIMAPAccount : NSObject {
    NSString * _host;
    uint16_t _port;
    NSString * _login;
    NSString * _password;
    LEPAuthType _authType;
	NSString * _realm;
    BOOL _idleEnabled;
	LEPIMAPSession * _session;
    NSDictionary * _gmailMailboxNames;
}

@property (nonatomic, copy) NSString * host;
@property (nonatomic) uint16_t port;
@property (nonatomic, copy) NSString * login;
@property (nonatomic, copy) NSString * password;
@property (nonatomic) LEPAuthType authType;
@property (nonatomic, copy) NSString * realm; // for NTLM

@property (nonatomic, getter=isIdleEnabled) BOOL idleEnabled;

// after the operation is created, it should be started
- (LEPIMAPFetchFoldersRequest *) fetchSubscribedFoldersRequest;

// after the operation is created, it should be started
- (LEPIMAPFetchFoldersRequest *) fetchAllFoldersRequest;

- (LEPIMAPRequest *) createFolderRequest:(NSString *)path;

- (LEPIMAPFolder *) inboxFolder;

@end
