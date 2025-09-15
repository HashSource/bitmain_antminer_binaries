
undefined4 tls1_check_curve(int param_1,char *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined1 *puVar3;
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
    puVar3 = *(undefined1 **)(param_1 + 0x150);
    uVar2 = *(uint *)(param_1 + 0x14c);
    if (puVar3 == (char *)0x0) {
      if ((*(int *)(param_1 + 0x24) == 0) || (*(int *)(*(int *)(param_1 + 0x98) + 0x34) != 0)) {
        uVar2 = 0xd;
        puVar3 = eccurves_auto;
      }
      else {
        puVar3 = eccurves_all;
        uVar2 = 0x1c;
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
      puVar3 = (undefined1 *)((int)&suiteb_curves + 2);
      uVar2 = 2;
    }
    else if (uVar2 == 0x30000) {
      puVar3 = "";
      uVar2 = 4;
    }
    else {
      if (uVar2 != 0x10000) goto LAB_00070796;
      puVar3 = "";
      uVar2 = 2;
    }
  }
  if ((int)(uVar2 << 0x1f) < 0) {
    ERR_put_error(0x14,0x152,0x44,"t1_lib.c",0x200);
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
    if ((*puVar3 == param_2[1]) && (param_2[2] == puVar3[1])) break;
    puVar3 = puVar3 + 2;
    if (uVar1 == uVar2) {
      return 0;
    }
  }
  return 1;
}

