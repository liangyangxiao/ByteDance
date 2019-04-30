//
//  rope.cpp
//  ByteDancePractices
//
//  Created by 梁杨晓 on 2019/4/25.
//  Copyright © 2019年 梁杨晓. All rights reserved.
//

#include "rope.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

int rope[100]; //数组初始值均为0
int t = 0.01; //梯度

void rope_solution(){
    
    int m=0,n=0,i=0,L=0,mp=0;
    float l=0;  //m段绳子的长度

    cout<<"请依次输入绳子长度,从小到大，以0结束："<<endl;
    while(1){
        cin>>rope[i];
        if(rope[i]==0){
            break;
        }
        i++;
    }
    n=i;
    i=0;
    cout<<"您输入的所有绳子长度：";
    while(rope[i]!=0){
        cout<<rope[i]<<" ";
        L+=rope[i];
        i++;
    }
    cout<<endl;
    cout<<"共"<<n<<"段"<<",总长为"<<L<<endl;
    cout<<"请输入分成m段的m值："<<endl;
    cin>>m;
    
    l = rope[0]; //l的最大值为最短绳子的长度
    while(1){
        
        i=0;
        while(rope[i]!=0){
            mp+=rope[i]/l;
            i++;
        }
        if(mp==m){
            break;
        }
        l-=t;
        if(l==0){
            cout<<"您输入的情况无解";
        }
    }
    
    cout<<"l的最大值为："<<l;

    
}
