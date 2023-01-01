class Solution {
public:
    string getHint(string secret, string guess) {

        int bulls = 0;
        int cows = 0;
        set<int> seen;
        string ans;
        unordered_map<int,int> ump1;
        unordered_map<int,int> ump2;


        for(int i = 0; i < secret.size() ; i++){
            if(secret[i]==guess[i]){
            bulls++;

            }else{
                ump1[stoi(to_string(secret[i]))]++;
                ump2[stoi(to_string(guess[i]))]++;
            }
        }

        for(auto &itr:ump1){
            if(ump2.count(itr.first) != 0){
                cows+=min(itr.second,ump2[itr.first]);
            }
        }

        ans=to_string(bulls)+"A"+to_string(cows)+"B";
        return ans;



        
    }
};
