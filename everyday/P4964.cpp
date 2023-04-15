#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
int mape[1001][1001];
int r[1001],c[1001];
int main (int argc, char *argv[])
{
    
    cin>>n>>m;
    cin>>a>>b;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>mape[i][j];

        }
    }
    int max;
    int min;
    long long sum = 0;
    for(int i = 1; i <= n - a + 1; i++){
        for(int j = 1; j <= m -b + 1; j++){
            max = mape[i][j];
            min = mape[i][j];
            for(int k = i; k <= i + a - 1; k++){
                for(int l = j; l <= j + b - 1; l++){
                    if(mape[k][l] > max){
                        max = mape[k][l];
                    }
                    if(mape[k][l] < min){
                        min = mape[k][l];
                    }
            
                }
            }
            sum += max * min;

        }
    }
    cout<< sum % 998244353 <<endl;
    return 0;
}


