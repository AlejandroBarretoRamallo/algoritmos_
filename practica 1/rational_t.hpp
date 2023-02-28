// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

# define EPSILON 1e-6

using namespace std;

class Rational_t {
  // pautas de estilos [44] y [73]: primero "public" y después "private"
  public:
    // Metodos
    Rational_t(const int numerador = 0, const int denominador = 1);
    ~Rational_t() {}  

    // getters
    const int get_num();
    const int get_den();

    // setters
    void set_num(const int);
    void set_den(const int);
    const double value();
    
    bool is_equal(Rational_t&, const double precision = EPSILON);  
    bool is_greater(Rational_t&, const double precision = EPSILON);
    bool is_less(Rational_t&, const double precision = EPSILON);

    void inverso();
  
    Rational_t add(Rational_t&);                //Suma de numeros racionales
    Rational_t substract(Rational_t&);          //Resta de numeros racionales
    Rational_t multiply(Rational_t&);           //Multiplicacion de numeros racionales
    Rational_t divide(Rational_t&);             //Division de numeros racionales
  
    void write(ostream& = cout);
    void read(istream& = cin);
  
  private:
    // Atributos
    int num_, den_;
};
