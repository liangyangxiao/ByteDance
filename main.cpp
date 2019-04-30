//
//  main.cpp
//  ByteDancePractices
//
//  Created by 梁杨晓 on 2019/4/19.
//  Copyright © 2019年 梁杨晓. All rights reserved.
//

#include <iostream>
#include<time.h>
#include "change.hpp"
#include "auto_process_str.hpp"
#include "group_prize.hpp"
#include "rope.hpp"
#include "heap_sort.hpp"
using namespace std;


int main(void)
{
    clock_t start,finish;
    double totaltime;
    start=clock();
    
    /*
     *第一题，最少找零问题
     */

    //change_solution1();
    //change_solution2();
    
    /*
     *第二题，字符串自动按要求处理问题
     */

    //cout<<auto_str("aabbbbb");
    //auto_str2("aabbbbbtesttttsttt");
    
    /*
     *第三题，礼物按座位和分数最少分配问题
     */

    //cout<<"至少需要"<<prize_solution()<<"个礼物";
    
    /*
     *第四题，等长分绳子，求等长绳子最大值
     */
    
    //rope_solution();
    
    /*
     * 补充：堆排序实现
     */
    
    //heap_sort_solution();
    
    
    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<"\n此程序的运行时间为"<<totaltime<<"秒！"<<endl;
    return 0;
}
