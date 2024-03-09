// Problem statement
// Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

// You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

// For Example
// If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.


int f(int days, int last_taks_done, vector<vector<int>> &points, vector<vector<int>> &dp) {
    // base case mtlb ki mai ab tree ke last point pr hu maine niche se tree kari hai start
    if (days == 0) {
        int maxi = 0;
        for (int i = 0; i < 3; ++i) {
            if (i != last_taks_done) {
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }
    if (dp[days][last_taks_done] != -1) return dp[days][last_taks_done];

    // but agar ab mai last pr nhi hu or mujhe abhi recussion chalani hia to
    int maxi = 0;
    for (int i = 0; i < 3; ++i) {
        if (i != last_taks_done) {
            int point = points[days][i] + f(days - 1, i, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[days][last_taks_done] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    // ab dp banunga bani dp ke tle de rhaa hai
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(n - 1, 3, points, dp);
}
