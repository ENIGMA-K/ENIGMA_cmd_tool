# ENIGMA_cmd_tool
It's a cmd tool to encrypt simple txt files or long strings.

##  文件结构
main.cpp 是主要框架，是主体结构，可以看到运行的全流程
help.h 是帮助文档，在程序运行时可以通过 -h 查看
blast.h 是生成加密轮用的
method.h 记录了运行程序所需要的全部方法
storage.h 记录了全部需要储存的内容，包括具体的轮

## 命令
. '-set' show your settings
. '-rn [NUM]' set ring numbers
. '-rs [SEL1][SEL2][SEL3]' choose rings you want to use
. '-rp [POS1][POS2][POS3]' set rings position
. '-fs [SEL]' choose reflexing board you want to use
. '-fp [POS]' set reflexing board position
. '-c [NUM][PR1a][PR1b][PR2a][PR2b]' set connection board
. '--' start/end coding/decoding
. '-f' enter a file route and the file can be code/decode(only avilable for .txt)
. '-q' quit the program
