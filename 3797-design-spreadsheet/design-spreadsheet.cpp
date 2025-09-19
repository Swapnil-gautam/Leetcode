class Spreadsheet {
public:
    
    unordered_map<char, vector<int>> Sheet;
    Spreadsheet(int rows) {
        for(char i = 'A'; i <='Z'; i++){
            vector<int> temp(rows+1, 0);
            Sheet[i] = temp;
            // cout << i << endl;
        }
    }
    
    void setCell(string cell, int value) {
        char col = cell[0];
        int row = stoi(cell.substr(1, cell.length()-1));
        cout << "col: " << col << " row: " << row << endl;
        Sheet[col][row] = value;
    }
    
    void resetCell(string cell) {
        char col = cell[0];
        int row = stoi(cell.substr(1, cell.length()-1));
        Sheet[col][row] = 0;
    }
    
    int getValue(string formula) {
        int sumi = 0;
        for(int i = 0; i < formula.size(); i++){
            if(formula[i] == '+'){
                sumi = i;
            }
        }
        string num1 = formula.substr(1, sumi-1);
        bool num1hasalpha = false;
        for(auto c: num1){
            if(isalpha(c)){
                num1hasalpha = true;
                break;
            }
        }
        int n1 = 0;
        if(num1hasalpha){
            char col = num1[0];
            int row = stoi(num1.substr(1, num1.length()-1));
            n1 = Sheet[col][row];
        }else{
            n1 = stoi(num1);
        }
        string num2 = formula.substr(sumi+1, formula.length()-sumi);
        bool num2hasalpha = false;
        for(auto c: num2){
            if(isalpha(c)){
                num2hasalpha = true;
                break;
            }
        }
        int n2 = 0;
        if(num2hasalpha){
            char col = num2[0];
            int row = stoi(num2.substr(1, num2.length()-1));
            n2 = Sheet[col][row];
        }else{
            n2 = stoi(num2);
        }

        // cout << "num1: " << num1 << " num2 " << num2 << endl;
        // cout << "n1: " << n1 << " n2 " << n2 << endl;
        return n1 + n2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */