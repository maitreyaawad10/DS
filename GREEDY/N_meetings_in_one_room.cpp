#include <bits/stdc++.h> 

using namespace std;


// TC : O(N log N)
// SC : O(N)
struct meeting {
    int start;
    int end;
    int pos;
};

bool cmp(struct meeting a, meeting b) {
    if(a.end < b.end)   
        return true;
    else if(a.end > b.end)      
        return false;
    else if(a.pos < b.pos)
        return true;
    else
        return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    
    struct meeting meet[n];
        
    for(int i = 0; i < n; ++i){
        meet[i].start = start[i];
        meet[i].end = end[i];
        meet[i].pos = i + 1;
    }
    
    sort(meet, meet + n, cmp);
    
    int meetCount = 0, lastMeet = -1;
    vector<int> ans;
    
    for(int i = 0; i < n; ++i){
        if(meet[i].start > lastMeet){
            meetCount++;
            ans.push_back(meet[i].pos);
            lastMeet = meet[i].end;
        }
    }
    
    return ans;
}