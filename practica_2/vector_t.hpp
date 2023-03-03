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



template<class T>
Vector_t<T>::Vector_t(const int num)
{ size_ = num;
  build();
}



template<class T>
Vector_t<T>::~Vector_t()
{
  destroy();
}



template<class T>
void
Vector_t<T>::build()
{
  v_ = NULL;
  if (size_ != 0) {
    v_ = new T[size_];
    assert(v_ != NULL);
  }
}



template<class T>
void
Vector_t<T>::destroy()
{
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  size_ = 0;
}



template<class T>
void
Vector_t<T>::resize(const int num)
{
  destroy();
  size_ = num;
  build();
}



template<class T>
inline T
Vector_t<T>::get_val(const int i) const
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}



template<class T>
inline int
Vector_t<T>::get_size() const
{
  return size_;
}



template<class T>
void
Vector_t<T>::set_val(const int i, const T d)
{
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}



template<class T>
T&
Vector_t<T>::at(const int i)
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}



template<class T>
T&
Vector_t<T>::operator[](const int i)
{
  return at(i);
}



template<class T>
const T& 
Vector_t<T>::at(const int i) const
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}



template<class T>
const T&
Vector_t<T>::operator[](const int i) const
{
  return at(i);
}



template<class T>
void
Vector_t<T>::write(ostream& os) const
{ 
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}



template<class T>
void
Vector_t<T>::read(istream& is)
{
  is >> size_;
  resize(size_);
  for (int i = 0; i < size_; ++i)
    is >> at(i);
}


// FASE II: producto escalar
template<class T>
T
scal_prod(const Vector_t<T>& v, const Vector_t<T>& w)
{
  
}



double
scal_prod(const Vector_t<Rational_t>& v, const Vector_t<Rational_t>& w)
{

}
