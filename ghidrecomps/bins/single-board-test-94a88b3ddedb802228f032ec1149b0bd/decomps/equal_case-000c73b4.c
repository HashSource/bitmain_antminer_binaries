
int equal_case(char *param_1,uint param_2,void *param_3,uint param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  char cVar4;
  char *pcVar5;
  char *pcVar6;
  uint __n;
  
  pcVar3 = param_1;
  if (param_5 << 0x10 < 0) {
    uVar1 = param_2;
    if ((param_4 < param_2) && (cVar4 = *param_1, cVar4 != '\0')) {
      pcVar5 = param_1;
      if (param_5 << 0x1b < 0) {
        do {
          pcVar6 = pcVar5 + 1;
          pcVar3 = pcVar5;
          if ((cVar4 == '.') || (uVar1 = uVar1 - 1, pcVar3 = pcVar6, uVar1 <= param_4)) break;
          cVar4 = pcVar5[1];
          pcVar5 = pcVar6;
        } while (cVar4 != '\0');
      }
      else {
        pcVar5 = param_1 + 1;
        do {
          uVar1 = uVar1 - 1;
          pcVar3 = pcVar5;
          if (uVar1 <= param_4) break;
          cVar4 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar4 != '\0');
      }
    }
    __n = param_4;
    if (param_4 == uVar1) goto LAB_000c73ec;
  }
  pcVar3 = param_1;
  __n = param_2;
  if (param_4 != param_2) {
    return 0;
  }
LAB_000c73ec:
  uVar1 = memcmp(pcVar3,param_3,__n);
  iVar2 = 1 - uVar1;
  if (1 < uVar1) {
    iVar2 = 0;
  }
  return iVar2;
}

