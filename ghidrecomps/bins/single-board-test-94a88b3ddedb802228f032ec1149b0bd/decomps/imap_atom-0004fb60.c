
char * imap_atom(char *param_1,int param_2)

{
  size_t sVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  size_t sVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_28 = *DAT_0004fc50;
  uStack_24 = DAT_0004fc50[1];
  if (param_1 == (char *)0x0) {
    return (char *)0x0;
  }
  cVar7 = *param_1;
  if (cVar7 == '\0') {
LAB_0004fc42:
    pcVar4 = (char *)(**DAT_0004fc58)(param_1);
    return pcVar4;
  }
  bVar12 = false;
  uVar11 = 0;
  uVar10 = 0;
  pcVar4 = param_1;
  do {
    if (cVar7 == '\\') {
      uVar10 = uVar10 + 1;
    }
    else if (cVar7 == '\"') {
      uVar11 = uVar11 + 1;
    }
    else if ((param_2 == 0) && (!bVar12)) {
      pcVar2 = (char *)((int)&uStack_28 + 1);
      cVar8 = '(';
      cVar6 = ')';
      while ((bVar12 = cVar7 == cVar8, cVar6 != '\0' && (!bVar12))) {
        pcVar2 = pcVar2 + 1;
        cVar8 = cVar6;
        cVar6 = *pcVar2;
      }
    }
    pcVar4 = pcVar4 + 1;
    cVar7 = *pcVar4;
  } while (cVar7 != '\0');
  if ((uVar10 | uVar11) == 0) {
    if (!bVar12) goto LAB_0004fc42;
    sVar1 = strlen(param_1);
  }
  else {
    sVar9 = strlen(param_1);
    sVar9 = uVar10 + uVar11 + sVar9;
    sVar1 = sVar9;
    if (!bVar12) {
      pcVar2 = (char *)(**DAT_0004fc54)(sVar9 + 1);
      pcVar4 = pcVar2;
      if (pcVar2 == (char *)0x0) {
        return (char *)0x0;
      }
      goto LAB_0004fbf2;
    }
  }
  sVar9 = sVar1 + 2;
  pcVar2 = (char *)(**DAT_0004fc54)(sVar1 + 3);
  if (pcVar2 == (char *)0x0) {
    return (char *)0x0;
  }
  *pcVar2 = '\"';
  pcVar2[sVar1 + 1] = '\"';
  pcVar4 = pcVar2 + 1;
LAB_0004fbf2:
  cVar7 = *param_1;
  if (cVar7 != '\0') {
    pcVar5 = param_1 + -1;
    do {
      pcVar3 = pcVar4;
      if (cVar7 == '\\' || cVar7 == '\"') {
        pcVar3 = pcVar4 + 1;
        *pcVar4 = '\\';
      }
      pcVar4 = pcVar3 + 1;
      *pcVar3 = pcVar5[1];
      cVar7 = pcVar5[2];
      pcVar5 = pcVar5 + 1;
    } while (cVar7 != '\0');
  }
  pcVar2[sVar9] = '\0';
  return pcVar2;
}

