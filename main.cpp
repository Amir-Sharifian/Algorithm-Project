#include <bits/stdc++.h>

using namespace std;

inline bool get(int x, int y) {
    cout << "? " << x << ' ' << y << '\n';
    cout.flush();
    bool a;
    cin >> a;
    return a;
}

inline void submit(int i) {
    cout << "! " << i << '\n';
    cout.flush();
}

int main() {
    int n, x, mid;
    cin >> n;
    int midx = n / 2;
    int low = 0;
    int high = n - 1;

    while (true) {
        if (high - mid == 1) {
            if (get(low, midx) == 1) {
                submit(low);
                break;
            } else {
                if (high == n - 1) {
                    if (get(high, midx) == 0) {
                        submit(-1);
                        break;
                    }
                }
                submit(high);
                break;
            }
        }
        mid = ceil((low + high) / 2);
        x = get(mid, midx);
        if (x == 0) {
            low = mid;

        } else if (x == 1) {
            high = mid;
        }
    }

}