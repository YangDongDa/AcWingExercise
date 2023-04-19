#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main (int argc, char *argv[])
{
    string s;
    while (cin >> s)
    {
        // cin >> s;
        int skew = 0;
        int k = 2;
        for (int i = s.length() - 1; i >= 0; i--) {
            int temp = s[i] - '0';
            skew = skew + temp * (k - 1);
            k = k * 2;
            
        }

        cout << skew << endl;
    }


    return 0;
}
