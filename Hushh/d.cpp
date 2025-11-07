#include <bits/stdc++.h>
using namespace std;

int main()
{

    int num;
    if (!(cin >> num))
        return 0;
    vector<vector<int>> arr(num + 1);
    for (int i = 0; i < num - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    vector<int> A(num + 1);
    for (int i = 1; i <= num; i++)
        cin >> A[i];
    int temp = 1;
    while ((1 << temp) <= num)
        temp++;
    vector<vector<int>> temp1(temp, vector<int>(num + 1));
    vector<int> dpt(num + 1), temp2(num + 1), temp3(num + 1);
    int cnt = 0;
    function<void(int, int)> dfs = [&](int u, int p)
    {
        temp2[u] = ++cnt;
        temp1[0][u] = p ? p : u;
        for (int k = 1; k < temp; k++)
            temp1[k][u] = temp1[k - 1][temp1[k - 1][u]];
        for (int v : arr[u])
            if (v != p)
            {
                dpt[v] = dpt[u] + 1;
                dfs(v, u);
            }
        temp3[u] = ++cnt;
    };
    dpt[1] = 0;
    dfs(1, 0);
    auto isPresent = [&](int u, int v)
    { return temp2[u] <= temp2[v] && temp3[v] <= temp3[u]; };
    auto ancestor = [&](int a, int b)
    {
        if (isPresent(a, b))
            return a;
        if (isPresent(b, a))
            return b;
        for (int k = temp - 1; k >= 0; k--)
            if (!isPresent(temp1[k][a], b))
                a = temp1[k][a];
        return temp1[0][a];
    };

    vector<vector<int>> arr3(num + 1);
    for (int i = 1; i <= num; i++)
        arr3[A[i]].push_back(i);
    vector<vector<pair<int, int>>> arr2(num + 1);
    vector<int> present(num + 1, 0);
    long long ans = 0;
    for (int val = 1; val <= num; val++)
    {
        if (arr3[val].size() < 2)
            continue;
        vector<int> arr4 = arr3[val];
        for (int x : arr4)
            present[x] = 1;
        sort(arr4.begin(), arr4.end(), [&](int a, int b)
             { return temp2[a] < temp2[b]; });
        int m = arr4.size();
        for (int i = 1; i < m; i++)
        {
            int L = ancestor(arr4[i - 1], arr4[i]);
            if (!present[L])
            {
                arr4.push_back(L);
                present[L] = 2;
            }
        }
        sort(arr4.begin(), arr4.end(), [&](int a, int b)
             { return temp2[a] < temp2[b]; });
        vector<int> st;
        st.push_back(arr4[0]);
        for (size_t i = 1; i < arr4.size(); i++)
        {
            int v = arr4[i];
            while (!st.empty() && !isPresent(st.back(), v))
                st.pop_back();
            int p = st.back();
            arr2[p].push_back({v, dpt[v] - dpt[p]});
            arr2[v].push_back({p, dpt[v] - dpt[p]});
            st.push_back(v);
        }
        int root = arr4[0];
        vector<int> arr5;
        arr5.reserve(arr4.size());
        stack<int> s;
        s.push(root);
        unordered_set<int> vis;
        while (!s.empty())
        {
            int u = s.top();
            s.pop();
            if (vis.insert(u).second)
            {
                arr5.push_back(u);
                for (auto &pr : arr2[u])
                    if (!vis.count(pr.first))
                        s.push(pr.first);
            }
        }
        reverse(arr5.begin(), arr5.end());
        unordered_map<int, int> add;
        int K = arr3[val].size();
        for (int u : arr5)
            add[u] = (present[u] == 1) ? 1 : 0;
        for (int u : arr5)
        {
            for (auto &pr : arr2[u])
            {
                int v = pr.first;
                if (dpt[v] > dpt[u])
                {
                    int count = add[v];
                    ans += 1LL * count * (K - count) * pr.second;
                    add[u] += add[v];
                }
            }
        }
        for (int x : arr4)
        {
            arr2[x].clear();
            present[x] = 0;
        }
    }
    cout << ans << endl;
}