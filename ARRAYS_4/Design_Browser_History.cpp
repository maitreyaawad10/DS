#include <bits/stdc++.h>

using namespace std;

// TC : O(1), SC : O(N)
class BrowserHistory {
    vector<string> visitedUrls;
    int currUrl;
    int lastUrl;

public:
    BrowserHistory(string homepage) {
        // 'homepage' is the first visited URL.
        visitedUrls.push_back(homepage);
        currUrl = 0;
        lastUrl = 0;
    }

    void visit(string url) {
        currUrl++;
        if(visitedUrls.size() > currUrl){
            // We have enough space in our array to overwrite an old 'url' entry with new one.
            visitedUrls[currUrl] = url;
        } else {
            // We have to insert a new 'url' entry at the end.
            visitedUrls.push_back(url);
        }

        // This 'url' will be last URL if we try to go forward.
        lastUrl = currUrl;
    }

    string back(int steps) {
        // Move 'currURL' pointer in left direction.
        currUrl = max(currUrl - steps, 0);
        return visitedUrls[currUrl];
    }

    string forward(int steps) {
        // Move 'currURL' pointer in right direction.
        currUrl = min(currUrl + steps, lastUrl);
        return visitedUrls[currUrl];
    }
};
