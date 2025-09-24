
undefined4 i2r_crldp(undefined4 param_1,undefined4 param_2,BIO *param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  GENERAL_NAME *pGVar5;
  int iVar6;
  ASN1_BIT_STRING *a;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  X509_NAME local_3c;
  
  iVar9 = 0;
  iVar2 = OPENSSL_sk_num(param_2);
  if (0 < iVar2) {
    do {
      BIO_puts(param_3,"\n");
      puVar3 = (undefined4 *)OPENSSL_sk_value(param_2,iVar9);
      piVar8 = (int *)*puVar3;
      if (piVar8 != (int *)0x0) {
        if (*piVar8 == 0) {
          BIO_printf(param_3,"%*sFull Name:\n",param_4,"");
          iVar4 = piVar8[1];
          iVar2 = 0;
          while( true ) {
            iVar6 = OPENSSL_sk_num(iVar4);
            if (iVar6 <= iVar2) break;
            BIO_printf(param_3,"%*s",param_4 + 2,"");
            pGVar5 = (GENERAL_NAME *)OPENSSL_sk_value(iVar4,iVar2);
            GENERAL_NAME_print(param_3,pGVar5);
            iVar2 = iVar2 + 1;
            BIO_puts(param_3,"\n");
          }
        }
        else {
          local_3c.entries = (stack_st_X509_NAME_ENTRY *)piVar8[1];
          BIO_printf(param_3,"%*sRelative Name:\n%*s",param_4,"",param_4 + 2,"");
          X509_NAME_print_ex(param_3,&local_3c,0,0x82031f);
          BIO_puts(param_3,"\n");
        }
      }
      a = (ASN1_BIT_STRING *)puVar3[1];
      if (a != (ASN1_BIT_STRING *)0x0) {
        BIO_printf(param_3,"%*s%s:\n%*s",param_4,"","Reasons",param_4 + 2,"");
        bVar1 = true;
        iVar2 = 0x2697b8;
        do {
          HintPreloadData(iVar2);
          iVar4 = ASN1_BIT_STRING_get_bit(a,*(int *)(iVar2 + -0x4c));
          if (iVar4 != 0) {
            if (!bVar1) {
              BIO_puts(param_3,", ");
            }
            bVar1 = false;
            BIO_puts(param_3,*(char **)(iVar2 + -0x48));
          }
          piVar8 = (int *)(iVar2 + -0x3c);
          iVar2 = iVar2 + 0xc;
        } while (*piVar8 != 0);
        if (bVar1) {
          BIO_puts(param_3,"<EMPTY>\n");
        }
        else {
          BIO_puts(param_3,"\n");
        }
      }
      if (puVar3[2] != 0) {
        iVar2 = 0;
        BIO_printf(param_3,"%*sCRL Issuer:\n",param_4,"");
        uVar7 = puVar3[2];
        while( true ) {
          iVar4 = OPENSSL_sk_num(uVar7);
          if (iVar4 <= iVar2) break;
          BIO_printf(param_3,"%*s",param_4 + 2,"");
          pGVar5 = (GENERAL_NAME *)OPENSSL_sk_value(uVar7,iVar2);
          GENERAL_NAME_print(param_3,pGVar5);
          iVar2 = iVar2 + 1;
          BIO_puts(param_3,"\n");
        }
      }
      iVar9 = iVar9 + 1;
      iVar2 = OPENSSL_sk_num(param_2);
    } while (iVar9 < iVar2);
  }
  return 1;
}

