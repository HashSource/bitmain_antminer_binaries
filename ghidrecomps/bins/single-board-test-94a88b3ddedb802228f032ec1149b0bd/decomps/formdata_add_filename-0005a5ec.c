
undefined4
formdata_add_filename(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code **ppcVar1;
  char *pcVar2;
  size_t sVar3;
  undefined4 uVar4;
  char *pcVar5;
  char cVar6;
  code *pcVar7;
  char *pcVar8;
  char *pcVar9;
  code **ppcVar10;
  char *pcVar11;
  
  ppcVar1 = DAT_0005a6c8;
  if (*(char **)(param_1 + 0x2c) == (char *)0x0) {
    pcVar5 = (char *)(**DAT_0005a6c8)(*(undefined4 *)(param_1 + 0xc));
    ppcVar10 = DAT_0005a6bc;
    if (pcVar5 == (char *)0x0) {
      return 0x1b;
    }
    pcVar7 = *ppcVar1;
    __xpg_basename(pcVar5);
    pcVar11 = (char *)(*pcVar7)();
    (**ppcVar10)(pcVar5);
    pcVar5 = pcVar11;
    if (pcVar11 == (char *)0x0) {
      return 0x1b;
    }
  }
  else {
    pcVar11 = (char *)0x0;
    ppcVar10 = DAT_0005a6bc;
    pcVar5 = *(char **)(param_1 + 0x2c);
  }
  pcVar2 = strchr(pcVar5,0x5c);
  if ((pcVar2 == (char *)0x0) && (pcVar2 = strchr(pcVar5,0x22), pcVar2 == (char *)0x0)) {
    pcVar2 = (char *)0x0;
  }
  else {
    sVar3 = strlen(pcVar5);
    pcVar2 = (char *)(**DAT_0005a6c0)(sVar3 * 2 + 1);
    if (pcVar2 == (char *)0x0) {
      (**ppcVar10)(pcVar11);
      return 0x1b;
    }
    cVar6 = *pcVar5;
    pcVar9 = pcVar2;
    if (cVar6 != '\0') {
      pcVar5 = pcVar5 + -1;
      do {
        pcVar8 = pcVar9;
        if (cVar6 == '\\' || cVar6 == '\"') {
          pcVar8 = pcVar9 + 1;
          *pcVar9 = '\\';
        }
        pcVar9 = pcVar8 + 1;
        *pcVar8 = pcVar5[1];
        cVar6 = pcVar5[2];
        pcVar5 = pcVar5 + 1;
      } while (cVar6 != '\0');
    }
    *pcVar9 = '\0';
    pcVar5 = pcVar2;
  }
  uVar4 = AddFormDataf(param_2,param_3,DAT_0005a6c4,pcVar5,param_4);
  (**ppcVar10)(pcVar2);
  (**ppcVar10)(pcVar11);
  return uVar4;
}

