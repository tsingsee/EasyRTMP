//
//  EasySetingViewController.h
//  EasyPusher
//
//  Created by yingengyue on 2017/1/10.
//  Copyright © 2017年 phylony. All rights reserved.
//

#import <UIKit/UIKit.h>
@protocol SetDelegate<NSObject>

- (void)setFinish;
@end
@interface EasySetingViewController : UIViewController

@property(assign)id<SetDelegate>delegate;
@end
