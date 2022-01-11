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
* Archivo backpack.h: clase mochila
* @brief Declaración de la clase backpack
*/

#ifndef BACKPACK
#define BACKPACK

#include <vector>
#include <fstream>
#include "item.h"
#include <iostream>

/**
* @brief Clase que permite almacenar los objetos en una mochila
*/
class Backpack {
 public:
  Backpack(const std::string max_weight, const std::string file);
  void SimpleBackpack();
  void UnboundedBackpack();
  void Print(double total_value, double total_weight, std::vector<int> sort_list, std::vector<double> use_list);
 private:
  double max_weight_;
  std::vector<Item> item_list_;
};

#endif