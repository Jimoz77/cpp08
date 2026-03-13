#include <iostream>
#include <vector>
#include <exception>
#include "easyfind.hpp" // Remplace par .h si c'est l'extension que tu as choisie

int main() {
    // 1. Initialisation d'un conteneur (std::vector)
    // En C++98, on ne peut pas utiliser les listes d'initialisation {1, 2, 3}, 
    // on doit donc utiliser push_back.
    std::vector<int> monVecteur;
    monVecteur.push_back(10);
    monVecteur.push_back(20);
    monVecteur.push_back(30);
    monVecteur.push_back(40);
    monVecteur.push_back(50);


    try {
        std::cout << "Recherche de la valeur 30..." << std::endl;
        std::vector<int>::iterator it = easyfind(monVecteur, 30);
        std::cout << "Succès ! Valeur trouvée : " << *it << std::endl;
    } 
    catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    std::cout << "-----------------------" << std::endl;

    try {
        std::cout << "Recherche de la valeur 99..." << std::endl;
        std::vector<int>::iterator it = easyfind(monVecteur, 99);
        std::cout << "Succès ! Valeur trouvée : " << *it << std::endl;
    } 
    catch (const std::exception& e) {
        std::cerr << "Erreur: "<< e.what() << std::endl;
    }

    return 0;
}
