class Solution {
public:

    void findCombination(int index,int target,int k,vector<vector<int>>& ans,vector<int>&ds){

        if(target==0){
            if(ds.size()==k)
            ans.push_back(ds);
            return;
        }else{
            if(ds.size()==k)
            return;
        }

        if(index>9){
            return;
        }

        if(index<=target){
            ds.push_back(index);
            findCombination(index+1,target-index,k,ans,ds);
            ds.pop_back();
        }
        findCombination(index+1,target,k,ans,ds);
   
    }

    vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(1,n,k,ans,ds);
    return ans;
        
    }
};
