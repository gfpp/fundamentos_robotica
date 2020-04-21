# Fundamentos de Robótica Móvil

 * [Instalación del toolchain y puesta en marcha del ejemplo](docs/Arrancando.md)
 * [Documentación de las distintas capas de programación](docs/Documentacion.md)

## Programación del robot EduRoMAA

En el directorio `eduromaa/lib` se encuentra la biblioteca de progamación del robot EduRoMAA. 
La misma fue copiada del [repositorio de desarrollo del robot](https://github.com/ciiiutnfrc/eduromaa).
La biblioteca está compuesta por un conjunto de módulos (par de archivos `.h` y `.c`) para los diferentes componentes del robot, tales como: `bocina`, `motores`, `paragolpes`, etc. Los demás directorios bajo `eduromaa` son:
 * `prueba`: código fuente de prueba de cada módulo de la biblioteca
 * `app`:  programas de ejemplo del robot que utiliza varios de sus componentes

Por otro lado, la placa [EduCIAA](http://www.proyecto-ciaa.com.ar/devwiki/doku.php?id=desarrollo:edu-ciaa:edu-ciaa-nxp), que conforma el sistema embebido del robot, puede ser programada de forma directa utilizando por ejemplo la biblioteca [sAPI](https://github.com/ciaa/firmware_v3/blob/master/documentation/firmware/examples/examples-es.md), sin necesidad de usar la biblioteca de programación del propio robot. En el directorio `educiaa` se encuentra un ejemplo que hace parpadear un LED de la placa.

Los programas que se desarrollen utilizando la biblioteca de programación del robot se deben colocar bajo el directorio `eduromaa/app` o bien bajo el directorio `educiaa` en caso contrario.

Para construir los diferentes proyectos se debe modificar el archivo `program.mk` donde se definen las variables:
 * `PROGRAM_PATH`: directorio del programa a construir
 * `PROGRAM_NAME`: nombre del programa a construir

Por ejemplo, si se quiere construir el ejemplo de la EduCIAA (`blinky`), las variables deben ser: `PROGRAM_PATH=educiaa` y `PROGRAM_NAME=blinky`; y si se quiere construir el ejemplo del EduRoMAA (`paragolpes`), `PROGRAM_PATH=eduromaa/app` y `PROGRAM_NAME=00_paragolpes`.


## Links útiles

 * [Repositorio del robot EduRoMAA](https://github.com/ciiiutnfrc/eduromaa)
 * [Página de la EduCIAA-NXP](http://www.proyecto-ciaa.com.ar/devwiki/doku.php?id=desarrollo:edu-ciaa:edu-ciaa-nxp)
 * [Repositorio principal del proyecto CIAA](https://github.com/ciaa)
 * [Repositorio del firmware de la EduCIAA](https://github.com/ciaa/firmware_v3)
 * [Documentación de biblioteca sAPI](https://github.com/ciaa/firmware_v3/blob/master/libs/sapi/documentation/api_reference_es.md)
