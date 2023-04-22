# LMAO

## Resumen
**Lector de Mapas de estructura Alámbrica Open source** es un pequeño programa gráfico desarrollado como proyecto de aprendizaje para la escuela 42 Madrid.
Está escrito acorde a unas normas internas que limitan tanto el uso de funciones externas como el tamaño y formato de estas.

## Dependencias
LMAO hace uso de la minilibx para gestionar gráficos, una versión simplificada de Libx desarrollada para uso en 42
```
https://github.com/42Paris/minilibx-linux
```

## Uso
Es necesario inicializar y actualizar los submódulos antes de compilar el programa.
```
git submodule init libft && git submodule update libft
```

Para compilar simplemente haz ```make``` en el fichero raíz del repositorio

Debes llamar al programa pasándole el mapa con el formato correcto como argumento, por ejemplo:
```
./fdf example.fdf
```

## Licencia
Este programa se distribuye sin ninguna garantía bajo la licencia GPL3 (se incluye una copia de la licencia en el repositorio)
