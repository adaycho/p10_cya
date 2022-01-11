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
* Archivo item.h: clase objeto
* @brief Declaraste de la clase item
*/


#ifndef ITEM
#define ITEM

/**
* @brief Clase que permite almacenar objetos con cierto peso y valor
*/
class Item {
 public:
  Item(const unsigned int name, const unsigned int weight, const unsigned int value);
  double GetUtility() const;
  double GetWeight() const;
  double GetValue() const;
  friend bool operator==(const Item& item1, const Item& item2);
  friend bool operator!=(const Item& item1, const Item& item2);
 private:
  double name_;
  double weight_;
  double value_;
};

#endif