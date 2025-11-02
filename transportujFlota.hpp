#pragma once
#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar) 
{
    if (towar == 0) return 0;

    Stocznia stocznia{}; 
    unsigned int iloscZaglowcow = 0; 

    // Dopóki ³¹czna pojemnoœæ utworzonych statków jest mniejsza ni¿ wymagany towar
    while (Stocznia::getTotalCap() < towar) {
        Statek* nowyStatek = stocznia(); 
        nowyStatek->transportuj(); 

        // SprawdŸ, czy utworzony statek by³ ¿aglowcem 
        if (dynamic_cast< Zaglowiec* >(nowyStatek))
            ++iloscZaglowcow;
        delete nowyStatek; 
    }
    return iloscZaglowcow; 
}