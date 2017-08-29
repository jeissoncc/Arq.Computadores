QUE SON LAS INSTRUCCIONES SINTETICAS?

Las instrucciones sinteticas son la notación utilizada en las descripciones de sintaxis del lenguaje ensamblador y 
son utilizadas para la comodidad de los programadores.

ejemplo:

Synthetic Instruction ----- SPARC Instruction(s)------------Comment

cmp reg rs1,reg_or_imm----- subcc regrs1,reg_or_imm,%g0-----compare
jmp address-----------------jmpl address,%g0
call address----------------jmpl address,%o7
mov reg_or_imm,regrd--------or %g0,reg_or_imm,regrd 
