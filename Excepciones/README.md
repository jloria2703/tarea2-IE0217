#Instrucciones de ejecución
1. En su consola con coloque el comando "make".
2. Presione la tecla < enter > 
3. El programa compilara y se ejecutará por sí solo.



##Tres tipos de excepciones de la librería estándar

1. **bad_alloc**: se produce cuando se queda sin memoria para asignar.En este caso, el programa intenta agregar un elemento al final del vector "fallo" en un bucle infinito. Como el vector no tiene un tamaño fijo, se asigna más memoria a medida que se agregan elementos, pero eventualmente el sistema operativo no puede proporcionar más memoria y sucede este error.
2. **out_of_range**: . se produce cuando se intenta acceder a un elemento fuera del rango definido. En este caso se tiene un vector v1 que consta de 3 elementos. Se le solicita obtener el elemento en la posición 4 pero como el vector solo cuenta con 3 elementos genera el error.
3. **bad_typeid:**: sucede cuando se aplica a un valor de puntero nulo de un tipo polimórfico. En este caso se inicializa con un puntero nulo nullptr, y luego se llama a typeid sobre el contenido de ese puntero. Esto provoca un error bad_typeid, ya que no se puede determinar el tipo de objeto al que apunta un puntero nulo.