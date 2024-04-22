
undefined4 check_gzip_header_part_0(int param_1,int param_2,int *param_3)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  
  bVar1 = *(byte *)(param_1 + 3);
  uVar7 = (uint)bVar1;
  if ((*(char *)(param_1 + 2) != '\b') || ((bVar1 & 0xe0) != 0)) {
    return 1;
  }
  iVar5 = param_2 + -10;
  pcVar6 = (char *)(param_1 + 10);
  if ((bVar1 & 4) == 0) {
LAB_0004cf14:
    if ((int)(uVar7 << 0x1c) < 0) {
      if (iVar5 == 0) goto LAB_0004cf30;
      cVar2 = *pcVar6;
      while (cVar2 != '\0') {
        pcVar6 = pcVar6 + 1;
        iVar5 = iVar5 + -1;
        if (iVar5 == 0) goto LAB_0004cf30;
        cVar2 = *pcVar6;
      }
      iVar5 = iVar5 + -1;
      pcVar6 = pcVar6 + 1;
    }
    if ((int)(uVar7 << 0x1b) < 0) {
      if (iVar5 == 0) goto LAB_0004cf30;
      cVar2 = *pcVar6;
      while (cVar2 != '\0') {
        iVar5 = iVar5 + -1;
        if (iVar5 == 0) goto LAB_0004cf30;
        pcVar6 = pcVar6 + 1;
        cVar2 = *pcVar6;
      }
      iVar5 = iVar5 + -1;
    }
    if ((int)(uVar7 << 0x1e) < 0) {
      if (iVar5 < 2) goto LAB_0004cf30;
      iVar5 = iVar5 + -2;
    }
    uVar3 = 0;
    *param_3 = param_2 - iVar5;
  }
  else {
    if ((1 < iVar5) && (uVar4 = (uint)*(ushort *)(param_1 + 10), (int)(uVar4 + 1) < iVar5)) {
      pcVar6 = pcVar6 + uVar4 + 2;
      iVar5 = iVar5 + (-2 - uVar4);
      goto LAB_0004cf14;
    }
LAB_0004cf30:
    uVar3 = 2;
  }
  return uVar3;
}

