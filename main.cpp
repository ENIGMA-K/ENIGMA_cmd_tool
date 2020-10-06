//
//  main.cpp
//  ENIGMA_cmd_tool
//
//  Created by Kevin on 2020/1/15.
//  Copyright © 2020年 Kevin. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
#include "method.h"
#include "storage.h"
#include "time.h"
#include "math.h"
#include "blast.h"
#include "help.h"
#include <fstream>

using namespace std;

int main(){
    cout<<WELCOME<<endl;//非正式语句
    cout<<"version:"<<version<<endl;
//命令
com:
    cout<<"->";
    cin>>command;
    //帮助
    if (command[0]=='-'&&(command=="-h"||command=="help")){
        cout<<HELP<<endl;
    }
    //退出
    if (command[0]=='-'&&command=="-q"){
        return 0;
    }
    //查看设置
    if (command[0]=='-'&&command=="-set"){
        display();
        goto com;
    }
    //设置轮数
    if (command[0]=='-'&&command=="-rn"){
        Ring_size_set();
        goto com;
    }
    //设置轮选择
    if (command[0]=='-'&&command=="-rs"){
        Ring_choose_set();
        goto com;
    }
    //设置轮位置选择
    if (command[0]=='-'&&command=="-rp"){
        Ring_pos_set();
        goto com;
    }
    //设置反射板选择
    if (command[0]=='-'&&command=="-fs"){
        Ref_choose_set();
        goto com;
    }
    //设置反射板位置选择
    if (command[0]=='-'&&command=="-fp"){
        Ref_pos_set();
        goto com;
    }
    //设置连接板
    if (command[0]=='-'&&command=="-c"){
        Con_set();
        goto com;
    }
    //进入加密解密模式code
    if (command[0]=='-'&&command=="--"){
        if (is_num!=true){
            cout<<"You haven't set ring numbers you want to use."<<endl;
            goto com;
        }if (is_choose!=true){
            cout<<"You haven't chosen the rings you want to use."<<endl;
            goto com;
        }
        goto code;
    }
    /*
    //测试test
    if (command=="test"){
        for (int i=0;i<10000;i++){
            cout<<CLOCK[17][0]<<" "<<CLOCK[18][0]<<" "<<CLOCK[19][0]<<endl;
            NeXt();
        }
        goto com;
    }
     */
    //错误命令
    //cout<<"command not found!"<<endl;
    goto com;
code:
    cout<<">>";
    cin>>command;
    //退出
    if (command[0]=='-'&&command=="-q"){
        return 0;
    }
    //查看设置
    if (command[0]=='-'&&command=="-set"){
        display();
        goto com;
    }
    //退出加密解密模式code
    if (command[0]=='-'&&command=="--"){
        goto com;
    }
    //文本加密
    if (command[0]=='-'&&command=="-f"){
    fff:
        cout<<"Enter file route:";
        string File_in;
        cin>>File_in;
        if (File_in[0]=='-'){
            goto code;
        }
        //退出
        if (command[0]=='-'&&command=="-q"){
            return 0;
        }
        string File_out=OptF(File_in);
        const char *File_point=File_in.data();
        const char *File_point_out=File_out.data();
        if (File_point==NULL){
            cout<<"File not found!";
            goto fff;
        }
        ifstream in(File_point);
        ofstream out(File_point_out);
        in>>input;
        output="";
        if (!islegals(input)){
            cout<<"illegal input in your text!"<<endl;
            in.close();
            out.close();
            goto fff;
        }
        for (int i=0;i<input.size();i++){
            A=DGT(STD(input[i]));
            CD();
            output=output+CRT(A);
            NeXt();
        }
        out<<output;
        cout<<"complete!"<<endl;
        in.close();
        out.close();
        goto fff;
        
    }
    
    //正式运算
    input=command;
    output="";
    if (!islegals(input)){
        cout<<"illegal input in your text!"<<endl;
        goto code;
    }
    for (int i=0;i<input.size();i++){
        A=DGT(STD(input[i]));
        CD();
        output=output+CRT(A);
        NeXt();
    }
    cout<<output<<endl<<endl;
    goto code;
    
    
    
    
    return 0;
}
