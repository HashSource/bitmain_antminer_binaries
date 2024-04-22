
undefined4 cookie_sort(int *param_1,int *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  size_t sVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = *param_1;
  iVar6 = *param_2;
  if (*(char **)(iVar5 + 0xc) == (char *)0x0) {
    pcVar4 = *(char **)(iVar6 + 0xc);
    if (pcVar4 != (char *)0x0) {
      uVar2 = 0;
      goto LAB_0003e8aa;
    }
  }
  else {
    uVar2 = strlen(*(char **)(iVar5 + 0xc));
    pcVar4 = *(char **)(iVar6 + 0xc);
    if (pcVar4 == (char *)0x0) {
      if (uVar2 != 0) {
        return 0xffffffff;
      }
    }
    else {
LAB_0003e8aa:
      sVar3 = strlen(pcVar4);
      if (uVar2 != sVar3) {
        if (sVar3 <= uVar2) {
          return 0xffffffff;
        }
        return 1;
      }
    }
  }
  if (*(char **)(iVar5 + 0x14) == (char *)0x0) {
    pcVar4 = *(char **)(iVar6 + 0x14);
    if (pcVar4 == (char *)0x0) goto LAB_0003e8e6;
    uVar2 = 0;
  }
  else {
    uVar2 = strlen(*(char **)(iVar5 + 0x14));
    pcVar4 = *(char **)(iVar6 + 0x14);
    if (pcVar4 == (char *)0x0) {
      if (uVar2 != 0) {
        return 0xffffffff;
      }
      goto LAB_0003e8e6;
    }
  }
  sVar3 = strlen(pcVar4);
  if (uVar2 != sVar3) {
    if (sVar3 <= uVar2) {
      return 0xffffffff;
    }
    return 1;
  }
LAB_0003e8e6:
  if (*(int *)(iVar5 + 4) == 0) {
    return 0;
  }
  if (*(int *)(iVar6 + 4) == 0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00012410. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR_LAB_00194368)();
  return uVar1;
}

