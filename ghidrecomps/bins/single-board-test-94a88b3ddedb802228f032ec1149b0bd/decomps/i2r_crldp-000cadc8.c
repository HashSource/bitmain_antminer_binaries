
undefined4 i2r_crldp(undefined4 param_1,_STACK *param_2,BIO *param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int **ppiVar3;
  int iVar4;
  GENERAL_NAME *pGVar5;
  int *piVar6;
  ASN1_BIT_STRING *a;
  _STACK *p_Var7;
  int iVar8;
  X509_NAME local_3c;
  
  iVar8 = 0;
  iVar2 = sk_num(param_2);
  if (0 < iVar2) {
    do {
      BIO_puts(param_3,DAT_000caf74);
      ppiVar3 = (int **)sk_value(param_2,iVar8);
      piVar6 = *ppiVar3;
      if (piVar6 != (int *)0x0) {
        if (*piVar6 == 0) {
          BIO_printf(param_3,DAT_000caf94,param_4,DAT_000caf7c);
          p_Var7 = (_STACK *)piVar6[1];
          for (iVar2 = 0; iVar4 = sk_num(p_Var7), iVar2 < iVar4; iVar2 = iVar2 + 1) {
            BIO_printf(param_3,DAT_000caf90,param_4 + 2,DAT_000caf7c);
            pGVar5 = (GENERAL_NAME *)sk_value(p_Var7,iVar2);
            GENERAL_NAME_print(param_3,pGVar5);
            BIO_puts(param_3,DAT_000caf74);
          }
        }
        else {
          local_3c.entries = (stack_st_X509_NAME_ENTRY *)piVar6[1];
          BIO_printf(param_3,DAT_000caf78,param_4,DAT_000caf7c,param_4 + 2,&DAT_0013a6fc);
          X509_NAME_print_ex(param_3,&local_3c,0,0x82031f);
          BIO_puts(param_3,DAT_000caf74);
        }
      }
      a = (ASN1_BIT_STRING *)ppiVar3[1];
      if (a != (ASN1_BIT_STRING *)0x0) {
        BIO_printf(param_3,DAT_000caf80,param_4,DAT_000caf7c,"Reasons",param_4 + 2,&DAT_0013a6fc);
        bVar1 = true;
        iVar2 = DAT_000caf84;
        do {
          HintPreloadData(iVar2 + 0x40);
          iVar4 = ASN1_BIT_STRING_get_bit(a,*(int *)(iVar2 + -0xc));
          if (iVar4 != 0) {
            if (!bVar1) {
              BIO_puts(param_3,DAT_000caf88);
            }
            bVar1 = false;
            BIO_puts(param_3,*(char **)(iVar2 + -8));
          }
          piVar6 = (int *)(iVar2 + 4);
          iVar2 = iVar2 + 0xc;
        } while (*piVar6 != 0);
        if (bVar1) {
          BIO_puts(param_3,DAT_000caf98);
        }
        else {
          BIO_puts(param_3,DAT_000caf74);
        }
      }
      if (ppiVar3[2] != (int *)0x0) {
        BIO_printf(param_3,DAT_000caf8c,param_4,DAT_000caf7c);
        p_Var7 = (_STACK *)ppiVar3[2];
        for (iVar2 = 0; iVar4 = sk_num(p_Var7), iVar2 < iVar4; iVar2 = iVar2 + 1) {
          BIO_printf(param_3,DAT_000caf90,param_4 + 2,DAT_000caf7c);
          pGVar5 = (GENERAL_NAME *)sk_value(p_Var7,iVar2);
          GENERAL_NAME_print(param_3,pGVar5);
          BIO_puts(param_3,DAT_000caf74);
        }
      }
      iVar8 = iVar8 + 1;
      iVar2 = sk_num(param_2);
    } while (iVar8 < iVar2);
  }
  return 1;
}

