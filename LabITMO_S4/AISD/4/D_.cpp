#include <bits/stdc++.h>

using namespace std;

template<class T>
ostream& operator<<(ostream& out, const vector<T>& a) {
    for (auto& i : a) {
        out << i << " ";
    }

    return out;
}


template<class T>
T read() {
    T t;
    std::cin >> t;
    return t;
}

#define ll long long
#define ull unsigned ll

ull const logLimit = 18;
ull const limit = 1 << logLimit;

vector <int> rev;

void calcRev () {
    rev = vector <int> (limit, 0);
    for (int i = 0; i < limit; i++)
        for (int k = 0; k < logLimit; k++)
            if (i & (1 << k))
                rev[i] ^= 1 << (logLimit - k - 1);
}

using Num = complex <double>;

double const Pi = acos (-1.0);

vector <Num> z;

void calcZ () {
    z = vector <Num> (limit);
    for (int i = 0; i < limit; i++)
        z[i] = Num (cos (i * 2 * Pi / limit),
                    sin (i * 2 * Pi / limit));
}

vector <Num> fft (const vector <Num> & a0, bool inv = false) {
    vector <Num> a = a0;
    for (int i = 0; i < limit; i++)
        if (i < rev[i])
            swap (a[i], a[rev[i]]);
    if (inv)
        reverse (z.begin () + 1, z.end ());
    for (int k = 0, span = 1, step = limit / 2; k < logLimit;
         k++, span *= 2, step /= 2) {
        for (int i = 0; i < limit; i += 2 * span)
            for (int j = 0; j < span; j++) {
                int u = i + j;
                int v = i + j + span;
                Num x = a[u] + a[v] * z[j * step];
                Num y = a[u] + a[v] * z[j * step + limit / 2];
                a[u] = x;
                a[v] = y;
            }
    }
    if (inv) {
        reverse (z.begin () + 1, z.end ());
        for (int i = 0; i < limit; i++)
            a[i] /= limit;
    }
    return a;
}

vector <Num> readNumber (int n) {
    vector <Num> res (limit, Num (0));
    vector<int> s(n + 1);
    for (int i = 0; i <= n; i++) s[i] = read<int>();
    for (int i = 0; i <= n; i++)
        res[i] = Num(s[n - i]);
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    auto n = read<int>();
    string str;
    getline(cin, str);
    calcRev ();
    calcZ ();
    auto a = readNumber (n);
    auto b = readNumber (n);

    auto fa = fft (a);
    auto fb = fft (b);
    auto fc = vector <Num> (limit);
    for (int i = 0; i < limit; i++)
        fc[i] = fa[i] * fb[i];
    auto c = fft (fc, true);
    vector<int> ans(n + n + 1);
    for (int i = 0; i < ans.size(); ++i) {
        ans[ans.size() - i - 1] = (int)(c[i].real() + 0.5);
    }

    cout << ans;
    return 0;
}