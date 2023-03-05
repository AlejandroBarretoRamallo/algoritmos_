// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include "Rational_t.hpp"
//Constructor
Rational_t::Rational_t(const int numerador, const int denominador)
{
  assert(denominador != 0);             //Comprobr que el denominador es distinto de 0
  num_ = numerador, den_ = denominador;
}



//getters
inline int Rational_t::get_num() const  {
  return num_;
}

inline int Rational_t::get_den() const {
  return den_;
}


//setters
void Rational_t::set_num(const int num) {
  num_ = num;
}

void Rational_t::set_den(const int denominador) {
  assert(denominador != 0);   //Comprobar que el denominador es distinto de 0
  den_ = denominador;
}


//Metodo para calcular el valor del numero racional
inline double Rational_t::value() const { 
  return double(get_num()) / get_den();
}


//Multiplica el numero racional por -1
Rational_t  Rational_t::opposite() const { 
  return Rational_t((-1)*get_num(), get_den());
}


//Cambia el numerador por el denominador y viceversa
Rational_t Rational_t::reciprocal() const { 
  return Rational_t(get_den(), get_num());
}



// comparaciones
//Comprueba a traves de una fórmula si los numeros son iguales
bool Rational_t::is_equal(const Rational_t& r, const double precision) const { 
  return fabs(value() - r.value()) < precision;
}


//Comprueba a traves de una formula si uno es mayor que otro
bool Rational_t::is_greater(const Rational_t& racional, const double precision) const {
  return (value() - racional.value()) > precision;
}


//Comprueba a traves de una formula si uno es menor que otro
bool Rational_t::is_less(const Rational_t& racional, const double precision) const {
  return racional.is_greater(*this, precision);
}


// operaciones
//Suma de numeros racionales
Rational_t Rational_t::add(const Rational_t& racional)const {
  return Rational_t(get_num() * racional.get_den() + get_den() * racional.get_num(), 
                    get_den() * racional.get_den());
}


//Resta de numeros racionales
Rational_t Rational_t::substract(const Rational_t& racional) const {
  return add(racional.opposite());
}


//Multiplica numeros racionales
Rational_t Rational_t::multiply(const Rational_t& racional) const {
  return Rational_t(get_num() * racional.get_num(), get_den() * racional.get_den());
}


//Divide numeros racionales
Rational_t Rational_t::divide(const Rational_t& racional) const {
  return multiply(racional.reciprocal());
}


// FASE I: operadores
//Sobrecarga del operador +
Rational_t operator+(const Rational_t& racional_1, const Rational_t& racional_2) {
  return Rational_t ((racional_1.get_num() * racional_2.get_den()) + (racional_1.get_den() * racional_2.get_num()), racional_1.get_den() * racional_2.get_den());
}


//Sobrecarga del operador -
Rational_t operator-(const Rational_t& racional_1, const Rational_t& racional_2) {
  return Rational_t ((racional_1.get_num() * racional_2.get_den()) - (racional_1.get_den() * racional_2.get_num()), racional_1.get_den() * racional_2.get_den());
}


//Sobrecarga del operador *
Rational_t operator*(const Rational_t& racional_1, const Rational_t& racional_2) {
  return Rational_t (racional_1.get_num() * racional_2.get_num(), racional_1.get_den() * racional_2.get_den());
}


//Sobrecarga del operador /
Rational_t operator/(const Rational_t& racional_1, const Rational_t& racional_2) {
  return Rational_t (racional_1.get_num() * racional_2.get_den(), racional_1.get_den() * racional_2.get_num());
}



// E/S
//Imprime el numero racional
void Rational_t::write(ostream& os) const {
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}


//Asigna valores al numerador y denominador
void Rational_t::read(istream& is) {
  is >> num_ >> den_;
  assert(den_ != 0);
}



ostream& operator<<(ostream& os, const Rational_t& racional) {
  racional.write(os);
  return os;
}


istream& operator>>(istream& is, Rational_t& racional) {
  racional.read(is);
  return is;
}