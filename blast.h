//
//  blast.h
//  ENIGMA_cmd_tool
//
//  Created by Kevin on 2020/1/19.
//  Copyright © 2020年 Kevin. All rights reserved.
//

#ifndef blast_h
#define blast_h
#include <iostream>
#include <cmath>
#include <string>
#include "time.h"
#include "math.h"
#include "method.h"
#include "storage.h"

using namespace std;
//以下部分用于生成部分程序内容用
//生成转轮组
void ringblast(){
    int use[50];
    int ins=0;
    int test=0;
    for (int i=0;i<100;i++){
        for (int j=0;j<50;j++){
            use[j]=ERROR_NUM;
        }
        ins=0;
        test=0;
        for (int j=0;j<50;){
            ins=RND(50);
            test=0;
            for (int k=0;k<j;k++){
                if (ins==use[k]){
                    test=1;
                    break;
                }
            }
            if (test!=1){
                use[j]=ins;
                j++;
            }
        }
        cout<<"{{";
        for (int j=0;j<49;j++){
            cout<<use[j]<<",";
        }
        cout<<use[49]<<"},"<<RND(50)<<"},"<<endl;
    }
};
void refblast(){
    int use[50];
    int ins=0;
    int test=0;
    for (int i=0;i<100;i++){
        for (int j=0;j<50;j++){
            use[j]=ERROR_NUM;
        }
        ins=0;
        test=0;
        for (int j=0;j<50;){
            ins=RND(50);
            test=0;
            for (int k=0;k<j;k++){
                if (ins==use[k]||ins==k){
                    test=1;
                    break;
                }
            }
            if (use[j]<50){
                test=1;
                j++;
            }
            if (test!=1){
                use[j]=ins;
                use[ins]=j;
                j++;
            }
        }
        cout<<"{{";
        for (int j=0;j<49;j++){
            cout<<use[j]<<",";
        }
        cout<<use[49]<<"},"<<RND(50)<<"},"<<endl;
    }
};
#endif /* blast_h */
