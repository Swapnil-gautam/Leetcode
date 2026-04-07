class Robot {
public:
    int x = 0;
    int y = 0;
    int w = 0;
    int h = 0;
    int dir = 0;
    Robot(int width, int height) {
        w = width;
        h = height;
    }
    
    void step(int num) {
        int parameter = 2 * (w+h-2);
        num = num%parameter;

        if (num == 0) {
            num = parameter;
        }

        while(num > 0){
            int nx = x;
            int ny = y;

            if(dir == 0){
                // nx = nx + num;
                nx++;
            }else if(dir == 2){
                // nx = nx - num;
                nx--;
            }else if(dir == 1){
                // ny = ny + num;
                ny++;
            }else if(dir == 3){
                // ny = ny - num;
                ny--;
            }

            // cout << "nx: " << nx << " ny: " << ny << " dir: " << dir <<  endl; 

            if(nx >=0 && nx < w && ny >= 0 && ny < h){
                x = nx;
                y = ny;
                num--;
            }else{
                // if(dir == 0){
                //     nx = w-1;
                //     num = num - (w-x-1);
                // }else if(dir == 2){
                //     nx = 0;
                //     num = num - (x);
                // }else if(dir == 1){
                //     ny = h-1;
                //     num = num - (h-y-1);
                // }else if(dir == 3){
                //     ny = 0;
                //     num = num - (y);
                // }
                dir = (dir + 1)%4;
                // x = nx;
                // y = ny;
                // step(num);
            }
        }
        
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(dir == 0){
            return "East";
        }else if(dir == 2){
            return "West";
        }else if(dir == 1){
            return "North";
        }else if(dir == 3){
            return "South";
        }
        return "NULL";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */