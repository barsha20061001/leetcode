class Solution {
    double r, xc, yc;
    public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        xc = x_center;
        yc = y_center;}
vector<double> randPoint() {
        double theta = ((double)rand() / RAND_MAX) * 2.0 * acos(-1);
        double len = sqrt((double)rand() / RAND_MAX) * r;
 return {xc + len * cos(theta), yc + len * sin(theta)};}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */