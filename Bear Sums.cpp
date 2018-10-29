#include<bits/stdc++.h>
#include<iostream>
//#include<cmath>
//#include<cstring>
//#include<map>
//#include<algorithm>
//#include<numeric>
//#include<vector>
//#include<queue>

using namespace std;
const int L=2e6+1;
const int W=1e6-1;
char cur[L];
int pos[L];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(cur,0,sizeof(cur));
        memset(pos,0x3f,sizeof(pos));//初始化无穷大,可以用0xff
        int S,E;
        cin>>S>>E;
        int *a=new int[E];
        //int a[10];
        for(int i=0;i<E;i++)
        {
            scanf("%d",&a[i]);
            cur[W+a[i]]++;
            //是否存在过
            if(i<pos[W+a[i]])
            {
                pos[W+a[i]]=i;
            }//最小位置
        }
        bool ju=false;;
        for(int i=0;i<E;i++)
        {
            int num2=S-a[i];
            if(i<=pos[W+num2])
                continue;//找后面的那个对应的是不是在前面
            if(num2==a[i])
            {
                if(cur[W+num2]>1)//相同要多个1
                {
                    ju=true;
                    if(a[i]<num2)
                        cout<<a[i]<<" "<<num2<<endl;
                    else
                        cout<<num2<<" "<<a[i]<<endl;
                    break;
                }
            }
            else
            {
                if(cur[W+num2]>0)//不同只要有一个
                {
                    ju=true;
                    if(a[i]<num2)
                        cout<<a[i]<<" "<<num2<<endl;
                    else
                        cout<<num2<<" "<<a[i]<<endl;
                    break;
                }
            }

        }
        if(!ju)
        {
            cout<<"!OK"<<endl;
        }
        delete []a;
    }
}
