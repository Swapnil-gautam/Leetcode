// class Solution {
// public:
//     int solve(string s, int x, int y){
//         if(s.length() == 0){
//             return 0;
//         }
        
//         // for x - ab
//         int n = s.length();
//         s.push_back('$');

//         string newsx = "";
//         int pointsx = 0;
//         bool lastelementcheckx = true;
//         for(int i = 0; i < n; i++){
//             lastelementcheckx = true;
//             if(s[i] == 'a' && s[i+1] == 'b'){
//                 lastelementcheckx = false;
//                 pointsx=pointsx + x;
//                 i++;
//             }else{
//                 newsx.push_back(s[i]);
//             }

//             // if(i == s.length()){
//             //     lastelementcheckx = false;
//             // }
//         }
//         // if(lastelementcheckx){
//         //     newsx.push_back(s[s.length()-1]);
//         // }

//         string newsy = "";
//         int pointsy = 0;
//         bool lastelementchecky = true;
//         for(int i = 0; i < n; i++){
//             lastelementchecky = true;
//             if(s[i] == 'b' && s[i+1] == 'a'){
//                 lastelementchecky = false;
//                 pointsy=pointsy + y;
//                 i++;
//             }else{
//                 newsy.push_back(s[i]);
//             }

//             // if(i == newsx.length()){
//             //     lastelementchecky = false;
//             // }
//         }
//         // if(lastelementchecky){
//         //     newsy.push_back(s[s.length()-1]);
//         // }

//         // cout << "pointsx: " << pointsx << " " << newsx << endl;
//         // cout << "pointsy: " << pointsy << " " << newsy << endl;

//         if(pointsx == 0 && pointsy == 0){
//             return 0;
//         }

//         if(pointsx > pointsy){
//             return pointsx  + solve(newsx, x, y);
//         }else{
//             return pointsy + solve(newsy, x, y);
//         }
        
        
        
//     }

//     int maximumGain(string s, int x, int y) {
//         return solve(s, x, y);
//         return 0;
//     }
// };


class Solution {
 public:
  int maximumGain(string s, int x, int y) {
    // The assumption that gain("ab") > gain("ba") while removing "ba" first is
    // optimal is contradicted. Only "b(ab)a" satisfies the condition of
    // preventing two "ba" removals, but after removing "ab", we can still
    // remove one "ba", resulting in a higher gain. Thus, removing "ba" first is
    // not optimal.
    return x > y ? gain(s, "ab", x, "ba", y) : gain(s, "ba", y, "ab", x);
  }

 private:
  // Returns the points gained by first removing sub1 ("ab" | "ba") from s with
  // point1, then removing sub2 ("ab" | "ba") from s with point2.
  int gain(const string& s, const string& sub1, int point1, const string& sub2,
           int point2) {
    int points = 0;
    vector<char> stack1;
    vector<char> stack2;

    // Remove "sub1" from s with point1 gain.
    for (const char c : s)
      if (!stack1.empty() && stack1.back() == sub1[0] && c == sub1[1]) {
        stack1.pop_back();
        points += point1;
      } else {
        stack1.push_back(c);
      }

    // Remove "sub2" from s with point2 gain.
    for (const char c : stack1)
      if (!stack2.empty() && stack2.back() == sub2[0] && c == sub2[1]) {
        stack2.pop_back();
        points += point2;
      } else {
        stack2.push_back(c);
      }

    return points;
  }
};