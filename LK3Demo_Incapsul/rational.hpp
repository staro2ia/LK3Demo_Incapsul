//
//  rational.hpp
//  LK3Demo_Incapsul
//
//  Created by Павел Тимош on 04/10/2018.
//  Copyright © 2018 Павел Тимош. All rights reserved.
//

#ifndef rational_hpp
#define rational_hpp

#include <iostream>
using namespace std;

class Rational {
public:
    // Конструктор
    Rational( int _num = 0, int _denom = 1 )
    : num( _num ), denom( _denom )
    {
        if( denom <= 0 )
            throw out_of_range( "Incorrect rational value "
                               "denominator "
                               "(should be positive)" );
        simplify();
    }
    
    // Изменение значения рациональной дроби
    Rational& assign( int _num, int _denom = 1 ) {
        num = _num;
        denom = _denom;
        
        if( denom <= 0 )
            throw out_of_range( "Incorrect rational value "
                               "denominator "
                               "(should be positive)" );
        
        simplify();
        return *this;
    }
    
    Rational& assign( const Rational& val ) {
        return assign( val.num, val.denom );
    }
    
    // Перегрузка арифметических операций
    Rational& operator+=( const Rational& arg2 ) {
        int cmnDivisor = gcd( denom, arg2.denom );
        num = num * (arg2.denom / cmnDivisor) + arg2.num * (denom / cmnDivisor);
        denom = denom / cmnDivisor * arg2.denom;
        return simplify();
    }
    
    Rational operator+( const Rational& arg2 ) const {
        Rational result( num, denom );
        return result += arg2;
    }
    
    // Другие арифметические операции
    // ...
    // Перегрузка операций отношения
    int operator<( const Rational& arg2 ) const {
        int cmnDivisor = gcd( denom, arg2.denom );
        return num * (arg2.denom / cmnDivisor) <  arg2.num * (denom / cmnDivisor);
    }
    
    // Другие операции отношения
    // ...
    // Перегрузка операции вывода в выходной поток
    friend ostream& operator << ( ostream& out, const Rational& value ) {
        int whole = value.num/value.denom;
        if( whole!=0 ) {
            out << value.num/value.denom << " ";
            if( value.num%value.denom == 0 )
                return out;
        }
        if( value.num != 0 ) {
            out << value.num%value.denom << "\\";
            out << value.denom;
        }
        else
            out << "0";
        
        return out;
    }
    
    // ...
private:
    // "Сокращение" дроби
    Rational& simplify() {
        int cmnDivisor = gcd( abs( num ), denom ); num /= cmnDivisor;
        denom /= cmnDivisor;
        return *this;
    }
    
    // Служебная функция:
    // вычисление наибольшего общего делителя
    static int gcd( int a, int b ) {
        if(a == 0)
            return 1;
        
        while( a!= b )
            a > b ? a -= b : b -= a;
        
        return a;
    }
    
    int num;        // Числитель (может иметь знак)
    int denom;      // Знаменатель (положителен)
};



#endif /* rational_hpp */
