//
//  help.h
//  ENIGMA_cmd_tool
//
//  Created by Kevin on 2020/1/20.
//  Copyright © 2020年 Kevin. All rights reserved.
//
//test ->-rn 3 -rs 1 2 3 -rp 12 14 16 -fs 43 -fp 2 -c 2 r g s v
#ifndef help_h
#define help_h
#include <iostream>
#include <cmath>
#include <string>
#include "method.h"
#include "storage.h"
#include "time.h"
#include "math.h"
#include "blast.h"
using namespace std;
//程序初始欢迎
const string WELCOME="\nWelcome to use this ENIGMA_Ultra commandline tool!";
//帮助文档
const string HELP="\n  This is a help file which you can check the commands and regulations. You can always show this file using command '-h' or 'help'.\n  First of all, do NOT use space in you coding file, or those characters follow the space will not be code or decode.\n  Secondly, follow the instructions of avilable char list, those chars out of the list will not be operate.(avilable char list:26 characters + numbers of 0~9 + 14 punctuation marks ',.?!*&^#@$%():')\n  COMMANDs are shown below:\n    1.'-set' show your settings\n    2.'-rn [NUM]' set ring numbers\n    3.'-rs [SEL1][SEL2][SEL3]' choose rings you want to use\n    4.'-rp [POS1][POS2][POS3]' set rings position\n    5.'-fs [SEL]' choose reflexing board you want to use\n    6.'-fp [POS]' set reflexing board position\n    7.'-c [NUM][PR1a][PR1b][PR2a][PR2b]' set connection board\n    8.'--' start/end coding/decoding\n    9.'-f' enter a file route and the file can be code/decode(only avilable for .txt)\n    10.'-q' quit the program\n";

#endif /* help_h */
