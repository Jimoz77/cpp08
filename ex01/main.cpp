#include <iostream>
#include <vector>
#include <cstdlib> // Pour rand() et srand()
#include <ctime>   // Pour time()
#include "Span.hpp"

int main()
{
    std::cout << "--- 1. TEST BASIQUE DU SUJET ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span : " << sp.shortestSpan() << std::endl; // Doit afficher 2
        std::cout << "Longest span : " << sp.longestSpan() << std::endl;   // Doit afficher 14
    } catch (std::exception &e) {
        std::cerr << "Erreur inattendue : " << e.what() << std::endl;
    }

    std::cout << "\n--- 2. TEST DES EXCEPTIONS ---" << std::endl;
    try {
        std::cout << "Test d'un Span vide..." << std::endl;
        Span emptySpan(5);
        emptySpan.shortestSpan(); // Doit lever une exception
    } catch (std::exception &e) {
        std::cerr << "Exception attrapée (Succès) : " << e.what();
    }

    try {
        std::cout << "Test de dépassement de capacité..." << std::endl;
        Span tinySpan(2);
        tinySpan.addNumber(1);
        tinySpan.addNumber(2);
        tinySpan.addNumber(3); // Doit lever une exception (capacité max = 2)
    } catch (std::exception &e) {
        std::cerr << "Exception attrapée (Succès) : " << e.what();
    }

    std::cout << "\n--- 3. TEST DE PERFORMANCE (10 000 NOMBRES) ---" << std::endl;
    try {
        Span bigSpan(10000);
        std::vector<int> randomNumbers;
        
        // Initialisation de la graine aléatoire
        std::srand(std::time(NULL));

        // Remplissage d'un vecteur avec 10 000 nombres aléatoires
        for (int i = 0; i < 10000; i++) {
            randomNumbers.push_back(std::rand());
        }

        std::cout << "Ajout de 10 000 nombres d'un coup grâce aux itérateurs..." << std::endl;
        // On utilise notre super fonction template qui prend des itérateurs !
        bigSpan.addNumber(randomNumbers.begin(), randomNumbers.end());

        std::cout << "Calculs en cours..." << std::endl;
        std::cout << "Shortest span sur 10 000 nb : " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span sur 10 000 nb  : " << bigSpan.longestSpan() << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Erreur inattendue : " << e.what() << std::endl;
    }

    return 0;
}
