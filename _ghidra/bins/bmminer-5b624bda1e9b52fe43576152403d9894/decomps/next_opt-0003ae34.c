
/* WARNING: Unknown calling convention */

char * next_opt(char *p,uint *i,uint *len)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  
  uVar3 = *i;
  if (uVar3 < opt_count) {
    do {
      if (opt_table[uVar3].type != OPT_SUBTABLE) {
        if (p == (char *)0x0) {
          pcVar2 = opt_table[uVar3].names;
          cVar1 = pcVar2[1];
          uVar3 = 0;
          while ((((cVar1 != '\0' && (cVar1 != '|')) && (cVar1 != '=')) && (cVar1 != ' '))) {
            cVar1 = pcVar2[uVar3 + 2];
            uVar3 = uVar3 + 1;
          }
          *len = uVar3;
          return pcVar2 + 1;
        }
        pcVar2 = next_name(p,len);
        if (pcVar2 != (char *)0x0) {
          return pcVar2;
        }
        uVar3 = *i;
        p = (char *)0x0;
      }
      uVar3 = uVar3 + 1;
      *i = uVar3;
    } while (uVar3 < opt_count);
  }
  return (char *)0x0;
}

