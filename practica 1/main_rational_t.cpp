// AUTOR: Jose Alejandro Barreto Ramallo
// FECHA: 16 feb 2023
// EMAIL: alu0101552774@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g Rational_t.cpp main_Rational_t.cpp -o main_Rational_t

#include <iostream>
#include <cmath>

#include "rational_t.hpp"

using namespace std;

int main()
{
  // Crear 3 objetos con sus respectivos atributos, si no son especificados el numerador
  // es 0 y el denominador 1
  Rational_t objeto_1(1, 2), objeto_2(3), objeto_3;
  cout << "objeto_1.value()= " << objeto_1.value() << endl;
  cout << "objeto_2.value()= " << objeto_2.value() << endl;
  cout << "objeto_3.value()= " << objeto_3.value() << endl;
  // El prodecimiento write se lleca a cabo con el primer objeto
  objeto_1.write();
  cout << "b: ";
  // El procedimiento write se lleva a caco con el segundo objeto
  objeto_2.write();
  // El prodecimiento read se lleva  acabo con el tercer objeto
  objeto_3.read();
  cout << "c: ";
  // El prodecimiento write se lleva  acabo con el tercer objeto
  objeto_3.write();
  //Creamos 2 objetos de la clase Rational_t y le damos valores a sus atributos
  Rational_t x(1, 3), y(2, 3);
  x.write();
  y.write();
  //Comprobar si x es igual a y pasando y como parametro
  cout << "x == y? " << (x.is_equal(y) ? "true" : "false") << endl;
  //Comprobar si y es mayor que x pasando y como paramtero
  cout << "x < y? " << (x.is_greater(y) ? "true" : "false") << endl;
  //Comprobar si x es mayor que y pasando y como parametro
  cout << "x > y? " << (x.is_less(y) ? "true" : "false") << endl

  //Sumamos ambos numeros racionales
  cout << "objeto_1 + objeto_2: ";
  objeto_1.add(objeto_2).write();
  //Restamos ambos numeros racionales
  cout << "objeto_2 - objeto_1: ";
  objeto_2.substract(objeto_1).write();
  //Multiplicamos ambos numeros racionales
  cout << "objeto_1 * objeto_2: ";
  objeto_1.multiply(objeto_2).write();
  //Dividimos ambos numeros racionales
  cout << "objeto_1 / objeto_2: ";
  objeto_1.divide(objeto_2).write();
  return 0;
}