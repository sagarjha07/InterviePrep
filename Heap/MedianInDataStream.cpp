// lEETCODE 295

class MedianFinder {
private:
    priority_queue<int> maxpart;                           //isme sab choto ka descending order rehta
    priority_queue<int, vector<int>, greater<int>> minpart;    //isme sab bade bhaiyo ka ascending order rehta
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {         
        maxpart.push(num);              // maxpart mey num jaata, waha sort hojata. 
        minpart.push(maxpart.top());    //Phir, maxpart ke top (largest) ku min part mey daalrai
        maxpart.pop();                  //bade bhai ku maxpart se nikaaldo    -> min mey neeche chalejaata 
        if(maxpart.size() < minpart.size()){     //agar bade bhailog zyada hogaye minpart mey 
            maxpart.push(minpart.top());        //toh unmese sabse chote bade bhai ku choto mey daaldo
            minpart.pop();                      //nikaaldo usku phir
        }
    }
    
    double findMedian() {
        if(maxpart.size() > minpart.size()) //odd number length hai toh hota, aur humesha maxpart(chote's desc.order) ku bada rakhrai
            return maxpart.top();   //odd length aaya toh odd one out apne choto mey se rehta, unka sabse bada wala apna banda 
        return (maxpart.top()+minpart.top())/2.0;    //even length aaya toh, choto ke bade aur bado ke chote ka avg hai ans
    }
};