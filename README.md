# ENIGMA_cmd_tool
It's a cmd tool to encrypt simple txt files or long strings.

##  文件结构
main.cpp 是主要框架，是主体结构，可以看到运行的全流程
help.h 是帮助文档，在程序运行时可以通过 -h 查看
blast.h 是生成加密轮用的
method.h 记录了运行程序所需要的全部方法
storage.h 记录了全部需要储存的内容，包括具体的轮

## 命令
1.'-set' show your settings\n
2.'-rn [NUM]' set ring numbers\n
3.'-rs [SEL1][SEL2][SEL3]' choose rings you want to use\n
4.'-rp [POS1][POS2][POS3]' set rings position\n
5.'-fs [SEL]' choose reflexing board you want to use\n
6.'-fp [POS]' set reflexing board position\n
7.'-c [NUM][PR1a][PR1b][PR2a][PR2b]' set connection board\n
8.'--' start/end coding/decoding\n
9.'-f' enter a file route and the file can be code/decode(only avilable for .txt)\n
10.'-q' quit the program\n
