#include <cmath>

class Complex {
public:
    std::string comp;
    double re;
    double im;

    Complex(std::string num) {
        comp = num;
        probel();
        make_complex();
    }

    void probel() {
        std::string str1 = "";
        for (auto c : comp) {
            if (c != ' ') {
                str1 += c;
            }
        }
        comp = str1;
    }

    void make_complex() {
        std::string aa, bb;
        int x;
        for (int i = 0; i < comp.size(); i++) {
            if (comp[i] == '-') {
                aa = aa +  '-';
            }
            if (isdigit(comp[i]) || comp[i] == '.') {
                aa = aa + comp[i];
                if (comp[i + 1] == '-') {
                    bb += '-';
                    x = i + 1;
                    break;
                }
                else if (comp[i + 1] == '+') {
                    x = i + 1;
                    break;
                }
            }
        }

        for (int p = x; p < comp.size(); p++) {
            if (isdigit(comp[p]) || comp[p] == '.') {
                bb += comp[p];
            }
        }
        re = stod(aa);
        im = stod(bb);
    }

    Complex operator+(const Complex& other) const {
        return Complex(std::to_string(re + other.re) + (im + other.im < 0 ? "" : "+") + std::to_string(im + other.im) + "j");
    }

    Complex operator-(const Complex& other) const {
        return Complex(std::to_string(re - other.re) + (im - other.im < 0 ? "" : "+") + std::to_string(im - other.im) + "j");
    }

    Complex operator*(const Complex& other) const {
        double new_re = re * other.re - im * other.im;
        double new_im = re * other.im + im * other.re;
        return Complex(std::to_string(new_re) + (new_im < 0 ? "" : "+") + std::to_string(new_im) + "j");
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.re * other.re + other.im * other.im;
        double new_re = (re * other.re + im * other.im) / denominator;
        double new_im = (im * other.re - re * other.im) / denominator;
        return Complex(std::to_string(new_re) + (new_im < 0 ? "" : "+") + std::to_string(new_im) + "j");
    }
};

std::ostream& operator<<(std::ostream& out, const Complex& num) {
    out << (num.re == 0.0 ? 0.0 : num.re)
        << (num.im < 0 ? "" : "+")
        << (num.im == 0.0 ? 0.0 : num.im) << 'j';
    return out;
}
