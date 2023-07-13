#include <bits/stdc++.h>

using namespace std;

// APPROACH 3: DP, TABULATION
// TC: O(N*4*3)
// SC: O(N*4)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Tabulation approach
    vector<vector<int>> dp(n, vector<int>(4, -1));
    // replicating the base condn
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int lastTask = 0; lastTask < 4; lastTask++)
        {
            int maxi = 0;

            for (int currTask = 0; currTask < 3; currTask++)
            {
                if (currTask != lastTask)
                {
                    int point = points[day][currTask] + dp[day - 1][currTask];
                    maxi = max(maxi, point);
                }
            }

            dp[day][lastTask] = maxi;
        }
    }

    return dp[n - 1][3];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N*4*3)
// SC: O(N) + O(N*4)
int maxPoints(int days, vector<vector<int>> &points, int lastTask, vector<vector<int>> &dp)
{
    if (days == 0)
    {
        int maxi = 0;
        for (int currTask = 0; currTask < 3; ++currTask)
        {
            if (currTask != lastTask)
                maxi = max(maxi, points[0][currTask]);
        }

        return maxi;
    }

    if (dp[days][lastTask] != -1)
        return dp[days][lastTask];

    int maxi = 0;
    for (int currTask = 0; currTask < 3; ++currTask)
    {
        if (currTask != lastTask)
        {
            int currPoints = points[days][currTask] + maxPoints(days - 1, points, currTask, dp);
            maxi = max(maxi, currPoints);
        }
    }

    return dp[days][lastTask] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    int lastTask = 3;
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return maxPoints(n - 1, points, lastTask, dp);
}

// APPROACH 1: RECURSION
// SC: O(N)
int maxPoints(int days, vector<vector<int>> &points, int lastTask)
{
    if (days == 0)
    {
        int maxi = 0;
        for (int currTask = 0; currTask < 3; ++currTask)
        {
            if (currTask != lastTask)
                maxi = max(maxi, points[0][currTask]);
        }

        return maxi;
    }

    int maxi = 0;
    for (int currTask = 0; currTask < 3; ++currTask)
    {
        if (currTask != lastTask)
        {
            int currPoints = points[days][currTask] + maxPoints(days - 1, points, currTask);
            maxi = max(maxi, currPoints);
        }
    }

    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    int lastTask = 3;
    return maxPoints(n - 1, points, lastTask);
}
