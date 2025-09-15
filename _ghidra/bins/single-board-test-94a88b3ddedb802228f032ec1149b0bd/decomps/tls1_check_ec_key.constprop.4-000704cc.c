
undefined4 tls1_check_ec_key_constprop_4(int param_1,char *param_2)

{
  uint uVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  
  if (param_2 == (char *)0x0) {
    return 1;
  }
  iVar4 = 0;
  do {
    if (iVar4 == 0) {
      uVar3 = *(uint *)(*(int *)(param_1 + 0x98) + 0x38) & 0x30000;
      if (uVar3 == 0x20000) {
        puVar2 = (undefined1 *)((int)&suiteb_curves + 2);
        uVar3 = 2;
        goto LAB_000704e8;
      }
      if (uVar3 == 0x30000) {
        uVar3 = 4;
        puVar2 = "";
        goto LAB_000704ec;
      }
      if (uVar3 == 0x10000) {
        puVar2 = "";
        uVar3 = 2;
        goto LAB_000704e8;
      }
      puVar2 = *(undefined1 **)(param_1 + 0x150);
      uVar3 = *(uint *)(param_1 + 0x14c);
      if (puVar2 != (char *)0x0) goto LAB_000704e8;
      if ((*(int *)(param_1 + 0x24) == 0) || (*(int *)(*(int *)(param_1 + 0x98) + 0x34) != 0)) {
        uVar3 = 0xd;
        puVar2 = eccurves_auto;
      }
      else {
        uVar3 = 0x1c;
        puVar2 = eccurves_all;
      }
    }
    else {
      puVar2 = *(undefined1 **)(*(int *)(param_1 + 0xc0) + 0xe0);
      uVar3 = *(uint *)(*(int *)(param_1 + 0xc0) + 0xdc);
LAB_000704e8:
      if ((int)(uVar3 << 0x1f) < 0) {
        ERR_put_error(0x14,0x152,0x44,"t1_lib.c",0x200);
        return 0;
      }
LAB_000704ec:
      uVar3 = uVar3 >> 1;
      if (iVar4 == 1) {
        if (uVar3 == 0) {
          return 1;
        }
      }
      else if (uVar3 == 0) {
        return 0;
      }
    }
    uVar1 = 0;
    do {
      if ((*puVar2 == *param_2) && (puVar2[1] == param_2[1])) break;
      uVar1 = uVar1 + 1;
      puVar2 = puVar2 + 2;
    } while (uVar1 < uVar3);
    if (uVar1 == uVar3) {
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

