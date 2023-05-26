# LMAO

## Resumen
**Lector de Mapas de estructura Alámbrica Open source** es un pequeño programa gráfico desarrollado como proyecto de aprendizaje para la escuela 42 Madrid.
Está escrito acorde a unas normas internas que limitan tanto el uso de funciones externas como el tamaño y formato de estas.

## Dependencias
LMAO hace uso de la [minilibx](https://github.com/42Paris/minilibx-linux) para gestionar gráficos, una versión simplificada de Libx desarrollada para uso en 42

## Uso
Es necesario inicializar y actualizar los submódulos antes de compilar el programa.
```
git submodule init libft && git submodule update libft
```

Para compilar simplemente haz ```make``` en el fichero raíz del repositorio
Para usar las opciones de mover y ampliar el mapa puedes usar la regla bonus:
```make bonus```

Debes llamar al programa pasándole el mapa con el formato correcto como argumento, por ejemplo:
```
./fdf test_maps/pylone.fdf
```

Los controles para la parte bonus son:
  - Teclas '+' & '-' para hacer zoom
  - Teclas 'Page_up' & 'Page_down' para aumentar/disminuir la altura del mapa
  - Teclas de dirección para mover el mapa

## Licencia
Este programa se distribuye sin ninguna garantía bajo la licencia GPL3 (se incluye una copia de la licencia en el repositorio)
