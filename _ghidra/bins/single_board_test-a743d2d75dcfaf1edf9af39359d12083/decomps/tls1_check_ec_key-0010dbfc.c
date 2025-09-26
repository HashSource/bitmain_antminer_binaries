
undefined4 tls1_check_ec_key(int param_1,char *param_2,char *param_3)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  
  if (param_3 != (char *)0x0) {
    pcVar2 = *(char **)(*(int *)(param_1 + 0xc0) + 0xd8);
    if (pcVar2 != (char *)0x0) {
      iVar5 = *(int *)(*(int *)(param_1 + 0xc0) + 0xd4);
      if (iVar5 == 0) {
        return 0;
      }
      if (*pcVar2 != *param_3) {
        iVar3 = 0;
        do {
          iVar3 = iVar3 + 1;
          if (iVar3 == iVar5) {
            return 0;
          }
          pcVar2 = pcVar2 + 1;
        } while (*pcVar2 != *param_3);
        if (iVar5 == iVar3) {
          return 0;
        }
      }
    }
  }
  if (param_2 == (char *)0x0) {
    return 1;
  }
  iVar5 = 0;
  do {
    if (iVar5 == 0) {
      uVar6 = *(uint *)(*(int *)(param_1 + 0x98) + 0x38) & 0x30000;
      if (uVar6 == 0x20000) {
        puVar4 = (undefined1 *)((int)&suiteb_curves + 2);
        uVar6 = 2;
        goto LAB_0010dc50;
      }
      if (uVar6 == 0x30000) {
        puVar4 = "";
        uVar6 = 4;
        goto LAB_0010dc50;
      }
      if (uVar6 == 0x10000) {
        puVar4 = "";
        uVar6 = 2;
        goto LAB_0010dc50;
      }
      puVar4 = *(undefined1 **)(param_1 + 0x150);
      uVar6 = *(uint *)(param_1 + 0x14c);
      if (puVar4 != (char *)0x0) goto LAB_0010dc50;
      if ((*(int *)(param_1 + 0x24) == 0) || (*(int *)(*(int *)(param_1 + 0x98) + 0x34) != 0)) {
        uVar6 = 0xd;
        puVar4 = eccurves_auto;
      }
      else {
        uVar6 = 0x1c;
        puVar4 = eccurves_all;
      }
    }
    else {
      puVar4 = *(undefined1 **)(*(int *)(param_1 + 0xc0) + 0xe0);
      uVar6 = *(uint *)(*(int *)(param_1 + 0xc0) + 0xdc);
LAB_0010dc50:
      if ((int)(uVar6 << 0x1f) < 0) {
        ERR_put_error(0x14,0x152,0x44,"t1_lib.c",0x200);
        return 0;
      }
      uVar6 = uVar6 >> 1;
      if (iVar5 == 1) {
        if (uVar6 == 0) {
          return 1;
        }
      }
      else if (uVar6 == 0) {
        return 0;
      }
    }
    uVar1 = 0;
    do {
      if ((*puVar4 == *param_2) && (puVar4[1] == param_2[1])) break;
      uVar1 = uVar1 + 1;
      puVar4 = puVar4 + 2;
    } while (uVar1 < uVar6);
    if (uVar6 == uVar1) {
      return 0;
    }
    if (*(int *)(param_1 + 0x24) == 0) {
      return 1;
    }
    iVar5 = iVar5 + 1;
    if (iVar5 == 2) {
      return 1;
    }
  } while( true );
}

