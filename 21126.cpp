#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int w1, w2, h1, h2;
    cin >> w1 >> w2 >> h1 >> h2;

    int A1 = w1 * w1;
    int A2 = w2 * w2;

    int V1 = A1 * h1;
    int V2 = A2 * h2;

    auto getHeight = [&](int vol) {
        if (vol <= V1) {
            return vol / A1;
        }
        else if (vol <= V1 + V2) {
            return h1 + (vol - V1) / A2;
        }
        else {
            return h1 + h2;
        }
    };

    int total = 0;
    int prevHeight = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;

        total += v;

        int nowHeight = getHeight(total);

        ans = max(ans, nowHeight - prevHeight);

        prevHeight = nowHeight;
    }

    cout << ans << '\n';
}