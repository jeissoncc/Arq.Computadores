PARCIAL I ARQUITECTURA DE COMPUTADORES

4. Explique cómo inicializar un valor grande, que ocupe más de 13 bits, en la arquitectura SPARC V8.
- Para inicializar valores mayores a 13 bits se realiza el siguiente procedimiento:
1. Se asigna registro A = 38000               A = %L0
2. se convierte el valor a binario:
38000 = 1 0 0 1 0 1 0 0 0 1 1 1 0 0 0 0
3. se completa 32 bits con cero o uno dependiendo el valor, si es positivo con ceros si es negativo con unos
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 1 0 0 0 1 1 1 0 0 0 0
4. se seleccionan los 22 bits más significativos izquierda a derecha
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 1 0 0 0 1 1 1 0 0 0 0


4. luego de obtener los valores se procede a inicializar con las siguientes instrucciones:
SETHI 37, %L0
OR %L0, 112, %L1

