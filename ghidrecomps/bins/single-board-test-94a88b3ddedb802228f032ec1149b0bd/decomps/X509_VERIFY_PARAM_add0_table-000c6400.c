
int X509_VERIFY_PARAM_add0_table(X509_VERIFY_PARAM *param)

{
  _STACK **pp_Var1;
  int iVar2;
  _STACK *st;
  undefined4 *ptr;
  _STACK **pp_Var3;
  
  pp_Var1 = DAT_000c64b4;
  if (*DAT_000c64b4 == (_STACK *)0x0) {
    st = sk_new(DAT_000c64c0);
    *pp_Var1 = st;
    if (st == (_STACK *)0x0) {
      return 0;
    }
  }
  else {
    iVar2 = sk_find(*DAT_000c64b4,param);
    st = *pp_Var1;
    if (iVar2 != -1) {
      ptr = (undefined4 *)sk_value(st,iVar2);
      if (ptr != (undefined4 *)0x0) {
        *ptr = 0;
        ptr[4] = 0;
        ptr[5] = 0;
        ptr[2] = 0;
        ptr[3] = 0;
        ptr[6] = 0xffffffff;
        if ((_STACK *)ptr[7] != (_STACK *)0x0) {
          sk_pop_free((_STACK *)ptr[7],DAT_000c64b8);
          ptr[7] = 0;
        }
        pp_Var3 = (_STACK **)ptr[8];
        if (*pp_Var3 != (_STACK *)0x0) {
          sk_pop_free(*pp_Var3,DAT_000c64bc);
          *pp_Var3 = (_STACK *)0x0;
        }
        if (pp_Var3[2] != (_STACK *)0x0) {
          CRYPTO_free(pp_Var3[2]);
        }
        if (pp_Var3[3] != (_STACK *)0x0) {
          CRYPTO_free(pp_Var3[3]);
          pp_Var3[3] = (_STACK *)0x0;
          pp_Var3[4] = (_STACK *)0x0;
        }
        if (pp_Var3[5] != (_STACK *)0x0) {
          CRYPTO_free(pp_Var3[5]);
          pp_Var3[5] = (_STACK *)0x0;
          pp_Var3[6] = (_STACK *)0x0;
        }
        CRYPTO_free((void *)ptr[8]);
        CRYPTO_free(ptr);
      }
      sk_delete(*pp_Var1,iVar2);
      st = *pp_Var1;
    }
  }
  iVar2 = sk_push(st,param);
  if (iVar2 != 0) {
    iVar2 = 1;
  }
  return iVar2;
}

