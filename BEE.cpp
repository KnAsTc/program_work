#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
//407220325 郭馥銘 全部 

using namespace std;
class BEE
{
public:
    int BEE_x;//蜜蜂x 
    int BEE_y;//蜜蜂y 
    int x;//目標x 
    int y;//目標y 
    int number;//編號 
    
    BEE *next;

public:
    BEE(int a, int b, int n) : x(a), y(b), number(n), next(NULL)
    {
        BEE_x=0;//原點BEE座標 
		BEE_y=20;//原點BEE座標 
		gotoxy(BEE_x,BEE_y);//BEE原點開始 
        cout << "B" << number;
		gotoxy(x, y);//目標 
        cout << "*";
    }
    void gotoxy(int x, int y)
    {
        HANDLE hConsoleOutput;
        COORD Cursor_Pos = {x, y};
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
    }
    bool MoveTo()
    {
		gotoxy(0, 20);//原點HIVE 
        cout <<"HIVE";
		gotoxy(x, y);//重複*號避免路線重複的將其蓋掉 
        cout << "*";
		gotoxy(BEE_x, BEE_y);//將原本位置的BEE蓋掉 
        cout <<"   ";//蓋掉3位數最大到999 
        if (BEE_x < x)
            BEE_x++;
        else if (BEE_x > x)
            BEE_x--;
        if (BEE_y < y)
            BEE_y++;
        else if (BEE_y > y)
            BEE_y--;
		if (BEE_y==y && BEE_x==x){//與目標相等 
			
			gotoxy(BEE_x, BEE_y);
        	cout <<"   ";//蓋掉3位數最大到999 
			*this=*(this->next);//刪除節點 
			return 1;//返回True	
		}
		else{	
        gotoxy(BEE_x, BEE_y);//不相等，繼續下個位置，飛向目標 
        cout << "B" << number;
        _sleep(50);}//間隔50毫秒 
        return 0;
    }
};

int main()
{
    BEE *p = NULL, *q;
    int x, y;//目標的x和y 
    srand(time(NULL));
    int i =0;//計算每十個ROUNDS 
    int i_number=0;//產生第N個的編號 
    int i_temp=0;//已有多少個完成 
    int i_run=0;//有多少個BEE活著要動 
    while (1)
    {        	
		if (i%10 == 0){		
        	i_number+=1;
			x = rand() % 100 + 1;//X軸隨機目標距離  
	        y = rand() % 10 + 1;//Y軸隨機目標距離 
	        q = new BEE(x, y, i_number);//產生目標和BEE 
	        if (p == NULL)
	        { //the first BEE 
	            p = q;
	            p->next = p;
	        }
	        else
	        { 
	            q->next = p->next;
	            p->next = q;
	            p = p->next;
	        }	
		}
		i_run=i_number-i_temp;//目前總數量減去已完成 
		for(int j=0;j<i_run;j++){//將每個可以動的都輪過一次 
			if(p->MoveTo()){//相等則傳回True		
				i_temp+=1;//已完成+1 
				i_run-=1;//目前的要做的回合-1			
			}
        	p = p->next; //下一個	
		}
		i=i+1;//回合數+1 
    }
    return 0;
}
