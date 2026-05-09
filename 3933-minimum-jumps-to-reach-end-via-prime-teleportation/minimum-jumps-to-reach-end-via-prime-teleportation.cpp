// class Solution {
// public:
//     bool isprime(int num){
//         if(num == 1){
//             return false;
//         }
//         for(int i = 2; i*1 < num; i++){
//             if(num%i == 0){
//                 return false;
//                 break;
//             }
//         }

//         return true;
//     }

//     int solve(vector<int>& nums, unordered_map<int, vector<int>>& primeTele, int i, int jumps,vector<int>& visited){
//         cout << "i: " << i << " jumps: " << jumps << endl;
//         if( i == nums.size() -1){
//             return jumps;
//         }
//         if( i < 0 || i > nums.size() -1){
//             return INT_MAX;
//         }

//         if(visited[i] != -1){
//             return visited[i];
//         }

//         int forw = INT_MAX;
//         int back = INT_MAX;
//         int tele = INT_MAX;

//         forw = solve(nums, primeTele, i+1, jumps+1, visited);
//         back = solve(nums, primeTele, i-1, jumps+1, visited);
//         if(primeTele.find(nums[i]) != primeTele.end()){
//             for( int j = 0; j < primeTele[nums[i]].size(); j++){
//                 tele = min(tele, solve(nums, primeTele, j, jumps+1, visited));
//             }
//         }

//         return visited[i] = min(forw, min(back, tele));
//     }

//     int minJumps(vector<int>& nums) {

//         vector<int> visited(nums.size(), -1);
//         vector<int> primes;
//         for(int i = 0; i < nums.size(); i++){
//             if(isprime(nums[i])){
//                 // cout << nums[i] << endl;
//                 primes.push_back(i);
//             }
//         }

//         unordered_map<int, vector<int>> primeTele;
//         for(int i = 0; i < primes.size(); i++){
//             for(int j = primes[i]+1; j < nums.size(); j++){
//                 if(nums[j]%nums[primes[i]] == 0){
//                     // cout << " nums[primes[i]]: " << nums[primes[i]] << " nums[j]: " << nums[j] << endl;
//                     primeTele[primes[i]].push_back(j);
//                 }
//             }
//         }

//         return solve(nums, primeTele, 0, 0, visited); 
//     }
// };




class Solution {
public:
    vector<bool> isPrime;
    
    void buildSieve(int maxEl) {
        //fill isPrime
        isPrime.resize(maxEl+1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int num = 2; num*num <= maxEl; num++) {
            if(isPrime[num]) {

                for(int multiple = num*num; multiple <= maxEl; multiple += num) {
                    isPrime[multiple] = false;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp; //element -> indices
        int maxEl = 0;
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            maxEl = max(maxEl, nums[i]);
        }

        //build isPrime vector using Sieve
        buildSieve(maxEl); //O(maxEL * loglog(maxEl));

        queue<int> que;
        vector<bool> visited(n, false);
        que.push(0);
        visited[0] = true;

        unordered_set<int> seen;

        int steps = 0;
        //We visite each node only once - O(n)
        //O(n + maxEL * loglog(maxEl));
        while(!que.empty()) {
            int size = que.size();
            
            while(size--) {
                int i = que.front();
                que.pop();

                if(i == n-1) {
                    return steps;
                }

                if(i-1 >= 0 && !visited[i-1]) {
                    que.push(i-1);
                    visited[i-1] = true;
                }

                if(i+1 <= n-1 && !visited[i+1]) {
                    que.push(i+1);
                    visited[i+1] = true;
                }

                if(!isPrime[nums[i]] || seen.count(nums[i])) {
                    continue;
                }

                for(int multiple = nums[i]; multiple <= maxEl; multiple += nums[i]) {
                    if(!mp.contains(multiple)) {
                        continue;
                    }

                    for(int &j : mp[multiple]) {
                        if(!visited[j]) {
                            que.push(j);
                            visited[j] = true;
                        }
                    }
                }

                seen.insert(nums[i]);
            }

            steps++;
        }

        return steps;
    }
};

