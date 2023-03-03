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
  Matrix_t(const int = 0, const int = 0);
  ~Matrix_t();
  
  void resize(const int, const int);
  
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
  void multiply(const Matrix_t<T>&, const Matrix_t<T>&);

  void write(ostream& = cout) const;
  void read(istream& = cin);

private:
  int fila_, columna_; // m_ filas y n_ columnas
  Vector_t<T> v_;
  
  int pos(const int, const int) const;
};



template<class T>
Matrix_t<T>::Matrix_t(const int fila, const int columna) { 
  fila_ = fila;
  columna_ = columna;
  v_.resize(fila_ * columna_);
}



template<class T>
Matrix_t<T>::~Matrix_t(){

}



template<class T>
void
Matrix_t<T>::resize(const int fila, const int columna) {
  assert(fila > 0 && columna > 0);
  fila_ = fila;
  columna_ = columna;
  v_.resize(fila_ * columna_);
}



template<class T>
inline int
Matrix_t<T>::get_fila() const {
  return fila_;
}



template<class T>
inline int
Matrix_t<T>::get_columna() const {
  return columna_;
}



template<class T>
T&
Matrix_t<T>::at(const int i, const int j) {
  assert(i > 0 && i <= get_fila());
  assert(j > 0 && j <= get_columna());
  return v_[pos(i, j)];
}



template<class T>
T&
Matrix_t<T>::operator()(const int i, const int j) {
  return at(i, j);
}



template<class T>
const T&
Matrix_t<T>::at(const int i, const int j) const {
  assert(i > 0 && i <= get_fila());
  assert(j > 0 && j <= get_columna());
  return v_[pos(i, j)];
}



template<class T>
const T&
Matrix_t<T>::operator()(const int i, const int j) const {
  return at(i, j);
}



template<class T>
void
Matrix_t<T>::write(ostream& os) const { 
  os << get_fila() << "x" << get_columna() << endl;
  for (int i = 1; i <= get_fila(); ++i) {
    for (int j = 1; j <= get_columna(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}



template<class T>
void
Matrix_t<T>::read(istream& is) {
  is >> fila_ >> columna_;
  resize(fila_, columna_);
  for (int i = 1; i <= get_fila(); ++i)
    for (int j = 1; j <= get_columna(); ++j)
      is >> at(i, j);
}


template<class T>
inline
int
Matrix_t<T>::pos(const int i, const int j) const {
  assert(i > 0 && i <= get_fila());
  assert(j > 0 && j <= get_columna());
  return (i - 1) * get_columna() + (j - 1);
}



// FASE III: producto matricial
template<class T>
void
Matrix_t<T>::multiply(const Matrix_t<T>& A, const Matrix_t<T>& B) {
  // rellenar código
}
