#include"name.h"
#include"public.h"
bool land = 0, over = 0;//�Ƿ����/������Ϸ
bool easy = 0;          //���Ƽ�/����ģʽ
bool normal = 0;		//��������/ԭ��ģʽ
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
	initEnvironment();					//��ʼ������
	playmusic();						//��ʼ��������
	gamebegin();						//���ƿ�ʼ����
	while (!over ) {	                  
		now = next;
		next = rand() % 7;
		BeginBatchDraw();					//ʹ��������ͼ�����Ƶ������	
		drawBGR();							//�Ȼ��Ҳ౳��(ԭ��ͼƬ��ɫ)
		block[next]->draw(next_x, next_y);	//�ٻ��Ҳ���һ������
		EndBatchDraw();						//����������ͼ
		while (!over && !land) {		//����ʱ������������ѭ������˴˴�Ҳ���ж�over�Ƿ�Ϊ0		
			getcmd(*(block[now]));      //���ڻ�ͼǰ�ߣ���֤����ʱҲ���Կ������һ�鷽��	
			writeread();				//��д�ļ�����¼������������ʱ�䣬���ҿ���ʹ���ļ�������Ϸ�Ѷ�
			BeginBatchDraw();           	
			drawBGL();                  //����౳��(����ݵ÷ֲ�ͬʵ�ֲ�ͬ����ɫ��ԭ��ͼƬ��
			drawmap();					//�����п�
			block[now]->draw(x, y);		//�������
			EndBatchDraw();			    	
		}
		record(block[now]);
		changemusic();					//���ݵ÷ָı䱳������
	}
	gameover();                          //������Ϸ����¼�÷֣����ƽ��㻭�棬��ʾ��������
	Sleep(2000);
	int x = _getch();                    //������˳�
}
//�ʼ��switch��case����������Ĳ�ͬ���첻ͬ���࣬�ô��ǿ���ʵ����ɫ����������Ǵ�����ڷ���
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
		//			getcmd(nowblock, nowblock.getblock());//���ڻ�ͼǰ�߱�֤����ʱҲ���Կ������һ�鷽��
		//			BeginBatchDraw();          //ʹ��������ͼ���Ƶ������
		//			drawBGL();
		//			drawmap();
		//			nowblock.draw(nowblock.getblock(), x, y);
		//			EndBatchDraw();			   //����������ͼ

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

//����ģ�庯������д��main���������У�����ᱨ��"�޷��������ⲿָ��"
//template<typename T1>

//template<typename T1>              //����ʹ��ģ��
