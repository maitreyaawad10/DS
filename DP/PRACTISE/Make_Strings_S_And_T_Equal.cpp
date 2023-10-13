#include <bits/stdc++.h>

using namespace std;

/*
Given two strings S and T of length N.
You can perform the following operations on string S any number of times:
1) Rotate it left by 1 character. This operation costs A rupees. Rotating left means the first character of the string becomes last, the second character becomes the first, the third character becomes the second and so on.
2) Change a character of string s to any other character. This operation costs B rupees.
Find the minimum cost to make string S equal to string T.
*/
/*
INPUT :
2
3 3 4
abc
bka
5 2 3
aaabc
aabbk

OUTPUT :
7
6
*/

void rotate(string &temp)
{
    int n = temp.size();
    reverse(temp.begin(), temp.end());
    reverse(temp.begin(), temp.begin() + 2);
}

int f(int index, string s, string t, int a, int b, int n, int count)
{
    if (index < 0)
        return 0;

    if (count == n - 1)
        return 1e8;

    if (s[index] == t[index])
        return 0 + f(index - 1, s, t, a, b, n, count);
    else
    {
        int left = 1e8, rep = 1e8;
        if (count < n - 1)
        {
            string temp = s;
            rotate(temp);
            left = a + f(index, temp, t, a, b, n, count + 1);
        }
        rep = b + f(index - 1, s, t, a, b, n, count);

        return min(left, rep);
    }
}

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    string s, t;
    cin >> s >> t;

    int index = n - 1;
    int count = 0;
    int ans = f(index, s, t, a, b, n, count);
    cout << "Ans is : " << ans << endl;
}

int main()
{
    solve();

    return 0;
}
