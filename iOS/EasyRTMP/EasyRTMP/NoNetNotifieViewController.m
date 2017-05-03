//
//  NoNetNotifieViewController.m
//  EasyPusher
//
//  Created by yingengyue on 2017/3/11.
//  Copyright © 2017年 phylony. All rights reserved.
//

#import "NoNetNotifieViewController.h"
#import "NoNetTableViewCell.h"
#import "PureLayout.h"
@interface NoNetNotifieViewController ()<UITableViewDelegate,UITableViewDataSource>

@end

@implementation NoNetNotifieViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    UIView *topView = [[UIView alloc] init];
    [self.view addSubview:topView];
    topView.translatesAutoresizingMaskIntoConstraints = NO;
    [topView autoPinEdgeToSuperviewEdge:ALEdgeTop withInset:0.0];
    [topView autoPinEdgeToSuperviewEdge:ALEdgeLeft withInset:0.0];
    [topView autoPinEdgeToSuperviewEdge:ALEdgeRight withInset:0.0];
    [topView autoSetDimension:ALDimensionHeight toSize:64];
    topView.backgroundColor = [UIColor colorWithWhite:0.98 alpha:0.9];
    UILabel *solveLabel = [[UILabel alloc] init];
    solveLabel.translatesAutoresizingMaskIntoConstraints = NO;
    solveLabel.text = @"解决方案";
    solveLabel.textColor = [UIColor darkGrayColor];
    [topView addSubview:solveLabel];
    [solveLabel autoPinEdgeToSuperviewEdge:ALEdgeTop withInset:20.0];
    [solveLabel autoSetDimension:ALDimensionHeight toSize:44];
     [solveLabel autoSetDimension:ALDimensionWidth toSize:100];
    [solveLabel autoAlignAxis:ALAxisVertical toSameAxisOfView:topView];
    
    UIButton *backBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    [backBtn setImageEdgeInsets:UIEdgeInsetsMake(0, 0, 0, 20)];
    backBtn.translatesAutoresizingMaskIntoConstraints = NO;
    [backBtn setImage:[UIImage imageNamed:@"BackVideo"] forState:UIControlStateNormal];
    [topView addSubview:backBtn];
    [backBtn addTarget:self action:@selector(back) forControlEvents:UIControlEventTouchUpInside];
    [backBtn autoPinEdgeToSuperviewEdge:ALEdgeTop withInset:20.0];
    [backBtn autoPinEdgeToSuperviewEdge:ALEdgeLeading withInset:0.0];
    [backBtn autoPinEdgeToSuperviewEdge:ALEdgeBottom withInset:0.0];
    [backBtn autoSetDimension:ALDimensionWidth toSize:64];
    
    UITableView *tabel = [[UITableView alloc] init];
     [self.view addSubview:tabel];
    tabel.translatesAutoresizingMaskIntoConstraints = NO;
    tabel.separatorStyle = UITableViewCellSeparatorStyleNone;
    [tabel autoPinEdgeToSuperviewEdge:ALEdgeBottom withInset:0.0];
    [tabel autoPinEdgeToSuperviewEdge:ALEdgeTop withInset:64.0];
    [tabel autoPinEdgeToSuperviewEdge:ALEdgeLeading withInset:0.0];
    [tabel autoPinEdgeToSuperviewEdge:ALEdgeTrailing withInset:0.0];
    tabel.estimatedRowHeight = 660;
    tabel.delegate = self;
    tabel.dataSource = self;
//    [tabel registerClass:[NoNetTableViewCell class] forCellReuseIdentifier:@"cell"];
    [tabel registerNib:[UINib nibWithNibName:@"NoNetTableViewCell" bundle:nil] forCellReuseIdentifier:@"cell"];
}

- (void)back{
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return 1;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    NoNetTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell" forIndexPath:indexPath];
    return cell;
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
