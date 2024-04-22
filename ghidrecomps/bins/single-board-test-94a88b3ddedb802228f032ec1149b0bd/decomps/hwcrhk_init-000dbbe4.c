
undefined4 hwcrhk_init(void)

{
  DSO_FUNC_TYPE *ppDVar1;
  DSO_FUNC_TYPE *ppDVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  DSO_FUNC_TYPE pDVar6;
  DSO *dso;
  DSO_FUNC_TYPE pDVar7;
  DSO_FUNC_TYPE pDVar8;
  DSO_FUNC_TYPE pDVar9;
  DSO_FUNC_TYPE pDVar10;
  DSO_FUNC_TYPE pDVar11;
  DSO_FUNC_TYPE line;
  DSO_FUNC_TYPE file;
  DSO_FUNC_TYPE file_00;
  int iVar12;
  CRYPTO_dynlock_value *l;
  CRYPTO_dynlock_value *l_00;
  char *file_01;
  
  ppDVar1 = DAT_000dbd90;
  if (DAT_000dbd90[8] == (DSO_FUNC_TYPE)0x0) {
    pDVar6 = DAT_000dbd90[6];
    if (DAT_000dbd90[6] == (DSO_FUNC_TYPE)0x0) {
      pDVar6 = DAT_000dbd98;
    }
    dso = DSO_load((DSO *)0x0,(char *)pDVar6,(DSO_METHOD *)0x0,0);
    ppDVar1[8] = (DSO_FUNC_TYPE)dso;
    if (dso == (DSO *)0x0) {
      pDVar6 = ppDVar1[7];
      if (pDVar6 == (DSO_FUNC_TYPE)0x0) {
        pDVar6 = (DSO_FUNC_TYPE)ERR_get_next_error_library();
        ppDVar1[7] = pDVar6;
      }
      iVar12 = 0x22c;
    }
    else {
      pDVar6 = DSO_bind_func(dso,DAT_000dbd9c);
      if (((((pDVar6 != (DSO_FUNC_TYPE)0x0) &&
            (pDVar7 = DSO_bind_func((DSO *)ppDVar1[8],DAT_000dbda0), pDVar7 != (DSO_FUNC_TYPE)0x0))
           && (pDVar8 = DSO_bind_func((DSO *)ppDVar1[8],DAT_000dbda4), pDVar8 != (DSO_FUNC_TYPE)0x0)
           ) && (((pDVar9 = DSO_bind_func((DSO *)ppDVar1[8],DAT_000dbda8),
                  pDVar9 != (DSO_FUNC_TYPE)0x0 &&
                  (pDVar10 = DSO_bind_func((DSO *)ppDVar1[8],DAT_000dbdac),
                  pDVar10 != (DSO_FUNC_TYPE)0x0)) &&
                 ((pDVar11 = DSO_bind_func((DSO *)ppDVar1[8],DAT_000dbdb0),
                  pDVar11 != (DSO_FUNC_TYPE)0x0 &&
                  ((line = DSO_bind_func((DSO *)ppDVar1[8],DAT_000dbdb4), line != (DSO_FUNC_TYPE)0x0
                   && (file = DSO_bind_func((DSO *)ppDVar1[8],DAT_000dbdb8),
                      file != (DSO_FUNC_TYPE)0x0)))))))) &&
         (file_00 = DSO_bind_func((DSO *)ppDVar1[8],DAT_000dbdbc), file_00 != (DSO_FUNC_TYPE)0x0)) {
        ppDVar1[1] = pDVar6;
        ppDVar1[9] = pDVar7;
        ppDVar1[10] = pDVar8;
        ppDVar1[0xb] = pDVar9;
        ppDVar1[0xc] = pDVar10;
        ppDVar1[0xd] = pDVar11;
        *ppDVar1 = line;
        ppDVar1[0xe] = file;
        ppDVar1[0xf] = file_00;
        if ((((ppDVar1[0x10] == (DSO_FUNC_TYPE)0x0) &&
             (l = CRYPTO_get_dynlock_create_callback((char *)file_00,0),
             l != (CRYPTO_dynlock_value *)0x0)) &&
            (CRYPTO_get_dynlock_lock_callback((int)l,l_00,(char *)file,(int)line),
            l != (CRYPTO_dynlock_value *)0x0)) &&
           (CRYPTO_get_dynlock_destroy_callback(l,file_01,(int)file), iVar5 = DAT_000dbdd4,
           iVar4 = DAT_000dbdd0, iVar12 = DAT_000dbdcc, piVar3 = DAT_000dbdc0,
           l != (CRYPTO_dynlock_value *)0x0)) {
          DAT_000dbdc0[9] = DAT_000dbdc8;
          piVar3[10] = iVar12;
          piVar3[0xb] = iVar4;
          piVar3[0xc] = iVar5;
        }
        iVar12 = get_context_constprop_2();
        piVar3 = DAT_000dbdc0;
        ppDVar2 = DAT_000dbd90;
        if (iVar12 != 0) {
          if (*DAT_000dbdc0 == -1) {
            iVar12 = RSA_get_ex_new_index
                               (0,DAT_000dbdc4,(undefined1 *)0x0,(undefined1 *)0x0,(undefined1 *)0x0
                               );
            *piVar3 = iVar12;
            return 1;
          }
          return 1;
        }
        pDVar6 = ppDVar1[7];
        if (pDVar6 == (DSO_FUNC_TYPE)0x0) {
          pDVar6 = (DSO_FUNC_TYPE)ERR_get_next_error_library();
          ppDVar2[7] = pDVar6;
        }
        ERR_put_error((int)pDVar6,0x67,0x71,DAT_000dbd94,0x266);
        goto LAB_000dbc06;
      }
      ppDVar2 = DAT_000dbd90;
      pDVar6 = ppDVar1[7];
      if (pDVar6 == (DSO_FUNC_TYPE)0x0) {
        pDVar6 = (DSO_FUNC_TYPE)ERR_get_next_error_library();
        ppDVar2[7] = pDVar6;
      }
      iVar12 = 0x243;
    }
    ERR_put_error((int)pDVar6,0x67,0x68,DAT_000dbd94,iVar12);
  }
  else {
    pDVar6 = DAT_000dbd90[7];
    if (pDVar6 == (DSO_FUNC_TYPE)0x0) {
      pDVar6 = (DSO_FUNC_TYPE)ERR_get_next_error_library();
      ppDVar1[7] = pDVar6;
    }
    ERR_put_error((int)pDVar6,0x67,100,DAT_000dbd94,0x226);
  }
LAB_000dbc06:
  if ((DSO *)ppDVar1[8] != (DSO *)0x0) {
    DSO_free((DSO *)ppDVar1[8]);
  }
  ppDVar1[8] = (DSO_FUNC_TYPE)0x0;
  ppDVar1[1] = (DSO_FUNC_TYPE)0x0;
  ppDVar1[9] = (DSO_FUNC_TYPE)0x0;
  ppDVar1[10] = (DSO_FUNC_TYPE)0x0;
  ppDVar1[0xb] = (DSO_FUNC_TYPE)0x0;
  ppDVar1[0xc] = (DSO_FUNC_TYPE)0x0;
  ppDVar1[0xd] = (DSO_FUNC_TYPE)0x0;
  *ppDVar1 = (DSO_FUNC_TYPE)0x0;
  ppDVar1[0xf] = (DSO_FUNC_TYPE)0x0;
  ppDVar1[0xe] = (DSO_FUNC_TYPE)0x0;
  return 0;
}

