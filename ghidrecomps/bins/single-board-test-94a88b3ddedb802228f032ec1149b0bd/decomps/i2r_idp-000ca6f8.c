
undefined4 i2r_idp(undefined4 param_1,int *param_2,BIO *param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  GENERAL_NAME *gen;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  _STACK *p_Var6;
  ASN1_BIT_STRING *a;
  X509_NAME local_34;
  
  piVar5 = (int *)*param_2;
  if (piVar5 != (int *)0x0) {
    if (*piVar5 == 0) {
      BIO_printf(param_3,"%*sFull Name:\n",param_4,&DAT_0013a6fc);
      p_Var6 = (_STACK *)piVar5[1];
      for (iVar2 = 0; iVar3 = sk_num(p_Var6), iVar2 < iVar3; iVar2 = iVar2 + 1) {
        BIO_printf(param_3,"%*s",param_4 + 2,&DAT_0013a6fc);
        gen = (GENERAL_NAME *)sk_value(p_Var6,iVar2);
        GENERAL_NAME_print(param_3,gen);
        BIO_puts(param_3,"\n");
      }
    }
    else {
      local_34.entries = (stack_st_X509_NAME_ENTRY *)piVar5[1];
      BIO_printf(param_3,"%*sRelative Name:\n%*s",param_4,&DAT_0013a6fc,param_4 + 2,&DAT_0013a6fc);
      X509_NAME_print_ex(param_3,&local_34,0,0x82031f);
      BIO_puts(param_3,"\n");
    }
  }
  if (0 < param_2[1]) {
    BIO_printf(param_3,"%*sOnly User Certificates\n",param_4,&DAT_0013a6fc);
  }
  if (0 < param_2[2]) {
    BIO_printf(param_3,"%*sOnly CA Certificates\n",param_4,&DAT_0013a6fc);
  }
  if (0 < param_2[4]) {
    BIO_printf(param_3,"%*sIndirect CRL\n",param_4,&DAT_0013a6fc);
  }
  a = (ASN1_BIT_STRING *)param_2[3];
  if (a != (ASN1_BIT_STRING *)0x0) {
    bVar1 = true;
    BIO_printf(param_3,"%*s%s:\n%*s",param_4,&DAT_0013a6fc,"Only Some Reasons",param_4 + 2,
               &DAT_0013a6fc);
    puVar4 = &DAT_00165c98;
    do {
      HintPreloadData(puVar4 + 0x10);
      iVar2 = ASN1_BIT_STRING_get_bit(a,puVar4[-3]);
      if (iVar2 != 0) {
        if (!bVar1) {
          BIO_puts(param_3,", ");
        }
        bVar1 = false;
        BIO_puts(param_3,(char *)puVar4[-2]);
      }
      piVar5 = puVar4 + 1;
      puVar4 = puVar4 + 3;
    } while (*piVar5 != 0);
    if (bVar1) {
      BIO_puts(param_3,"<EMPTY>\n");
    }
    else {
      BIO_puts(param_3,"\n");
    }
  }
  if (0 < param_2[5]) {
    BIO_printf(param_3,"%*sOnly Attribute Certificates\n",param_4,&DAT_0013a6fc);
  }
  if ((((*param_2 == 0) && (param_2[1] < 1)) && (param_2[2] < 1)) &&
     (((param_2[4] < 1 && (param_2[3] == 0)) && (param_2[5] < 1)))) {
    BIO_printf(param_3,"%*s<EMPTY>\n",param_4,&DAT_0013a6fc);
  }
  return 1;
}

