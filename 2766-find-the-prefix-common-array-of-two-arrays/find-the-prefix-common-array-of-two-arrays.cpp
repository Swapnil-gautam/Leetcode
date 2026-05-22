class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> seta;
        set<int> setb;
        vector<int> res;
        int count = 0;
        for(int i = 0; i < A.size(); i++){
            seta.insert(A[i]);
            setb.insert(B[i]);
            if(A[i] != B[i]){
                if(seta.find(B[i]) != seta.end()){
                    count++;
                }
                if(setb.find(A[i]) != setb.end()){
                    count++;
                }
            }else{
                count++;
            }

            res.push_back(count);
        }

        return res;
    }
};