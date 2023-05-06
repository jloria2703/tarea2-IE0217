/**
Licencia MIT

Copyright (c) [2023] Tarea 2 - Grupo 2 - IE 0217 - I Ciclo 2023

Se concede aquí, sin cargo, a cualquier persona que obtenga una copia de este
software y los archivos de documentación asociados (el "Software"), para
utilizar el Software sin restricciones, incluyendo, sin limitación, los
derechos para usar, copiar, modificar, fusionar, publicar, distribuir,
sublicenciar y/o vender copias del Software, y para permitir a las personas a
quienes se les proporcione el Software que lo hagan, sujeto a las siguientes
condiciones:

El aviso de copyright anterior y este aviso de permiso se incluirán en todas
las copias o partes sustanciales del Software.

EL SOFTWARE SE PROPORCIONA "TAL CUAL", SIN GARANTÍA DE NINGÚN TIPO, EXPRESA O
IMPLÍCITA, INCLUYENDO PERO NO LIMITADO A GARANTÍAS DE COMERCIALIZACIÓN,
IDONEIDAD PARA UN PROPÓSITO PARTICULAR Y NO INFRACCIÓN. EN NINGÚN CASO LOS
AUTORES O TITULARES DEL COPYRIGHT SERÁN RESPONSABLES POR NINGUNA RECLAMACIÓN,
DAÑO O OTRA RESPONSABILIDAD, YA SEA EN UNA ACCIÓN CONTRACTUAL, AGRAVIO O DE
OTRO MODO, QUE SURJA DE, FUERA DE O EN CONEXIÓN CON EL SOFTWARE O EL USO U
OTROS ACUERDOS EN EL SOFTWARE.
*/

/**
 * @brief incluimos el .hpp que cuenta con la informacion de la clase
 */

#include "Exceptions.hpp"
#include <iostream>
#include <vector>
#include <typeinfo>




using namespace std;


int main() {
  /**
   * @brief try-catch maneja la excepción del tipo MyException
   * 
   */
  try {
    throw MyException();
  } catch (exception& e) {
    cout << "Error: " << e.what() <<endl;
  }
  /**
   * @brief try-catch bad_alloc se crea un vector vació y se intenta agregarle elementos a él en un bucle infinito
   */
  try {
    vector<int> fallo;
    while (true) {fallo.push_back(27); }
  } catch (bad_alloc& e) {
      cerr << "Error: " << e.what() << endl;
  }  
  /**
   * @brief try-catch Out_of_range se crea un vector con 3 valores y luego se intenta acceder al elemento de la posición 4 sin embargo solo tiene 3 elementos.
   */
  try{
    vector<int> v1{2, 8 , 27};
    v1.at(4);

  }catch(out_of_range& e){
    cerr << "Error: Out_of_range "<<e.what()<<endl;
  }
  /**
   * @brief try-catch se crea un puntero que no apunta a ninguna dirección de memoria válida
   * 
   */
  try{
    Error* prueba = nullptr;
    typeid( *prueba ).name();
  }catch(bad_typeid& e){
    cout<<"Error: "<<e.what()<<endl;
  }
}
