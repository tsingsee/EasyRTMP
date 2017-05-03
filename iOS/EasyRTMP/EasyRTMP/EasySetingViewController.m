//
//  EasySetingViewController.m
//  EasyPusher
//
//  Created by yingengyue on 2017/1/10.
//  Copyright © 2017年 phylony. All rights reserved.
//

#import "EasySetingViewController.h"

#define ScreenWidth [UIScreen mainScreen].bounds.size.width

@interface EasySetingViewController ()<UITextFieldDelegate>

@end

@implementation EasySetingViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.

    self.view.backgroundColor = [UIColor whiteColor];
    UITextField *ipTextField = [[UITextField alloc] initWithFrame:CGRectMake(10, 84, ScreenWidth - 20 , 30.0)];
    ipTextField.tag = 1000;
    ipTextField.delegate = self;
    ipTextField.placeholder = @"RTMP地址";
    ipTextField.text = [[NSUserDefaults standardUserDefaults] objectForKey:@"ConfigUrl"];
    [self.view addSubview:ipTextField];
    
    UIView *linView = [[UIView alloc] initWithFrame:CGRectMake(10, 114, CGRectGetWidth(ipTextField.frame), 2.0)];
    linView.backgroundColor = [UIColor colorWithRed:241/255.0 green:158/255.0 blue:194/255.0 alpha:1.0];
    [self.view addSubview:linView];

    UIButton *saveBtn = [[UIButton alloc] initWithFrame:CGRectMake(10, 144,CGRectGetWidth(ipTextField.frame), 40.0)];
    saveBtn.backgroundColor = [UIColor lightGrayColor];
    [saveBtn setTitle:@"保存" forState:UIControlStateNormal];
    [saveBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [saveBtn addTarget:self action:@selector(saveIpAndPort) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:saveBtn];
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField{
    [textField resignFirstResponder];
    return YES;
}

- (void)saveIpAndPort{
    [self.view endEditing:YES];
    UITextField *ipConfig = (UITextField *)[self.view viewWithTag:1000];
    [[NSUserDefaults standardUserDefaults] setObject:ipConfig.text forKey:@"ConfigUrl"];

    [[NSUserDefaults standardUserDefaults] synchronize];
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
