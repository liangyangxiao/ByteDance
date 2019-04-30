//
//  auto_process_str.cpp
//  ByteDancePractices
//
//  Created by 梁杨晓 on 2019/4/24.
//  Copyright © 2019年 梁杨晓. All rights reserved.
//

#include "auto_process_str.hpp"

#include <iostream>
#include <string>
using namespace std;


string auto_str(string text){
    char T[]={};
    strcpy(T, text.c_str());  //把string变量转为char型数组
    int size = strlen(T);  //获取字符数组的长度
    //cout<<size;
    
    for(int i=0;i<size-3;i++){
        if(T[i]==T[i+1]){ //CC类型或AA类型
            
            if(T[i+1]==T[i+2]){ //CCC类型
                //执行删除C的操作
                string temp = T;
                int j=1;
                if(i+3+j<size){ //如果后续还有C继续删除，例：CCCC
                    while(T[i+2]==T[i+3+j]){
                        j++;
                        if(i+3+j>=size)
                            break;
                        
                    }
                }
                temp.erase(i+2,j+1);  //字符串删减函数erase(a,b); 从字符串第a位开始删除b个字符
                strcpy(T, temp.c_str());
                size--;
                
            }else if(T[i+2]==T[i+3]){ //AABB类型
                //执行删除B的操作
                string temp = T;
                int j=1;
                if(i+3+j<size){ ////如果后续还有B继续删除B，例：AABBB
                    while(T[i+2]==T[i+3+j]){
                        j++;
                        if(i+3+j>=size)
                            break;
                        
                    }
                }
                temp.erase(i+3,j);
                strcpy(T, temp.c_str());
                size--;
            }
        }
    }
    text=T;
    return text;
}

char s[8000000];
string auto_str2(string text){
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int len = strlen(s);
        for(int i = 0 ; i < len; )
        {
            int next1 = i+1;
            while(s[next1] == '@' && next1<len)
                ++next1;
            int next2 = next1+1;
            while(s[next2] == '@' && next2<len)
                ++next2;
            int next3 = next2+1;
            while(s[next3] == '@' && next3<len)
                ++next3;
            if(s[i]==s[next1] && s[next1]==s[next2])
            {
                s[i] = '@';
                i = i+1;
                continue;
            }
            else if(s[i]==s[next1] && s[next2]==s[next3])
            {
                s[next2] = '@';
                continue;
            }
            else
            {
                i = i+1;
                continue;
            }
        }
        for(int i=0;i<len;++i)
            if(s[i]!='@')
                printf("%c",s[i]);
        printf("\n");
    }
    
    return text;
}
