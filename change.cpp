//
//  change.cpp
//  ByteDancePractices
//
//  Created by 梁杨晓 on 2019/4/24.
//  Copyright © 2019年 梁杨晓. All rights reserved.
//

#include "change.hpp"
#include <iostream>

using namespace std;

int all_money = 1024;
const int CHANGE[] = {64,16,4,1}; //CHANGE数组中存储了4种零钱

void change_solution1(){
    
    
        int value;
        int rest_money;
        int time[4]; //time数组用于存储4种零钱各需多少次
        int total=0;
    
        do{
            cout<<"Please enter the value(<=1024 and >0) of product:"<<endl;
            cin>>value;
        }while(value>1024||value<0);
    
        rest_money = all_money - value; //rest_money为买完商品后还剩多少钱
        int remainer;
        int times=0;
    
        for(int i=0;i<4;i++){ //把4种数额的零钱按从大到小排序，依次循环遍历计算
            //cout<<"零钱数："<<CHANGE[i]<<endl;
            if(rest_money<CHANGE[i]){ //如果剩下的钱已经小于当前计算的零钱数额，跳出当前循环
                continue;
            }
            remainer = rest_money%CHANGE[i];
            //cout<<"求余的结果："<<remainer<<endl;
            times=(rest_money - remainer)/CHANGE[i];
            time[i]=times;
            rest_money = rest_money - times * CHANGE[i];
            //cout<<"新的余钱："<<rest_money<<endl;
        }
    
        for(int j=0;j<4;j++){
            total= total + time[j];
        }
        cout<<"64:"<<time[0]<<endl;
        cout<<"16:"<<time[1]<<endl;
        cout<<"4:"<<time[2]<<endl;
        cout<<"1:"<<time[3]<<endl;
        cout<<"total:"<<total<<endl;
}

void change_solution2(){
    int value;
    do{
        cout<<"Please enter the value(<=1024 and >0) of product:"<<endl;
        cin>>value;
    }while(value>1024||value<0);
    
    int rec = 1024 - value; //rec为买完商品后剩余的钱
    
    int num64 = rec / 64;  //num64只保留整数部分，小数被忽略
    rec = rec - 64*num64;
    int num16 = rec / 16;
    rec = rec - 16*num16;
    int num4 = rec / 4;
    rec = rec - 4*num4;
    int num1 = rec / 1;
    rec = rec - 1*num1;
    cout<<"64:"<<num64<<endl;
    cout<<"16:"<<num16<<endl;
    cout<<"4:"<<num4<<endl;
    cout<<"1:"<<num1<<endl;
    cout<<num64+num16+num4+num1<<endl;
    
}
