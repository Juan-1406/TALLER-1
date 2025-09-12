Integrantes: Juan David Alvarado Galleguillos / 22.142.173-6

Este proyecto permite gestionar alumnos, cursos, notas e inscripciones de una forma sensilla. Ofreciendo la 
posibilidad de crear cursos y alumnos, asignarlos entre si e ingresando sus notas. Facilitando la entrega de 
datos de una forma más ordenada para su lectura. Ademas permitiendo obtener los promedios de cada alumno, ya 
sea de un curso en específico o de manera general.

Estructura del Proyecto: Se mencionan las clases creadas para la funcionalidad del proyecto.

  CLASE PRINCIPAL
    - Main.cpp -> Contiene la organización de cada uno de los menú que se pueden utilizar en el 
                  proyecto junto con la funcionalidad de cada uno de ellos.
  OBJETOS
    - Alumno.h / Alumno.cpp -> Clase Alumno
    - Curso.h / Curso.cpp -> Clase Curso
    - Inscripcion.h / Inscripcion.cpp -> Clase Inscripción
    - Nota.h / Nota.cpp -> Clase Nota
  NODOS
    - NodoAlumno.h / NodoAlumno.cpp -> Nodo que guarda un alumno
    - NodoCurso.h / NodoCurso.cpp -> Nodo que guarda un curso
    - NodoInscripcion.h / NodoInscripcion.cpp -> Nodo que guarda una inscripción
    - NodoNota.h / NodoNota.cpp -> Nodo que guarda una nota
  LISTAS
    - ListAlumnos.h / ListAlumnos.cpp -> Se implementa la lista enlazada de alumnos
    - ListCursos.h / ListCursos.cpp -> Se implementa la lista enlazada de cursos
    - ListInscripciones.h / ListInscripciones.cpp -> Se implementa la lista enlazada de inscripciones
    - ListNotas.h / ListNotas.cpp -> Se implementa la lista enlazada de notas

Ejemplo de Ejeccución (Manejo de Alumnos):
                --- MENU PRINCIPAL ---
                1. Manejo de Alumnos
                2. Manejo de Cursos
                3. Manejo de Inscripciones
                4. Manejo de Notas
                5. Consultas y Reportes
                0. Salir
                Ingrese una opcion:1
                
                --- MANEJO DE ALUMNOS ---
                1. Crear Alumno
                2. Buscar Alumno
                3. Eliminar Alumno
                0. Salir
                Ingrese una opcion:1
                ID:1
                Nombre:Sebastian
                Apellido:Contreras
                Carrera:IngenierIa Civil Industrial
                Fecha Ingreso (Year):2024
                
                Alumno/a creado con exito!
