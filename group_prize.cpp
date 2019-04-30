//
//  group_prize.cpp
//  ByteDancePractices
//
//  Created by 梁杨晓 on 2019/4/24.
//  Copyright © 2019年 梁杨晓. All rights reserved.
//

#include "group_prize.hpp"
#include <iostream>

using namespace std;

//使用双向列表表示圆桌，此处用结构体表示学生个体

struct student{ //student结构体
    public:
        string name;
        int score;
        int prize_num;
        student *next;
        student *previous;
    
    public:
        student(){};
        student(string name, int score, int prize_num, student *next, student *previous){
        this->name = name;
        this->score = score;
        this->prize_num = prize_num;
        this->next = next;  //指明它next
        this->previous = previous; //指明它的previous
    }
};

class double_linked{ //建立链表类，用于表示学生座位关系
    
public:
    double_linked();
    ~double_linked();
    int size();
    student* delete_node(int pos);
    student* add_node(string name, int score, int prize_num, student *next,student *previous);
    student* get_node(string name);
    void show_link();
    bool is_empty();

private:
    int count; //用于计数节点
    student *header;
    student *first_node;
    
    
    
};

double_linked::double_linked():count(0){
    
    header = new student(); //创建表头
    header->previous=header->next=header;
    //header的next指向第一个节点，previous指向最后一个节点
    
}

student* double_linked::add_node(string name, int score, int prize_num, student *next,student *previous){ //该函数用于给链表添加节点，即给圆桌添加学生
    student *s=NULL;
    if(count==0){ //插入首节点
        first_node=s;
        s = new student(name,score,prize_num,next,previous);
        header->next=header->previous=s;
        
    }else if(next==first_node){ //在结尾插入节点
        s = new student(name,score,prize_num,next,previous);
        header->next->previous=s; //首节点的pre是新结尾节点
        header->previous->next=s; //原结尾节点的next是新结尾节点
        header->previous=s; //表头的pre是新结尾节点
        
    }else{ //在中间插入
        s = new student(name,score,prize_num,next,previous);
        s->next->previous=s;
        s->previous->next=s;
    }
    count++;
    return s;
}

void double_linked::show_link(){ //该函数用于展示链表中所有元素
    student *temp = header;
    for(int i=0;i<count+1;i++){
        cout<<temp->next->name<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

student* double_linked::get_node(string name){ //该函数用于按照学生名字获取对于节点
    student *temp = header;
    for(int i=0;i<count;i++){
        if(temp->next->name==name){
            return temp->next;
        }
        temp=temp->next;
    }
    return NULL;
}

int double_linked::size(){
    return count;
}

double_linked *rd;

void round_desk(){ //建立一个圆桌（双向链表）对象，并定义学生个体和他们的座位安排
    //Jack-Lucy-Max-Shirly-(Jack)
    rd = new double_linked();
    student *Jack = rd->add_node("Jack", 100, 0,NULL,NULL); //首节点的next和previous用NULL值代替
    student *Lucy = rd->add_node("Lucy", 89, 0, Jack, Jack);
    student *Shirly = rd->add_node("Shirly", 79, 0, Jack, Lucy);
    student *Max = rd->add_node("Max", 60, 0, Shirly, Lucy);
    student *Tan = rd->add_node("Tan", 95, 0,Jack, Shirly);
    rd->show_link();
    
}

int prize_solution(){ //思路：从最小的分数开始
    
    round_desk();
    
    int prize_total=0;
    student* score_rank[]={rd->get_node("Jack"),rd->get_node("Lucy"),rd->get_node("Max"),rd->get_node("Shirly"),rd->get_node("Tan")};
    
    int max = score_rank[0]->score; //max变量存储了每次比较的最大值，初始值为第一个student元素的score
    student *temp;
    for(int i=0;i<rd->size();i++){ // 冒泡法排序
        
        for(int j=0;j+1<rd->size()-i;j++){
            
            if(max>score_rank[j+1]->score){ //如果下一个元素的score大于当前max的值，则两个元素交换位置
                temp=score_rank[j];
                score_rank[j]=score_rank[j+1];
                score_rank[j+1]=temp;
            }
            max = score_rank[j+1]->score;
            
        }
        max = score_rank[0]->score;
        
    }
    for(int i=0;i<rd->size();i++){
        cout<<score_rank[i]->name<<":"<<score_rank[i]->score<<" ";
    }
    //交换后score_rank数组中存储着按score从小到大排序的student元素
    //接下来要开始分配礼物了，从score最小的开始
    for(int i=0;i<rd->size();i++){
        if(score_rank[i]->next->score>score_rank[i]->score && score_rank[i]->next->prize_num<=score_rank[i]->prize_num){
            //如果本身的next元素的score大于本身的且next元素的prize个数小于或等于本身的个数，则需要让next的prize_num比本身的prize_num多1个
            
            score_rank[i]->next->prize_num = score_rank[i]->prize_num + 1;
            
        }
        if(score_rank[i]->previous->score>score_rank[i]->score && score_rank[i]->previous->prize_num<=score_rank[i]->prize_num){
            //如果本身的previous元素的score大于本身的且previous元素的prize个数小于或等于本身的个数，则需要让previous的prize_num比本身的prize_num多1个
            
            score_rank[i]->previous->prize_num = score_rank[i]->prize_num + 1;
        }
    }
    
    for(int i=0;i<rd->size();i++){
        prize_total+=score_rank[i]->prize_num;
    }
    
    return prize_total;
}



