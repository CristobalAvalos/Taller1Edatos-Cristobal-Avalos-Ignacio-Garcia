#include <iostream>
#include <fstream>
#include <string>
#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Usuario.h"
#include "Revista.h"

using namespace std;
void listarMaterial(MaterialBibliografico* lista[]){

    for(int i = 0;i<100;i++){

       if(lista[i]!=nullptr){lista[i]->mostrarInformacion();}

    }
}
void limpiarMemoria(MaterialBibliografico* lista[], Usuario* lista2[]){

    for(int i =0;i<100;i++){

        if(lista[i] != nullptr){delete lista[i];}
        if(lista2[i] != nullptr){delete lista2[i];}

    }

}
void agregarMaterial(string nombre,string isbn,string autor,string extra1,string extra2,int lor, MaterialBibliografico* lista[]){

    MaterialBibliografico* material;

    if(lor==1){

        material = new Libro(nombre,isbn,autor,extra1,extra2);

    } else {

        material = new Revista(nombre,isbn,autor,extra1,extra2);

    }

    for(int i = 0;i<100;i++){

        if (lista[i]==nullptr){

            lista[i]=material;
            return;

        }


    }

}
void buscarMaterial(string info, MaterialBibliografico* lista[]){

    MaterialBibliografico* material;
    bool existe = false;
    for(int i=0;i<100;i++){

        material = lista[i];
        
        if (material != nullptr){
        
            if (material->getNombre() == info || material->getAutor() == info){
        
                material->mostrarInformacion();
                existe = true;
            }
        }
    }

    if (existe == false){
    
        cout<< "No existe en el sistema."<<endl;
    }
}
void crearUsuario(string nombre, string id, Usuario* lista[]){

    Usuario* usuario;
    for (int i = 0;i<100;i++){

        if (lista[i]==nullptr){

            usuario = new Usuario(nombre,id);
            
            lista[i]=usuario;

            cout<<"Creado con exito."<<endl;

            return;

        }else if (lista[i]->getNombre() == nombre && lista[i]->getId() == id){ 

            cout<<"No se puede crear, ya existe. "<<endl;
            return;
        }
    }

}
void datosUsuario(string nombre, string id, Usuario* lista[]){

    Usuario* usuario;


    for (int i=0;i<100;i++){
        

        usuario = lista[i];


        if (usuario != nullptr){
            if (usuario->getNombre() == nombre && usuario->getId() == id){
                
                usuario = lista[i];
                cout<<"El usuario es: "<<usuario->getNombre()<<" De ID: "<<usuario->getId()<<"\nArtículos en propiedad: \n"<<endl;

                usuario->mostrarMaterialesPrestados();
                return;
            
            }
        }
    }
    
    if (usuario == nullptr){
    
        cout<<"No existe. "<<endl;
    }

}
Usuario* buscarUsuario(string nombre, string id, Usuario* lista[]){

    Usuario* usuario;


    for (int i=0;i<100;i++){
    

        usuario = lista[i];

        if (usuario != nullptr){

            if (usuario->getNombre() == nombre && usuario->getId() == id){
               
                return usuario;

            }
            
        }
    }
    return nullptr;
}
MaterialBibliografico* encontrarMaterial(string info, MaterialBibliografico*lista[]){

    MaterialBibliografico* material;
    
    for(int i=0;i<100;i++){

        material = lista[i];
        
        if (material != nullptr){
        
            if (material->getNombre() == info || material->getAutor() == info){
        
                return material;

            }
        }
    }

    return nullptr;

}
void asignarMaterial(string titulo, Usuario* usuario, MaterialBibliografico* lista[]){

    MaterialBibliografico* material = encontrarMaterial(titulo,lista);

    if(material==nullptr){
        
        cout<<"No existe el material"<<endl;
        return;
    }

    else if(material->getEstado()=="Disponible"){

        usuario->prestarMaterial(material);

    } else {

        cout<<"Material no disponible para prestamo"<<endl;

    }

}

void devolverMaterial(string titulo, Usuario* usuario, MaterialBibliografico* lista[]){

    MaterialBibliografico* material = encontrarMaterial(titulo,lista);

    if(material==nullptr){

        cout<<"No existe el material"<<endl;
        return;
    }else {
    
        usuario->devolverMaterial(material);
    }

}

int contarEspacios(MaterialBibliografico* lista[],int maximo){

    int contador = 0;

    for(int i = 0;i<maximo;i++){

        if(lista[i] != nullptr){

            contador++;

        }

    }

    return contador;

}

int contarEspacios(Usuario* lista[]){

    int contador = 0;

    for(int i = 0;i<100;i++){

        if(lista[i] != nullptr){

            contador++;

        }

    }

    return contador;

}


void guardarDatos(MaterialBibliografico* biblioteca[], Usuario* usuarios[]){

    fstream archivo("respaldo.txt");

    int material = contarEspacios(biblioteca,100);
    int cantUsuarios = contarEspacios(usuarios);

    archivo<<material<<endl;

    for(int i = 0; i<100;i++){

        if(biblioteca[i]!=nullptr){

        
            archivo<<biblioteca[i]->getTipo()<<endl;
            archivo<<biblioteca[i]->getNombre()<<endl;
            archivo<<biblioteca[i]->getIsbn()<<endl;
            archivo<<biblioteca[i]->getAutor()<<endl;
            archivo<<biblioteca[i]->getExtra1()<<endl;
            archivo<<biblioteca[i]->getExtra2()<<endl;

            

        }

    }

    archivo<<cantUsuarios<<endl;

    for(int i = 0; i<100;i++){

        if(usuarios[i]!=nullptr){

            archivo<<usuarios[i]->getNombre()<<endl;
            archivo<<usuarios[i]->getId()<<endl;

            int prestados = contarEspacios(usuarios[i]->getMaterial(),5);

            archivo<<prestados<<endl;

            MaterialBibliografico** materialPrestado; 
            materialPrestado = usuarios[i]->getMaterial(); 

            for(int j = 0;j<5;j++){

                if(materialPrestado[j]!=nullptr){

                    archivo<<materialPrestado[j]->getTipo()<<endl;
                    archivo<<materialPrestado[j]->getNombre()<<endl;
                    archivo<<materialPrestado[j]->getIsbn()<<endl;
                    archivo<<materialPrestado[j]->getAutor()<<endl;
                    archivo<<materialPrestado[j]->getExtra1()<<endl;
                    archivo<<materialPrestado[j]->getExtra2()<<endl;


                }

            }

        }

    }

    archivo.close();

}
void cargarDatos(MaterialBibliografico** biblioteca, Usuario** usuarios){

    limpiarMemoria(biblioteca, usuarios);


    ifstream archivo("respaldo.txt");

    string linea;

    getline(archivo,linea);


    int cantMaterial = stoi(linea);

    for(int i = 0; i<cantMaterial; i++){

        getline(archivo,linea);

        string tipo = linea;

        getline(archivo,linea);

        string nombre = linea;

        getline(archivo,linea);

        string isbn = linea;

        getline(archivo,linea);

        string autor = linea;

        getline(archivo,linea);

        string extra1 = linea;

        getline(archivo,linea);

        string extra2 = linea;

        int lor = 0;

        if(tipo=="Libro"){lor++;}

        agregarMaterial(nombre, isbn, autor, extra1, extra2, lor,biblioteca);

    }

    getline(archivo,linea);

    int cantUsuarios = stoi(linea);

    for(int i = 0; i<cantUsuarios;i++){

        getline(archivo,linea);

        string nombre = linea;

        getline(archivo,linea);
        
        string id = linea;

        getline(archivo,linea);

        crearUsuario(nombre,id,usuarios);

        Usuario* usuario = buscarUsuario(nombre,id,usuarios);

        cantMaterial = stoi(linea);

        for(int j = 0; j<cantMaterial;j++){

            getline(archivo,linea);

            string tipo = linea;

            getline(archivo,linea);

            string nombreMaterial = linea;

            getline(archivo,linea);

            string isbn = linea;

            getline(archivo,linea);

            string autor = linea;

            getline(archivo,linea);

            string extra1 = linea;

            getline(archivo,linea);

            string extra2 = linea;

            asignarMaterial(nombreMaterial, usuario, biblioteca);

        }



    }

}

int main(){

    MaterialBibliografico* biblioteca[100] = {nullptr};
    Usuario* usuarios[100] = {nullptr};

    int opcion = 10;
    int lor;
    int opcionInterior = 10;
    cout<<biblioteca[0]<<endl;

    while(opcion!=0){

        cout<<"Introduce la opcion: \n1.- Agregar material a la biblioteca\n2.- Mostrar informacion\n3.- Buscar Material\n4.- Prestar y Devolver el material\n5.-Gestion de Usuarios\n6.-Guardar estado de biblioteca y Usuarios "<<endl;

        cin>>opcion;

        if(opcion==1){

            cout<<"¿Que desea agregar=\n1.-Libro\n2.-Revista"<<endl;
            
            cin>>lor;

            cin.ignore();

            if(lor==1){

                cout<<"Ingrese el nombre"<<endl;

                string nombre;

                getline(cin,nombre);

                cout<<"Ingrese el isbn"<<endl;

                string isbn;

                getline(cin,isbn);

                cout<<"Ingrese el autor"<<endl;

                string autor;

                getline(cin,autor);

                cout<<"Ingrese la fecha de publicación"<<endl;

                string fechaDePublicacion;

                getline(cin,fechaDePublicacion);

                cout<<"Ingrese el resumen"<<endl;

                string resumen;

                getline(cin,resumen);

                agregarMaterial(nombre,isbn,autor,fechaDePublicacion,resumen,lor, biblioteca);


            } else if(lor==2){

                cout<<"Ingrese el nombre"<<endl;

                string nombre;

                getline(cin,nombre);

                cout<<"Ingrese el isbn"<<endl;

                string isbn;

                getline(cin,isbn);

                cout<<"Ingrese el autor"<<endl;

                string autor;

                getline(cin,autor);

                cout<<"Ingrese el numero de edición"<<endl;

                string numeroEdicion;

                getline(cin,numeroEdicion);

                cout<<"Ingrese el mes de publicacion"<<endl;

                string mesPublicacion;

                getline(cin,mesPublicacion);

                agregarMaterial(nombre,isbn,autor,numeroEdicion,mesPublicacion,lor, biblioteca);

            }
            
            cout<<"Agregado con exito"<<endl;

        } else if(opcion==2){

            cin.ignore();

            listarMaterial(biblioteca);

        } else if(opcion==3){

            cout<<"¿Como quieres buscar?\n1.-Por Titulo\n2.-Por Autor"<<endl;
            cin>>opcionInterior;
          
            cin.ignore();

                if(opcionInterior==1){

                    string titulo;
                    cout<<"Ingrese el Titulo: "<<endl;
                    getline(cin,titulo);

                    buscarMaterial(titulo,biblioteca);

                }

                else if(opcionInterior==2){
                
                
                    string autor;
                    cout<<"Ingrese el nombre del Autor: "<<endl;
                    getline(cin,autor);

                    buscarMaterial(autor,biblioteca);
                }

        } else if(opcion==4){
        
        
            cout<<"Ingresa tu nombre: "<<endl;
            string nombre;
            cin.ignore();
            getline(cin,nombre);
            cout<<"Ingresa tu id: "<<endl;
            string id;
            getline(cin,id);

            if (buscarUsuario(nombre,id,usuarios) == nullptr){
            
                cout<<"El usuario no existe, registrelo por favor. "<<endl;

            }else{
            
                cout<<"Desea pedir prestado (1) o devolver (2)"<<endl;

                Usuario* usuario = buscarUsuario(nombre,id,usuarios);
                int opcionPrestamo = 0;
                cin>>opcionPrestamo;
                
                cin.ignore();


                if (opcionPrestamo == 1){
                
                    cout<<"Ingrese el titulo de lo que desea."<<endl;
                    string titulo;

                    getline(cin,titulo);
                    
                    asignarMaterial(titulo,usuario,biblioteca);


                }else if (opcionPrestamo == 2){
                
                    cout<<"Ingrese el titulo del titulo que desea devolver."<<endl;
                    string titulo;

                    getline(cin,titulo);

                    devolverMaterial(titulo,usuario,biblioteca);



                }


            }
        
        }else if(opcion==5){
    
            cout<<"Que deseas, Crear usuario (1), Buscar un usuario (2),  eliminar un usuario (3)"<<endl;
            int opcionUsuario = 10;
            cin.ignore();
            cin>>opcionUsuario;

            if (opcionUsuario == 1) {
        
                cout<<"Ingresa tu nombre: "<<endl;
                string nombre;
                cin.ignore();
                getline(cin,nombre);
                cout<<"ID: "<<endl;
                string id;
                getline(cin,id);
                crearUsuario(nombre,id,usuarios);

            }else if (opcionUsuario == 2){
            
            
                cout<<"Ingresa el nombre"<<endl;
                string nombre;
                cin.ignore();
                getline(cin,nombre);
                cout<<"ID del usuario que deseas buscar: "<<endl;
                string id;
                getline(cin,id);

                datosUsuario(nombre,id,usuarios);
            }
        } else if (opcion==6){

            int opcion6 = 0;
            cin.ignore();

            cout<<"¿Que desea?\n1.-Guardar el estado de la biblioteca\n2.-Cargar el estado de la biblioteca"<<endl;
            
            cin>>opcion6;

            if(opcion6==1){

                guardarDatos(biblioteca, usuarios);

            } else {
                
                cargarDatos(biblioteca,usuarios);

            }


        }
    
    }

    limpiarMemoria(biblioteca, usuarios);

    return 0;
}
