
undefined4 i2r_crldp(undefined4 param_1,_STACK *param_2,BIO *param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  GENERAL_NAME *pGVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  ASN1_BIT_STRING *a;
  _STACK *p_Var8;
  int iVar9;
  X509_NAME local_3c;
  
  iVar9 = 0;
  iVar2 = sk_num(param_2);
  if (0 < iVar2) {
    do {
      BIO_puts(param_3,"\n");
      puVar3 = (undefined4 *)sk_value(param_2,iVar9);
      piVar7 = (int *)*puVar3;
      if (piVar7 != (int *)0x0) {
        if (*piVar7 == 0) {
          BIO_printf(param_3,"%*sFull Name:\n",param_4,"");
          p_Var8 = (_STACK *)piVar7[1];
          for (iVar2 = 0; iVar5 = sk_num(p_Var8), iVar2 < iVar5; iVar2 = iVar2 + 1) {
            BIO_printf(param_3,"%*s",param_4 + 2,"");
            pGVar4 = (GENERAL_NAME *)sk_value(p_Var8,iVar2);
            GENERAL_NAME_print(param_3,pGVar4);
            BIO_puts(param_3,"\n");
          }
        }
        else {
          local_3c.entries = (stack_st_X509_NAME_ENTRY *)piVar7[1];
          BIO_printf(param_3,"%*sRelative Name:\n%*s",param_4,"",param_4 + 2,"");
          X509_NAME_print_ex(param_3,&local_3c,0,0x82031f);
          BIO_puts(param_3,"\n");
        }
      }
      a = (ASN1_BIT_STRING *)puVar3[1];
      if (a != (ASN1_BIT_STRING *)0x0) {
        BIO_printf(param_3,"%*s%s:\n%*s",param_4,"","Reasons",param_4 + 2,"");
        bVar1 = true;
        puVar6 = &DAT_00218fb0;
        do {
          HintPreloadData(puVar6 + 0x10);
          iVar2 = ASN1_BIT_STRING_get_bit(a,puVar6[-3]);
          if (iVar2 != 0) {
            if (!bVar1) {
              BIO_puts(param_3,", ");
            }
            bVar1 = false;
            BIO_puts(param_3,(char *)puVar6[-2]);
          }
          piVar7 = puVar6 + 1;
          puVar6 = puVar6 + 3;
        } while (*piVar7 != 0);
        if (bVar1) {
          BIO_puts(param_3,"<EMPTY>\n");
        }
        else {
          BIO_puts(param_3,"\n");
        }
      }
      if (puVar3[2] != 0) {
        BIO_printf(param_3,"%*sCRL Issuer:\n",param_4,"");
        p_Var8 = (_STACK *)puVar3[2];
        for (iVar2 = 0; iVar5 = sk_num(p_Var8), iVar2 < iVar5; iVar2 = iVar2 + 1) {
          BIO_printf(param_3,"%*s",param_4 + 2,"");
          pGVar4 = (GENERAL_NAME *)sk_value(p_Var8,iVar2);
          GENERAL_NAME_print(param_3,pGVar4);
          BIO_puts(param_3,"\n");
        }
      }
      iVar9 = iVar9 + 1;
      iVar2 = sk_num(param_2);
    } while (iVar9 < iVar2);
  }
  return 1;
}

