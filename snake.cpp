#include<iostream>
#include<vector>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
using namespace std;

class food
{
    public:
    int fx;
    int fy;
    char fvalue;
    int score;
    static initialise(food &f)
    {

        f.fx=7;
        f.fy=8;
        f.fvalue='F';
        f.score=0;
    }

};
class snake
{
    public:
    int sx;
    int sy;
    char svalue;
    static void initialise(vector<snake> &s)
    {
        s[0].sx=4;
        s[0].sy=5;
        s[0].svalue='H';
        s[1].sx=4;
        s[1].sy=6;
        s[1].svalue='#';
        s[2].sx=4;
        s[2].sy=7;
        s[2].svalue='#';
        s[3].sx=4;
        s[3].sy=8;
        s[3].svalue='T';
    }

};
void print(char **gen)
{
   int i,j;
    for(i=0;i<10;i++)
    {
        for(j=0;j<40;j++)
        {
            cout<<gen[i][j];
        }
        cout<<endl;
    }

}
void initial(char **board,vector<snake> &s,food f)
{
int i,j;
for(i=0;i<10;i++)
{
    for(j=0;j<40;j++)
    {
        if(i==0 ||i==9)
        board[i][j]='~';
        else if(j==0 || j==39)
        board[i][j]='!';
        else
        board[i][j]=' ';
    }
}



    for(i=0;i<s.size();i++)
    {
        board[s[i].sx][s[i].sy]=s[i].svalue;
    }
    board[f.fx][f.fy]=f.fvalue;

}

void change(char ch,char **board,vector<snake> &s,food &f)
{
  int i,k=0,swap1,swap2;
  int fixed1=s[0].sx;
  int fixed2=s[0].sy;
  if(ch==' ')
  {
      for(i=0;i<s.size();i++)
    {
        s[i].sy--;
        if(s[i].sy==-1)
        {
            s[i].sy=39;
        }

    }
    board[s[3].sx][s[3].sy-1]=' ';
  }

  else if(ch=='W' || ch=='w')
  {
      s[0].sx--;
      if(s[0].sx==0)
        s[0].sx=9;
  }
  else if(ch=='S' || ch=='s')
  {
      s[0].sx++;
      if(s[0].sx==9)
        s[0].sx=0;
  }
  else if(ch=='D' || ch=='d')
  {
      s[0].sy++;
      if(s[0].sy==39)
        s[0].sy=0;
  }
  else if(ch=='A' || ch=='a')
  {
      s[0].sy--;
      if(s[0].sy==0)
        s[0].sy=39;
  }
  if(ch!=' ')
    for(i=1;i<s.size();i++)
    {
      swap1=s[i].sx;
      swap2=s[i].sy;
      s[i].sx=fixed1;
      s[i].sy=fixed2;
      fixed1=swap1;
      fixed2=swap2;
    }
  if(s[0].sx==f.fx && s[0].sy==f.fy)
    {
        f.fx=(rand()%8);
        f.fy=(rand()%8);
        snake s1;
        s1.sx=fixed1;
        s1.sy=fixed2;
        s1.svalue='T';
        s[s.size()-1].svalue='#';
        s.insert(s.end(),s1);
        f.score++;
    }
    else
        board[fixed1][fixed2]=' ';

}
int main()
{

char **board=new char*[10];
int i;
char ch=' ';
for(i=0;i<10;i++)
{
    board[i]=new char[40];
}
vector<snake> s(4);
snake::initialise(s);
food f;
food::initialise(f);

initial(board,s,f);


while(1)
{


    change(ch,board,s,f);
    initial(board,s,f);
    print(board);

    if(kbhit())
    {
        ch=getch();
    }
    if(int(ch)==27)
        break;
    cout<<"SCORE:"<<f.score<<endl<<endl;
    system("CLS");
    Sleep(20);
}
cout<<"Game ended"<<endl;
cout<<"Your score :"<<f.score<<endl;
system("pause");
return 0;
}
