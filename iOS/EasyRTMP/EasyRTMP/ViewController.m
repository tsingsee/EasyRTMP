//
//  ViewController.m
//  EasyCapture
//
//  Created by phylony on 9/11/16.
//  Copyright © 2016 phylony. All rights reserved.
//

#import "ViewController.h"
#import "PureLayout.h"
#import "EasySetingViewController.h"
#import <AVFoundation/AVFoundation.h>
#import "EasyResolutionViewController.h"
#import "EasyDarwinInfoViewController.h"
#import <CoreTelephony/CTCellularData.h>
#import "NoNetNotifieViewController.h"

@interface ViewController ()<SetDelegate,EasyResolutionDelegate,ConnectDelegate>
{
    UIButton *startButton;
    UIButton *settingButton;
    NSString *urlName;
    NSString *statusString;
    BOOL isRunning;
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(someMethod:)
                                                 name:UIApplicationDidBecomeActiveNotification object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(someMethod:)
                                                 name:UIApplicationDidEnterBackgroundNotification object:nil];
    encoder = [[CameraEncoder alloc] init];
    encoder.delegate = self;
    [encoder initCameraWithOutputSize:CGSizeMake(480, 640)];
    
    encoder.previewLayer.frame = self.view.bounds;
    [self.view.layer addSublayer:encoder.previewLayer];
    AVCaptureVideoPreviewLayer *prev = encoder.previewLayer;
    [[prev connection] setVideoOrientation:AVCaptureVideoOrientationPortrait];
    prev.frame = self.view.bounds;
    encoder.previewLayer.hidden = NO;
    [encoder startCapture];

    [encoder changeCameraStatus];
    UIView *bottomView = [[UIView alloc] init];
    bottomView.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:bottomView];
    bottomView.backgroundColor = [[UIColor darkGrayColor] colorWithAlphaComponent:0.5];
//    bottomView.alpha = 0.4;
    [bottomView autoPinEdgeToSuperviewEdge:ALEdgeLeading withInset:0.0];
    [bottomView autoPinEdgeToSuperviewEdge:ALEdgeBottom withInset:0.0];
    [bottomView autoPinEdgeToSuperviewEdge:ALEdgeTrailing withInset:0.0];
    [bottomView autoSetDimension:ALDimensionHeight toSize:80];
    
    startButton = [UIButton buttonWithType:UIButtonTypeCustom];
    startButton.translatesAutoresizingMaskIntoConstraints = NO;
    [bottomView addSubview:startButton];
//    [startButton setTitle:@"开始推流" forState:UIControlStateNormal];
    [startButton setImage:[UIImage imageNamed:@"icon1"] forState:UIControlStateNormal];
    [startButton setImage:[UIImage imageNamed:@"icon2"] forState:UIControlStateSelected];
    [startButton autoAlignAxisToSuperviewAxis:ALAxisVertical];
    [startButton autoPinEdgeToSuperviewEdge:ALEdgeBottom withInset:15.0];
    [startButton autoSetDimension:ALDimensionWidth toSize:50];
    [startButton autoSetDimension:ALDimensionHeight toSize:50];
//    startButton.backgroundColor = [[UIColor darkGrayColor] colorWithAlphaComponent:0.5];
    [startButton addTarget:self action:@selector(startAction:) forControlEvents:UIControlEventTouchUpInside];
    
    settingButton = [UIButton buttonWithType:UIButtonTypeCustom];
    settingButton.translatesAutoresizingMaskIntoConstraints = NO;
    [bottomView addSubview:settingButton];
//    [settingButton setTitle:@"设置" forState:UIControlStateNormal];
    [settingButton autoPinEdge:ALEdgeTrailing toEdge:ALEdgeLeading ofView:startButton withOffset:-30.0];
    [settingButton setImage:[UIImage imageNamed:@"set"] forState:UIControlStateNormal];
    [settingButton autoPinEdgeToSuperviewEdge:ALEdgeBottom withInset:15.0];
    [settingButton autoSetDimension:ALDimensionWidth toSize:50];
    [settingButton autoSetDimension:ALDimensionHeight toSize:50];
//    settingButton.backgroundColor = [[UIColor darkGrayColor] colorWithAlphaComponent:0.5];
    [settingButton addTarget:self action:@selector(settingAction:) forControlEvents:UIControlEventTouchUpInside];
    
    UIButton *changeButton = [UIButton buttonWithType:UIButtonTypeCustom];
    changeButton.translatesAutoresizingMaskIntoConstraints = NO;
    [bottomView addSubview:changeButton];
//    [changeButton setTitle:@"切换" forState:UIControlStateNormal];
    [changeButton setImage:[UIImage imageNamed:@"icon3"] forState:UIControlStateNormal];
    [changeButton autoPinEdge:ALEdgeLeading toEdge:ALEdgeTrailing ofView:startButton withOffset:30.0];
    [changeButton autoPinEdgeToSuperviewEdge:ALEdgeBottom withInset:15.0];
    [changeButton autoSetDimension:ALDimensionWidth toSize:50];
    [changeButton autoSetDimension:ALDimensionHeight toSize:50];
//    changeButton.backgroundColor = [[UIColor darkGrayColor] colorWithAlphaComponent:0.5];
    [changeButton addTarget:self action:@selector(toggleCamera) forControlEvents:UIControlEventTouchUpInside];
    
    
    UIButton *resolutionBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    resolutionBtn.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:resolutionBtn];
    resolutionBtn.tag = 100001;
    [resolutionBtn setTitle:@"分辨率:640*480" forState:UIControlStateNormal];
    [resolutionBtn autoPinEdgeToSuperviewEdge:ALEdgeLeading withInset:10];
    [resolutionBtn autoPinEdgeToSuperviewEdge:ALEdgeTop withInset:20.0];
    [resolutionBtn autoSetDimension:ALDimensionWidth toSize:180];
    [resolutionBtn autoSetDimension:ALDimensionHeight toSize:30];
//    resolutionBtn.backgroundColor = [[UIColor blackColor] colorWithAlphaComponent:0.7];
    [resolutionBtn addTarget:self action:@selector(showPop) forControlEvents:UIControlEventTouchUpInside];
    
    
    UIButton *infoBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    infoBtn.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:infoBtn];
    [infoBtn setImage:[UIImage imageNamed:@"ic_action_about"] forState:UIControlStateNormal];
    
    [infoBtn autoPinEdgeToSuperviewEdge:ALEdgeTrailing withInset:20];
    [infoBtn autoPinEdgeToSuperviewEdge:ALEdgeTop withInset:20.0];
    [infoBtn autoSetDimension:ALDimensionWidth toSize:30];
    [infoBtn autoSetDimension:ALDimensionHeight toSize:30];
    [infoBtn addTarget:self action:@selector(showInfo) forControlEvents:UIControlEventTouchUpInside];
    
    UILabel *urlLabel = [[UILabel alloc] init];
    urlLabel.translatesAutoresizingMaskIntoConstraints = NO;
    urlLabel.tag = 3000;
    urlLabel.textColor = [UIColor redColor];
    urlLabel.numberOfLines = 0;
    urlLabel.text = statusString;
    [self.view addSubview:urlLabel];
    
    [urlLabel autoPinEdge:ALEdgeBottom toEdge:ALEdgeTop ofView:bottomView withOffset:-10.0];
    [urlLabel autoPinEdgeToSuperviewEdge:ALEdgeLeading withInset:20.0];
    [urlLabel autoPinEdgeToSuperviewEdge:ALEdgeTrailing withInset:20.0];
//    [self getPushName];
}

- (void)someMethod:(NSNotification *)sender{
//    NSLog(@"%@",sender.name);
    if ([sender.name isEqualToString:UIApplicationDidBecomeActiveNotification]) {
        if (isRunning && encoder) {
             [encoder startCamera:urlName];
        }
    }else{
        if (isRunning && encoder) {
            [encoder stopCamera];
        }
    }
    
}

- (void)setFinish{
    [encoder changeCameraStatus];
}

//- (void)getPushName{
//    NSMutableString *randomNum = [[NSMutableString alloc] init];
//    for(int i = 0; i < 6;i++){
//        int num = arc4random() % 10;
//        [randomNum appendString:[NSString stringWithFormat:@"%d",num]];
//    }
//    [randomNum appendString:@".sdp"];
//    [[NSUserDefaults standardUserDefaults] setObject:randomNum forKey:@"PushName"];
//    [[NSUserDefaults standardUserDefaults] synchronize];
//}

- (void)showAuthorityView{
    __weak typeof(self)weakSelf = self;
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        
        dispatch_async(dispatch_get_main_queue(), ^{
            NoNetNotifieViewController *vc = [[NoNetNotifieViewController alloc] init];
            [weakSelf presentViewController:vc animated:YES completion:nil];
        });
    });
   
}

- (void)showInfo{
    EasyDarwinInfoViewController *infoVc = [[EasyDarwinInfoViewController alloc] init];
    [self presentViewController:infoVc animated:YES completion:nil];
}

- (void)showPop{
    if (encoder.running) {
        return;
    }
    EasyResolutionViewController *popVc = [[EasyResolutionViewController alloc] init];
    popVc.delegate = self;
    popVc.modalPresentationStyle = UIModalPresentationOverFullScreen;
    [self presentViewController:popVc animated:YES completion:nil];
}

- (void)onSelecedesolution:(NSInteger)resolutionNo{
    [encoder swapResolution];
    UIButton *resolutionBtn = (UIButton *)[self.view viewWithTag:100001];
    [resolutionBtn setTitle:[NSString stringWithFormat:@"分辨率:%@",[[NSUserDefaults standardUserDefaults] objectForKey:@"resolition"]] forState:UIControlStateNormal];
}

- (void)toggleCamera{
    [encoder swapFrontAndBackCameras];
}

- (IBAction)startAction:(UIButton *)sender
{
    __weak typeof(self)weakSelf = self;
    CTCellularData *cellularData = [[CTCellularData alloc]init];
    cellularData.cellularDataRestrictionDidUpdateNotifier =  ^(CTCellularDataRestrictedState state){
        //获取联网状态
        switch (state) {
            case kCTCellularDataRestricted:
                //                NSLog(@"Restricrted");
                //                [weakSelf showAuthorityView];
                break;
            case kCTCellularDataNotRestricted:
                //                NSLog(@"Not Restricted");
                break;
            case kCTCellularDataRestrictedStateUnknown:
            {
                [weakSelf showAuthorityView];
                return;
            }
                break;
            default:
                break;
        };
    };
    sender.selected = !sender.selected;
    isRunning = sender.selected;
    if (sender.selected) {
        settingButton.enabled = NO;
        urlName = [[NSUserDefaults standardUserDefaults] objectForKey:@"PushName"];
        
        [encoder startCamera:urlName];
    }else{
                settingButton.enabled = YES;
//                [startButton setTitle:@"开始推流" forState:UIControlStateNormal];
                [encoder stopCamera];
    }

//    if (!encoder.running)
//    {
//        sender.selected = YES;
//        settingButton.enabled = NO;
////        [startButton setTitle:@"停止推流" forState:UIControlStateNormal];
////        NSMutableString *randomNum = [[NSMutableString alloc] init];
////        for(int i = 0; i < 6;i++){
////            int num = arc4random() % 10;
////            [randomNum appendString:[NSString stringWithFormat:@"%d",num]];
////        }
////        [randomNum appendString:@".sdp"];
//        urlName = [[NSUserDefaults standardUserDefaults] objectForKey:@"PushName"];
//      
//        [encoder startCamera:urlName];
//    }
//    else
//    {
////        settingButton.enabled = YES;
////        [startButton setTitle:@"开始推流" forState:UIControlStateNormal];
////        sender.selected = NO;
////        [encoder stopCamera];
//    }
   
}

- (void)getConnectStatus:(NSString *)status isFist:(int)tag{
    __block UILabel *label = (UILabel *)[self.view viewWithTag:3000];
    if (tag == 1) {
        if (label) {
            dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
                
                dispatch_async(dispatch_get_main_queue(), ^{
                    label.text = [NSString stringWithFormat:@"%@",status];
                });
            });
        }else{
            statusString = status;
        }
    }else{
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        
        dispatch_async(dispatch_get_main_queue(), ^{
            NSString *url = [[NSUserDefaults standardUserDefaults] objectForKey:@"ConfigUrl"];
            label.text = [NSString stringWithFormat:@"%@\n%@",status,url];
        });
    });
    }
}


- (IBAction)settingAction:(id)sender
{
    if (startButton.selected) {
        [encoder stopCamera];
    }
    startButton.selected = NO;
//    [startButton setTitle:@"开始推流" forState:UIControlStateNormal];
    
    EasySetingViewController *setVc = [[EasySetingViewController alloc] init];
    setVc.delegate = self;
    [self presentViewController:setVc animated:YES completion:nil];
}

- (void)dealloc{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
