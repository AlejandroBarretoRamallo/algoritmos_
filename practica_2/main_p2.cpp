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
  Rational_t objeto_racional1(1, 2), objeto_racional2(3); //Crea dos objetos de la clase Rational_t

  //Se realizan las operaciones utilizando la sobrecarga de operadores
  //Se realiza la overacion y se escribe por pantalla con la funcion write
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
  Vector_t<double> vector1, vector2;  //Se crean dos vectores con numeros de tipo double
  vector1.read(), vector1.write();    //A ambos vectores se les aplica el metodo write y read
  vector2.read(), vector2.write();
  //Se imprime por pantalla el producto escalar de ambos vectores
  cout << "Producto escalar de Vector_t<double>: " << scal_prod(vector1, vector2) << endl << endl;
  //Se crean otros dos objetos de tipo vector con objetos de la clase Rational_t
  Vector_t<Rational_t> vector3, vector4;
  vector3.read(), vector3.write();  //A ambos vectores se les aplica el metodo write y read
  vector4.read(), vector4.write();
  //Se imprime por pantalla el producto escalar del tercer y cuarto vector
  cout << "Producto escalar de Vector_t<Rational_t>: " << scal_prod(vector3, vector4) << endl << endl;
  
  // FASE III
  Matrix_t<double> matriz_a, matriz_b, matriz_c; //Se crean tres objetos del tipo matriz
  matriz_a.read(), matriz_a.write();   //Se aplica a mbos objetos los metodos write y read
  matriz_b.read(), matriz_b.write();
  //Se guarda en la matriz c la multiplicacion de la matriz a y b
  matriz_c.multiply(matriz_a, matriz_b);
  cout << "Multiplicación de matrices matriz_a y matriz_b: " << endl;
  matriz_c.write();
  //Se imprime por pantalla a matriz c
  return 0;
}