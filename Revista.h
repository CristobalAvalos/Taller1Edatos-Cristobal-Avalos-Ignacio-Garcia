#pragma once
#include <iostream>
#include "MaterialBibliografico.h"


//**Clase Revista que hereda de MaterialBibliografico
//*NumeroEdicion
//*MesPublicacion

//** Revista(): Constructor de la clase
//**MostrarInformacion: Muestra la informacion que contiene tanto la clase como su padre */

class Revista : public MaterialBibliografico {

    private:

    std::string numeroEdicion;
    std::string mesPublicacion;

    public:

    Revista(std::string nombre, std::string isbn, std::string autor, std::string numeroEdicion, std::string mesPublicacion);
    ~Revista();
    void mostrarInformacion();
};