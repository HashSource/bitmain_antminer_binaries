
undefined4 cswift_init(void)

{
  char **ppcVar1;
  char **ppcVar2;
  char *pcVar3;
  DSO *dso;
  DSO_FUNC_TYPE pDVar4;
  DSO_FUNC_TYPE pDVar5;
  DSO_FUNC_TYPE pDVar6;
  DSO_FUNC_TYPE pDVar7;
  int iVar8;
  undefined4 local_1c [2];
  
  ppcVar1 = DAT_000dac60;
  if (DAT_000dac60[2] == (char *)0x0) {
    pcVar3 = *DAT_000dac60;
    if (*DAT_000dac60 == (char *)0x0) {
      pcVar3 = DAT_000dac68;
    }
    dso = DSO_load((DSO *)0x0,pcVar3,(DSO_METHOD *)0x0,0);
    ppcVar1[2] = (char *)dso;
    if (dso == (DSO *)0x0) {
      pcVar3 = ppcVar1[1];
      if (pcVar3 == (char *)0x0) {
        pcVar3 = (char *)ERR_get_next_error_library();
        ppcVar1[1] = pcVar3;
      }
      iVar8 = 0x195;
    }
    else {
      pDVar4 = DSO_bind_func(dso,DAT_000dac6c);
      if ((((pDVar4 != (DSO_FUNC_TYPE)0x0) &&
           (pDVar5 = DSO_bind_func((DSO *)ppcVar1[2],DAT_000dac70), pDVar5 != (DSO_FUNC_TYPE)0x0))
          && (pDVar6 = DSO_bind_func((DSO *)ppcVar1[2],DAT_000dac74), pDVar6 != (DSO_FUNC_TYPE)0x0))
         && (pDVar7 = DSO_bind_func((DSO *)ppcVar1[2],DAT_000dac78), pDVar7 != (DSO_FUNC_TYPE)0x0))
      {
        ppcVar1[3] = (char *)pDVar4;
        ppcVar1[4] = (char *)pDVar5;
        ppcVar1[5] = (char *)pDVar6;
        ppcVar1[6] = (char *)pDVar7;
        iVar8 = (*pDVar4)(local_1c);
        if (iVar8 == 0) {
          (*(code *)ppcVar1[6])(local_1c[0]);
          return 1;
        }
        pcVar3 = ppcVar1[1];
        if (pcVar3 == (char *)0x0) {
          pcVar3 = (char *)ERR_get_next_error_library();
          ppcVar1[1] = pcVar3;
        }
        ERR_put_error((int)pcVar3,0x68,0x6c,DAT_000dac64,0x1ac);
        goto LAB_000dab92;
      }
      ppcVar2 = DAT_000dac60;
      pcVar3 = ppcVar1[1];
      if (pcVar3 == (char *)0x0) {
        pcVar3 = (char *)ERR_get_next_error_library();
        ppcVar2[1] = pcVar3;
      }
      iVar8 = 0x1a0;
    }
    ERR_put_error((int)pcVar3,0x68,0x6a,DAT_000dac64,iVar8);
  }
  else {
    pcVar3 = DAT_000dac60[1];
    if (pcVar3 == (char *)0x0) {
      pcVar3 = (char *)ERR_get_next_error_library();
      ppcVar1[1] = pcVar3;
    }
    ERR_put_error((int)pcVar3,0x68,100,DAT_000dac64,399);
  }
LAB_000dab92:
  ppcVar2 = DAT_000dac60;
  if ((DSO *)ppcVar1[2] != (DSO *)0x0) {
    DSO_free((DSO *)ppcVar1[2]);
    ppcVar2[2] = (char *)0x0;
  }
  ppcVar1[3] = (char *)0x0;
  ppcVar1[4] = (char *)0x0;
  ppcVar1[5] = (char *)0x0;
  ppcVar1[6] = (char *)0x0;
  return 0;
}

