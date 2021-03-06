//
//  FSCHarmonyClient.h
//  HarmonyX
//
//  Created by Philippe Boudreau on 2014-11-06.
//  Copyright (c) 2014 Fasterre. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "FSCHarmonyConfiguration.h"
#import "FSCActivity.h"
#import "FSCFunction.h"

static NSString * const FSCHarmonyClientCurrentActivityChangedNotification = @"FSCHarmonyClientCurrentActivityChangedNotification";
static NSString * const FSCHarmonyClientCurrentActivityChangedNotificationActivityKey = @"FSCHarmonyClientCurrentActivityChangedNotificationActivityKey";

typedef NS_ENUM(NSUInteger, FSCHarmonyClientFunctionType) {
    FSCHarmonyClientFunctionTypePress,
    FSCHarmonyClientFunctionTypeRelease
};

@interface FSCHarmonyClient : NSObject

+ (id) clientWithMyHarmonyUsername: (NSString *) username
                 myHarmonyPassword: (NSString *) password
               harmonyHubIPAddress: (NSString *) IPAddress
                    harmonyHubPort: (NSUInteger) port;

@property (nonatomic, strong) FSCHarmonyConfiguration * configuration;
@property (nonatomic, assign) NSTimeInterval IQCmdTimeout;

- (void) connect;
- (BOOL) isConnected;
- (void) disconnect;

- (FSCHarmonyConfiguration *) configurationWithRefresh: (BOOL) refresh;
- (FSCActivity *) currentActivityFromConfiguration: (FSCHarmonyConfiguration *) configuration;

- (void) startActivity: (FSCActivity *) activity;

- (void) executeFunction: (FSCFunction *) function
                withType: (FSCHarmonyClientFunctionType) type;

- (void) turnOff;

#pragma mark - DEBUG

- (void) renewTokens;

@end
