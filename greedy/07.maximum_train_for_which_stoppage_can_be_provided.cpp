#include <bits/stdc++.h> 
bool compareByEndTime(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

void countTrains(vector<pair<int, int>>& schedule, int& count) {
    int size = schedule.size();
    sort(schedule.begin(), schedule.end(), compareByEndTime);

    int currentStartTime = 0;
    for (int i = 0; i < size; ++i) {
        if (currentStartTime <= schedule[i].first) {
            ++count;
            currentStartTime = schedule[i].second;
        }
    }
}

int maxStop(vector<vector<int>>& trains, int n, int m) {
    vector<vector<pair<int, int>>> schedule(m, vector<pair<int, int>>());
    

    for (int i = 0; i < n; ++i) {
        int platform = trains[i][2] - 1;
        schedule[platform].push_back({trains[i][0], trains[i][1]});
    }

    int stopCount = 0;
    for (int i = 0; i < m; ++i) {
        countTrains(schedule[i], stopCount);
    }

    return stopCount;
}