
undefined4 tls1_check_ec_key(int param_1,char *param_2,char *param_3)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (param_3 != (char *)0x0) {
    pcVar2 = *(char **)(*(int *)(param_1 + 0xc0) + 0xd8);
    if (pcVar2 != (char *)0x0) {
      iVar4 = *(int *)(*(int *)(param_1 + 0xc0) + 0xd4);
      if (iVar4 == 0) {
        return 0;
      }
      if (*pcVar2 != *param_3) {
        iVar3 = 0;
        do {
          iVar3 = iVar3 + 1;
          if (iVar3 == iVar4) {
            return 0;
          }
          pcVar2 = pcVar2 + 1;
        } while (*pcVar2 != *param_3);
        if (iVar4 == iVar3) {
          return 0;
        }
      }
    }
  }
  if (param_2 == (char *)0x0) {
    return 1;
  }
  iVar4 = 0;
  do {
    if (iVar4 == 0) {
      uVar5 = *(uint *)(*(int *)(param_1 + 0x98) + 0x38) & 0x30000;
      if (uVar5 == 0x20000) {
        uVar5 = 2;
        pcVar2 = DAT_000704c0;
        goto LAB_00070400;
      }
      pcVar2 = DAT_000704c4;
      if (uVar5 == 0x30000) {
        uVar5 = 4;
        goto LAB_00070400;
      }
      if (uVar5 == 0x10000) {
        uVar5 = 2;
        goto LAB_00070400;
      }
      uVar5 = *(uint *)(param_1 + 0x14c);
      pcVar2 = *(char **)(param_1 + 0x150);
      if (*(char **)(param_1 + 0x150) != (char *)0x0) goto LAB_00070400;
      if ((*(int *)(param_1 + 0x24) == 0) || (*(int *)(*(int *)(param_1 + 0x98) + 0x34) != 0)) {
        uVar5 = 0xd;
        pcVar2 = DAT_000704b8;
      }
      else {
        uVar5 = 0x1c;
        pcVar2 = DAT_000704c8;
      }
    }
    else {
      uVar5 = *(uint *)(*(int *)(param_1 + 0xc0) + 0xdc);
      pcVar2 = *(char **)(*(int *)(param_1 + 0xc0) + 0xe0);
LAB_00070400:
      if ((int)(uVar5 << 0x1f) < 0) {
        ERR_put_error(0x14,0x152,0x44,DAT_000704bc,0x200);
        return 0;
      }
      uVar5 = uVar5 >> 1;
      if (iVar4 == 1) {
        if (uVar5 == 0) {
          return 1;
        }
      }
      else if (uVar5 == 0) {
        return 0;
      }
    }
    uVar1 = 0;
    do {
      if ((*pcVar2 == *param_2) && (pcVar2[1] == param_2[1])) break;
      uVar1 = uVar1 + 1;
      pcVar2 = pcVar2 + 2;
    } while (uVar1 < uVar5);
    if (uVar5 == uVar1) {
      return 0;
    }
    if (*(int *)(param_1 + 0x24) == 0) {
      return 1;
    }
    iVar4 = iVar4 + 1;
    if (iVar4 == 2) {
      return 1;
    }
  } while( true );
}

