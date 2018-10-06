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

/**
 Класс рациональной дроби
 */
class Rational {
public:
    
    // MARK: - Ортодоксальна и кононическая форма
    
    /**
     Конструктор по умолчанию
     Инициализирует экземпляр класса значениями по умолчанию.
     */
    Rational()
    : num_( 1 ), denom_( 1 )
    {}
    
    /**
     Конструктор с параметрами
     Инициализирует экземпляр класса заданными значениями.

     @param num числитель дроби
     @param denom знаменатель дроби
     */
    Rational( int num, int denom )
    : num_( num ), denom_( denom )
    {
        if( denom_ <= 0 ) {
            throw out_of_range( "Incorrect rational value denominator (should be positive)" );
        }
        simplify();
    }
    
    /**
     Конструктор копирования
     инициализирует новый экземпляр значениями указанного

     @param v экземпляр класса, копию которого надо сделать
     */
    Rational(const Rational& v)
    : num_( v.num_ ), denom_( v.denom_ )
    { }
    
    /**
     Деструктор
     Для этого класса выполнять действий при удалении экземпляра не требуется.
     */
    ~Rational() {
        
    }
    
    
    /**
     Перегрузка оператора присваивания

     @param arg2 присваиваемое значение
     @return значение переменной
     */
    Rational& operator=( const Rational& arg2 ) {
        num_ = arg2.num_;
        denom_ = arg2.denom_;
        return simplify();
    }
    
    /**
     Обеспечивает доступ к значению числителя
     
     @return значение числителя
     */
    int num() {
        return num_;
    }
    
    /**
     Обеспечивает доступ к значению знаменателя

     @return значение занминателя
     */
    int denom() {
        return denom_;
    }
    
    // MARK:- Перегрузка арифметических операций
    /**
     Перегрузка оператора присваения с суммированием

     @param arg2 второй операнд (праводопустимое выражение)
     @return значение переменной
     */
    Rational& operator+=( const Rational& arg2 ) {
        int cmnDivisor = gcd( denom_, arg2.denom_ );
        num_ = num_ * (arg2.denom_ / cmnDivisor) + arg2.num_ * (denom_ / cmnDivisor);
        denom_ = denom_ / cmnDivisor * arg2.denom_;
        return simplify();
    }
    
    /**
     Перегрузка оператора сложения

     @param arg2 второй операнд
     @return результат операции
     */
    Rational operator+( const Rational& arg2 ) const {
        Rational result( num_, denom_ );
        return result += arg2;
    }
    
    // Другие арифметические операции
    // ...
    
    
    // MARK: - Перегрузка операций отношения
    
    /**
     Перегрузка операции сравнения <

     @param arg2 второй операнд операции
     @return истина, когда текущий экземпляр меньше второго операнда
            лож в противном случае
     */
     bool operator<( const Rational& arg2 ) const {
        int cmnDivisor = gcd( denom_, arg2.denom_ );
        return num_ * (arg2.denom_ / cmnDivisor) <  arg2.num_ * (denom_ / cmnDivisor);
    }
    
    // Другие операции отношения
    // ...
    //
    
    // MARK: - Внешний интерфейс класса
    
    /**
     Перегрузка операции вывода в выходной поток

     @param out выходной поток
     @param value рациональная дробь
     @return выходной поток
     */
    friend ostream& operator << ( ostream& out, const Rational& value ) {
        int whole = value.num_/value.denom_;
        if( whole!=0 ) {
            out << value.num_/value.denom_ << " ";
            if( value.num_%value.denom_ == 0 )
                return out;
        }
        if( value.num_ != 0 ) {
            out << value.num_%value.denom_ << "\\";
            out << value.denom_;
        }
        else
            out << "0";
        
        return out;
    }
    
    /**
     Перегрузка операции ввода из входного потока

     @param in входной поток
     @param v рациональная дробь
     @return входной поток
     */
    friend istream& operator >> ( istream& in, Rational& v ) {
        
        cin >> v.num_;
        cin >> v.denom_;
        
        if( v.denom_ <= 0 ) {
            throw out_of_range( "Incorrect rational value denominator (should be positive)" );
        }
        v.simplify();
        
        return in;
    }
    
   
private:
    // MARK: - Вспомогательные функции
    
    // "Сокращение" дроби
    /**
     Упрощение дроби
     Делит числитель и знаменатель на НОД.

     @return экземпляр с
     */
    Rational& simplify() {
        int cmnDivisor = gcd( abs( num_ ), denom_ );
        num_ /= cmnDivisor;
        denom_ /= cmnDivisor;
        
        return *this;
    }
    
    /**
     НОД
     Нахождение наибольшего общего делителя для двух целых чисел.
     Ключевое слово static делает доступным функцию (поле) независимо от экземпляра.
     Возможно обращаться через имя класса.
     
     @param a целое число
     @param b второе число
     @return наибольший общий делитель
     */
    static int gcd( int a, int b ) {
        if(a == 0)
            return 1;
        
        while( a!= b )
            a > b ? a -= b : b -= a;
        
        return a;
    }
    
    // MARK: Поля класса
    /**
     Числитель дроби
     Может иметь знак
     */
    int num_;
    /**
     Знаменатель дроби
     Всегда положителен
     */
    int denom_;
};



#endif /* rational_hpp */
