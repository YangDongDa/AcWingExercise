#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef struct Element
{
    long V;
    long A;
    long B;
} Element;
bool cmp(Element a, Element b)
{
    return a.V > b.V;
}
Element E[10001];
int main (int argc, char *argv[])
{
    int n;
    long Max,Min;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> E[i].A >> E[i].B;
        E[i].V = E[i].A / E[i].B;
        
    }
    sort(E + 1, E + n + 1, cmp);
    Max = E[n].V;
    Min = Max; 
    // cout << Max << " ";
    while(true){
        if(Min * (E[1].B + 1) > E[1].A){
            Min--;
        }
        else{
            Min++;
            break;
        }
    }
    cout << Min<< " "<< Max << endl;

    return 0;
}

