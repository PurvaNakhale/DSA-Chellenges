int subarraySum(vector<int>& nums, int k) {
      int n = nums.size();
      int count = 0;
      int sum = 0;
      
      for(int i=0; i<n; i++){
        sum = nums[i];
        if(sum == k){
            count++;
        }
        for(int j=i+1; j<n; j++){
            sum += nums[j];

            if(sum == k){
                count++;
            }
        }
      }

      return count;
    }