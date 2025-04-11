#include"name.h"
#include"public.h"
bool land = 0, over = 0;//是否落地/结束游戏
bool easy = 0;          //控制简单/困难模式
bool normal = 0;		//控制正常/原神模式
int x = 72* 4, y = -72* 3;
int mapx =1440, mapy = 1440;
int shape = 0;
int next = rand() % 7,nextcolor=rand()%7, now;
int maxNum = 0;
const int next_x = 720+100, next_y =100;
wchar_t score_[25];
wchar_t speed_[25];
unsigned int score =0;
int speed=1;
DWORD time_now;
int map[10][20];
int map_tmp[10][20];
COLORREF map_c[10][20];
COLORREF colors[7] = { RGB(255, 0, 0), RGB(255, 165, 0), RGB(255, 225, 70), RGB(0, 128, 0), RGB(0, 206, 209), RGB(0, 0, 255), RGB(128, 0, 128) };
STAR star[800];
int Block:: num = 0;

int main()
{
	I i; O o; T t; L1 l1; L2 l2; Z1 z1; Z2 z2;
	Block* block[7] = { &i,&o,&t,&l1,&l2,&z1,&z2 };
	initEnvironment();					//初始化窗口
	playmusic();						//开始界面音乐
	gamebegin();						//绘制开始界面
	while (!over ) {	                  
		now = next;
		next = rand() % 7;
		BeginBatchDraw();					//使用批量绘图，解决频闪问题	
		drawBGR();							//先画右侧背景(原神图片或纯色)
		block[next]->draw(next_x, next_y);	//再画右侧下一个方块
		EndBatchDraw();						//结束批量绘图
		while (!over && !land) {		//结束时必须跳出两层循环，因此此处也须判断over是否为0		
			getcmd(*(block[now]));      //放在绘图前边，保证结束时也可以看到最后一块方块	
			writeread();				//读写文件，记录分数、姓名、时间，并且可以使用文件控制游戏难度
			BeginBatchDraw();           	
			drawBGL();                  //画左侧背景(会根据得分不同实现不同渐变色或原神图片）
			drawmap();					//画现有块
			block[now]->draw(x, y);		//画下落块
			EndBatchDraw();			    	
		}
		record(block[now]);
		changemusic();					//根据得分改变背景音乐
	}
	gameover();                          //结束游戏，记录得分，绘制结算画面，提示输入姓名
	Sleep(2000);
	int x = _getch();                    //任意键退出
}
//最开始用switch—case根据随机数的不同创造不同的类，好处是可以实现颜色随机，坏处是代码过于繁琐
			//		}
			//		record(nowblock);
			//		break;
		//	switch (next) {
		//	case 0: {
		//		O nextblock{};
		//		nextblock.draw(nextblock.getblock(), next_x, next_y);
		//		break;
		//	}
		//	case 1: {
		//		I nextblock{};
		//		nextblock.draw(nextblock.getblock(), next_x, next_y);
		//		break;
		//	}
		//	case 2: {
		//		L1 nextblock{};
		//		nextblock.draw(nextblock.getblock(), next_x, next_y);
		//		break;
		//	}
		//	case 3: {
		//		L2 nextblock{};
		//		nextblock.draw(nextblock.getblock(), next_x, next_y);
		//		break;
		//	}
		//	case 4: {
		//		T nextblock{};
		//		nextblock.draw(nextblock.getblock(), next_x, next_y);
		//		break;
		//	}
		//	case 5: {
		//		Z1 nextblock{};
		//		nextblock.draw(nextblock.getblock(), next_x, next_y);
		//		break;
		//	}
		//	case 6: {
		//		Z2 nextblock{};
		//		nextblock.draw(nextblock.getblock(), next_x, next_y);
		//		break;
		//	}
		//	}
		//	switch (now) {
		//	case 0: {
		//		O nowblock{};
		//		while (!land) {
		//			getcmd(nowblock, nowblock.getblock());//放在绘图前边保证结束时也可以看到最后一块方块
		//			BeginBatchDraw();          //使用批量绘图解决频闪问题
		//			drawBGL();
		//			drawmap();
		//			nowblock.draw(nowblock.getblock(), x, y);
		//			EndBatchDraw();			   //结束批量绘图

		//		}
		//		record(nowblock);
		//		break;
		//	}
		//	case 1: {
		//		I nowblock{};
		//		while (!land) {
		//			getcmd(nowblock, nowblock.getblock());
		//			BeginBatchDraw();
		//			drawBGL();
		//			drawmap();
		//			nowblock.draw(nowblock.getblock(), x, y);
		//			EndBatchDraw();

		//		}
		//		record(nowblock);
		//		break;
		//	}
		//	case 2: {
		//		L1 nowblock{};
		//		while (!land) {
		//			getcmd(nowblock, nowblock.getblock());
		//			BeginBatchDraw();
		//			drawBGL();
		//			drawmap();
		//			nowblock.draw(nowblock.getblock(), x, y);
		//			EndBatchDraw();

		//		}
		//		record(nowblock);
		//		break;
		//	}
		//	case 3: {
		//		L2 nowblock{};
		//		while (!land) {
		//			getcmd(nowblock, nowblock.getblock());
		//			BeginBatchDraw();
		//			drawBGL();
		//			drawmap();
		//			nowblock.draw(nowblock.getblock(), x, y);
		//			EndBatchDraw();

		//		}
		//		record(nowblock);
		//		break;
		//	}
		//	case 4: {
		//		T nowblock{};
		//		while (!land) {
		//			getcmd(nowblock, nowblock.getblock());
		//			BeginBatchDraw();
		//			drawBGL();
		//			drawmap();
		//			nowblock.draw(nowblock.getblock(), x, y);
		//			EndBatchDraw();

		//		}
		//		record(nowblock);
		//		break;
		//	}
		//	case 5: {
		//		Z1 nowblock{};
		//		while (!land) {
		//			getcmd(nowblock, nowblock.getblock());
		//			BeginBatchDraw();
		//			drawBGL();
		//			drawmap();
		//			nowblock.draw(nowblock.getblock(), x, y);
		//			EndBatchDraw();

		//		}
		//		record(nowblock);
		//		break;
		//	}
		//	case 6: {
		//		Z2 nowblock{};
		//		while (!land) {
		//			getcmd(nowblock, nowblock.getblock());
		//			BeginBatchDraw();
		//			drawBGL();
		//			drawmap();
		//			nowblock.draw(nowblock.getblock(), x, y);
		//			EndBatchDraw();

		//		}
		//		record(nowblock);
		//		break;
		//	}
		//	}

		//}

//两个模板函数必须写在main（）函数中，否则会报错"无法解析的外部指令"
//template<typename T1>

//template<typename T1>              //无需使用模板
