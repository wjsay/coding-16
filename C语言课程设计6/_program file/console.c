#include<stdio.h>
#include<conio.h>
#include<windows.h>

//把光标定位到行x,列y处 
void move_point_to(int x, int y) 
{
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos={y,x};
    SetConsoleCursorPosition(handle, pos); 
}

//获取控制台光标位置的函数，行号是对的，列号可能不准 
int get_point(int *x,int *y){
	HANDLE hout;
	COORD coord;
	HANDLE gh_std_out;
    gh_std_out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bInfo;
    GetConsoleScreenBufferInfo(gh_std_out,&bInfo);
    *x=bInfo.dwCursorPosition.Y;
    *y=bInfo.dwCursorPosition.X;
}

int press_key(){
	int ch;
	getch();
	ch=getch();
	return ch;
}

