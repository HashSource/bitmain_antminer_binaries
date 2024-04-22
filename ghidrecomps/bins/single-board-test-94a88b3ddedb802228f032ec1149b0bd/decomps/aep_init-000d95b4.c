
undefined4 aep_init(void)

{
  char **ppcVar1;
  char **ppcVar2;
  char *pcVar3;
  DSO *dso;
  DSO_FUNC_TYPE pDVar4;
  DSO_FUNC_TYPE pDVar5;
  DSO_FUNC_TYPE pDVar6;
  DSO_FUNC_TYPE pDVar7;
  DSO_FUNC_TYPE pDVar8;
  DSO_FUNC_TYPE pDVar9;
  DSO_FUNC_TYPE pDVar10;
  int line;
  
  ppcVar1 = DAT_000d96b4;
  if (DAT_000d96b4[2] == (char *)0x0) {
    pcVar3 = *DAT_000d96b4;
    if (*DAT_000d96b4 == (char *)0x0) {
      pcVar3 = DAT_000d96bc;
    }
    dso = DSO_load((DSO *)0x0,pcVar3,(DSO_METHOD *)0x0,0);
    ppcVar1[2] = (char *)dso;
    if (dso == (DSO *)0x0) {
      pcVar3 = ppcVar1[1];
      if (pcVar3 == (char *)0x0) {
        pcVar3 = (char *)ERR_get_next_error_library();
        ppcVar1[1] = pcVar3;
      }
      line = 0x1d4;
    }
    else {
      pDVar4 = DSO_bind_func(dso,DAT_000d96c0);
      if ((((pDVar4 != (DSO_FUNC_TYPE)0x0) &&
           (pDVar5 = DSO_bind_func((DSO *)ppcVar1[2],DAT_000d96c4), pDVar5 != (DSO_FUNC_TYPE)0x0))
          && (pDVar6 = DSO_bind_func((DSO *)ppcVar1[2],DAT_000d96c8), pDVar6 != (DSO_FUNC_TYPE)0x0))
         && (((pDVar7 = DSO_bind_func((DSO *)ppcVar1[2],DAT_000d96cc), pDVar7 != (DSO_FUNC_TYPE)0x0
              && (pDVar8 = DSO_bind_func((DSO *)ppcVar1[2],DAT_000d96d0),
                 pDVar8 != (DSO_FUNC_TYPE)0x0)) &&
             ((pDVar9 = DSO_bind_func((DSO *)ppcVar1[2],DAT_000d96d4), pDVar9 != (DSO_FUNC_TYPE)0x0
              && (pDVar10 = DSO_bind_func((DSO *)ppcVar1[2],DAT_000d96d8),
                 pDVar10 != (DSO_FUNC_TYPE)0x0)))))) {
        ppcVar1[3] = (char *)pDVar4;
        ppcVar1[4] = (char *)pDVar5;
        ppcVar1[5] = (char *)pDVar6;
        ppcVar1[6] = (char *)pDVar7;
        ppcVar1[7] = (char *)pDVar8;
        ppcVar1[8] = (char *)pDVar9;
        ppcVar1[9] = (char *)pDVar10;
        return 1;
      }
      ppcVar2 = DAT_000d96b4;
      pcVar3 = ppcVar1[1];
      if (pcVar3 == (char *)0x0) {
        pcVar3 = (char *)ERR_get_next_error_library();
        ppcVar2[1] = pcVar3;
      }
      line = 0x1e2;
    }
    ERR_put_error((int)pcVar3,0x67,0x6f,DAT_000d96b8,line);
  }
  else {
    pcVar3 = DAT_000d96b4[1];
    if (pcVar3 == (char *)0x0) {
      pcVar3 = (char *)ERR_get_next_error_library();
      ppcVar1[1] = pcVar3;
    }
    ERR_put_error((int)pcVar3,0x67,100,DAT_000d96b8,0x1cc);
  }
  if ((DSO *)ppcVar1[2] != (DSO *)0x0) {
    DSO_free((DSO *)ppcVar1[2]);
  }
  ppcVar1[2] = (char *)0x0;
  ppcVar1[7] = (char *)0x0;
  ppcVar1[3] = (char *)0x0;
  ppcVar1[4] = (char *)0x0;
  ppcVar1[6] = (char *)0x0;
  ppcVar1[5] = (char *)0x0;
  ppcVar1[8] = (char *)0x0;
  ppcVar1[9] = (char *)0x0;
  return 0;
}

