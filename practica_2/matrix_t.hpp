// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"

using namespace std;

template<class T>
class Matrix_t {
public:
  Matrix_t(const int = 0, const int = 0);   //Constructor por defecto
  ~Matrix_t();  //Constructor de copia
  
  void resize(const int, const int); //Redimensionar la matriz
  
  // getters
  int get_fila(void) const;
  int get_columna(void) const;
  
  // getters-setters
  T& at(const int, const int);
  T& operator()(const int, const int);
  
  // getters constantes
  const T& at(const int, const int) const;
  const T& operator()(const int, const int) const;
  
  // operaciones y operadores
  void multiply(const Matrix_t<T>&, const Matrix_t<T>&); //Multiplicacion de matrices

  void write(ostream& = cout) const;  //Imprimir la matriz
  void read(istream& = cin);  //Asignar valores a la matriz

private:
  int fila_, columna_; // m_ filas y n_ columnas
  Vector_t<T> v_;
  
  int pos(const int, const int) const; //Posicion de un elemento
};


//Constructor
template<class T>
Matrix_t<T>::Matrix_t(const int fila, const int columna) { 
  fila_ = fila;
  columna_ = columna;
  v_.resize(fila_ * columna_);
}


//Constructor de copia
template<class T>
Matrix_t<T>::~Matrix_t(){

}


//Metodo para cambiar el tamaño de la matriz
template<class T>
void Matrix_t<T>::resize(const int fila, const int columna) {
  assert(fila > 0 && columna > 0); //Comprobar que el numero de filas y columnas es mayor que 0
  fila_ = fila;
  columna_ = columna;
  v_.resize(fila_ * columna_); //el vector tiene m * n elementos
}


//getters
template<class T>
inline int Matrix_t<T>::get_fila() const {
  return fila_;
}

template<class T>
inline int Matrix_t<T>::get_columna() const {
  return columna_;
}


//Establecer una posicion
template<class T>
T& Matrix_t<T>::at(const int i, const int j) {
  assert(i > 0 && i <= get_fila());  //asegurarse de que la fila es mayor que cero y menor o igual que el numero de filas
  assert(j > 0 && j <= get_columna());//asegurarse de que la columna es mayor que cero y menor o igual que el numero de columnas
  return v_[pos(i, j)];
}



template<class T>
T& Matrix_t<T>::operator()(const int i, const int j) {
  return at(i, j);
}


//Establecer una posicion
template<class T>
const T& Matrix_t<T>::at(const int i, const int j) const {
  assert(i > 0 && i <= get_fila()); //asegurarse de que la fila es mayor que cero y menor o igual que el numero de filas
  assert(j > 0 && j <= get_columna()); //asegurarse de que la columna es mayor que cero y menor o igual que el numero de columnas
  return v_[pos(i, j)];
}



template<class T>
const T& Matrix_t<T>::operator()(const int i, const int j) const {
  return at(i, j);
}


//Metodo para imprimir por pantalla la matriz
template<class T>
void Matrix_t<T>::write(ostream& os) const { 
  os << get_fila() << "x" << get_columna() << endl;
  for (int i = 1; i <= get_fila(); ++i) {
    for (int j = 1; j <= get_columna(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}


//Asignar valores a la matriz
template<class T>
void Matrix_t<T>::read(istream& is) {
  is >> fila_ >> columna_;
  resize(fila_, columna_);
  for (int i = 1; i <= get_fila(); ++i)
    for (int j = 1; j <= get_columna(); ++j)
      is >> at(i, j);
}

//Metodo para establecer la posicion de un elemento
template<class T>
inline
int Matrix_t<T>::pos(const int i, const int j) const {
  assert(i > 0 && i <= get_fila());    //Comprobar que i es mayor que cero y no mayor quue el numero de filas
  assert(j > 0 && j <= get_columna());  //Comprobar que j es mayor que cero y no mayor que el numero de columnas
  return (i - 1) * get_columna() + (j - 1);
}



//Multiplicacion de matrices
template<class T>
void Matrix_t<T>::multiply(const Matrix_t<T>& A, const Matrix_t<T>& B) {
  assert(A.get_columna() == B.get_fila()); //Comprobar que las matrices pueden multiplicarse
  resize(A.get_fila(),B.get_columna());  //Redimensionar la matriz
  for(int i = 1; i <= get_fila();++i) {
    for(int j = 1; j <= get_columna(); ++j) {
      at(i,j) = 0; //EL valor inicial del elemento es 0
      for(int k = 1; k <= get_columna() + 1; ++k) {
        at(i,j) = at(i,j) + (A.at(i,k) * B.at(k,j)); //Ir sumando el elemnto a la multiplicaion de los elementos correspondientes
      }
    }
  }
}