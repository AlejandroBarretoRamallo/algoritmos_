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

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6

using namespace std;

class Rational_t
{
public:
  Rational_t(const int = 0, const int = 1);
  ~Rational_t() {}
  
  // pauta de estilo [71]: indentación a 2 espacios
  
  // getters
  int get_num() const;
  int get_den() const;
  
  // setters
  void set_num(const int);
  void set_den(const int);

  double value(void) const;
  Rational_t opposite(void) const;
  Rational_t reciprocal(void) const;

  bool is_equal(const Rational_t&, const double precision = EPSILON) const;
  bool is_greater(const Rational_t&, const double precision = EPSILON) const;
  bool is_less(const Rational_t&, const double precision = EPSILON) const;

  Rational_t add(const Rational_t&) const;
  Rational_t substract(const Rational_t&) const;
  Rational_t multiply(const Rational_t&) const;
  Rational_t divide(const Rational_t&) const;

  void write(ostream& os = cout) const;
  void read(istream& is = cin);
  
private:

  int num_, den_;
};


// sobrecarga de los operadores de E/S
ostream& operator<<(ostream& os, const Rational_t&);
istream& operator>>(istream& is, Rational_t&);

// FASE I: operadores
//Sobrecarga de operadores +,-,*,/
Rational_t operator+(const Rational_t&, const Rational_t&);
Rational_t operator-(const Rational_t&, const Rational_t&);
Rational_t operator*(const Rational_t&, const Rational_t&);
Rational_t operator/(const Rational_t&, const Rational_t&);

