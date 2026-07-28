#include <iostream>
#include <string>
#include <cmath>

using namespace std;

constexpr double pi = acos(-1); 

double degreeToRadian(double degree) {
    return degree/180*pi;
}

class vector {
public:
    double x;
    double y;

    double degrees() { return atan2(x, y)*180/pi; }
    double magnitude() { return sqrt((x*x)+(y*y)); };

    vector() {
        x = 0;
        y = 0;
    }
    vector(const double a) {
        x = a;
        y = 0;
    }
    vector(const double a, const double b) {
        x = a;
        y = b;
    }

    vector operator+(const vector a) {
        return vector(x+a.x, y+a.y);
    }

    vector operator-(const vector a) {
        return vector(x-a.x, y-a.y);
    }

    vector operator*(const vector a) {
        return vector(x*a.x, y*a.y);
    }

    vector operator/(const vector a) {
        if (a.y == 0 || a.x == 0) {
            throw -1;
        }
        return vector(x/a.x, y/a.y);
    }

};

double degrees(vector v1) { return atan2(v1.x, v1.y)*180/pi; }
double magnitude(vector v1) { return sqrt((v1.x*v1.x)+(v1.y*v1.y)); };

ostream& operator<<(ostream& out, const vector a) {
    out << a.x << ' ' << a.y;
    return out;
}

int main() {
    vector v1(36000, 0);
    vector v2(16320, 0);

    cout << magnitude(v1-v2) << endl;
    cout << (v1-v2).magnitude() << endl;
}

