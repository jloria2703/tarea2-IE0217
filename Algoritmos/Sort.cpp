/**
 * @file Sort.cpp
 * @author Jorge Loria (jloria2703)
 
 * @date 2023-05-05
 * 
 * /**
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


#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief metodo de bubbleSort , "vector<int> &arr" quiere decir que va a accesar a los parametros originales y los cambios que se realicen se veran reflejados en los parametros originales
 * @param arr recibe un arreglo de tipo vector
 * @param n la cantidad de elementos de ese arreglo
 */
void bubbleSort(vector<int> &arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
/**
 * @brief metodo de selectionSort
 * 
 * @param arr recibe un arreglo de tipo vector
 * @brief "vector<int> &arr" quiere decir que va a accesar a los parametros originales y los cambios que se realicen se veran reflejados en los parametros originales
 */
void selectionSort(vector<int> &arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    /**
     * @brief min_indx es la posicion minima en el vector que se esta corriendo
     * 
     */
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    /**
     * @brief temp es una variable temporal que se usa para intercambiar dos elementos del arr
     * 
     */
    int temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }
}
/**
 * @brief metodo para insertionSort
 * El "vector<int> &arr" quiere decir que va a accesar a los parametros originales y los cambios que se realicen se veran reflejados en los parametros originales
 * @param arr recibe un arreglo de tipo vector
 * @param n 
 */
void insertionSort(vector<int> &arr, int n) {
  for (int i = 1; i < n; i++) {
    int act = arr[i];
    /**
     * @brief varCom compara a "act" con los anteriores elementos del vector
     */
    int varCom = i - 1;
    while (varCom >= 0 && arr[varCom] > act) {
      arr[varCom + 1] = arr[varCom];
      varCom--;
    }
    /**
     * @brief Se le asigna el valor de "act" en la posicion correcta despues de todos los elementos menores que el.
     */
    arr[varCom + 1] = act;
  }
}

/**
 * @brief int partition se utiliza para dividir el arreglo en dos subarreglos, uno con elementos menores que el pivote y otro con elementos mayores que el pivote.
 * 
 * @param arr 
 * @param low 
 * @param high 
 */
int partition(vector<int> &arr, int low, int high) {
  /**
   * @brief Se selecciona el valor mas alto del arreglo como pivote
   * "i" representa el indice del ultimo elemento que es menor que el pivote
   */
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;
  /**
   * @return el indice donde el pivote queda ordenado 
   */
  return i + 1;
}
/**
 * @brief metodo para quickSort
 * 
 * @param arr recibe el arreglo de tipo vector entero 
 * @param low indice mas bajo del sub-arreglo
 * @param high indice mas alto del sub-arreglo
 */
void quickSort(vector<int> &arr, int low, int high) {
  if (low < high) {
    /**
     * @brief Se procede a llamar a la función partition para dividir la lista en dos segmentos: 
     *  los elementos más pequeños que el pivote a la izquierda y los elementos mas grandes que el pivote a la derecha.
     */
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}


int main() {
  /**
   * @brief Definimos un vector que guarda un arreglo de tipo entero
   * 
   */
  vector<int> arr = {27, 10, 1, 7, 4};
  int n = arr.size();

  cout << "Arreglo original: ";
  /**
   * @brief Imprimir el arreglo original, ademas la funcion "auto" se usa para que el compilador deduzca el tipo de variable que es "x" , pero se sabe que va a ser int debido al arreglo
   * @param arr recibe el arreglo
   */
  for (auto x : arr) {
    cout << x << " ";
  }
  cout << endl;
  
  /**
   * @brief Se llama la funcion bubbleSort
   * @param arr el arreglo definido al inicio del main
   * @param n el tamanio del arreglo
   */
  bubbleSort(arr, n);
  cout << "Arreglo ordenado con Bubble Sort: ";
  /**
   * @brief la funcion "auto" se usa para que el compilador deduzca el tipo de variable que es "x" , pero se sabe que va a ser int debido al arreglo
   */
  for (auto x : arr) {
    cout << x << " ";
  }
  cout << endl;


  /**
   * @brief Es necesario colocar el arreglo original debido a que el método pasado ya lo ha ordenado
   * 
   */
  arr = {27, 10, 1, 7, 4};
  
  /**
   * @brief Invocamos a la funcion selectionSort
   * 
   */
  selectionSort(arr, n);
  cout << "Arreglo ordenado con Selection Sort: ";
  /**
   * @brief la funcion "auto" se usa para que el compilador deduzca el tipo de variable que es "x" , pero se sabe que va a ser int debido al arreglo
   */
  for (auto x : arr) {
    cout << x << " ";
  }
  cout << endl;
  /**
   * @brief  Es necesario colocar el arreglo original debido a que el método pasado ya lo ha ordenado
   * 
   */
  arr = {27, 10, 1, 7, 4}; 
  /**
   * @brief Invocamos a la funcion insertionSort
   * 
   */
  insertionSort(arr, n);
  cout << "Arreglo ordenado con Insertion Sort: ";
  for (auto x : arr) {
    cout << x << " ";
  }
  cout << endl;

  /**
   * @brief Es necesario colocar el arreglo original debido a que el método pasado ya lo ha ordenado
   * 
   */
  arr = {27, 10, 1, 7, 4};
  /**
   * @brief se llama a la funcion quickSort
   * 
   */
  quickSort(arr, 0, n - 1);
  cout << "Arreglo ordenado con Quick Sort: ";
  for (auto x : arr) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
