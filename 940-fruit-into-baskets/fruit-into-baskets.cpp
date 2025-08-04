class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size();
        if(n == 1 || n == 2){
            return n;
        }

        int i = 0; 
        int j = 1; 
        int b1_count = 1;
        int b2_count = 0;
        int b1_value = fruits[i];
        int b2_value = -1;
        int maxfruitcount = 0;
        int lastContiniousCount = b1_count;
        int lastContiniousValue = b1_value;
        
        while(j < n){
            
            // cout << "1 b1_value: " << b1_value << " b2_value: " << b2_value << " lastContiniousValue: " << lastContiniousValue << " fruit[j]" << fruits[j] << endl;



            if(fruits[j] == b1_value){
                b1_count++;
            }else if(b2_value == -1){
                b2_value = fruits[j];
                b2_count++;
            }else if(fruits[j] == b2_value){
                b2_count++;
            }else{
                b1_value = lastContiniousValue;
                b1_count = lastContiniousCount;

                b2_value = fruits[j];
                b2_count = 1;
            }

            if(fruits[j] == lastContiniousValue){
                lastContiniousCount++;
            }else{
                lastContiniousValue = fruits[j];
                lastContiniousCount = 1;
            }

            // cout << "2 b1_value: " << b1_value << " b2_value: " << b2_value << " lastContiniousValue: " << lastContiniousValue << " fruit[j]" << fruits[j] << endl;

            maxfruitcount = max(maxfruitcount, b1_count+b2_count);

            j++;
            

        }

        return maxfruitcount;
    }
};