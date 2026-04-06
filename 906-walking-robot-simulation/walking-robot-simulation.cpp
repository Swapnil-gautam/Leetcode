class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0;
        int y = 0;
        int direction = 1;
        int maxDist = 0;
        set<pair<int, int>> obsmap;
        for(int i = 0; i < obstacles.size(); i++){
            // obsmap[{obstacles[i][0],obstacles[i][1]}] = false;
            obsmap.insert({obstacles[i][0],obstacles[i][1]});
        }
        for(int i = 0; i < commands.size(); i++){
            // cout << "k: " << commands[i] << endl;
            if(commands[i] > 0){
                int k = commands[i];
                
                while(k > 0){ 
                    int nx = x, ny = y;
                    if(direction == 0){
                        nx--;
                    }else if(direction == 1){
                        ny++;
                    }else if(direction == 2){
                        nx++; 
                    }else if(direction == 3){
                        ny--;
                    }
                    k = k -1;
                    if(obsmap.contains({nx,ny})){
                        // obsmap.erase({nx,ny});
                        // obsmap[{x,y}] = true; != obsmap.end() && obsmap[{x,y}] == false
                        break;
                    }else{
                        x = nx;
                        y = ny;
                    }

                    maxDist = max(maxDist, x*x + y*y);

                }
            }else if(commands[i] == -1){
                direction = direction+1;
                direction = direction%4;
            }else if(commands[i] == -2){
                direction = direction+3;
                direction = direction%4;
            }
            // cout << "x: " << x << " y: " << y << endl;
        }

        return maxDist;
    }
};