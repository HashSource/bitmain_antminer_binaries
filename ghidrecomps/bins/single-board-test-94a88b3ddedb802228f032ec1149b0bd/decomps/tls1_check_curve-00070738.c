
undefined4 tls1_check_curve(int param_1,char *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  
  if (param_3 != 3) {
    return 0;
  }
  if (*param_2 != '\x03') {
    return 0;
  }
  uVar2 = *(uint *)(*(int *)(param_1 + 0x98) + 0x38) & 0x30000;
  if (uVar2 == 0) {
LAB_00070796:
    uVar2 = *(uint *)(param_1 + 0x14c);
    pcVar3 = *(char **)(param_1 + 0x150);
    if (*(char **)(param_1 + 0x150) == (char *)0x0) {
      if ((*(int *)(param_1 + 0x24) == 0) || (*(int *)(*(int *)(param_1 + 0x98) + 0x34) != 0)) {
        uVar2 = 0xd;
        pcVar3 = DAT_00070824;
      }
      else {
        uVar2 = 0x1c;
        pcVar3 = DAT_00070814;
      }
      goto LAB_000707ac;
    }
  }
  else {
    iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 8);
    if (param_2[1] != '\0') {
      return 0;
    }
    if (iVar4 == 0x300c02b) {
      if (param_2[2] != '\x17') {
        return 0;
      }
    }
    else {
      if (iVar4 != 0x300c02c) {
        return 0;
      }
      if (param_2[2] != '\x18') {
        return 0;
      }
    }
    if (uVar2 == 0x20000) {
      uVar2 = 2;
      pcVar3 = DAT_0007081c;
    }
    else {
      pcVar3 = DAT_00070818;
      if (uVar2 == 0x30000) {
        uVar2 = 4;
      }
      else {
        if (uVar2 != 0x10000) goto LAB_00070796;
        uVar2 = 2;
      }
    }
  }
  if ((int)(uVar2 << 0x1f) < 0) {
    ERR_put_error(0x14,0x152,0x44,DAT_00070820,0x200);
    return 0;
  }
  uVar2 = uVar2 >> 1;
  if (uVar2 == 0) {
    return 0;
  }
LAB_000707ac:
  uVar1 = 0;
  while( true ) {
    uVar1 = uVar1 + 1;
    if ((*pcVar3 == param_2[1]) && (param_2[2] == pcVar3[1])) break;
    pcVar3 = pcVar3 + 2;
    if (uVar1 == uVar2) {
      return 0;
    }
  }
  return 1;
}

