#Tarea_01_ostep

El objetivo de la asignación era modificar 3 archivos en lenguaje C para cumplir con unas 
determinadas tareas. Estos eran:

*[mem.c](mem.c): El objetivo era acceder al sistema operativo como súper usuario para
cambiar las condiciones y hacer que dos procesos, claramente diferentes, de la maquina se
 dirigieran a la misma dirección de memoria.
 
*[threads.c](threads.c): necesitaba que los hilos no accedieran al mismo tiempo a la 
información. por esta razón se necesitaba un proceso que controlara la entrada y la salida
de los hilos, para evitar que se perdiera información. Se crearon funciones con 
“pthread_mutex_t” que sirve para tener un acceso controlado a la información. Las funciones
creadas fueron las siguientes:

Crear_puerta: se inicializa la variable de control y se le indican las condiciones iniciales. 
Abrir_puerta: en esta se le indica dejar la variable abierta para el ingreso de hilos .
Cerrar_puerta: se bloquea la variable de control para restringir el acceso a la información.
Destruir_puerta: se destruye la variable de control, sabiendo que ya no se usara.

Se sabe bien que la función worker se hace de manera repetitiva y se usa para cambiar 
información en la variable counter, por esto es importante conocer que es ahí donde a veces
se pierde información, por esta razón la primera acción que se debe hacer es cerrar la 
puerta y cuando ya se haya modificado la información y se esté listo para salir se abre la 
puerta para dejar el libre acceso a el siguiente hilo.  

*[io.c](io.c): Se debía crear un código que recibiera como argumento un fichero de texto
y que el programa hiciera un recorrido del texto al revés, imprimiendo como resultado el
texto escrito al revés usando funciones del tipo fseek, situándoe al final del texto con la
función SEEK_END y en un ciclo FOR desplazarse de atrás hacia adelante mientras se imprime
cada palabra.
