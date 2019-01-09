# 项目报告

## 项目内容
- 一个简单的五子棋的demo
- 完成了人机，本机人人对战，保存、读取游戏，保存、读取游戏录像
- 完全使用CLI作为界面，没有独立UI

## 项目地址
### [Github](https://github.com/AsterNighT/FIAR)

## 组员
### 王英豪 
- Github:AsterNighT 
- 学号：3180102062 
- 邮箱：3180102062@zju.edu.cn
- 分工：项目负责人，项目的游戏逻辑和交互逻辑设计和实现，AI部分


## 项目结构
- 为了方便编译和调试，使用Visual Studio进行开发
- 共7个文件

### FIAR.c
- 程序入口，展示菜单

### menu.h & menu.c
- 将显示菜单进行封装得到的函数

### ai.h & ai.c 
- AI的估值函数，type为1时输出整个棋盘的估值

### board.h & board.c
- 游戏核心逻辑
- startGameBoard(struct Board* board, int type); 开始游戏，type为0时人机，1人人
- clearBoard(struct Board* board); 清空棋盘
- displayBoard(struct Board* board, int type); 显示棋盘，type为0显示光标，1不显示
- placePieceBoard(struct Board* board, int cordx, int cordy); 落子
- undoBoard(struct Board* board); 悔棋
- checkStatusBoard(struct Board* board); 检查棋盘状态
- saveBoard(struct Board* board); 存档
- loadBoard(struct Board* board, char* saveData); 读档
- saveReplayBoard(struct Board* board); 保存录像
- playReplayBoard(struct Board* board, char* replayData); 播放录像
- encodeMove(struct Move move); decodeMove(struct CharPair code); 保存和读取录像用的函数

## 难点
- 组员不是很会用git，可能反而降低了开发效率
- 代码质量难以控制，代码重复率比较高
- C的面向对象不够优雅，如果不考虑宏，没有办法用```board.display()```这样的方式写，显得比较难看

## 目前存在的问题
- ```printf```遇到换行符会立刻刷新缓冲区，这导致展示棋盘有严重的闪烁问题，目前没有想到办法解决
- AI的估价函数调参太消耗时间，没有时间优化，现在AI的水平还很低，尤其不会主动进攻