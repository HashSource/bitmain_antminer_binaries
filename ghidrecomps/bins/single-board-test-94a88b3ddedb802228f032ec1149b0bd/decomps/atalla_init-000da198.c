
undefined4 atalla_init(void)

{
  char **ppcVar1;
  char **ppcVar2;
  char *pcVar3;
  DSO *dso;
  DSO_FUNC_TYPE pDVar4;
  DSO_FUNC_TYPE pDVar5;
  DSO_FUNC_TYPE pDVar6;
  int iVar7;
  undefined auStack_1018 [4100];
  
  ppcVar1 = DAT_000da274;
  if (DAT_000da274[2] == (char *)0x0) {
    pcVar3 = *DAT_000da274;
    if (*DAT_000da274 == (char *)0x0) {
      pcVar3 = DAT_000da27c;
    }
    dso = DSO_load((DSO *)0x0,pcVar3,(DSO_METHOD *)0x0,0);
    ppcVar1[2] = (char *)dso;
    if (dso == (DSO *)0x0) {
      pcVar3 = ppcVar1[1];
      if (pcVar3 == (char *)0x0) {
        pcVar3 = (char *)ERR_get_next_error_library();
        ppcVar1[1] = pcVar3;
      }
      iVar7 = 0x17f;
    }
    else {
      pDVar4 = DSO_bind_func(dso,DAT_000da280);
      if (((pDVar4 != (DSO_FUNC_TYPE)0x0) &&
          (pDVar5 = DSO_bind_func((DSO *)ppcVar1[2],DAT_000da284), pDVar5 != (DSO_FUNC_TYPE)0x0)) &&
         (pDVar6 = DSO_bind_func((DSO *)ppcVar1[2],DAT_000da288), pDVar6 != (DSO_FUNC_TYPE)0x0)) {
        ppcVar1[3] = (char *)pDVar4;
        ppcVar1[4] = (char *)pDVar5;
        ppcVar1[5] = (char *)pDVar6;
        iVar7 = (*pDVar4)(0,auStack_1018);
        if (iVar7 == 0) {
          return 1;
        }
        pcVar3 = ppcVar1[1];
        if (pcVar3 == (char *)0x0) {
          pcVar3 = (char *)ERR_get_next_error_library();
          ppcVar1[1] = pcVar3;
        }
        ERR_put_error((int)pcVar3,0x66,0x6b,DAT_000da278,0x194);
        goto LAB_000da1ba;
      }
      ppcVar2 = DAT_000da274;
      pcVar3 = ppcVar1[1];
      if (pcVar3 == (char *)0x0) {
        pcVar3 = (char *)ERR_get_next_error_library();
        ppcVar2[1] = pcVar3;
      }
      iVar7 = 0x189;
    }
    ERR_put_error((int)pcVar3,0x66,0x69,DAT_000da278,iVar7);
  }
  else {
    pcVar3 = DAT_000da274[1];
    if (pcVar3 == (char *)0x0) {
      pcVar3 = (char *)ERR_get_next_error_library();
      ppcVar1[1] = pcVar3;
    }
    ERR_put_error((int)pcVar3,0x66,100,DAT_000da278,0x170);
  }
LAB_000da1ba:
  if ((DSO *)ppcVar1[2] != (DSO *)0x0) {
    DSO_free((DSO *)ppcVar1[2]);
  }
  ppcVar1[2] = (char *)0x0;
  ppcVar1[3] = (char *)0x0;
  ppcVar1[4] = (char *)0x0;
  ppcVar1[5] = (char *)0x0;
  return 0;
}

