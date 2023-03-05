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

using namespace std;

template<class T>
class Vector_t
{
public:
  Vector_t(const int = 0); 
  ~Vector_t(); 
  
  void resize(const int);
  
  // getters
  T get_val(const int) const;
  int get_size(void) const;
  
  // setters
  void set_val(const int, const T);
  
  // getters-setters
  T& at(const int);
  T& operator[](const int);
  
  // getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;

  void write(ostream& = cout) const;
  void read(istream& = cin);

private:
  T *v_;
  int size_;
  
  void build(void);
  void destroy(void);
};


//Constructor
template<class T> Vector_t<T>::Vector_t(const int num) { size_ = num;
  build();
}


//Destructor
template<class T> Vector_t<T>::~Vector_t() {
  destroy();
}


//Constructor de copia
template<class T>
void Vector_t<T>::build() {
  v_ = NULL;
  if (size_ != 0) {
    v_ = new T[size_];
    assert(v_ != NULL);
  }
}


//Destructor
template<class T>
void Vector_t<T>::destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  size_ = 0;
}


//Cambiar tamaño del vector
template<class T>
void Vector_t<T>::resize(const int num) {
  destroy();
  size_ = num;
  build();
}


//getters
//Obitene el valor
template<class T>
inline T Vector_t<T>::get_val(const int i) const {
  assert(i >= 0 && i < get_size()); //Asegurarse que i es mayor o igual que cero y menor que el tamaño del vector
  return v_[i];
}

//Obtiene el tamaño
template<class T>
inline int Vector_t<T>::get_size() const {
  return size_;
}


//Setters
template<class T>
void Vector_t<T>::set_val(const int i, const T d) {
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}

//Devovle rla posicion 
template<class T>
T& Vector_t<T>::at(const int i) {
  assert(i >= 0 && i < get_size()); //COmprobar que i es mayor o igual que cero y menor que el tamaño del vector
  return v_[i];
}


//Sobrecarga de operador []
template<class T>
T& Vector_t<T>::operator[](const int i) {
  return at(i);
}


//Devolver posicion
template<class T>
const T&  Vector_t<T>::at(const int i) const {
  assert(i >= 0 && i < get_size()); //Comprobar que i es mayor o igualq ue 0 y menor que el tamaño del vector
  return v_[i];
}


//Sobrecarga de operador []
template<class T>
const T& Vector_t<T>::operator[](const int i) const {
  return at(i);
}


//Imprimir por pantalla el vector
template<class T>
void Vector_t<T>::write(ostream& os) const { 
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}


//Obtener los valores de un vector
template<class T>
void Vector_t<T>::read(istream& is) {
  is >> size_;
  resize(size_);
  for (int i = 0; i < size_; ++i)
    is >> at(i);
}


//Producto escalar para dos vectores de tipo Rational_t
template<class T>
T scal_prod(const Vector_t<T>& v, const Vector_t<T>& w) {
  assert(v.get_size() == w.get_size());
  double resultado{0};
  for(int i =0;i < v.get_size(); ++i) { 
    resultado = resultado + (v.at(i) * w.at(i));
  }
  return resultado;
}


//Producto escalar para dos vectores de tipo double
double scal_prod(const Vector_t<Rational_t>& v, const Vector_t<Rational_t>& w) {  
  double resultado {0};
  for(int i = 0; i < v.get_size(); ++i) {
    resultado = resultado + (v[i].value() * w[i].value());
  }
  return resultado;
}
