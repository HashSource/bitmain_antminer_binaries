
undefined4 nid_cb(void *param_1,size_t param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char acStack_2c [24];
  
  if (param_1 == (void *)0x0) {
    return 0;
  }
  if (*param_3 != 0x1e && (int)param_2 < 0x14) {
    memcpy(acStack_2c,param_1,param_2);
    acStack_2c[param_2] = '\0';
    iVar1 = EC_curve_nist2nid(acStack_2c);
    if (((iVar1 != 0) || (iVar1 = OBJ_sn2nid(acStack_2c), iVar1 != 0)) ||
       (iVar1 = OBJ_ln2nid(acStack_2c), iVar1 != 0)) {
      iVar2 = *param_3;
      if (iVar2 == 0) {
        iVar4 = 1;
LAB_000fa3a6:
        *param_3 = iVar4;
        param_3[iVar2 + 1] = iVar1;
        return 1;
      }
      if (param_3[1] != iVar1) {
        piVar3 = param_3 + 1;
        iVar4 = 0;
        do {
          iVar4 = iVar4 + 1;
          if (iVar4 == iVar2) {
            iVar4 = iVar2 + 1;
            goto LAB_000fa3a6;
          }
          piVar3 = piVar3 + 1;
        } while (*piVar3 != iVar1);
      }
    }
  }
  return 0;
}

