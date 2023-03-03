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

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método
inline
int
Rational_t::get_num() const  {
  return num_;
}



inline
int
Rational_t::get_den() const {
  return den_;
}


  
void
Rational_t::set_num(const int num) {
  num_ = num;
}


  
void
Rational_t::set_den(const int denominador) {
  assert(denominador != 0);
  den_ = denominador;
}



inline
double
Rational_t::value() const { 
  return double(get_num()) / get_den();
}



Rational_t 
Rational_t::opposite() const { 
  return Rational_t((-1)*get_num(), get_den());
}



Rational_t
Rational_t::reciprocal() const { 
  return Rational_t(get_den(), get_num());
}



// comparaciones
bool
Rational_t::is_equal(const Rational_t& r, const double precision) const { 
  return fabs(value() - r.value()) < precision;
}



bool
Rational_t::is_greater(const Rational_t& racional, const double precision) const {
  return (value() - racional.value()) > precision;
}



bool
Rational_t::is_less(const Rational_t& racional, const double precision) const {
  return racional.is_greater(*this, precision);
}


// operaciones
Rational_t
Rational_t::add(const Rational_t& racional)const {
  return Rational_t(get_num() * racional.get_den() + get_den() * racional.get_num(), 
                    get_den() * racional.get_den());
}



Rational_t
Rational_t::substract(const Rational_t& racional) const {
  return add(racional.opposite());
}



Rational_t
Rational_t::multiply(const Rational_t& racional) const {
  return Rational_t(get_num() * racional.get_num(), get_den() * racional.get_den());
}



Rational_t
Rational_t::divide(const Rational_t& racional) const {
  return multiply(racional.reciprocal());
}


// FASE I: operadores
Rational_t
operator+(const Rational_t& racional_1, const Rational_t& racional_2) {
  return Rational_t ((racional_1.get_num() * racional_2.get_den()) + (racional_1.get_den() * racional_2.get_num()), racional_1.get_den() * racional_2.get_den());
}



Rational_t
operator-(const Rational_t& racional_1, const Rational_t& racional_2) {
  return Rational_t ((racional_1.get_num() * racional_2.get_den()) - (racional_1.get_den() * racional_2.get_num()), racional_1.get_den() * racional_2.get_den());
}



Rational_t
operator*(const Rational_t& racional_1, const Rational_t& racional_2) {
  return Rational_t (racional_1.get_num() * racional_2.get_num(), racional_1.get_den() * racional_2.get_den());
}



Rational_t
operator/(const Rational_t& racional_1, const Rational_t& racional_2) {
  return Rational_t (racional_1.get_num() * racional_2.get_den(), racional_1.get_den() * racional_2.get_num());
}



// E/S
void
Rational_t::write(ostream& os) const {
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}



void
Rational_t::read(istream& is) {
  is >> num_ >> den_;
  assert(den_ != 0);
}



ostream&
operator<<(ostream& os, const Rational_t& racional) {
  racional.write(os);
  return os;
}


istream&
operator>>(istream& is, Rational_t& racional) {
  racional.read(is);
  return is;
}