#pragma once
#include <cmath>
#include <ostream>

class Fraction {
    private:
        int numerator;
        int denominator;

        void reduce();

    public:
        Fraction(int numerator, int denominator);
        Fraction(const Fraction &ref);

        [[nodiscard]] int getNumerator() const;
        void setNumerator(int numerator);
        [[nodiscard]] int getDenominator() const;
        void setDenominator(int denominator);
        void set(int numerator, int denominator);
        void set(const Fraction &that);

        bool operator== (const Fraction &that) const;
        bool operator<= (const Fraction &that) const;
        bool operator>= (const Fraction &that) const;
        bool operator<  (const Fraction &that) const;
        bool operator>  (const Fraction &that) const;

        Fraction& operator+= (const Fraction &that);
        Fraction& operator-= (const Fraction &that);
        Fraction& operator*= (const Fraction &that);
        Fraction& operator/= (const Fraction &that);

        Fraction& operator++ ();
        Fraction& operator-- ();
        Fraction  operator++ (int x);
        Fraction  operator-- (int x);

        Fraction  operator+  (const Fraction &that) const;
        Fraction  operator-  (const Fraction &that) const;
        Fraction  operator*  (const Fraction &that) const;
        Fraction  operator/  (const Fraction &that) const;

        Fraction  operator~  () const;
        friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction);
};



