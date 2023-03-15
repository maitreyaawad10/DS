#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &stations, int k, double d){
    int cnt = 0;
    
    for(int i = 1; i < stations.size(); ++i)
        cnt += (int) (stations[i] - stations[i - 1]) / d;
    
    return cnt <= k;
}

double findSmallestMaxDist(vector<int> &stations, int k){
    double eps = 1e-6;
    double s = 0, e = stations[stations.size() - 1] - stations[0];
    double ans = e;
    
    while(e - s > eps){
        double mid = s + (e - s) / 2.0;
        
        if(isPossible(stations, k, mid)){
            ans = mid;
            e = mid;
        }

        else
            s = mid;
    }
    
    return ans;
}

int main(){
    vector<int> stations = {3,6,12,19,33,44,67,72,89,95};
    int k = 2;

    cout << findSmallestMaxDist(stations, k) << endl; 

    return 0;
}


/*
class Solution {

    /**given an array of stations which denotes the position of stations and we have 

    to add k more gas stations between the maximum distance between adjacent stations

    such that the distance can be minimized ,after performing such we need to return

    the maximum difference between adjacent stations after that.

    we need to return result till exactly two decimal point */

    

    /** e:g -> 1 5 10 , k =1 , we will add the station between 5 and 10 having maximum

    difference, after adding the diff between stations in 5 and 10 become 2.5 ,2.5

    and hence after it we observe maximum distance is 4 i.e 5 - 1*/

//   public static double findSmallestMaxDist(int stations[],int k) {

      

//       /**use binary search O(nlog(upperbound)-> keeping lower bound as 0, as diff can be in decimal and

//       the maximum difference we can have is lastvalofarray - firsval */

      

//       //lower and upperbound -> denotes the value can be our maximum after minimizing

//       //the maximum distance

//          double low=0,high=stations[stations.length-1]-stations[0];

 

//      //we will consider the decimal point till 1e-6 i.e 10^-6 -> giving in question

//         while((high-low)>1e-6){

 

//             double mid=(low + high)/2.0;

 

// //if possible for given mid be the maximum distance between two stations,than check

// //for than check a value in lower bound

 

//             if(isPossible(mid,stations,k))high=mid;

 

// //if not possible look for value in upper bound

//             else low=mid;

 

//         }

 

        // return low+0.000001;

 

//   }

  

//   public static boolean isPossible(double dist,int[]stations, int k){

 

        // int stationsToAdd=0;

 

        // for(int i=0;i<stations.length-1;i++){

            //can for dist as maximum distance,we add k stations to minimize max distnace between

            //stations

//             stationsToAdd+=Math.floor((stations[i+1]-stations[i])/dist);

//         }

//         return stationsToAdd<=k;

 

//     }

// }

// */