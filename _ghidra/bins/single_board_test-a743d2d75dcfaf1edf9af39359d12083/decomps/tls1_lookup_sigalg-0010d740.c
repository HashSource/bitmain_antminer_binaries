
void tls1_lookup_sigalg(int *param_1,int *param_2,int *param_3,byte *param_4)

{
  int *piVar1;
  int pkey_nid;
  int *piVar2;
  int *piVar3;
  int dig_nid;
  uint uVar4;
  undefined1 *puVar5;
  int *piVar6;
  
  piVar1 = param_2;
  if (param_2 == (int *)0x0 && param_1 == (int *)0x0) {
    if (param_3 == (int *)0x0) {
      return;
    }
    piVar2 = (int *)0x1;
    piVar6 = (int *)0x0;
LAB_0010d754:
    piVar3 = &tls12_md;
    uVar4 = (uint)*param_4;
    if (uVar4 == DAT_002482f4) {
LAB_0010d806:
      dig_nid = *piVar3;
    }
    else {
      if (uVar4 == DAT_002482fc) {
        piVar3 = &DAT_002482f8;
        goto LAB_0010d806;
      }
      if (uVar4 == DAT_00248304) {
        piVar3 = &DAT_00248300;
        goto LAB_0010d806;
      }
      if (uVar4 == DAT_0024830c) {
        piVar3 = &DAT_00248308;
        goto LAB_0010d806;
      }
      if (uVar4 == DAT_00248314) {
        piVar3 = &DAT_00248310;
        goto LAB_0010d806;
      }
      if (uVar4 == DAT_0024831c) {
        piVar3 = &DAT_00248318;
        goto LAB_0010d806;
      }
      dig_nid = 0;
    }
    if (piVar6 != (int *)0x0) {
      *param_1 = dig_nid;
    }
    if (param_2 != (int *)0x0) {
      piVar1 = (int *)0x1;
    }
    if (piVar2 == (int *)0x0 && piVar1 == (int *)0x0) {
      return;
    }
  }
  else {
    piVar6 = param_1;
    if (param_1 != (int *)0x0) {
      piVar6 = (int *)0x1;
    }
    piVar2 = param_3;
    if (param_3 != (int *)0x0) {
      piVar2 = (int *)0x1;
    }
    if (piVar2 != (int *)0x0 || piVar6 != (int *)0x0) goto LAB_0010d754;
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
  if (uVar4 == tls12_sig._4_4_) {
    puVar5 = tls12_sig;
  }
  else if (uVar4 == tls12_sig._12_4_) {
    puVar5 = tls12_sig + 8;
  }
  else {
    if (uVar4 != tls12_sig._20_4_) {
      pkey_nid = 0;
      goto LAB_0010d7b2;
    }
    puVar5 = tls12_sig + 0x10;
  }
  pkey_nid = *(int *)puVar5;
LAB_0010d7b2:
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

