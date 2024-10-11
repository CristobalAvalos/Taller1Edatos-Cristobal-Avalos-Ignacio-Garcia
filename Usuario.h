#pragma once
#include <iostream>
#include "MaterialBibliografico.h"
#include <string>

//**Clase usuario
//** Atributos: */
//*Nombre: string
//id: String
//MaterialesPrestados: Lista de tipo MaterialBibliografico que corresponde a los materiales que tiene el usuario.

//**Metodos: */
//*Usuario(): Constructor
//*MostrarMaterialesPrestados(): Tipo void, Muestra los materiales que tiene el usuario
//*PrestarMaterial(): tipo void, Se le asigna al usuario el material que busca.
//*DevolverMaterial(): Devuelve el material del usuario a la biblioteca, asignandole el estado y eliminandolo de la lista del usuario.
//*getters y setters.
class Usuario{

    private:

    std::string nombre;
    std::string id;
    MaterialBibliografico* materialesPrestados[5] = {nullptr};

    public:

    Usuario(std::string nombre,std::string id);
    void mostrarMaterialesPrestados();

    
    void prestarMaterial(MaterialBibliografico* material);
    void devolverMaterial(MaterialBibliografico* material);

    std::string getNombre();
    std::string getId();

    MaterialBibliografico** getMaterial();

};