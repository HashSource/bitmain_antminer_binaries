
void CONF_modules_unload(int all)

{
  _STACK **pp_Var1;
  _STACK **pp_Var2;
  int *ptr;
  void *ptr_00;
  int iVar3;
  DSO **ppDVar4;
  bool bVar5;
  
  pp_Var1 = DAT_000cec7c;
  while (iVar3 = sk_num(pp_Var1[1]), pp_Var2 = DAT_000cec7c, 0 < iVar3) {
    ptr = (int *)sk_pop(pp_Var1[1]);
    iVar3 = *ptr;
    if (*(code **)(iVar3 + 0xc) != (code *)0x0) {
      (**(code **)(iVar3 + 0xc))();
      iVar3 = *ptr;
    }
    ptr_00 = (void *)ptr[1];
    *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + -1;
    CRYPTO_free(ptr_00);
    CRYPTO_free((void *)ptr[2]);
    CRYPTO_free(ptr);
  }
  sk_free(DAT_000cec7c[1]);
  pp_Var2[1] = (_STACK *)0x0;
  iVar3 = sk_num(*pp_Var2);
  iVar3 = iVar3 + -1;
  if (-1 < iVar3) {
    if (all == 0) {
      do {
        ppDVar4 = (DSO **)sk_value(*pp_Var1,iVar3);
        if (((int)ppDVar4[4] < 1) && (*ppDVar4 != (DSO *)0x0)) {
          sk_delete(*pp_Var2,iVar3);
          if (*ppDVar4 != (DSO *)0x0) {
            DSO_free(*ppDVar4);
          }
          CRYPTO_free(ppDVar4[1]);
          CRYPTO_free(ppDVar4);
        }
        bVar5 = iVar3 != 0;
        iVar3 = iVar3 + -1;
      } while (bVar5);
    }
    else {
      do {
        ppDVar4 = (DSO **)sk_value(*pp_Var1,iVar3);
        sk_delete(*pp_Var1,iVar3);
        if (*ppDVar4 != (DSO *)0x0) {
          DSO_free(*ppDVar4);
        }
        iVar3 = iVar3 + -1;
        CRYPTO_free(ppDVar4[1]);
        CRYPTO_free(ppDVar4);
      } while (iVar3 != -1);
    }
  }
  iVar3 = sk_num(*pp_Var1);
  pp_Var1 = DAT_000cec7c;
  if (iVar3 == 0) {
    sk_free(*DAT_000cec7c);
    *pp_Var1 = (_STACK *)0x0;
  }
  return;
}

