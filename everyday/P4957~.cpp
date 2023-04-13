#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int st[1 << 10][10];//dp状态压缩
int I[10],D[10],L[10];
int main (int argc, char *argv[])
{
    int T;
    cin >> T;
    while(T > 0){
        T--;
        cin >> n;
        memset(st,1,sizeof(st));
        cout << st[0][0] << endl;
        cout << st[1][0] << endl;
        cout << st[2][0] << endl;
        for(int i = 0; i < n; i++){
            cin >> I[i] >> D[i] >> L[i];
            st[1 << i][i] = I[i] + L[i];
        }
        for(int i = 0; i < (1 << n); i++){
            for(int j = 0; j < n; j++){
                if((i << j) & 1){
                    for(int k = 0; k < n; k++){
                        if((i << k) & 1){
                            if(j != k){
                                int temp = st[i - (1 << j)][k];
                                if(temp < I[j]) st[i][j] = min(st[i][j],I[j] + L[j]);
                                else if(temp >= I[j] && temp <= I[j] + D[j] ) st[i][j] = min(st[i][j], temp + L[j]);
                            }

                        }
                    }
                }
            }
        }
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(st[(1 << n) - 1][i] != 16843009){
                flag = true;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
