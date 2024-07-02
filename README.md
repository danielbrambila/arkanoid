# Juego de Arcanoid

![PortadaArkanoid](https://github.com/RoTtiN2/PROGRAMAS-TERCERO/assets/160083533/b7705685-a0ec-4537-a689-3bbed128dbbd)
![arkanoid 2](https://github.com/RoTtiN2/Arkanoid/assets/160083533/6d284602-8fbd-46cc-af72-9cec77021359)
![arkanoid 1](https://github.com/RoTtiN2/Arkanoid/assets/160083533/fab76246-9cfe-4e83-aa4c-f801c66ccaf9)

Este proyecto implementa el clásico juego arcade "Arkanoid" usando la biblioteca SFML en C++. Controla una paleta para rebotar una bola y romper bloques, evitando que la bola caiga fuera de la pantalla.

## Características

- **Mecánicas del Juego**: Control de paleta y bola con colisiones realistas.
- **Bloques**: Diversidad de bloques de colores que se rompen al impacto.
- **Power-Up**: Ocasional aumento del tamaño de la paleta.
- **Efectos de Sonido**: Sonidos para colisiones y eventos clave del juego.
- **Condiciones de Juego**: Gana al eliminar todos los bloques, pierde si la bola cae.

## Requisitos

### Entorno de Desarrollo

- [Visual Studio Code](https://code.visualstudio.com/)
- [MSYS2](https://www.msys2.org/)
- [Github Desktop](https://desktop.github.com/)
- [Git](https://git-scm.com/)

### Bibliotecas Necesarias

1. **SFML**: `mingw-w64-x86_64-sfml`
2. **Box2D**: `mingw-w64-x86_64-box2d`

## Configuración de Visual Studio Code

- **Extensiones**: Material Icon Theme, C/C++ Extension Pack, Plant UML, CMake Tools, GitGraph.

## Instalación

1. **Clonar el Repositorio**:

   ```bash
   git clone https://github.com/yourusername/arcanoid-game.git
   ```

2. **Compilar el Proyecto**:

   ```bash
   cd arcanoid-game
   g++ -o arcanoid main.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
   ```

## Uso

1. **Ejecutar el Juego**:

   ```bash
   ./Main o en visual studio make runMain
   ```

2. **Controles**:

   - Flecha izquierda y derecha para mover la paleta.
   - Rebotar la bola para romper bloques y ganar puntos.
   - Recoger el power-up para agrandar la paleta temporalmente.

## Estructura del Juego

- **Variables y Estructuras**: Bloques, power-ups, bola, paleta y estado del juego.
- **Inicialización**: Ventana, formas, fuentes y sonidos.
- **Bucle del Juego**: Eventos, lógica y renderizado.

## Recursos

- **Activos**: Asegurar ubicación correcta de fuentes y sonidos.

## Desarrollador

Luis Daniel Brambila Ramos Reg 23110116

## Agradecimientos

A la comunidad de SFML por su biblioteca multimedia.

## Licencia

Licenciado bajo la Licencia MIT.
```

Este README ahora contiene todas las secciones esenciales en un formato único y claro, proporcionando toda la información necesaria para entender, instalar, ejecutar y utilizar el juego "Arcanoid" desarrollado con SFML en C++.
