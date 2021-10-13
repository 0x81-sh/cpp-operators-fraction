#include "Fraction.h"
#include <cassert>

void test_equals(const Fraction &a, const Fraction &b);
void test_smallerEqual(const Fraction &a, const Fraction &b);
void test_smaller(const Fraction &a, const Fraction &b);
void test_largerEqual(const Fraction &a, const Fraction &b);
void test_larger(const Fraction &a, const Fraction &b);

void test_addEquals(const Fraction &a, const Fraction &b, const Fraction &result);
void test_subtractEquals(const Fraction &a, const Fraction &b, const Fraction &result);
void test_multiplyEquals(const Fraction &a, const Fraction &b, const Fraction &result);
void test_divideEquals(const Fraction &a, const Fraction &b, const Fraction &result);

void test_prefixIncrement(const Fraction &a, const Fraction &result);
void test_postfixIncrement(const Fraction &a, const Fraction &result);
void test_prefixDecrement(const Fraction &a, const Fraction &result);
void test_postfixDecrement(const Fraction &a, const Fraction &result);

void test_add(const Fraction &a, const Fraction &b, const Fraction &result);
void test_subtract(const Fraction &a, const Fraction &b, const Fraction &result);
void test_multiply(const Fraction &a, const Fraction &b, const Fraction &result);
void test_divide(const Fraction &a, const Fraction &b, const Fraction &result);

void test_invert(const Fraction &a, const Fraction &result);

int main () {
    test_equals(Fraction(99, 63), Fraction(99, 63));
    test_smallerEqual(Fraction(11, 56), Fraction(11, 56));
    test_smaller(Fraction(15, 38), Fraction(15, 37));
    test_largerEqual(Fraction(74, 21), Fraction(74, 21));
    test_larger(Fraction(24, 10), Fraction(24, 11));

    test_addEquals(Fraction(82, 108), Fraction(8, 27), Fraction(19, 18));
    test_subtractEquals(Fraction(82, 108), Fraction(8, 27), Fraction(25,54));
    test_multiplyEquals(Fraction(52, 44), Fraction(20, 81), Fraction(260, 891));
    test_divideEquals(Fraction(54, 86), Fraction(52, 43), Fraction(27, 52));

    test_prefixIncrement(Fraction(78, 20), Fraction(98, 20));
    test_postfixIncrement(Fraction(78, 20), Fraction(98, 20));
    test_prefixDecrement(Fraction(82, 67), Fraction(15, 67));
    test_postfixDecrement(Fraction(82, 67), Fraction(15, 67));

    test_add(Fraction(82, 108), Fraction(8, 27), Fraction(19, 18));
    test_subtract(Fraction(82, 108), Fraction(8, 27), Fraction(25,54));
    test_multiply(Fraction(52, 44), Fraction(20, 81), Fraction(260, 891));
    test_divide(Fraction(54, 86), Fraction(52, 43), Fraction(27, 52));

    test_invert(Fraction(14, 95), Fraction(95, 14));
}

void test_equals(const Fraction &a, const Fraction &b) {
    assert(a == b);
}
void test_smallerEqual(const Fraction &a, const Fraction &b) {
    assert(a <= b);
}
void test_smaller(const Fraction &a, const Fraction &b) {
    assert(a < b);
}
void test_largerEqual(const Fraction &a, const Fraction &b) {
    assert(a >= b);
}
void test_larger(const Fraction &a, const Fraction &b) {
    assert(a > b);
}

void test_addEquals(const Fraction &a, const Fraction &b, const Fraction &result) {
    Fraction temp(a);
    assert((temp += b) == result);
}
void test_subtractEquals(const Fraction &a, const Fraction &b, const Fraction &result) {
    Fraction temp(a);
    assert((temp -= b) == result);
}
void test_multiplyEquals(const Fraction &a, const Fraction &b, const Fraction &result) {
    Fraction temp(a);
    assert((temp *= b) == result);
}
void test_divideEquals(const Fraction &a, const Fraction &b, const Fraction &result) {
    Fraction temp(a);
    assert((temp /= b) == result);
}

void test_prefixIncrement(const Fraction &a, const Fraction &result) {
    Fraction temp(a);
    assert(++temp == result);
}
void test_postfixIncrement(const Fraction &a, const Fraction &result) {
    Fraction temp(a);
    temp++;
    assert(temp == result);
}
void test_prefixDecrement(const Fraction &a, const Fraction &result) {
    Fraction temp(a);
    assert(--temp == result);
}
void test_postfixDecrement(const Fraction &a, const Fraction &result) {
    Fraction temp(a);
    temp--;
    assert(temp == result);
}

void test_add(const Fraction &a, const Fraction &b, const Fraction &result) {
    assert(a + b == result);
}
void test_subtract(const Fraction &a, const Fraction &b, const Fraction &result) {
    assert(a - b == result);
}
void test_multiply(const Fraction &a, const Fraction &b, const Fraction &result) {
    assert(a * b == result);
}
void test_divide(const Fraction &a, const Fraction &b, const Fraction &result) {
    assert(a / b == result);
}

void test_invert(const Fraction &a, const Fraction &result) {
    assert(~a == result);
}