// SAME AS SIEVE LOGIC 
// JUST REPLACE MULTIPLES OF PARTICULAR PRIME with that prime


vector<int> spf(int n){
    vector<int> spf(n+1);
    for(int i=1;i<=n;i++) spf[i]=i; // Initialise each element with their oen value
    // SIEVE LOGIC
    for(int i=2;i*i<=n;i++){
        if(spf[i]==i){// MEans it smallest prime factor is yet not fixed (i.e. this value is a prime)
            for(int j=i*i;j<=n;j+=i){
                if(spf[j]==j){ // MEANS already not filled by any smallest prime
                    spf[j]=i;
                }
            }
        }
    }
    return spf;
}