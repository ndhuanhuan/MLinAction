//http://blog.csdn.net/kangrydotnet/article/details/45971659

class Solution {  
public:  
    vector<vector<int>> combinationSum3(int k, int n) {  
        vector<vector<int>> result;  
          
        vector<int> item;  
        helper(result, item, 0, k, n);  
          
        return result;  
    }  
      
    //max是item中最大的那个数，left是还剩下的值，k是需要找的数目  
    void helper(vector<vector<int>>& result, vector<int>& item, int max, int k, int left){  
        if(item.size()==k&&left==0){  
            result.push_back(item);  
            return;  
        }  
        for(int i=max+1; i<=9&&i<=left; i++){  
            item.push_back(i);  
            helper(result, item, i, k, left-i);  
            item.pop_back();  
        }  
    }  
}; 
