 long long int largestPrimeFactor(int N){
        long long int maxi=0;
        long long int i;
        for( i=2;i*i<=N;i++){
            while(N%i==0){
                maxi=max(maxi,i);
                N=N/i;
            }
        }
        if(N>1){
            if(N>maxi)
            maxi=N;
        }
        return maxi;
    }