class Solution {
  public:
    int countSetBits(int n) {
        // code here
        /* 0 0 0 0
           0 0 0 1
           0 0 1 0
           0 0 1 1
           0 1 0 0
           0 1 0 1
           0 1 1 0
           0 1 1 1  4 4 4
           1 0 0 0
           1 0 0 1
           1 0 1 0 
           1 0 1 1  
           1 1 0 0       (n  +1 )/ 2
           1 1 0 1
           1 1 1 0
           1 1 1 1
           
           8 8 8 8
         */  
         
        
        int ans = 0;
        
        for(int i = 0 ;i<30;i++){
            int blocksize = (1 << (i  +1));
            int completeblock = n / blocksize;
            // if((1<<i)>n) completeblock = 0;
            ans+=completeblock * (1<<i);
            
            int remnum = n - completeblock * blocksize +  1;
            
            ans+=max(0 , remnum - (blocksize / 2));
            
            // cout<<"bit "<<i<<"-> "<<blocksize<<" "<<completeblock<<" "<<remnum<<" "<<remnum - (blocksize / 2) <<"\n";
        }
        
        return ans;
    }
};
