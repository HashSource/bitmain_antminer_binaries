
undefined4 i2r_idp(undefined4 param_1,int **param_2,BIO *param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  GENERAL_NAME *gen;
  int iVar3;
  int *piVar4;
  _STACK *p_Var5;
  ASN1_BIT_STRING *a;
  X509_NAME local_34;
  
  piVar4 = *param_2;
  if (piVar4 != (int *)0x0) {
    if (*piVar4 == 0) {
      BIO_printf(param_3,DAT_000ca8bc,param_4,DAT_000ca890);
      p_Var5 = (_STACK *)piVar4[1];
      for (iVar3 = 0; iVar2 = sk_num(p_Var5), iVar3 < iVar2; iVar3 = iVar3 + 1) {
        BIO_printf(param_3,DAT_000ca8c0,param_4 + 2,DAT_000ca890);
        gen = (GENERAL_NAME *)sk_value(p_Var5,iVar3);
        GENERAL_NAME_print(param_3,gen);
        BIO_puts(param_3,DAT_000ca898);
      }
    }
    else {
      local_34.entries = (stack_st_X509_NAME_ENTRY *)piVar4[1];
      BIO_printf(param_3,DAT_000ca894,param_4,DAT_000ca890,param_4 + 2,DAT_000ca890);
      X509_NAME_print_ex(param_3,&local_34,0,0x82031f);
      BIO_puts(param_3,DAT_000ca898);
    }
  }
  if (0 < (int)param_2[1]) {
    BIO_printf(param_3,DAT_000ca89c,param_4,DAT_000ca890);
  }
  if (0 < (int)param_2[2]) {
    BIO_printf(param_3,DAT_000ca8a0,param_4,DAT_000ca890);
  }
  if (0 < (int)param_2[4]) {
    BIO_printf(param_3,DAT_000ca8a4,param_4,DAT_000ca890);
  }
  iVar3 = DAT_000ca8b0;
  a = (ASN1_BIT_STRING *)param_2[3];
  if (a != (ASN1_BIT_STRING *)0x0) {
    bVar1 = true;
    BIO_printf(param_3,DAT_000ca8ac,param_4,DAT_000ca890,DAT_000ca8a8,param_4 + 2,DAT_000ca890);
    do {
      HintPreloadData(iVar3 + 0x40);
      iVar2 = ASN1_BIT_STRING_get_bit(a,*(int *)(iVar3 + -0xc));
      if (iVar2 != 0) {
        if (!bVar1) {
          BIO_puts(param_3,DAT_000ca8b4);
        }
        bVar1 = false;
        BIO_puts(param_3,*(char **)(iVar3 + -8));
      }
      piVar4 = (int *)(iVar3 + 4);
      iVar3 = iVar3 + 0xc;
    } while (*piVar4 != 0);
    if (bVar1) {
      BIO_puts(param_3,DAT_000ca8c4);
    }
    else {
      BIO_puts(param_3,DAT_000ca898);
    }
  }
  if (0 < (int)param_2[5]) {
    BIO_printf(param_3,DAT_000ca8b8,param_4,DAT_000ca890);
  }
  if ((((*param_2 == (int *)0x0) && ((int)param_2[1] < 1)) && ((int)param_2[2] < 1)) &&
     ((((int)param_2[4] < 1 && (param_2[3] == (int *)0x0)) && ((int)param_2[5] < 1)))) {
    BIO_printf(param_3,DAT_000ca8c8,param_4,DAT_000ca890);
  }
  return 1;
}

