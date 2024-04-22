
/* WARNING: Unknown calling convention */

char * first_opt(uint *i,uint *len)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  int *piVar8;
  bool bVar9;
  
  puVar4 = DAT_0003ae2c;
  *i = 0;
  if (*puVar4 == 0) {
LAB_0003ae22:
    pcVar6 = (char *)0x0;
  }
  else {
    piVar8 = *DAT_0003ae30;
    if (piVar8[1] == 8) {
      uVar7 = 1;
      piVar3 = piVar8;
      do {
        piVar8 = piVar3 + 7;
        *i = uVar7;
        if (*puVar4 <= uVar7) goto LAB_0003ae22;
        piVar1 = piVar3 + 8;
        uVar7 = uVar7 + 1;
        piVar3 = piVar8;
      } while (*piVar1 == 8);
    }
    iVar5 = *piVar8;
    uVar7 = (uint)*(byte *)(iVar5 + 1);
    if (uVar7 != 0) {
      if ((uVar7 == 0x7c) || (uVar7 == 0x3d)) {
        uVar7 = 0;
      }
      else {
        bVar9 = uVar7 != 0x20;
        uVar7 = 0;
        if (bVar9) {
          do {
            uVar7 = uVar7 + 1;
            cVar2 = *(char *)(iVar5 + uVar7 + 1);
            if (((cVar2 == '\0') || (cVar2 == '|')) || (cVar2 == '=')) break;
          } while (cVar2 != ' ');
        }
      }
    }
    pcVar6 = (char *)(iVar5 + 1);
    *len = uVar7;
  }
  return pcVar6;
}

