# Distributed Programming

> Sergio Nesmachnow (sergion@fing.edu.uy)
>
> Universidad de la Republica, Uruguay

- [Distributed Programming](#distributed-programming)
  - [Computación Distribuida](#computaci%C3%B3n-distribuida)
  - [Cluster](#cluster)
  - [Modelo de Programación Paralela](#modelo-de-programaci%C3%B3n-paralela)
    - [Diseño de Algoritmos Paralelos](#dise%C3%B1o-de-algoritmos-paralelos)
    - [Técnicas de Computacion Paralela-Distribuida](#t%C3%A9cnicas-de-computacion-paralela-distribuida)
- [MPI](#mpi)
  - [Conceptos](#conceptos)
  - [Modos de Envio](#modos-de-envio)
  - [Rutinas Basicas de MPI](#rutinas-basicas-de-mpi)
  - [Modos de Comunicación](#modos-de-comunicaci%C3%B3n)

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

## Modelo de Programación Paralela

Dificultades de la programación paralela:

- Multiejecución simultanea
- Sincronización

Niveles de Paralelismo:

- Intrainstrucción
- Interinstruccion
- Algoritmico funcional
- Algoritmico tareas

Estrategias de Programación PAralela

- Implicito o automático
- Explicito utilizando bibliotecas
- Explicito con rediseño del código

### Diseño de Algoritmos Paralelos

**Descomposicion**:
Identifica los procesos concurrentes y decide el nivel y l forma en la cual se explotara la concurrencia

**Asignación**:
Asigna los datos a los procesos concurrentes. La asignación puede ser estatica o dinámica. Se requiere balance de cargas.

**Orquestación**:
Decisiones sobre los parametros de arquitectura, modelo de programación, lenguajes, bibliotecas.

**Mapeo (Scheduling)**:
Asigna los procesos a los recursos. Criterios: Desempeño, utilización, reducción de costos.

---

Los mecanismos para definir, controlar y sincronizar tareas debe permitir

- Control de flujo de ejecución de instrucciones
- Particionamiento de los datos

### Técnicas de Computacion Paralela-Distribuida

Descomposición:

- Definir mas tareas que procesadores disponibles
- Evitar calculos redundantes
- Generar tareas de tamaño comparable
- Generar tareas escalables con el tamaño del problema

---

1. La descomposición de dominio consiste en el particionamiento de los datos (_data parallelism_) del problema. Se dividen los datos en piezas pequeñas de aproximadamente el mismo tamaño

1. Descomposición funcional

1. Paralelismo optimista

1. Modelo maestro-esclavo

1. Modelos híbridos

# MPI

Message Passing Interface

Procesos en ejecución se comunican mediante mensajes explicitos

```c
// Envio de mensajes
send(origen, destino, tipo, msg, flags)

// Recepción de mensajes
receive(origen, destino, tipo, msg, flags)
```

Es un estandar que define un API para la comunicación entre procesos paralelos distribuidos. Existen varias implementaciones.

## Conceptos

MPI trabaja con el esquema de SPMD (Single Program, Multiple Data)

- **Rango**: Identificador del proceso (numero entero).
- **Grupo**: Conjunto ordenado (_relevante_) de N procesos. Los mismos procesos, en otro orden, son otro grupo.
- **Contexto**: Asociación del comunicador con los grupos.
- **Comunicador**: Asocia los conceptos de grupo y contexto para proveer un espacio común para la comunicación entre procesos. Los mensajes se dan en el contexto de un comunicador. Por lo que los mensajes deben especificar el comunicador
- **Buffer de la aplicación**: Espacio de memoria que contiene datos a enviar o recibir por el programa. Es manejado por el programador
- **Buffer del sistema**: Espacio de memoria del sistema (MPI) para almacenar mensajes

## Modos de Envio

- **Modos Bloqueantes**: Suspende la ejecución del programa hasta que el buffer que se esta enviando/recibiendo sea segura de usar. Es decir, continua cuando se haya hecho la copia del buffer de la aplicación al buffer del sistema, no necesariamente cuando la otra tarea reciba el mensaje (eso es "sincrono")
- **Modos No Bloqueantes**: Retorna inmediatamente despues de ser iniciada la comunicación. El programador no sabe si los datos han sido enviados o copiados al buffer del sistema (envio) o si los datos a ser recibifos han llegado.

## Rutinas Basicas de MPI

**Inicializar**: Se debe poner al inicio de la sección paralela

```
iterr = MPI_Init(&argc, &argv)
```

**Numero de procesos en ejecución**: Utiliza el comunicador global

```
iterr = MPI_Comm_size(MPI_COMM_WORLD, &npes)
```

**Identificador del proceso en su contexto de comunicación**

```
iterr = MPI_Comm_rank(MPI_COMM_WORLD, &iam)
```

**Envio de mensajes**

```
iterr = MPI_Send(buff, count, datatype, destination, tag, comm)
```

**Recepción de mensajes**

```
iterr = MPI_Recv(buff, count, datatype, source, tag, comm, state)
```

**Finalizar**

```
iterr = MPI_Finalize()
```

## Modos de Comunicación

- **Envio Estandar**: Asincronico. Su comportamiento (uso de buffers) depende de la implementación
- **Envio Sincronico**: Bloquea el proceso hasta que el proceso destino/receptor realice la operación de recepción correspondiente
- **Envio Buffereado**: El programador reserva un buffer para los datos que puedan ser enviados. Ofrece seguridad sobre el espacio de bufffer
- **Envio Pronto**: Se utiliza si se sabe que el receptor esta esperando el envio de antemano. Permite no utilizar buffer.
