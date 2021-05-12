# Actividad 4.1

## 7.1 A
En el estado inicial solo se puede avanzar con un 0, pues si no, la cadena directamente es invalida, este 0 será cambiado por una M.
En el primer estado, si ve un 0 lo cambia por una M, si no, lo deja en M, si ve un 1 se va al estado 2 y lo sustituye por M.
En el estado q2, se sustituye el 1 por N y N se queda en N y se mueve a la derecha, de esta forma se mantiene en el estado q2.
Si encuentra algún 0 lo sustituye por una M y se mueve a la izquierda, también ahora si se cambia el estado a q3.
En el estado q3 debemos revisar que exista la misma cantidad de 010. Movemos el cursor a la izquierda para ver si hay otros caracteres, y a la derecha cambiando 1 a X y 0 a M , solo se cambia al estado q0 moviendo el cursor a la derecha, si se encuentra una N.

En el cado en el que el símbolo en el que nos encontramos sea diferente de X nos regresamos al estado de 0, pero si es X nos movemos al estado 4 moviéndonos a la derecha.
En el estado 4 se cambia la N o X por el mismo símbolo, solo estos dos caracteres son válidos, si hay otro no es valida la cadena y no llega al h que es el estado final que en máquinas de Turing nos indica un true.


![image](https://user-images.githubusercontent.com/73607499/116767578-0e80aa80-a9ff-11eb-90e5-456c45db77fb.png)


## Teoría de la decidibilidad
En la teoría de la computación, se define un problema de decisión como aquél que tiene dos respuestas posibles: “sí” o “no”.
-	Se dice que un problema de decisión es decidible si existe un algoritmo que lo resuelva.
-	Decimos que un problema de decisión es indecidible si podemos demostrar que no existe ningún algoritmo que pueda responder a todas las preguntas que el problema pueda plantear.

## Teoría de la computabilidad
La teoría de la computabilidad busca clasificar los problemas en computables o no computables (que se pueden resolver o no se pueden resolver) y parte de dos preguntas fundamentales: “¿Qué es un algoritmo?” y “¿Cuáles son las capacidades y limitaciones de la computación algorítmica?”.   
Un ejemplo de un acercamiento a responder estas preguntas es la Tésis de Church-Turing, la cual dice que todo problema que pueda ser resuelto por al menos una configuración de la Máquina de Turing es computable, ya que esta, a pesar de sus instrucciones primitivas, puede simular cualquier otro conjunto de instrucciones utilizados por otras clases de computadoras.  

## Referencias
Sudkamp, T. (2016). Languages and machines: an introduction to the theory of computer science. Estados Unidos: Pearson.

Fenández, G. (2004). Representación del conocimiento en sistemas inteligentes. 3.7.3. Compleción y decidibilidad. Recuperado el 30 de abril de 2021 de http://dit.upm.es/~gfer/ssii/rcsi/rcsisu32.html

UCM (s. f.). Lógica y computabilidad. Autómatas y Computabilidad. Decidibilidad. Pág. 63. Recuperado el 30 de abril de 2021 de https://webs.ucm.es/info/pslogica/automatas.pdf
