#pragma once
#include <iostream>
#include "MaterialBibliografico.h"
#include <string>
class Usuario{

    private:

    std::string nombre;
    std::string id;
    MaterialBibliografico* materialesPrestados[5] = {nullptr};

    public:

    Usuario(std::string nombre,std::string id);
    void mostrarMaterialesPrestados();

    std::string getNombre();
    std::string getId();
    void prestarMaterial(MaterialBibliografico* material);
    void devolverMaterial(MaterialBibliografico* material);
};