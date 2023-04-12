#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// typedef struct Element
// {
//     long V;
//     long A;
//     long B;
// } Element;
// bool cmp(Element a, Element b)
// {
//     return a.V > b.V;
// }
// Element E[10001];
int main (int argc, char *argv[])
{
    int n;
    long Max,Min,A,B;
    cin >> n;
    cin >> A >> B;
    Max = A / B;
    Min = A / (B + 1) + 1;
    for (int i = 2; i <= n; i++) {
        cin >> A >> B;
        Max = min(Max, A / B);
        Min = max(Min, A / (B + 1) + 1);
        
    }
    cout << Min<< " "<< Max << endl;

    return 0;
}

