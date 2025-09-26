
undefined4 i2r_idp(undefined4 param_1,int *param_2,BIO *param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  GENERAL_NAME *gen;
  int iVar3;
  int iVar4;
  int *piVar5;
  ASN1_BIT_STRING *a;
  X509_NAME local_3c;
  
  piVar5 = (int *)*param_2;
  if (piVar5 != (int *)0x0) {
    if (*piVar5 == 0) {
      BIO_printf(param_3,"%*sFull Name:\n",param_4,"");
      iVar2 = piVar5[1];
      iVar4 = 0;
      while( true ) {
        iVar3 = OPENSSL_sk_num(iVar2);
        if (iVar3 <= iVar4) break;
        BIO_printf(param_3,"%*s",param_4 + 2,"");
        gen = (GENERAL_NAME *)OPENSSL_sk_value(iVar2,iVar4);
        GENERAL_NAME_print(param_3,gen);
        iVar4 = iVar4 + 1;
        BIO_puts(param_3,"\n");
      }
    }
    else {
      local_3c.entries = (stack_st_X509_NAME_ENTRY *)piVar5[1];
      BIO_printf(param_3,"%*sRelative Name:\n%*s",param_4,"",param_4 + 2,"");
      X509_NAME_print_ex(param_3,&local_3c,0,0x82031f);
      BIO_puts(param_3,"\n");
    }
  }
  if (0 < param_2[1]) {
    BIO_printf(param_3,"%*sOnly User Certificates\n",param_4,"");
  }
  if (0 < param_2[2]) {
    BIO_printf(param_3,"%*sOnly CA Certificates\n",param_4,"");
  }
  if (0 < param_2[4]) {
    BIO_printf(param_3,"%*sIndirect CRL\n",param_4,"");
  }
  a = (ASN1_BIT_STRING *)param_2[3];
  if (a != (ASN1_BIT_STRING *)0x0) {
    bVar1 = true;
    BIO_printf(param_3,"%*s%s:\n%*s",param_4,"","Only Some Reasons",param_4 + 2,"");
    iVar4 = 0x275298;
    do {
      HintPreloadData(iVar4);
      iVar2 = ASN1_BIT_STRING_get_bit(a,*(int *)(iVar4 + -0x4c));
      if (iVar2 != 0) {
        if (!bVar1) {
          BIO_puts(param_3,", ");
        }
        bVar1 = false;
        BIO_puts(param_3,*(char **)(iVar4 + -0x48));
      }
      piVar5 = (int *)(iVar4 + -0x3c);
      iVar4 = iVar4 + 0xc;
    } while (*piVar5 != 0);
    if (bVar1) {
      BIO_puts(param_3,"<EMPTY>\n");
    }
    else {
      BIO_puts(param_3,"\n");
    }
  }
  if (0 < param_2[5]) {
    BIO_printf(param_3,"%*sOnly Attribute Certificates\n",param_4,"");
  }
  if ((((*param_2 == 0) && (param_2[1] < 1)) && (param_2[2] < 1)) &&
     (((param_2[4] < 1 && (param_2[3] == 0)) && (param_2[5] < 1)))) {
    BIO_printf(param_3,"%*s<EMPTY>\n",param_4,"");
  }
  return 1;
}

