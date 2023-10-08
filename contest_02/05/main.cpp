#include <string>
#include <complex>

std::string probel(std::string str) {
    std::string str1 = "";
    for (auto c : str) {
        if (c != ' ') {
            str1 = str1 + c;
        }
    }  
    return str1;
}

Complex make_complex(const std::string& input) {
    Complex complex;
    std::string str = probel(input);
    std::string aa, bb;
    int x;
    for (int i = 0;i < str.size(); i++) {
        if (str[i] == '-') {
            aa = aa + '-';
        }
        if (isdigit(str[i]) || str[i] == '.') {
            aa = aa + str[i];
            if (str[i + 1] == '-') {
                bb = bb + '-';
                x = i + 1;
                break;
            }
            else if(str[i + 1] == '+') {
                x = i + 1;
                break;
            }
        }
    }

    for (int p = x; p < str.size(); p++) {
        if (isdigit(str[p]) || str[p] == '.') {
            bb = bb + str[p];
        }
    }
    complex.re = stod(aa);
    complex.im = stod(bb);
    return complex;
}


Complex sum(const Complex& c1, const Complex& c2) {
    Complex result;
    std::complex<double> k(c1.re, c1.im);
    std::complex<double> k1(c2.re, c2.im);
    std::complex<double> summ = k + k1;

    result.re = summ.real();
    result.im = summ.imag();
    return result;
}

Complex sub(const Complex& c1, const Complex& c2) {
    Complex result;
    std::complex<double> k(c1.re, c1.im);
    std::complex<double> k1(c2.re, c2.im);
    std::complex<double> summ = k - k1;

    result.re = summ.real();
    result.im = summ.imag();
    return result;
}

Complex mul(const Complex& c1, const Complex& c2) {
    Complex result;
    std::complex<double> k(c1.re, c1.im);
    std::complex<double> k1(c2.re, c2.im);
    std::complex<double> summ = k * k1;

    result.re = summ.real();
    result.im = summ.imag();
    return result;
}

Complex div(const Complex& c1, const Complex& c2) {
    Complex result;
    std::complex<double> k(c1.re, c1.im);
    std::complex<double> k1(c2.re, c2.im);
    std::complex<double> summ = k / k1;

    result.re = summ.real();
    result.im = summ.imag();
    return result;
}

void print(const Complex& complex) {
    if (complex.re == 0) {
        std::cout << abs(complex.re);
    }
    else {
        std::cout << complex.re;
    }
    if (complex.im >= 0) {
        std::cout << "+";
    }
    if (complex.im == 0) {
        std::cout << abs(complex.im) << "j" << std::endl;
    } else { 
        std::cout << complex.im << "j" << std::endl; 
    }
}
