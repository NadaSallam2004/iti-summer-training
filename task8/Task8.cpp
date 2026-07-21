#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    float* real;
    float* img;

    static int constructorCount;
    static int destructorCount;

public:
    Complex();                              
    Complex(float real, float img);         
    Complex(const Complex& otherObj);       

    Complex& operator=(const Complex& otherObj);

    ~Complex();

    float getReal() const;
    float getImg() const;
    void setReal(float real);
    void setImg(float img);
    static int getConstructorCount();
    static int getDestructorCount();

    Complex addComplex(Complex otherObj);
    Complex subComplex(Complex otherObj);
    Complex mulComplex(Complex otherObj);
    Complex divComplex(Complex otherObj);

    Complex operator+(Complex otherObj);
    Complex operator-(Complex otherObj);
    Complex operator*(Complex otherObj);
    Complex operator/(Complex otherObj);
    Complex& operator+=(Complex otherObj);
    Complex& operator-=(Complex otherObj);

    Complex& operator++();      
    Complex operator++(int);    
    Complex& operator--();      
    Complex operator--(int);    

    bool operator==(Complex otherObj);
    bool operator!=(Complex otherObj);
    bool operator>(Complex otherObj);
    bool operator<(Complex otherObj);

    friend ostream& operator<<(ostream& out, Complex& obj);
    friend istream& operator>>(istream& in, Complex& obj);

    operator float();

    void operator()();
};

int Complex::constructorCount = 0;
int Complex::destructorCount = 0;

Complex::Complex() {
    real = new float(0);
    img = new float(0);
    constructorCount++;
}

Complex::Complex(float real, float img) {
    this->real = new float(real);
    this->img = new float(img);
    constructorCount++;
}

Complex::Complex(const Complex& otherObj) {
    real = new float(*otherObj.real);
    img = new float(*otherObj.img);
    constructorCount++;
}

Complex& Complex::operator=(const Complex& otherObj) {
    if (this == &otherObj) return *this;   

    *real = *otherObj.real;
    *img = *otherObj.img;
    return *this;
}

Complex::~Complex() {
    delete real;
    delete img;
    destructorCount++;
}

float Complex::getReal() const { return *real; }
float Complex::getImg() const { return *img; }

void Complex::setReal(float real) { *(this->real) = real; }
void Complex::setImg(float img) { *(this->img) = img; }

int Complex::getConstructorCount() { return constructorCount; }
int Complex::getDestructorCount() { return destructorCount; }

Complex Complex::addComplex(Complex otherObj) {
    return Complex(*real + *otherObj.real, *img + *otherObj.img);
}

Complex Complex::subComplex(Complex otherObj) {
    return Complex(*real - *otherObj.real, *img - *otherObj.img);
}

Complex Complex::mulComplex(Complex otherObj) {
    float r = (*real * *otherObj.real) - (*img * *otherObj.img);
    float i = (*real * *otherObj.img) + (*img * *otherObj.real);
    return Complex(r, i);
}

Complex Complex::divComplex(Complex otherObj) {
    float denom = (*otherObj.real * *otherObj.real) + (*otherObj.img * *otherObj.img);
    float r = ((*real * *otherObj.real) + (*img * *otherObj.img)) / denom;
    float i = ((*img * *otherObj.real) - (*real * *otherObj.img)) / denom;
    return Complex(r, i);
}

Complex Complex::operator+(Complex otherObj) { return addComplex(otherObj); }
Complex Complex::operator-(Complex otherObj) { return subComplex(otherObj); }
Complex Complex::operator*(Complex otherObj) { return mulComplex(otherObj); }
Complex Complex::operator/(Complex otherObj) { return divComplex(otherObj); }

Complex& Complex::operator+=(Complex otherObj) {
    *real += *otherObj.real;
    *img += *otherObj.img;
    return *this;
}

Complex& Complex::operator-=(Complex otherObj) {
    *real -= *otherObj.real;
    *img -= *otherObj.img;
    return *this;
}

Complex& Complex::operator++() {
    (*real)++;
    (*img)++;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp(*this);
    (*real)++;
    (*img)++;
    return temp;
}

Complex& Complex::operator--() {
    (*real)--;
    (*img)--;
    return *this;
}

Complex Complex::operator--(int) {
    Complex temp(*this);
    (*real)--;
    (*img)--;
    return temp;
}

bool Complex::operator==(Complex otherObj) {
    return (*real == *otherObj.real) && (*img == *otherObj.img);
}

bool Complex::operator!=(Complex otherObj) {
    return !(*this == otherObj);
}

bool Complex::operator>(Complex otherObj) {
    float thisMag = (*real * *real) + (*img * *img);
    float otherMag = (*otherObj.real * *otherObj.real) + (*otherObj.img * *otherObj.img);
    return thisMag > otherMag;
}

bool Complex::operator<(Complex otherObj) {
    float thisMag = (*real * *real) + (*img * *img);
    float otherMag = (*otherObj.real * *otherObj.real) + (*otherObj.img * *otherObj.img);
    return thisMag < otherMag;
}

ostream& operator<<(ostream& out, Complex& obj) {
    out << *obj.real << " + " << *obj.img << "i";
    return out;
}

istream& operator>>(istream& in, Complex& obj) {
    cout << "Enter real part: ";
    in >> *obj.real;
    cout << "Enter imaginary part: ";
    in >> *obj.img;
    return in;
}

Complex::operator float() {
    return sqrt((*real * *real) + (*img * *img));
}

void Complex::operator()() {
    cout << *real << " + " << *img << "i" << endl;
}

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;
    Complex quot = c1 / c2;

    cout << "c1 + c2 = " << sum << endl;
    cout << "c1 - c2 = " << diff << endl;
    cout << "c1 * c2 = " << prod << endl;
    cout << "c1 / c2 = " << quot << endl;

    c1 += c2;
    cout << "c1 += c2 -> " << c1 << endl;
    c1 -= c2;
    cout << "c1 -= c2 -> " << c1 << endl;

    c1++;
    cout << "c1++ -> " << c1 << endl;
    ++c1;
    cout << "++c1 -> " << c1 << endl;
    c1--;
    cout << "c1-- -> " << c1 << endl;
    --c1;
    cout << "--c1 -> " << c1 << endl;

    cout << "c1 == c2 -> " << (c1 == c2) << endl;
    cout << "c1 != c2 -> " << (c1 != c2) << endl;
    cout << "c1 > c2  -> " << (c1 > c2) << endl;
    cout << "c1 < c2  -> " << (c1 < c2) << endl;

    c1();

    float magnitude = (float)c1;
    cout << "magnitude of c1 = " << magnitude << endl;

    Complex c3(c1);
    c3.setReal(999);           
    cout << "c3 (modified copy) = " << c3 << endl;
    cout << "c1 (unchanged)     = " << c1 << endl;

    Complex c4;
    c4 = c2;
    c4.setImg(555);            
    cout << "c4 (after = c2, then modified) = " << c4 << endl;
    cout << "c2 (unchanged)                 = " << c2 << endl;

    c3.setReal(10);
    c3.setImg(20);
    cout << "c3 after setters = " << c3 << endl;
    cout << "c3.getReal() = " << c3.getReal() << endl;
    cout << "c3.getImg()  = " << c3.getImg() << endl;

    cout << "Total constructors called: " << Complex::getConstructorCount() << endl;
    cout << "Total destructors called:  " << Complex::getDestructorCount() << endl;

    return 0;
}