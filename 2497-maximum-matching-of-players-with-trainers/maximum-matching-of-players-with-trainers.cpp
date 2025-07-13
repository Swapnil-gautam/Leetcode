class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        priority_queue<int, vector<int>, greater<int>> p_pq;
        priority_queue<int, vector<int>, greater<int>> t_pq;
        int count = 0;

        for(int i = 0; i < players.size(); i++){
            p_pq.push(players[i]);
        }

        for(int i = 0; i < trainers.size(); i++){
            t_pq.push(trainers[i]);
        }

        int i = 0;
        while(p_pq.size() != 0 && t_pq.size() != 0){

            if(p_pq.top() <= t_pq.top()){
                count = count + 1;
                p_pq.pop();
            }

            t_pq.pop();
            i++;
        }

        return count;
        
    }
};