class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour%12;
        double h = (hour/12.0)*360 + (minutes/60.0)*30;
        double m = (minutes/60.0)*360;
        // cout << (1/2.0) << "  " << m << endl;
        // cout << h << m << endl;
        double a = min(abs(h-m), 360-abs(h-m));
        return a;
    }
};