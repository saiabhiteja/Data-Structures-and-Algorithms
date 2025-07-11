vector<int> method1(vector<int>& nums){
    int n = nums.size() ;
    set<int> s ;
    for(int i = 0;i<n;i++){
        s.insert(nums[i]) ;
    }
    int k = s.size() ;
    auto it = s.begin() ;
    for(int i = 0;i<k;i++){
        nums[i] = *it ;
        it++;
    }
    for(int i = k;i<n;i++){
        nums[i] = 0 ;
    }
    return nums ;
}

vector<int> method2(vector<int>& nums){
    int n = nums.size() ;
    int i = 0 ;
    int j = 1 ;
    while(j<n){
        nums[i] = nums[j] ;
        int prev = nums[i] ;
        while(j<n && nums[j] == prev)j++ ;
        i++;
    }
    return nums ;
}