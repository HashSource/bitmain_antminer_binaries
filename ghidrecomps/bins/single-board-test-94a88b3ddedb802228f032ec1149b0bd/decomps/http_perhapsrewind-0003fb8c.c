
undefined4 http_perhapsrewind(int *param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  size_t sVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  
  iVar10 = *param_1;
  iVar4 = *(int *)(iVar10 + 0x14c);
  if (iVar4 == 0) {
    return 0;
  }
  iVar6 = *(int *)(iVar10 + 0x278);
  if (iVar6 == 1) {
    return 0;
  }
  if (iVar6 == 5) {
    return 0;
  }
  cVar1 = *(char *)((int)param_1 + 0x1fb);
  uVar8 = *(uint *)(iVar4 + 0x28);
  uVar9 = *(uint *)(iVar4 + 0x2c);
  if (cVar1 == '\0') {
    uVar2 = 0;
    if (*(char *)(param_1 + 0x7e) == '\0') {
      sVar5 = 0;
      uVar7 = 0;
      goto LAB_0003fbb6;
    }
    if (iVar6 == 3) {
      sVar5 = *(uint *)(iVar4 + 8);
      uVar7 = *(uint *)(iVar4 + 0xc);
      uVar2 = (uint)((sVar5 & uVar7) == 0xffffffff);
      goto LAB_0003fbb6;
    }
    if (iVar6 == 4) {
      sVar5 = *(uint *)(iVar10 + 0x86b0);
      uVar7 = *(uint *)(iVar10 + 0x86b4);
      if (uVar7 == 0xffffffff && sVar5 == 0xffffffff) goto LAB_0003fbf0;
      goto LAB_0003fbb6;
    }
    if (iVar6 == 2) {
      sVar5 = *(uint *)(iVar10 + 0x86b0);
      uVar7 = *(uint *)(iVar10 + 0x86b4);
      if (uVar7 == 0xffffffff && sVar5 == 0xffffffff) {
        if (*(char **)(iVar10 + 0x18c) == (char *)0x0) goto LAB_0003fbf0;
        sVar5 = strlen(*(char **)(iVar10 + 0x18c));
        uVar2 = 0;
        uVar7 = uVar2;
      }
      goto LAB_0003fbb6;
    }
LAB_0003fbf0:
    sVar5 = 0xffffffff;
    uVar7 = 0xffffffff;
    *(undefined *)(param_1 + 0x7f) = 0;
  }
  else {
    uVar2 = 0;
    sVar5 = 0;
    uVar7 = 0;
LAB_0003fbb6:
    if ((int)((uVar9 - uVar7) - (uint)(uVar8 < sVar5)) < 0 !=
        (SBORROW4(uVar9,uVar7) != SBORROW4(uVar9 - uVar7,(uint)(uVar8 < sVar5)))) {
      uVar2 = 1;
    }
    *(undefined *)(param_1 + 0x7f) = 0;
    if (uVar2 == 0) goto LAB_0003fbcc;
  }
  if ((((*(int *)(iVar10 + 0x8634) == 8) || (*(int *)(iVar10 + 0x8624) == 8)) ||
      (*(int *)(iVar10 + 0x8634) == 0x20)) || (*(int *)(iVar10 + 0x8624) == 0x20)) {
    iVar4 = (uVar7 - uVar9) - (uint)(sVar5 < uVar8);
    bVar11 = sVar5 - uVar8 < 2000;
    if ((((int)(iVar4 - (uint)bVar11) < 0 != (SBORROW4(iVar4,(uint)bVar11) != false)) ||
        (param_1[0x9d] != 0)) || (param_1[0xa3] != 0)) {
      if (cVar1 != '\0') {
        return 0;
      }
      *(undefined *)(param_1 + 0x7f) = 1;
      Curl_infof(iVar10,DAT_0003fce0);
      return 0;
    }
    if (*(char *)((int)param_1 + 0x1ed) != '\0') {
      return 0;
    }
    Curl_infof(iVar10,DAT_0003fce4);
  }
  *(undefined *)((int)param_1 + 0x1ed) = 1;
  *(undefined4 *)(iVar10 + 0x50) = 0;
  *(undefined4 *)(iVar10 + 0x54) = 0;
LAB_0003fbcc:
  if ((uVar8 | uVar9) == 0) {
    return 0;
  }
  uVar3 = Curl_readrewind(param_1);
  return uVar3;
}

