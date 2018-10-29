#include<bits/stdc++.h>
using namespace std;
const int Board_size=1e6+1;
const int Play_Number=11;
bool play_win[Play_Number];
bool play_dir[Play_Number];
struct Play_pos
{
    int x;
    int y;
}play_pos[Play_Number];
const int Snaker_Number=2e5+1;
int board_size;
int play_num;
vector<int>play_keep;
int snaker_number;
int ladder_num;
class HashTabel
{
public:
    int x,y;
    int ex,ey;
    HashTabel *next;
    HashTabel()
    {
        next=NULL;
    }
};
const int N=2e6+1;
const int LEN=199999;
HashTabel *Hash[N];
void insert_Hash(int i,int j,int x,int y)
{
    long long int pos1=i;
    long long int pos2=j;
    int pos=(pos1*Board_size+pos2)%LEN;//哈希表乘法，平方很多种
    if(!Hash[pos])
    {
        HashTabel *t=new HashTabel;
        t->x=i;
        t->y=j;
        t->ex=x;
        t->ey=y;
        Hash[pos]=t;
    }
    else
    {
        HashTabel *t;
        t=Hash[pos];
        while(t->next)
        {
            t=t->next;
        }
        t->next=new HashTabel;
        t->next->x=i;
        t->next->y=j;
        t->next->ex=x;
        t->next->ey=y;
    }
}
HashTabel* findHash(int x,int y)
{
    long long int pos1=x;
    long long int pos2=y;
    long long int pos=(pos1*Board_size+pos2)%LEN;
    if(!Hash[pos])
        return NULL;
    HashTabel *t;
    t=Hash[pos];
    while(t)
    {
        int a=t->x;
        int b=t->y;
        if(a==x&&b==y)
            return  t;
        t=t->next;
    }
    return NULL;
}
void go(int i,int dx,int &de)
{
    //棋盘好怪
    bool dir=play_dir[i];//false向右
    if(1)//解决TLE,不改过6，改了过8,越改越错
    {
        while(dx--)
        {
            if(!dir)
            {
                play_pos[i].x++;
            }
            else
            {
                play_pos[i].x--;
            }
            if(play_pos[i].x==board_size+1)
            {
                dir=true;//向左
                play_dir[i]=dir;
                play_pos[i].y++;
                play_pos[i].x--;
            }else if(play_pos[i].x==0)
            {
                if(play_pos[i].y==board_size)
                {
                    play_win[i]=true;
                    play_keep.erase(play_keep.begin()+de);
                    de--;
                    return;
                }
                else
                {
                    dir=false;
                    play_dir[i]=dir;
                    play_pos[i].y++;
                    play_pos[i].x++;
                }
            }
        }
    }else//多步节省时间
    {
        if(!dir)//向右
        {
            play_pos[i].x+=dx;
            if(play_pos[i].x>board_size)
            {
                //改方向
                dir=true;//向左
                play_dir[i]=dir;
                play_pos[i].x-=(play_pos[i].x-board_size);
                play_pos[i].x++;
                play_pos[i].y++;
            }
        }
        else
        {
            play_pos[i].x-=dx;
            if(play_pos[i].x<=0&&play_pos[i].y==board_size)//over
            {
                play_win[i]=true;
                play_keep.erase(play_keep.begin()+de);
                de--;
                return;
            }
            else if(play_pos[i].x<0)
            {
                dir=false;//向右
                play_dir[i]=dir;
                play_pos[i].x=-play_pos[i].x;
                play_pos[i].x--;
                play_pos[i].y++;
            }
        }
    }
    //滑行
    HashTabel *t;
    t=findHash(play_pos[i].x,play_pos[i].y);
    while(t!=NULL)
    {
        play_pos[i].x=t->ex;//滑行终点
        play_pos[i].y=t->ey;
        if(play_pos[i].y%2)
        {
            dir=false;//向右
            play_dir[i]=dir;
        }
        else
        {
            dir=true;
            play_dir[i]=dir;
        }
        t=findHash(play_pos[i].x,play_pos[i].y);
    }
}
int main()
{
    cin>>board_size>>play_num>>snaker_number;
    int num=snaker_number;
    int i,j,x,y;
    memset(Hash,0,sizeof(Hash));
    while(num--)
    {
        scanf("%d%d%d%d",&i,&j,&x,&y);
        insert_Hash(i,j,x,y);
    }
    cin>>ladder_num;
    num=ladder_num;
    while(num--)
    {
        scanf("%d%d%d%d",&i,&j,&x,&y);
        insert_Hash(i,j,x,y);
    }
    //初始化人物
    memset(play_win,0,sizeof(play_win));
    memset(play_pos,0,sizeof(play_pos));
    for(int i=0;i<play_num;i++)
    {
        play_pos[i].y=1;//起点
    }
    memset(play_dir,0,sizeof(play_dir));
    int K;
    cin>>K;
    play_keep.clear();
    for(int i=0;i<play_num;i++)
    {
        play_keep.push_back(i);
    }
    for(i=0,j=0;i<K;i++,j++)
    {
        int len=play_keep.size();
        if(len==0)
            break;
        //j=j%int(play_keep.size());
        j%=len;
        scanf("%d%d",&x,&y);
        if(len>0)
        {
            go(play_keep[j],x+y,j);
        }
    }
    for(;i<K;i++)
    {
        scanf("%d%d",&x,&y);
    }
    for(int i=0;i<play_num;i++)
    {
        if(play_win[i])
            cout<<i+1<<" winner"<<endl;
        else
            cout<<i+1<<" "<<play_pos[i].x<<" "<<play_pos[i].y<<endl;
    }
}
