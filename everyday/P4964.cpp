#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
int mape[1001][1001];
int rcMax[1001][1001],rcMin[1001][1001];    
// int MAX[1001][20];
// int MIN[1001][20];
long long sum = 0;
int q[1001];
void get_max(int ma[],int rc[], int a,int b){
    int head = 0;
    int tail = 0;
    for(int i = 1; i <= a; i++){
        if(tail > head && i - b + 1 > q[head]){
            head++;
        }
        while(tail > head && ma[i] > ma[q[tail -1]]) tail--;
        q[tail] = i;
        tail++;
        if(i >= b){
            rc[i - b + 1] = ma[q[head]];
        }
    }
}
void get_min(int ma[],int rc[],int a, int b){
    int head = 0;
    int tail = 0;
    for(int i = 1; i <= a; i++){
        if(tail > head && i - b + 1 > q[head]){
            head++;
        }
        while(tail > head && ma[i] < ma[q[tail -1]]) tail--;
        q[tail] = i;
        tail++;
        if(i >= b){
            rc[i - b + 1] = ma[q[head]];
        }
    }
}
// int compareMax(int a,int b){
//     int l = b - a + 1;
//     int k = log2(l);
//     return max(MAX[a][k],MAX[b -(1 << k) + 1][k]);
// }
// int compareMin(int a,int b){
//     int l = b - a + 1;
//     int k = log2(l);
//     return min(MIN[a][k],MIN[b -(1 << k) + 1][k]);
// }
int main (int argc, char *argv[])
{
    cin>>n>>m;
    cin>>a>>b;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>mape[i][j];
        }
        get_max(mape[i],rcMax[i],m,b);
        get_min(mape[i],rcMin[i],m,b);
    }
    int x[1001],y[1001],xmax[1001],xmin[1001];
    for(int i = 1; i <= m - b + 1; i++){
        for(int j = 1; j <= n; j++){
            x[j] = rcMax[j][i];
            y[j] = rcMin[j][i];
        }
        get_max(x,xmax,n,a);
        get_min(y,xmin,n,a);
        for(int j = 1; j <= n - a + 1; j++){
            // cout<<xmax[j]<<" "<<xmin[j]<<endl;
            sum = (sum + (long long)xmax[j] * xmin[j]) % 998244353; //爆int
        }

    }
    cout<<sum<<endl;
    // int k = log2(m);
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cin>>mape[i][j];
    //         MAX[j][0] = mape[i][j];
    //         MIN[j][0] = mape[i][j];
    //     }
    //     for(int j = 1; j <= k; j++){
    //         for(int l = 1; l <= m -(1 << j) + 1; l++){
    //             MAX[l][j] = max(MAX[l][j - 1],MAX[l + (1 << (j - 1))][j -1]);
    //             MIN[l][j] = min(MIN[l][j - 1],MIN[l + (1 << (j - 1))][j -1]);
    //         }
    //     }
    //     for(int j = 1; j <= m - b + 1; j++){
    //         rcMax[i][j] = compareMax(j,j + b - 1);
    //         rcMin[i][j] = compareMin(j,j + b - 1);
    //     }
    //     if(i >= a){
    //         int max,min;
    //         for(int j = 1; j <= m - b + 1; j++){
    //             max = rcMax[i][j];
    //             min = rcMin[i][j];
    //             for(int l = i; l >= i - a + 1; l--){
    //                 if(rcMax[l][j] > max){
    //                     max = rcMax[l][j];
    //                 }
    //                 if(rcMin[l][j] < min){
    //                     min = rcMin[l][j];
    //                 }
    //             }
    //             sum +=( max * min) % 998244353;
    //         }
    //
    //     }
    //         
    // }
    // cout<< sum <<endl;
    // int max;
    // int min;
    // long long sum = 0;
    // for(int i = 1; i <= n - a + 1; i++){
    //     for(int j = 1; j <= m -b + 1; j++){
    //         max = mape[i][j];
    //         min = mape[i][j];
    //         for(int k = i; k <= i + a - 1; k++){
    //             for(int l = j; l <= j + b - 1; l++){
    //                 if(mape[k][l] > max){
    //                     max = mape[k][l];
    //                 }
    //                 if(mape[k][l] < min){
    //                     min = mape[k][l];
    //                 }
    //         
    //             }
    //         }
    //         sum += max * min;
    //
    //     }
    // }
    // cout<< sum % 998244353 <<endl;
    return 0;
}


