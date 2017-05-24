//
//  AppDelegate.m
//  EasyCapture
//
//  Created by phylony on 9/11/16.
//  Copyright © 2016 phylony. All rights reserved.
//

#import "AppDelegate.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [application setIdleTimerDisabled:YES];
    NSString *url = [[NSUserDefaults standardUserDefaults] objectForKey:@"ConfigUrl"];
    if (!url || [url containsString:@"rtmp://www.easydss.com/live"] || [url containsString:@"121.40.50.44/live"] ) {
        NSMutableString *randomNum = [[NSMutableString alloc] initWithString:@"rtmp://www.easydss.com:10085/live/stream_"];
        for(int i = 0; i < 6;i++){
            int num = arc4random() % 10;
            [randomNum appendString:[NSString stringWithFormat:@"%d",num]];
        }
        [[NSUserDefaults standardUserDefaults] setObject:randomNum forKey:@"ConfigUrl"];
    }
//    if (!url) {
//        NSMutableString *randomNum = [[NSMutableString alloc] initWithString:@"rtmp://www.easydss.com/live/stream_"];
//        for(int i = 0; i < 6;i++){
//            int num = arc4random() % 10;
//            [randomNum appendString:[NSString stringWithFormat:@"%d",num]];
//        }
//        [[NSUserDefaults standardUserDefaults] setObject:randomNum forKey:@"ConfigUrl"];
//    }
    [[NSUserDefaults standardUserDefaults] setObject:@"480*640" forKey:@"resolition"];
    [[NSUserDefaults standardUserDefaults] synchronize];
//    [[NSUserDefaults standardUserDefaults] setObject:@"192.168.66.108" forKey:@"ConfigIP"];
//    [[NSUserDefaults standardUserDefaults] setObject:@"554" forKey:@"ConfigPORT"];
//    [[NSUserDefaults standardUserDefaults] synchronize];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
