//
//  EasyResolutionViewController.m
//  EasyPusher
//
//  Created by yingengyue on 2017/3/3.
//  Copyright © 2017年 phylony. All rights reserved.
//

#import "EasyResolutionViewController.h"

@interface EasyResolutionViewController ()

@property (nonatomic, strong) NSArray *resolutionArray;
@end

@implementation EasyResolutionViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    _myTabel.rowHeight = 44.0;
}

- (NSArray *)resolutionArray{
    if (!_resolutionArray) {
        _resolutionArray = @[@"288*352",@"480*640",@"720*1280",@"1080*1920"];
    }
    return _resolutionArray;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return self.resolutionArray.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    static NSString *cellIden = @"cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIden];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellIden];
        UIView *lineView = [[UIView alloc] initWithFrame:CGRectMake(0, 43.0, 150.0, 1.0)];
        lineView.backgroundColor = [UIColor lightGrayColor];
        [cell.contentView addSubview:lineView];
    }
    cell.textLabel.textAlignment = NSTextAlignmentCenter;
    cell.textLabel.text = self.resolutionArray[indexPath.row];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [[NSUserDefaults standardUserDefaults] setObject:self.resolutionArray[indexPath.row] forKey:@"resolition"];
    [[NSUserDefaults standardUserDefaults] synchronize];
    if (_delegate) {
        [_delegate onSelecedesolution:indexPath.row];
    }
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (IBAction)closeView:(id)sender{
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
