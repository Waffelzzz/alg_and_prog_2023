#include <cmath>

class Point {
private:
    double x1, y1, r, a;
public:
    Point(double x, double y) {
        x1 = x;
        y1 = y;

        r = sqrt(x1*x1+y1*y1);
        a = atan2(y1, x1);
    }

    double get_x() {return x1;}
    double get_y() {return y1;}
    double get_r() {return r;}
    double get_a() {return a;}

    void set_x(double nx) {
        x1 = nx;

        r = sqrt(x1*x1+y1*y1);
        a = atan2(y1, x1);
    }

    void set_y(double ny) {
        y1 = ny;

        r = sqrt(x1*x1+y1*y1);
        a = atan2(y1, x1);
    }

    void set_r(double nr) {
        r = nr;

        x1 = r * cos(a);
        y1 = r * sin(a);
    }

    void set_a(double na) {
        a = na;

        x1 = r * cos(a);
        y1 = r * sin(a);
    }
};
