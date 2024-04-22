
undefined4 ibm_4758_cca_init(void)

{
  DSO_FUNC_TYPE *ppDVar1;
  DSO_FUNC_TYPE *ppDVar2;
  DSO_FUNC_TYPE pDVar3;
  DSO *dso;
  int iVar4;
  
  ppDVar1 = DAT_000d89a4;
  if (DAT_000d89a4[5] == (DSO_FUNC_TYPE)0x0) {
    pDVar3 = DAT_000d89a4[4];
    if (DAT_000d89a4[4] == (DSO_FUNC_TYPE)0x0) {
      pDVar3 = DAT_000d89ac;
    }
    dso = DSO_load((DSO *)0x0,(char *)pDVar3,(DSO_METHOD *)0x0,0);
    ppDVar1[5] = (DSO_FUNC_TYPE)dso;
    if (dso == (DSO *)0x0) {
      pDVar3 = ppDVar1[3];
      if (pDVar3 == (DSO_FUNC_TYPE)0x0) {
        pDVar3 = (DSO_FUNC_TYPE)ERR_get_next_error_library();
        ppDVar1[3] = pDVar3;
      }
      iVar4 = 0x122;
    }
    else {
      pDVar3 = DSO_bind_func(dso,DAT_000d89b0);
      ppDVar1[6] = pDVar3;
      if (pDVar3 != (DSO_FUNC_TYPE)0x0) {
        pDVar3 = DSO_bind_func((DSO *)ppDVar1[5],DAT_000d89b4);
        *ppDVar1 = pDVar3;
        if (pDVar3 != (DSO_FUNC_TYPE)0x0) {
          pDVar3 = DSO_bind_func((DSO *)ppDVar1[5],DAT_000d89b8);
          ppDVar1[7] = pDVar3;
          if (pDVar3 != (DSO_FUNC_TYPE)0x0) {
            pDVar3 = DSO_bind_func((DSO *)ppDVar1[5],DAT_000d89bc);
            ppDVar1[8] = pDVar3;
            if (pDVar3 != (DSO_FUNC_TYPE)0x0) {
              pDVar3 = DSO_bind_func((DSO *)ppDVar1[5],DAT_000d89c0);
              ppDVar1[9] = pDVar3;
              if (pDVar3 != (DSO_FUNC_TYPE)0x0) {
                pDVar3 = DSO_bind_func((DSO *)ppDVar1[5],DAT_000d89c4);
                ppDVar1[2] = pDVar3;
                if (pDVar3 != (DSO_FUNC_TYPE)0x0) {
                  pDVar3 = DSO_bind_func((DSO *)ppDVar1[5],DAT_000d89c8);
                  ppDVar1[1] = pDVar3;
                  if (pDVar3 != (DSO_FUNC_TYPE)0x0) {
                    iVar4 = RSA_get_ex_new_index
                                      (0,DAT_000d89d0,(undefined1 *)0x0,(undefined1 *)0x0,
                                       DAT_000d89cc);
                    *DAT_000d89d4 = iVar4;
                    return 1;
                  }
                }
              }
            }
          }
        }
      }
      ppDVar2 = DAT_000d89a4;
      pDVar3 = ppDVar1[3];
      if (pDVar3 == (DSO_FUNC_TYPE)0x0) {
        pDVar3 = (DSO_FUNC_TYPE)ERR_get_next_error_library();
        ppDVar2[3] = pDVar3;
      }
      iVar4 = 0x135;
    }
    ERR_put_error((int)pDVar3,0x66,0x67,DAT_000d89a8,iVar4);
  }
  else {
    pDVar3 = DAT_000d89a4[3];
    if (pDVar3 == (DSO_FUNC_TYPE)0x0) {
      pDVar3 = (DSO_FUNC_TYPE)ERR_get_next_error_library();
      ppDVar1[3] = pDVar3;
    }
    ERR_put_error((int)pDVar3,0x66,100,DAT_000d89a8,0x11c);
  }
  if ((DSO *)ppDVar1[5] != (DSO *)0x0) {
    DSO_free((DSO *)ppDVar1[5]);
  }
  ppDVar1[5] = (DSO_FUNC_TYPE)0x0;
  ppDVar1[6] = (DSO_FUNC_TYPE)0x0;
  ppDVar1[7] = (DSO_FUNC_TYPE)0x0;
  ppDVar1[8] = (DSO_FUNC_TYPE)0x0;
  ppDVar1[9] = (DSO_FUNC_TYPE)0x0;
  ppDVar1[2] = (DSO_FUNC_TYPE)0x0;
  ppDVar1[1] = (DSO_FUNC_TYPE)0x0;
  *ppDVar1 = (DSO_FUNC_TYPE)0x0;
  return 0;
}

