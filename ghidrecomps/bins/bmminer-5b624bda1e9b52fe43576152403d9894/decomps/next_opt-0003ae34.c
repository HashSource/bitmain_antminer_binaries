
/* WARNING: Unknown calling convention */

char * next_opt(char *p,uint *i,uint *len)

{
  char cVar1;
  uint *puVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  
  piVar3 = DAT_0003aeb4;
  puVar2 = DAT_0003aeb0;
  uVar6 = *i;
  if (uVar6 < *DAT_0003aeb0) {
    do {
      piVar7 = (int *)(*piVar3 + uVar6 * 0x1c);
      if (piVar7[1] != 8) {
        if (p == (char *)0x0) {
          iVar5 = *piVar7;
          uVar6 = 0;
          cVar1 = *(char *)(iVar5 + 1);
          while ((((cVar1 != '\0' && (cVar1 != '|')) && (cVar1 != '=')) && (cVar1 != ' '))) {
            uVar6 = uVar6 + 1;
            cVar1 = *(char *)(iVar5 + uVar6 + 1);
          }
          *len = uVar6;
          return (char *)(iVar5 + 1);
        }
        pcVar4 = next_name(p,len);
        if (pcVar4 != (char *)0x0) {
          return pcVar4;
        }
        uVar6 = *i;
        p = (char *)0x0;
      }
      uVar6 = uVar6 + 1;
      *i = uVar6;
    } while (uVar6 < *puVar2);
  }
  return (char *)0x0;
}

