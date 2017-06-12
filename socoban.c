#include <stdio.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define MAXSTAGE 3
#define putchxy(x,y,c) {gotoxy(x,y);putch(c);}

void DrawScreen();
BOOL TestEnd();
void Move(int dir);

char ns[18][21];
int nStage;
int nx,ny;
int nMove;

void main()
{
  int ch;
  int x,y;

setcursortype(NOCURSOR);
nStage=0;

for(;1;){
  memcpy(ns,arStage[nStage],sizeof(ns));
  for (y=0;y<18;y++){
     for (x=0;x<20;x++){
       if (ns[y][x]=='@'){
                nx=x;
                ny=y;
                ns[y][x]=' ';
}
}
}
clrscr();
nMove=0;

for(;2;){
        DrawScreen();
        ch=getch();
        if(ch==0xE0 || ch==0) {
                ch=getch();
                switch (ch) {
                case LEFT;
                case RIGHT;
                case UP;
                case DOWN;
                        Move(ch);
                        break;
                }
        } else {
                ch=tolower(ch);
                if(ch=='r') {
                        break;
                }
                if (ch=='n'){
                        if(nStage <MAXSTAGE-1) {
                                nStage++;
                        }
                        break;
                }
                if(ch=='p') {
                        if (nStage > 0) {
                                nStage--;
                        }
                        break;
                }
                if (ch=='q') {
                        setcursortype(NORMALCURSOR);
                        exit(0);
                }
        }

        if (TestEnd()) {
                clrscr();
                gotoxy(10,10);
                printf("%d ���������� Ǯ�����ϴ�. ���� ���������� �̵��մϴ�",nStage+1);
                delay(2000);
                if (nStage < MAXSTAGE-1) {
                        nStage++;
                }
                break;
        }
   }
  }
}

void DrawScreen()
{
  int x,y;
  for (y=0;y<18;y++) {
        for (x=0;x<20;x++) {
                putchxy(x,y,ns[y][x]);
                }
        }
        putchxy(nx,ny,'@');

        gotoxy(40,2);puts("SOKOBAN");
        gotoxy(40,4);puts("Q:����, R:�ٽ� ����");
        gotoxy(40,6);puts("N:����, P:����");
        gotoxy(40,8);printf("�������� : %d",nStage+1);
        gotoxy(40,10);printf("�̵� Ƚ�� : %d",nMove);
}

BOOL TestEnd()
{
  int x,y;

  for (y=0;y<18;y++) {
        for (x=0;x<20;x++) {
                if (arStage[nStage][y][x]=='.'&& ns[y][x]!='0'){
                        return FALSE;
                }
                }
        }
        return TRUE;
}

void Move(int dir)
{
  int dx=0,dy=0;

  switch (dir) {
  case LEFT;
        dx=-1;
        break;
  case RIGHT;
        dx=1;
        break;
  case UP;
        dy=-1;
        break;
  case DOWN;
        dy=1;
        break;
  }

if (ns[ny+dy][nx+dx]!='#') {
  if (ns[ny+dy][nx+dx]=='0') {
        if (ns[ny+dy*2][nx+dx*2] == '' || ns[ny+dy*2][nx+dx*2] == '.') {
          if (arStage[nStage][ny+dy][nx+dx]=='.') {
                ns[ny+dy][nx+dx]='.';
        } else {
                ns[ny+dy][nx+dx]='';
        }
        ns[ny+dy*2][nx+dx*2]='0';
        } else {
        return;
        }
        }
        nx+=dx;
        ny+=dy;
        nMove++;
        }
 }


                                                                                                                                                                                              