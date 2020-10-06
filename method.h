//
//  method.h
//  ENIGMA_cmd_tool
//
//  Created by Kevin on 2020/1/19.
//  Copyright © 2020年 Kevin. All rights reserved.
//

#ifndef method_h
#define method_h
#include "storage.h"
#include "time.h"
#include <string>
#include <ctype.h>
#include <iostream>
#include <fstream>
using namespace std;
//判断是否为整数√
bool isint(string s)
{
    for (int i=1;i<s.size();i++)
        if (!isdigit(s[i]))
            return false;
    if (s.size()>1&&s[0]=='-'){
        return true;
    }
    if (isdigit(s[0])){
        return true;
    }
    return false;
}
//判断字符是否合规√
bool islegal(string _in){
    char _use;
    _use=toupper(_in[0]);
    for (int __i=0;__i<50;__i++){
        if (_use==BASIC[__i]){
            if (TB[__i]==false){
                TB[__i]=true;
                return true;
            }else{
                TB_clear();
                return false;
            }
        }
    }
    TB_clear();
    return false;
}
//生成小于size的随机整数√
int RND(int _size){
    int opt;
    srand((int)time(NULL)*rand());
    opt=rand()%_size;
    return opt;
}
//标准化√
string STD(string _in){
    string _out;
    _out=_in;
    for (int _i=0;_i<_in.size();_i++){
        _out[_i]=toupper(_out[_i]);
    }
    return _out;
}
//标准化√
char STD(char _in){
    char _out;
    _out=toupper(_in);
    return _out;
}
//数字化√
int DGT(char _in){
    int _out=ERROR_NUM;
    for (int _i=0;_i<50;_i++){
        if (_in==BASIC[_i]){
            return _i;
        }
    }
    return _out;
}
//字母化√
char CRT(int _in){
    char _out=ERROR_CHR;
    if (_in<50&&_in>=0){
        _out=BASIC[_in];
        return _out;
    }
    return _out;
}
//判断字符串是否合规√
bool islegals(string _in){
    for (int _i=0;_i<_in.size();_i++){
        if (DGT(STD(_in[_i]))==7700){
            return false;
        }
    }
    return true;
}
//时间进位 *注意用%50防止溢出√
void NeXt(){//这里的设计方式很不理智，懒得改了
    for (int _i=19;_i>=0;_i=_i-1){
        if (CLOCK[_i][0]==CLOCK[_i][1]){
            CLOCK[_i][2]=0;//as true
        }else{
            CLOCK[_i][2]=1;//as false
        }
        CLOCK[_i][3]=1;//as false
    }
    CLOCK[19][0]++;
    CLOCK[19][0]=CLOCK[19][0]%50;
    CLOCK[19][3]=0;//as moving
    for (int _i=19;_i>0;_i=_i-1){
        if (CLOCK[_i][3]==0&&(CLOCK[_i][2]==0||CLOCK[_i-1][2]==0)){
            CLOCK[_i-1][0]++;
            CLOCK[_i-1][0]=CLOCK[_i-1][0]%50;
            //CLOCK[_i][2]=1;//as not carrying
            CLOCK[_i-1][3]=0;//as moving
        }
    }
}
//时间防溢出√
void regulate_C(){
    for (int _i=0;_i<20;_i++){
        CLOCK[_i][0]=CLOCK[_i][0]%50;
        CLOCK[_i][1]=CLOCK[_i][1]%50;
    }
}
//转轮设置√
//数量√
void CLOCK_set_num(int _num){
    CLOCK_size=_num+1;
}
//显示设置√
void display(){
    cout<<"Ring numbers:"<<CLOCK_size-1<<endl;
    cout<<"Ring.num:\t";
    for (int _i=21-CLOCK_size;_i<20;_i++){
        cout<<CLOCK[_i][4]<<"\t";
    }
    cout<<endl;
    cout<<"Ring.pos:\t";
    for (int _i=21-CLOCK_size;_i<20;_i++){
        cout<<CLOCK[_i][0]<<"\t";
    }
    cout<<endl;
    cout<<"Reflex.num:"<<CLOCK[20-CLOCK_size][4]<<endl;
    cout<<"Reflex.pos:"<<CLOCK[20-CLOCK_size][0]<<endl;
    cout<<"Connection board pairs:"<<conB_size<<"\t";
    for (int i=0;i<conB_size;i++){
        cout<<CRT(conB[i][0])<<"-"<<CRT(conB[i][1])<<" ";
    }
    cout<<endl;
}
//设置轮数√
void Ring_size_set(){
    cin>>command;
    if (!isint(command)){
        cout<<"cannot read! Not an int! check command list!"<<endl;
        return;
    }
    if (atoi(command.c_str())<=0||atoi(command.c_str())>19){
        cout<<"ring numbers out of range [1,19]!"<<endl;
        return;
    }
    CLOCK_set_num(atoi(command.c_str()));//CLOCK_size是包含有反射板的数目
    is_num=true;
    cout<<"ring numbers set completed!"<<endl;
    return;
}
//设置轮选择√
void Ring_choose_set(){
    if (is_num!=true){
        cout<<"You haven't set ring numbers you want to use."<<endl;
        return;
    }
    for (int _j=21-CLOCK_size;_j<20;_j++) {
        cin>>command;
        if (!isint(command)){
            cout<<"cannot read! Not an int! check command list!"<<endl;
            CLOCK_clear();
            return;
        }
        if (atoi(command.c_str())<=0||atoi(command.c_str())>100){
            cout<<"ring numbers out of range [1,100]!"<<endl;
            CLOCK_clear();
            return;
        }
        CLOCK[_j][4]=atoi(command.c_str())-1;
        CLOCK[_j][1]=Ring[CLOCK[_j][4]].Car;
    }
    regulate_C();
    is_choose=true;
    cout<<"ring choose completed!"<<endl;
    return;
}
//设置轮位置√
void Ring_pos_set(){
    if (is_num!=true){
        cout<<"You haven't set ring numbers you want to use."<<endl;
        return;
    }if (is_choose!=true){
        cout<<"You haven't chosen the rings you want to use."<<endl;
        return;
    }
    for (int _j=21-CLOCK_size;_j<20;_j++) {
        cin>>command;
        if (!isint(command)){
            cout<<"cannot read! Not an int! check command list!"<<endl;
            CLOCK_clear_set();
            return;
        }
        if (atoi(command.c_str())<0||atoi(command.c_str())>=50){
            cout<<"position out of range [0,49]!"<<endl;
            CLOCK_clear_set();
            return;
        }
        CLOCK[_j][0]=atoi(command.c_str());
    }
    regulate_C();
    cout<<"ring position set completed!"<<endl;
    return;
}
//设置反射板选择√
void Ref_choose_set(){
    if (is_num!=true){
        cout<<"You haven't set ring numbers you want to use."<<endl;
        return;
    }
    cin>>command;
    if (!isint(command)){
        cout<<"cannot read! Not an int! check command list!"<<endl;
        CLOCK_clear();
        return;
    }
    if (atoi(command.c_str())<=0||atoi(command.c_str())>100){
        cout<<"reflexing board numbers out of range [1,100]!"<<endl;
        CLOCK_clear();
        return;
    }
    CLOCK[20-CLOCK_size][4]=atoi(command.c_str())-1;
    CLOCK[20-CLOCK_size][1]=Ring[CLOCK[20-CLOCK_size][4]].Car;
    regulate_C();
    cout<<"reflexing board choose completed!"<<endl;
    return;
}
//设置反射板位置√
void Ref_pos_set(){
    if (is_num!=true){
        cout<<"You haven't set ring numbers you want to use."<<endl;
        return;
    }if (is_choose!=true){
        cout<<"You haven't chosen the rings you want to use."<<endl;
        return;
    }
    cin>>command;
    if (!isint(command)){
        cout<<"cannot read! Not an int! check command list!"<<endl;
        CLOCK_clear_set();
        return;
    }
    if (atoi(command.c_str())<0||atoi(command.c_str())>=50){
        cout<<"position numbers out of range [0,49]!"<<endl;
        CLOCK_clear_set();
        return;
    }
    CLOCK[20-CLOCK_size][0]=atoi(command.c_str());
    regulate_C();
    cout<<"flexing board position set completed!"<<endl;
    return;
}
//设置连接板√
void Con_set(){
    cin>>command;
    if (!isint(command)){
        cout<<"cannot read! Not an int! check command list!"<<endl;
        CLOCK_clear();
        return;
    }
    if (atoi(command.c_str())<=0||atoi(command.c_str())>25){
        cout<<"connection pairs out of range [1,25]!"<<endl;
        CLOCK_clear();
        return;
    }
    conB_size=atoi(command.c_str());
    for (int _i=0;_i<conB_size;_i++){
        cin>>command;
        if (islegal(command)){
            conB[_i][0]=DGT(STD(command[0]));
        }else{
            conB_clear();
            cout<<"connection pairs choose error!"<<endl;
            return;
        }
        cin>>command;
        if (islegal(command)){
            conB[_i][1]=DGT(STD(command[0]));
        }else{
            conB_clear();
            cout<<"connection pairs choose error!"<<endl;
            return;
        }
    }
    cout<<"connection board set completed!"<<endl;
    TB_clear();
    return;
}
//转轮防溢出
int R(int _in){
    int _out;
    _out=(_in+50)%50;
    return _out;
}
//转轮加密入
void Ring_in(int POS_in_CLOCK){
    int NUM=CLOCK[POS_in_CLOCK][4];
    int POS=CLOCK[POS_in_CLOCK][0];
    A=R(A+POS);
    for (int _i=0;_i<50;_i++){
        if (Ring[NUM].Con[_i]==A){
            A=_i;
            break;
        }
    }
    A=R(A-POS);
}
//转轮加密出
void Ring_out(int POS_in_CLOCK){
    int NUM=CLOCK[POS_in_CLOCK][4];
    int POS=CLOCK[POS_in_CLOCK][0];
    A=R(A+POS);
    A=Ring[NUM].Con[A];
    A=R(A-POS);
}
//反射板加密
void Ref_IO(int POS_in_CLOCK){
    int NUM=CLOCK[POS_in_CLOCK][4];
    int POS=CLOCK[POS_in_CLOCK][0];
    A=R(A+POS);
    A=Ref[NUM].Con[A];
    A=R(A-POS);
}
//连接板加密√
void Connect(){
    for (int _i=0;_i<conB_size;_i++){
        if (A==conB[_i][0]){
            A=conB[_i][1];
            break;
        }else if (A==conB[_i][1]){
            A=conB[_i][0];
            break;
        }
    }
}
//轮板全加密
void CD(){
    Connect();
    for (int __i=0;__i<CLOCK_size-1;__i++){
        Ring_in(19-__i);
    }
    Ref_IO(20-CLOCK_size);
    for (int __i=21-CLOCK_size;__i<20;__i++){
        Ring_out(__i);
    }
    Connect();
}
//文件重命名
inline
const string OptF(string _F){
    int _m = 0;
    for (int _i=(int)_F.size()-1;_i>=0;_i=_i-1){
        if(_F[_i]=='_'){
            _m=_i;
            break;
        }
    }
    if (_m==0){
        _m=(int)_F.size()-4;
    }
    string NAME=_F.substr(0,_m);
    time_t tt = time(NULL);
    tm* t=localtime(&tt);
    string time=to_string(t->tm_year+1900)+"."+to_string(t->tm_mon+1)+"."+to_string(t->tm_mday)+"-"+to_string(t->tm_hour)+"."+to_string(t->tm_min)+"."+to_string(t->tm_sec);
    NAME=NAME+"_"+time+".txt";
    return NAME;
}

#endif /* method_h */
