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
* Archivo backpack_problem.cc: main
* @brief Programa principal
*/

#include "backpack.h"

void Help(char* argv[]) {
  std::cout << argv[0] << std::endl;
  std::cout << "El programa te permite resolver el problema de la mochila, "
  << "introduciendo por parámetros el peso máximo y el fichero con los obejtos"
  << " diaponibles." << std::endl;
  std::cout << "Modo de empleo: " << std::endl << argv[0] <<
  " [-u] [Peso máximo de la mochila] [Fichero cfg]" << std::endl;
}

void MissingParameters(char* argv[]) {
  std::cout << argv[0] << std::endl;
  std::cout << "Modo de empleo: " << std::endl << argv[0] <<
  " [-u] [Peso máximo de la mochila] [Fichero cfg]" << std::endl;
  std::cout << "Para más información, use " << argv[0] << " --help";
  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  if (argc == 3) {
    if (std::stoi(argv[1]) > 0) {
      Backpack backpack(argv[1], argv[2]);
      backpack.SimpleBackpack();
    }
    else {
      std::cout << "El peso máximo es un número no válido" << std::endl;
    }
    
  }
  else if (argc == 2) {
    std::string option = argv[1];
    if (option == "--help" || option == "-h") {
      Help(argv);
    }
    else {
      MissingParameters(argv);
    }
  }
  else if (argc == 4) {
    std::string option = argv[1];
    if (option == "-u") {
      if (std::stoi(argv[2]) > 0) {
        Backpack backpack(argv[2], argv[3]);
        backpack.UnboundedBackpack();
      }
      else {
        std::cout << "El peso máximo es un número no válido" << std::endl;
      }
    }
    else {
      MissingParameters(argv);
    }
  }
  else {
    MissingParameters(argv);
  }
  return 0;
}