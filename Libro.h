#pragma once
#include <iostream>
#include "MaterialBibliografico.h"

class Libro : public MaterialBibliografico {

    protected:

    std::string fechaPublicacion;
    std::string resumen;

    public:

    Libro(std::string nombre,std::string isbn, std::string autor, std::string fechaPublicacion, std::string resumen);
    ~Libro();
    void mostrarInformacion();

};