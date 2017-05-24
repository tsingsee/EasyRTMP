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
    
    UIButton *back = [[UIButton alloc] initWithFrame:CGRectMake(0, 25, 90, 44)];
    [back setImage:[UIImage imageNamed:@"BackVideo"] forState:UIControlStateNormal];
    [back setTitle:@"返回" forState:UIControlStateNormal];
    [back setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [back setTitleEdgeInsets:UIEdgeInsetsMake(0, -10, 0, 10)];
    [back addTarget:self action:@selector(back) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:back];
    UITextField *ipTextField = [[UITextField alloc] initWithFrame:CGRectMake(10, 84, ScreenWidth - 20 , 30.0)];
    ipTextField.tag = 1000;
    ipTextField.font = [UIFont systemFontOfSize:14.0];
    ipTextField.delegate = self;
    ipTextField.placeholder = @"RTMP地址";
    ipTextField.text = [[NSUserDefaults standardUserDefaults] objectForKey:@"ConfigUrl"];
    [self.view addSubview:ipTextField];
    
    UIView *linView = [[UIView alloc] initWithFrame:CGRectMake(10, 114, CGRectGetWidth(ipTextField.frame), 2.0)];
    linView.backgroundColor = [UIColor colorWithRed:241/255.0 green:158/255.0 blue:194/255.0 alpha:1.0];
    [self.view addSubview:linView];
    
    NSUserDefaults *user = [NSUserDefaults standardUserDefaults];
    int select = [[user objectForKey:@"isVideo"] intValue];
    UISegmentedControl *seg = [[UISegmentedControl alloc] initWithItems:@[@"否",@"是"]];
    seg.tag = 200;
    seg.frame = CGRectMake(75.0, 164, 200.0, 30.0);
    seg.tintColor = [UIColor colorWithRed:241/255.0 green:158/255.0 blue:194/255.0 alpha:1.0];;
    seg.selectedSegmentIndex = select;
    [self.view addSubview:seg];
    
    UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(15, 75 + 2 * 45, 60, 30)];
    label.backgroundColor = [UIColor clearColor];
    label.font = [UIFont systemFontOfSize:14];
    label.text = @"只推音频";
//    label.textColor = MAIN_COLOR;
    
    [self.view addSubview:label];
    
    UIButton *saveBtn = [[UIButton alloc] initWithFrame:CGRectMake(10, 224,CGRectGetWidth(ipTextField.frame), 40.0)];
    saveBtn.backgroundColor = [UIColor lightGrayColor];
    [saveBtn setTitle:@"保存" forState:UIControlStateNormal];
    [saveBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [saveBtn addTarget:self action:@selector(saveIpAndPort) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:saveBtn];
    
    
}

- (void)back{
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField{
    [textField resignFirstResponder];
    return YES;
}

- (void)saveIpAndPort{
    [self.view endEditing:YES];
    UITextField *ipConfig = (UITextField *)[self.view viewWithTag:1000];
    NSUserDefaults *user = [NSUserDefaults standardUserDefaults];
    [user setObject:ipConfig.text forKey:@"ConfigUrl"];
    UISegmentedControl*seg = (UISegmentedControl *)[self.view viewWithTag:200];
    if (seg.selectedSegmentIndex == 0) {
        [user setObject:@"0" forKey:@"isVideo"];
    }else{
        [user setObject:@"1" forKey:@"isVideo"];
    }
    [user synchronize];
    if (_delegate) {
        [_delegate setFinish];
    }
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
