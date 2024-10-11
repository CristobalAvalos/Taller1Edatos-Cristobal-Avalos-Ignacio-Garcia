#include "Usuario.h"

Usuario::Usuario(std::string nombre,std::string id){

    
    this->nombre = nombre;
    this->id = id;
    

}


std::string Usuario::getNombre(){return nombre;}
std::string Usuario::getId(){return id;}
MaterialBibliografico** Usuario::getMaterial(){return materialesPrestados;}

void Usuario::mostrarMaterialesPrestados(){

    for(int i = 0;i<5;i++){

        if(materialesPrestados[i]==nullptr){return;}

        materialesPrestados[i]->mostrarInformacion();

    }

}

void Usuario::prestarMaterial(MaterialBibliografico* material){

    for(int i = 0;i<5;i++){

        if(materialesPrestados[i]==nullptr){

            materialesPrestados[i]=material;
            material->actualizarEstado();

            return;
        }

    }

    std::cout<<"Ya tienes el Maximo de materiales prestados"<<std::endl;

}

void Usuario::devolverMaterial(MaterialBibliografico* material){

    for(int i = 0;i<5;i++){
    
        if(materialesPrestados[i]->getNombre() == material->getNombre()){
        
            material->actualizarEstado();
            materialesPrestados[i] == nullptr;
            std::cout<<"Devuelto con exito"<<std::endl;
            return;
        }
    }

    std::cout<<"No existe este material en los prestados al usuario."<<std::endl;
}

