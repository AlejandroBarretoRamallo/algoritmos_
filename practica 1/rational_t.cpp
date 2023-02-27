// AUTOR: Jose Alejandro Barreto Ramallo
// FECHA: 16 feb 2023
// EMAIL: alu0101552774@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#include "rational_t.hpp"

// Constructor
Rational_t::Rational_t(const int numerador, const int denominador) {
  assert(denominador != 0);                    //Comprobamos que el denominador es distinto de 0
  num_ = numerador, den_ = denominador;
}

// Getters
const int Rational_t::get_num() {
  return num_;
}

const int Rational_t::get_den() {
  return den_;
}

// Setters
void Rational_t::set_num(const int numerador) {
  num_ = numerador;
}

void Rational_t::set_den(const int denominador) {
  assert(denominador != 0);                 //Comprobamos que el denominador es distinto de 0
  den_ = denominador;
}

// Calcula la division del numerador entre el denominador
const double Rational_t::value() { 
  return double(get_num()) / get_den();
}

bool Rational_t::is_equal(Rational_t& r, const double precision)
{ bool resultado = fabs(value() - r.value()) < precision; //Comparar el valor absoluto de la resta con epsilon
return resultado;
}

bool Rational_t::is_greater(Rational_t& r, const double precision)
{bool resultado_ =value() - r.value() < precision;  //Comparar la resta con epsilon
return resultado_;
}

bool Rational_t::is_less(Rational_t& r, const double precision)
{bool segundo_resultado = r.value() - value() < precision;   //Comparar la resta con epsilon
 return segundo_resultado;
}

Rational_t Rational_t::add(Rational_t& r)  {
  return Rational_t (((num_ * r.get_den()) + (den_ * r.get_num())), den_ * r.get_den());
}


Rational_t Rational_t::substract(Rational_t& r) { return Rational_t ((r.get_den() * num_) - (r.get_num() * den_), den_ * r.get_den());
}

Rational_t Rational_t::multiply(Rational_t& r) { 
  return Rational_t (num_ * r.get_num(), den_ * r.get_den());
}

Rational_t Rational_t::divide(Rational_t& r) {
  return Rational_t (num_ * r.get_den(), den_ * r.get_num() );
}

// Imprime la operacion y su resultado por pantalla
void Rational_t::write(ostream& os) {
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

// Recoge los valores del numerador y del denominador
void  Rational_t::read(istream& is) {
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);    //Comprobar que el denominador es distinto de 0
}