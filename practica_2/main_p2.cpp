// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "matriz_c++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g Rational_t.cpp main_p2.cpp -o main_p2

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include <iostream>
#include <cmath>

// pauta de estilo [41]: ficheros de cabecera agrupados y separados
#include "Rational_t.hpp"

#include "vector_t.hpp"

#include "matrix_t.hpp"

using namespace std;

int main() {
  Rational_t objeto_racional1(1, 2), objeto_racional2(3);

  // FASE I
  cout << "objeto_racional1 + objeto_racional2: ";
  (objeto_racional1+objeto_racional2).write();

  cout << "objeto_racional2 - objeto_racional1: ";
  (objeto_racional2-objeto_racional1).write();

  cout << "objeto_racional1 * objeto_racional2: ";
  (objeto_racional1*objeto_racional2).write();
  
  cout << "objeto_racional1 / objeto_racional2: ";
  (objeto_racional1/objeto_racional2).write();
  
  cout << endl;
  
  // FASE II
  Vector_t<double> vector1, vector2;
  vector1.read(), vector1.write();
  vector2.read(), vector2.write();
  
  cout << "Producto escalar de Vector_t<double>: " << scal_prod(vector1, vector2) << endl << endl;
  
  Vector_t<Rational_t> vector3, vector4;
  vector3.read(), vector3.write();
  vector4.read(), vector4.write();
  
  cout << "Producto escalar de Vector_t<Rational_t>: " << scal_prod(vector3, vector4) << endl << endl;
  
  // FASE III
  Matrix_t<double> matriz_a, matriz_b, matriz_c;
  matriz_a.read(), matriz_a.write();
  matriz_b.read(), matriz_b.write();
  
  matriz_c.multiply(matriz_a, matriz_b);
  cout << "Multiplicación de matrices matriz_a y matriz_b: " << endl;
  matriz_c.write();
  
  return 0;
}