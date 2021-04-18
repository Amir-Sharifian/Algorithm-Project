#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;

int n, row[maxn];

inline int random(int a, int b){
    return rand() % (b - a + 1) + a;
}

int main(){
    srand(time(0));
    n = random(100, maxn);
    cout << n << endl;
    cout.flush();
    for(int i = 0; i < n; i++)
        row[i] = random(0, n);
    sort(row, row + n);
    int questions = log2(n) + 10;
    while(questions--){
        char c;
        int i, j;
        if(!(cin >> c)){
            cout << "Insufficient interaction" << endl;
            return 1;
        }
        if(c == '?'){
            if(!(cin >> i >> j)){
                cout << "Wrong or insufficient interaction" << endl;
                return 1;
            }
            if(i < 0 || i >= n || j < 0 || j >= n){
                cout << "Incorrect indices" << endl;
                return 1;
            }
            cout << (j < row[i]) << endl;
            cout.flush();
        }
        else if(c == '!'){
            if(!(cin >> i)){
                cout << "Wrong or insufficient interaction" << endl;
                return 1;
            }
            if(i < -1 || i >= n){
                cout << "Incorrect indices" << endl;
                return 1;
            }
            if(i == -1){
                if(row[n-1] <= n / 2){
                    cout << "Accepted" << endl;
                    return 0;
                }
                cout << "Wrong Answer" << endl;
                return 1;
            }
            if(row[i] > n / 2 && (!i || row[i-1] <= n / 2)){
                cout << "Accepted" << endl;
                return 0;
            }
            cout << "Wrong Answer" << endl;
            return 1;
        }
        else{
            cout << "Wrong interaction" << endl;
            return 1;
        }
    }
    cout << "Too many questions" << endl;
    return 1;
}
