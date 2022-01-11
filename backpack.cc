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
* Archivo backpack.cc: clase mochila
* @brief Definición de métodos de la clase backpack
*/


#include "backpack.h"

/**
* @brief Constructor de la clase
max_weight: peso máximo de la mochila
* @param file: archivo donde se encuentran los datos
*/
Backpack::Backpack(const std::string max_weight, const std::string file) {
  max_weight_ = std::stod(max_weight);
  std::ifstream infile(file);
  std::string target;
  getline(infile, target);
  int found;
  double item_number, value, weight;
  if (target.find_first_of(" ") != -1) {
    found = target.find_first_of(" ");
    item_number = std::stod(target.substr(0, found));
  }
  else {
    item_number = std::stod(target);
  }
  for (int i {0}; i < item_number; ++i) {
    getline(infile, target);
    found = target.find_first_of(" ");
    weight = std::stod(target.substr(0, found));
    target = target.substr(found +1);
    if (target.find_first_of(" ") != -1) {
      found = target.find_first_of(" ");
      value = std::stod(target.substr(0, found));
    }
    else {
      value = std::stod(target);
    }
    Item item (i + 1, weight, value);
    item_list_.push_back(item);
  }
}

/**
* @brief Método que resuelve la mochila simple
*/
void Backpack::SimpleBackpack() {
  double free_weight{max_weight_}, total_weight{0}, total_value{0};
  std::vector<Item> item_list_copy = item_list_;
  std::vector<double> use_list(item_list_copy.size(), 0);
  std::vector<int> sort_list;
  while (free_weight > 0 && !item_list_copy.empty()) {
    bool flag = false;
    int selected_item{-1};
    double utility{0};
    for (int i{0}; i < item_list_copy.size(); ++i) {
      if (item_list_copy[i].GetUtility() >= utility) {
        utility = item_list_copy[i].GetUtility();
        selected_item = i;
        if (item_list_copy[i].GetWeight() < free_weight) {
          flag = true;
        }
        else {
          flag = false;
        }
      }
    }
    if (flag) {
      total_weight += item_list_copy[selected_item].GetWeight();
      total_value += item_list_copy[selected_item].GetValue();
      for (int i{0}; i < item_list_.size(); ++i) {
        if (item_list_[i] == item_list_copy[selected_item]) {
          flag = true;
          for (int j{0}; j < sort_list.size(); ++j) {
            if (sort_list[j] == i) {
              flag = false;
            }
          }
          if (flag) {
            sort_list.push_back(i);
          }
          use_list[i] += 1.0;
        }
      }
    }
    else {
      total_weight += free_weight;
      total_value += item_list_copy[selected_item].GetValue()*(free_weight/item_list_copy[selected_item].GetWeight());
      for (int i{0}; i < item_list_.size(); ++i) {
        if (item_list_[i] == item_list_copy[selected_item]) {
          sort_list.push_back(i);
          use_list[i] += free_weight/item_list_copy[selected_item].GetWeight();
        }
      }
    }
    item_list_copy.erase(item_list_copy.begin() + selected_item);
    free_weight = max_weight_ - total_weight;
  }
  Print(total_value, total_weight, sort_list, use_list);
}

/**
* @brief Método que resuelve la mochila ilimitada
*/
void Backpack::UnboundedBackpack() {
  double free_weight{max_weight_}, total_weight{0}, total_value{0};
  bool flag;
  std::vector<double> use_list(item_list_.size(), 0);
  std::vector<int> sort_list;
  while (free_weight > 0) {
    int selected_item{-1};
    double utility{0};
    for (int i{0}; i < item_list_.size(); ++i) {
      if (item_list_[i].GetUtility() >= utility && item_list_[i].GetWeight() <= free_weight) {
        utility = item_list_[i].GetUtility();
        selected_item = i;
      }
    }
    if (selected_item != -1) {
      total_weight += item_list_[selected_item].GetWeight();
      total_value += item_list_[selected_item].GetValue();
      for (int i{0}; i < item_list_.size(); ++i) {
        if (item_list_[i] == item_list_[selected_item]) {
          flag = true;
          for (int j{0}; j< sort_list.size(); ++j) {
            if (sort_list[j] == i) {
              flag = false;
            }
          }
          if (flag) {
            sort_list.push_back(i);
          }
          use_list[i] += 1.0;
        }
      }
      free_weight = max_weight_ - total_weight;
    }
    else {
      break;
    }
  }
  Print(total_value, total_weight, sort_list, use_list);
}

/**
* @brief Método que imprime los resultados de las mochilas
* @param total_value: valor total de la mochila
* @param total_weight: peso total de la mochila
* @param sort_list: vector que contiene el orden de uso de un objeto
* @param use_list: vector que contiene las veces de uso de un objeto
*/
void Backpack::Print(double total_value, double total_weight, std::vector<int> sort_list, std::vector<double> use_list) {
  if (sort_list.size() > 0) {
    std::cout << "Beneficio: " << total_value << std::endl;
    std::cout << "Peso: " << total_weight << std::endl;
    std::cout << "Solución: " << sort_list[0] + 1 << ":" << use_list[sort_list[0]];
    for (int i{1}; i < sort_list.size(); ++i) {
      std::cout << ", " << sort_list[i] + 1 << ":" << use_list[sort_list[i]];
    }
    std::cout << std::endl;
  }
  else {
    std::cout << "No entran objetos en la mochila" << std::endl;
  }
}