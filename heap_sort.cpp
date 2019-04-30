//
//  heap_sort.cpp
//  ByteDancePractices
//
//  Created by 梁杨晓 on 2019/4/29.
//  Copyright © 2019年 梁杨晓. All rights reserved.
//

#include "heap_sort.hpp"
#include <iostream>
#include <cmath>
using namespace std;

int arr[100];
int i=0,n=0,Max=0;

//P.S. 这是我最后一次用数组实现树！！！！计算下标累死我了。。。(立个flag先～)

//堆排序实现从小到大的排序

float log_2(int i){  //以2为底log
    return log(i)/log(2);
}

int max_cal_3(int m1,int m2,int m3){ //返回3个数组值中的最大值对应的code(1,2,3)
    int max_index;
    if(m1>=m2){
        if(m1>=m3){
            max_index=1;  //m1为最大值
        }else{
            max_index=3; //m3为最大值
        }
    }else if(m2>=m3){
        max_index=2; //m2为最大值
    }else{
        max_index=3; //m3为最大值
    }
    return max_index;
}

void swap(int& a,int& b){ //交换两个元素
    int temp = a;
    a = b;
    b = temp;
}


void print_tree(int* arr,int number){ //打印树
    
    int n = log_2(number)+1; //计算树的层数
    int index_p=0;
    for(int a = n-1;a>-1;a--){ //循环的次数为树打印的层数
        
        int space = pow(2,a);//第a层开头需打印多少个空格
        
        while(space>0){
            if(a==0){ //最底一层不要空格
                break;
            }
            cout<<" ";
            space--;
        }
        
        for(int b=0;b<pow(2,n-a-1);b++){ //第a层需要打印pow(2,n-a-1)次
            cout<<arr[index_p];
            index_p++;
            if(index_p==number){ //如果下标已经超过范围则不再打印
                break;
            }
            cout<<" ";
            cout<<" ";
            cout<<" ";
        }
        cout<<endl;
    }
}

void heap_sort_solution(){
    cout<<"请输入乱序数列的个数:"<<endl;
    cin>>Max;
    cout<<"请输入所有的乱序数列:"<<endl;
    
    while(1){
        cin>>arr[i];
        i++;//i记录有多少个有效数字
        if((cin.get() == '\n') && (Max<=i)){  //该判断条件为如果输入为空格并且超过设定个数Max就退出
            break;
        }
    }
    cout<<"您输入的数列:"<<endl;
    for(int j=0;j<i;j++){
        cout<<arr[j]<<" ";
    }
    cout<<endl;
    n=log_2(i)+1;
    cout<<"对于该序列建成的树有"<<n<<"层"<<endl;//该输入序列二叉树有n层，分别为第0层，...第n-1层
    
    cout<<"打印初始树"<<endl;
    
    print_tree(arr,Max);
    
    
    //堆排序从最后一个非叶节点开始，也就是在倒数第二层，即第n-2层
    //按从左到右，从下到上的准则开始，每次得到一个大顶堆就把根元素与最后一个未排好的元素交换
    int index; //非叶节点下标
    int max_index; //用于存储3个比较大小的数组元素最大的code（1，2，3）
    
    for(int k=Max;k>1;k--){ //每次都剔除掉已排序好的元素,初始状态为对全部元素进行排序
        n = log_2(k)+1;
        for(int j=n-2;j>=0;j--){ //外层for循环用于循环访问所有层数，从第n-2层（第一个非叶节点层）开始，到最顶层即第0层结束
            index = pow(2, j)-1;  //index为当前层第一个节点
            for(int t=index;t<pow(2, j+1)-1;t++){ //内层for循环用于循环访问当前层所有成员
                if(2*t+2<k){ //说明有当前非叶节点有2个子节点
                    max_index = max_cal_3(arr[t], arr[2*t+1], arr[2*t+2]);
                    if(max_index==2){
                        swap(arr[t], arr[2*t+1]);
                    }else if(max_index==3){
                        swap(arr[t], arr[2*t+2]);
                    }
                }else if(2*t+2>=k&&2*t+1<k){ //说明当前非叶节点只有1个子节点
                    if(arr[t]<arr[2*t+1]){
                        swap(arr[t], arr[2*t+1]);
                    }
                }
            }
        }

        int p=k-1; //该p变量开始指向除了已经排序好的最后一个节点的下标
        swap(arr[0], arr[p]); //每次得到一个大顶堆后交换根元素和除了已经排序好的最后一个元素
    }
    
    cout<<"排序后的数列:"<<endl;
    for(int j=0;j<i;j++){
        cout<<arr[j]<<" ";
    }
    cout<<endl;
    
    cout<<"排序后的树"<<endl;
    print_tree(arr,Max);
    
}
