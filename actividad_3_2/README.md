# Actividad 3.2

Implementación de autómata finito determinista en c++  

Este programa recibe como entrada un archivo .txt con una serie de expresiones aritméticas, y entrega como salida el conjunto de tokens reconocidos, indicando su tipo, o indicando que hay un error en su formación, es decir, que no se respetaron las reglas establecidas.  

Para compilar con g++:
```
g++ -std=c++17 DFA.cpp 
```

Si quieres leer un archivo de texto (.txt) distinto al de este repositorio, cambia el nombre del archivo en la línea 222 de DFA.cpp.
```
automata.lexerAritmetico("laDireccionDeTuArchivo.txt");
```

Para más información, véase nuestro manual de uso: https://docs.google.com/document/d/1RBXhst_ivTDAc2rLpML0-wKuzFj-HESoIYYutK0vuHs/edit?usp=sharing
Video demostrativo: https://www.youtube.com/watch?v=Ml4JY6OI4-o
