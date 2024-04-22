
uint tls1_shared_curve(int param_1,uint param_2)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  bool bVar10;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    return 0xffffffff;
  }
  if ((param_2 == 0xfffffffe) &&
     (param_2 = *(uint *)(*(int *)(param_1 + 0x98) + 0x38) & 0x30000, param_2 != 0)) {
    iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 8);
    if (iVar4 == 0x300c02b) {
      return 0x19f;
    }
    if (iVar4 == 0x300c02c) {
      return 0x2cb;
    }
    return 0;
  }
  uVar5 = *(uint *)(param_1 + 0x100) & 0x400000;
  if (uVar5 == 0) {
    uVar7 = *(uint *)(*(int *)(param_1 + 0x98) + 0x38) & 0x30000;
    if (uVar7 == 0x20000) {
      uVar7 = 2;
      pcVar8 = DAT_00070a2c;
      goto LAB_00070852;
    }
    pcVar8 = DAT_00070a30;
    if (uVar7 == 0x30000) {
      uVar7 = 4;
      goto LAB_00070852;
    }
    if (uVar7 == 0x10000) {
      uVar7 = 2;
      goto LAB_00070852;
    }
    uVar7 = *(uint *)(param_1 + 0x14c);
    pcVar8 = *(char **)(param_1 + 0x150);
    if (*(char **)(param_1 + 0x150) != (char *)0x0) goto LAB_00070852;
    if (*(int *)(*(int *)(param_1 + 0x98) + 0x34) == 0) {
      uVar7 = 0x1c;
      pcVar8 = DAT_00070a1c + 0x1c;
    }
    else {
      uVar7 = 0xd;
      pcVar8 = DAT_00070a1c;
    }
LAB_0007098e:
    pcVar6 = *(char **)(*(int *)(param_1 + 0xc0) + 0xe0);
    uVar2 = *(uint *)(*(int *)(param_1 + 0xc0) + 0xdc);
    goto LAB_0007099a;
  }
  uVar7 = *(uint *)(*(int *)(param_1 + 0xc0) + 0xdc);
  pcVar8 = *(char **)(*(int *)(param_1 + 0xc0) + 0xe0);
LAB_00070852:
  if ((int)(uVar7 << 0x1f) < 0) goto LAB_000709b8;
  uVar7 = uVar7 >> 1;
  if (uVar5 == 0) goto LAB_0007098e;
  uVar2 = *(uint *)(*(int *)(param_1 + 0x98) + 0x38) & 0x30000;
  if (uVar2 == 0x20000) {
    uVar2 = 2;
    pcVar6 = DAT_00070a2c;
LAB_0007099a:
    if ((int)(uVar2 << 0x1f) < 0) {
LAB_000709b8:
      ERR_put_error(0x14,0x152,0x44,DAT_00070a28,0x200);
      return 0;
    }
    uVar2 = uVar2 >> 1;
    uVar9 = uVar5;
    if (uVar7 == 0) goto joined_r0x000709a6;
LAB_000709a8:
    uVar9 = uVar2;
    if (uVar2 == 0) {
      uVar2 = 0;
      if (uVar5 != 0) goto LAB_000709e6;
      uVar9 = 0x1c;
      pcVar6 = DAT_00070a24;
    }
  }
  else {
    pcVar6 = DAT_00070a30;
    if (uVar2 == 0x30000) {
      uVar2 = 4;
      goto LAB_0007099a;
    }
    if (uVar2 == 0x10000) {
      uVar2 = 2;
      goto LAB_0007099a;
    }
    uVar2 = *(uint *)(param_1 + 0x14c);
    pcVar6 = *(char **)(param_1 + 0x150);
    if (*(char **)(param_1 + 0x150) != (char *)0x0) goto LAB_0007099a;
    uVar9 = uVar7;
    if (*(int *)(*(int *)(param_1 + 0x98) + 0x34) == 0) {
      uVar2 = 0x1c;
      pcVar6 = DAT_00070a1c + 0x1c;
    }
    else {
      uVar2 = 0xd;
      pcVar6 = DAT_00070a1c;
    }
joined_r0x000709a6:
    if (uVar9 == 0) goto LAB_000709a8;
    if (uVar2 == 0) goto LAB_000709e6;
    uVar7 = 0x1c;
    pcVar8 = DAT_00070a24;
    uVar9 = uVar2;
  }
  uVar5 = 0;
  uVar2 = 0;
  do {
    if (uVar7 != 0) {
      uVar3 = 0;
      pcVar1 = pcVar8;
      do {
        uVar3 = uVar3 + 1;
        if (((*pcVar1 == *pcVar6) && (pcVar1[1] == pcVar6[1])) &&
           (bVar10 = param_2 == uVar2, uVar2 = uVar2 + 1, bVar10)) {
          uVar5 = CONCAT11(*pcVar6,pcVar1[1]) - 1;
          if (uVar5 < 0x1c) {
            return *(uint *)(DAT_00070a20 + uVar5 * 4 + 100);
          }
          goto LAB_000709ea;
        }
        pcVar1 = pcVar1 + 2;
      } while (uVar3 != uVar7);
    }
    uVar5 = uVar5 + 1;
    pcVar6 = pcVar6 + 2;
  } while (uVar5 < uVar9);
LAB_000709e6:
  if (param_2 != 0xffffffff) {
LAB_000709ea:
    uVar2 = 0;
  }
  return uVar2;
}

