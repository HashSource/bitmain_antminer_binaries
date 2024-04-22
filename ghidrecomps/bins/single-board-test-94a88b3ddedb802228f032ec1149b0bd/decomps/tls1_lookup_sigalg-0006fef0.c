
void tls1_lookup_sigalg(int *param_1,int *param_2,int *param_3,byte *param_4)

{
  int *piVar1;
  int pkey_nid;
  int *piVar2;
  int dig_nid;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  
  piVar1 = param_2;
  if (param_2 == (int *)0x0 && param_1 == (int *)0x0) {
    if (param_3 == (int *)0x0) {
      return;
    }
    piVar2 = (int *)0x1;
    piVar5 = (int *)0x0;
LAB_0006ff04:
    uVar4 = (uint)*param_4;
    piVar3 = DAT_0006ffd0;
    if (uVar4 == DAT_0006ffd0[1]) {
LAB_0006ffb6:
      dig_nid = *piVar3;
    }
    else {
      if (uVar4 == DAT_0006ffd0[3]) {
        piVar3 = DAT_0006ffd0 + 2;
        goto LAB_0006ffb6;
      }
      if (uVar4 == DAT_0006ffd0[5]) {
        piVar3 = DAT_0006ffd0 + 4;
        goto LAB_0006ffb6;
      }
      if (uVar4 == DAT_0006ffd0[7]) {
        piVar3 = DAT_0006ffd0 + 6;
        goto LAB_0006ffb6;
      }
      if (uVar4 == DAT_0006ffd0[9]) {
        piVar3 = DAT_0006ffd0 + 8;
        goto LAB_0006ffb6;
      }
      if (uVar4 == DAT_0006ffd0[0xb]) {
        piVar3 = DAT_0006ffd0 + 10;
        goto LAB_0006ffb6;
      }
      dig_nid = 0;
    }
    if (piVar5 != (int *)0x0) {
      *param_1 = dig_nid;
    }
    if (param_2 != (int *)0x0) {
      piVar1 = (int *)0x1;
    }
    if (((uint)piVar2 | (uint)piVar1) == 0) {
      return;
    }
  }
  else {
    piVar5 = param_1;
    if (param_1 != (int *)0x0) {
      piVar5 = (int *)0x1;
    }
    piVar2 = param_3;
    if (param_3 != (int *)0x0) {
      piVar2 = (int *)0x1;
    }
    if (((uint)piVar2 | (uint)piVar5) != 0) goto LAB_0006ff04;
    if (param_2 != (int *)0x0) {
      piVar1 = (int *)0x1;
    }
    if (piVar1 == (int *)0x0) {
      return;
    }
    piVar2 = (int *)0x0;
    dig_nid = 0;
  }
  uVar4 = (uint)param_4[1];
  if (uVar4 == DAT_0006ffd0[0xd]) {
    piVar5 = DAT_0006ffd0 + 0xc;
  }
  else if (uVar4 == DAT_0006ffd0[0xf]) {
    piVar5 = DAT_0006ffd0 + 0xe;
  }
  else {
    if (uVar4 != DAT_0006ffd0[0x11]) {
      pkey_nid = 0;
      goto LAB_0006ff62;
    }
    piVar5 = DAT_0006ffd0 + 0x10;
  }
  pkey_nid = *piVar5;
LAB_0006ff62:
  if (piVar1 != (int *)0x0) {
    *param_2 = pkey_nid;
  }
  if (piVar2 != (int *)0x0) {
    if (pkey_nid != 0 && dig_nid != 0) {
      OBJ_find_sigid_by_algs(param_3,dig_nid,pkey_nid);
      return;
    }
    *param_3 = 0;
  }
  return;
}

