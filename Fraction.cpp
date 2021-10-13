#include "Fraction.h"

int gcd (int a, int b) {
    if (a == b) return a;

    if (a > b) {
        return gcd(a - b, b);
    } else {
        return gcd(b - a, a);
    }
}

int lcm (int a, int b) {
    return abs(a / gcd(a, b) * b);
}

// ---------------------------------------

void Fraction::reduce() {
    int gcdV = gcd(abs(numerator), denominator);
    if (gcdV == 1) return;

    numerator /= gcdV;
    denominator /= gcdV;
}

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    reduce();
}

Fraction::Fraction(const Fraction &ref) {
    set(ref);
    reduce();
}

int Fraction::getNumerator() const {
    return numerator;
}

void Fraction::setNumerator(int numerator) {
    this->numerator = numerator;
    reduce();
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::setDenominator(int denominator) {
    this->denominator = denominator;
    reduce();
}

void Fraction::set(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
    reduce();
}

void Fraction::set(const Fraction &that) {
    numerator = that.numerator;
    denominator = that.denominator;
}

// ---------------------------------------

Fraction Fraction::operator+(const Fraction &that) const {
    int lcmV = lcm(denominator, that.denominator);
    return {(numerator * lcmV / denominator) + (that.numerator * lcmV / that.denominator), lcmV};
}

Fraction Fraction::operator-(const Fraction &that) const {
    int lcmV = lcm(denominator, that.denominator);
    return {(numerator * lcmV / denominator) - (that.numerator * lcmV / that.denominator), lcmV};
}

Fraction Fraction::operator*(const Fraction &that) const {
    return {numerator * that.numerator, denominator * that.denominator};
}

Fraction Fraction::operator/(const Fraction &that) const {
    return {numerator * that.denominator, denominator * that.numerator};
}

bool Fraction::operator==(const Fraction &that) const {
    return denominator == that.denominator && numerator == that.numerator;
}

bool Fraction::operator<(const Fraction &that) const {
    int lcmV = lcm(denominator, that.denominator);
    return (numerator * lcmV / denominator) < (that.numerator * lcmV / that.denominator);
}

bool Fraction::operator>(const Fraction &that) const {
    return !(*this <= that);
}

bool Fraction::operator<=(const Fraction &that) const {
    int lcmV = lcm(denominator, that.denominator);
    return (numerator * lcmV / denominator) <= (that.numerator * lcmV / that.denominator);
}

bool Fraction::operator>=(const Fraction &that) const {
    return !(*this < that);
}

Fraction Fraction::operator~() const {
    return {denominator, numerator};
}

Fraction& Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction& Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator++(int x) {
    Fraction res(numerator + denominator, denominator);
    numerator += denominator;

    return res;
}

Fraction Fraction::operator--(int x) {
    Fraction res(numerator - denominator, denominator);
    numerator -= denominator;

    return res;
}

Fraction& Fraction::operator+=(const Fraction &that) {
    set(*this + that);
    return *this;
}

Fraction& Fraction::operator-=(const Fraction &that) {
    set(*this - that);
    return *this;
}

Fraction& Fraction::operator*=(const Fraction &that) {
    set(*this * that);
    return *this;
}

Fraction& Fraction::operator/=(const Fraction &that) {
    set(*this / that);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Fraction &fraction) {
    os << "[" << fraction.numerator << "/" << fraction.denominator << "]";
    return os;
}
