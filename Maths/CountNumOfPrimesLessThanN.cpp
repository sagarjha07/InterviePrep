class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1) return 0;

        // SIEVE LOGIC
        vector<int> isPrime(n+1,1);
        isPrime[0]=0;
        isPrime[1]=0;
        for(int i=2;i*i<n;i++){
            if(isPrime[i]==1){
                for(int j=i*i;j<n;j+=i){
                    isPrime[j]=0;
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(isPrime[i]==1) ans+=1;
        }
        return ans;
    }
};