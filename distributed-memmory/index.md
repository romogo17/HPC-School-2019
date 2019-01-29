# Distributed Programming

> Sergio Nesmachnow (sergion@fing.edu.uy)
>
> Universidad de la Republica, Uruguay

- [Distributed Programming](#distributed-programming)
  - [Computación Distribuida](#computaci%C3%B3n-distribuida)
  - [Cluster](#cluster)

**Memoria Distibuida**: No es una colección de memorias agregables (memoria compartida). Las memorias son separadas y no son direccionables por el equipo o procesos.

No hay un recurso global de memoria.

## Computación Distribuida

Multiples procesos utilizan multiples recursos de computo de modo cooperativo.

La cooperacion entre procesos se logra a travez de comunicaciones y sincronizaciones

La comuniacion debe hacerse mediante mecanismos de IPC (inter process communication) sobre una red. Cada comunicación es un cuello de botella en cuanto al costo que tendría la implementacion en memoria compartida.

**Arquitecturas Paralelas Distribuida**

Esta arquitectura es altamente escalable y con una muy buena disponibilidad, en contraposición a la memoria compartida.

## Cluster

Es una agregación de recursos de cómputo. Múltiples recursos de computo funcionando de modo coordinado para resolver un problema global.

El _cluster middleware_ ofrece la infraestructura necesaria para soportar _Single System Image_ (SSI), que globaliza los recursos del equipo y los hce ver como un único equipo; y _System Availability_ (SA) que provee la disponibilidad mediante migracion de procesos, replicación de datos, etc.
