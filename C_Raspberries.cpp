#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> nums(n);
        for (auto &it : nums)
            cin >> it;

        if (k == 2)
        {
            bool flag = false;
            for (auto it : nums)
            {
                if (it % 2 == 0)
                {
                    flag = true;
                    break;
                }
            }
            cout << (flag ? 0 : 1) << "\n";
        }
        else if (k == 3)
        {
            int minstep = INT_MAX;
            for (auto it : nums)
            {
                minstep = min(minstep, (3 - it % 3) % 3);
            }
            cout << minstep << "\n";
        }
        else if (k == 4)
        {
            int cnt2 = 0;
            for (auto it : nums)
            {
                if (it % 4 == 0)
                    cnt2 += 2;
                else if (it % 2 == 0)
                    cnt2 += 1;
            }

            // already divisible by 4
            if (cnt2 >= 2)
            {
                cout << 0 << "\n";
                continue;
            }

            int make4 = INT_MAX;
            vector<int> evenCost;

            for (auto it : nums)
            {
                // cost to make divisible by 4
                make4 = min(make4, (4 - it % 4) % 4);

                // cost to make even
                if (it % 2 == 0)
                    evenCost.push_back(0);
                else
                    evenCost.push_back(1);
            }

            sort(evenCost.begin(), evenCost.end());

            int make2 = INT_MAX;
            if (evenCost.size() >= 2)
            {
                make2 = evenCost[0] + evenCost[1];
            }

            cout << min(make4, make2) << "\n";
        }
        else
        {
            int minstep = INT_MAX;
            for (auto it : nums)
            {
                minstep = min(minstep, (5 - it % 5) % 5);
            }
            cout << minstep << "\n";
        }
    }

    return 0;
}