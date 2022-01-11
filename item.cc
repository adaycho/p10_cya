/**
* Universidad de La Laguna
* Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
* Grado en Ingeniería Informática
* Asignatura: Computabilidad y Algoritmia
* Curso: 2º
* Práctica 11
* Correo: alu0101437538@ull.edu.es
* @author Aday Chocho Aisa
* @date 12/01/2021
* Archivo item.cc: clase objeto
* @brief Definición de métodos de la clase item
*/


#include "item.h"

/**
* @brief Constructor de la clase
* @param name: nombre(número) del objeto
* @param weight: peso del objeto
* @param value: valor del objeto
*/
Item::Item(const unsigned int name, const unsigned int weight, const unsigned int value) {
  name_ = name;
  weight_ = weight;
  value_ = value;
}

/**
* @brief Getter que devuelve la utilidad
*/
double Item::GetUtility() const{
  return value_ / weight_;
}

/**
* @brief Getter que devuelve el peso
*/
double Item::GetWeight() const{
  return weight_;
}

/**
* @brief Getter que devuelve el valor
*/
double Item::GetValue() const{
  return value_;
}

/**
* @brief Sobrecarga del operador de igualdad
*/
bool operator==(const Item& item1, const Item& item2) {
  return (item1.GetWeight() == item2.GetWeight() && item1.GetValue() == item2.GetValue());
}

/**
* @brief Sobrecarga del operador de desigualdad
*/
bool operator!=(const Item& item1, const Item& item2) {
  return (item1.GetWeight() != item2.GetWeight() || item1.GetValue() == item2.GetValue());
}
