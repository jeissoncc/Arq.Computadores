Los registros de control / estado IU de 32 bits incluyen:
* el registro de estado del procesador (PSR)

- EC, EF: determinan habilitación de los coprocesadores
- Obs: se puede controlar acceso del software a coprocesadores utilizando estos bits
- PIL: interrupt_level
- S: Bit Supervisor
- PS: bit previous_supervisor. Contiene el valor de S cuando ocurrió el trap más reciente
- ET: Enable_traps. Un trap pone este bit ET = 0
- CWP: Current Window Pointer
- El hardware decrementa el CWP en las traps e instrucciones SAVE, y lo incrementa en las instrucciones RESTORE y RETT
(modulo NWINDOWS).

* El registro de la máscara de la ventana inválida (WIM) 

El WIM (controlado por software supervisor) determina si se genera un trap de window overflow o
underflow cuando se ejecuta SAVE, RESTORE, o RETT:
New_CWP=CWP±1 mod NWINDOWS Si WIM[New_CWP] =1 -> trap
-  window_overflow:-  Causado por un SAVE cuando New_CWP apunta a una ventana invalidada en el WIM
-  window_underflow:-  Causado por un RESTORE o RETT cuando New_CWP apunta a una ventana invalidada en el WIM
-  WIM se accede mediante RDWIM y WRWIM

* el registro base de la trap (TBR)

- Contiene campos que permiten determinar la dirección de losmanejadores de traps:

  :- TBR_trap_base_address (TBA): 20 bits más significativos de la dirección de la trap table (escrito por WRTBR)
  :- TBR_trap_type (tt): este campo de 8 bits es escrito por el hardware cuando se produce un trap, y mantiene el valor hasta
     el siguiente trap. Es el offset en la trap table. Dado quelos 4 bits menos significativos son cero, cada entrada de la trap table
     contiene los primeros 16 bytes (4 palabras) del manejador de trap correspondiente.
         • Valores 0 al 0x7F reservados para traps de hardware traps
         • Valores 0x80 al 0xFF reservados para traps de software traps (instrucciones Ticc)
- TBR_zero (0): campo fijo en cero

* el Registro Multiplicar / dividir (Y)

* los contadores de programa (PC y nPC)

- PC:- Dirección de la instrucción en ejecución
- nPC:- Dirección de la próxima instrucción a ser ejecutada (si noocurre un trap)
   :- En un salto retardado el PC apunta a la instrucción retardada, mientras que el nPC apunta al destino del salto
- PC es leído por el CALL o JMPL.
- En un trap PC y nPC se copian en los registros r[17] y r[18](locales 1 y 2) en la ventana

* y opcional, Los registros de estados auxiliares dependientes de la implementación (ASRs) y los IU
Cola de tramp diferida.

