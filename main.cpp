#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
//#include <helloworld.h>

struct toado {
	int x, y;
};

struct flap {
	toado td;
} bird;

struct Barrier {
	toado br[10];
}BR;

void start()
{
	bird.td.x=50;
	bird.td.y=250;
	for(int i=0;i<5;i++)
	{
		BR.br[i].x= 900 + i*300;
		BR.br[i].y=rand()%200+240;
	}
}

void control()
{
	bird.td.y+=1;
	if(kbhit()){
		getch();
		bird.td.y -= 60;
	}
}

void BIRD()
{
	setfillstyle(1,14); setcolor(14); fillellipse(bird.td.x,bird.td.y,25,18);		//Than chim
	setfillstyle(1,15); setcolor(15); fillellipse(bird.td.x+12,bird.td.y-9,8,4); 	//Mat
	setfillstyle(1,0); setcolor(0); fillellipse(bird.td.x+12,bird.td.y-9,2,2); 		//Mat den
	setfillstyle(1,4); setcolor(4); fillellipse(bird.td.x-13,bird.td.y,15,11);		//Canh
	setcolor(0); setlinestyle(1,2,3); line(bird.td.x+15,bird.td.y,bird.td.x+30,bird.td.y);
}
void DLBIRD()
{
	setfillstyle(1,0); setcolor(0); fillellipse(bird.td.x,bird.td.y,25,18);		//Than
	setfillstyle(1,0); setcolor(0); fillellipse(bird.td.x+12,bird.td.y-9,8,4); 	//Mat
	setfillstyle(1,0); setcolor(0); fillellipse(bird.td.x-13,bird.td.y,15,11);	//Canh
}

void display()
{
	for(int i=0;i<5;i++) 	//xoa
	{
		setfillstyle(1,0);
		bar(BR.br[i].x,BR.br[i].y,BR.br[i].x+40,450);
		bar(BR.br[i].x,BR.br[i].y-190,BR.br[i].x+40,BR.br[i].y-400);

	}
	for(int i=0;i<5;i++)	//refresh new
	{
		
		BR.br[i].x--;
		if(BR.br[i].x == -20) {
			BR.br[i].x = 1200;
			BR.br[i].y=rand()%200 + 200;
		}
	}
	for(int i=0;i<5;i++) //ve
	{
		setfillstyle(1,2);
		bar(BR.br[i].x,BR.br[i].y,BR.br[i].x+40,450);
		bar(BR.br[i].x,BR.br[i].y-190,BR.br[i].x+40,BR.br[i].y-400);

	}
}
void gameover(bool &thua)
{
	for(int i=0;i<5;i++)
	{
		if((BR.br[i].x<bird.td.x && BR.br[i].x+40>bird.td.x)&&(bird.td.y>BR.br[i].y || bird.td.y<BR.br[i].y-190)) thua = true;
		else if(bird.td.y<0||bird.td.y>450) thua = true;
	}
}
int main()
{
	initwindow(1200,600);	
	bool thua = false;
	int a;
	start();
	BIRD();
	setfillstyle(1,0); bar(0,0,1200,600);
	setfillstyle(1,15); bar(0,450,1200,600);
	setcolor(12); settextstyle(6,0,9); setbkcolor(15); outtextxy(150,460,"Flappy Bird CRF");
	getch();
	while(thua == false)
	{
		DLBIRD();
		control(); 
		BIRD();
		display();
		gameover(thua);
		for(int i=0;i<2000000;i+=1);
	}
	setfillstyle(1,0); bar(0,0,1200,600);
	setbkcolor(0); settextstyle(6,0,9);
	setcolor(12); outtextxy(100,200,"GAME OVER"); delay(5000);
	fflush(stdin);
	setfillstyle(1,0); bar(0,0,1200,600);
	getch();
}
