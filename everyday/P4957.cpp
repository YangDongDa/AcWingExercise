#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int I[10],D[10],L[10];
bool vis[10];
bool dfs(int Last,int time){

    //递归出口,判断飞机是否全部着陆
    if(Last >= n) return true;
    
    //枚举所有飞机
    for(int i = 0; i < n; i++){

        //如果飞机已经着陆,跳过
        if(vis[i]) continue;

        //如果飞机已经过了最晚着陆时间,返回false
        if(time > I[i] + D[i]) return false;

        //如果飞机未着陆,着陆
        vis[i] = true; 

        //如果飞机在最早着陆时间之前着陆,则直接着陆
        if(time < I[i]) {
            if(dfs(Last + 1,I[i] + L[i])) return true;
        }else if(dfs(Last + 1,time + L[i])) return true;

        vis[i] = false; //还原现场
    }
    return false;

}
int main (int argc, char *argv[])
{
    // freopen("P4957.in","r",stdin);

    int T;
    cin >> T;
    while(T > 0){
        T--;
        cin >> n;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d",&I[i],&D[i],&L[i]);
        }
        memset(vis,0,sizeof(vis));
        if(dfs(0,0)) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }
    // fclose(stdin);
    return 0;
}
