
undefined4 check_revocation(int param_1)

{
  X509 *a;
  int iVar1;
  X509_NAME *pXVar2;
  int iVar3;
  _STACK *st;
  int iVar4;
  X509_CRL *pXVar5;
  int iVar6;
  int iVar7;
  X509_CRL *local_40;
  X509_CRL *local_3c;
  X509_CRL *local_38;
  undefined4 local_34;
  X509_CRL *local_30;
  X509_CRL *local_2c [2];
  
  iVar4 = *(int *)(*(int *)(param_1 + 0x14) + 0xc);
  if (iVar4 << 0x1d < 0) {
    if (iVar4 << 0x1c < 0) {
      iVar4 = sk_num(*(_STACK **)(param_1 + 0x54));
      iVar4 = iVar4 + -1;
      if (iVar4 < 0) {
        return 1;
      }
    }
    else {
      if (*(int *)(param_1 + 0x7c) != 0) {
        return 1;
      }
      iVar4 = 0;
    }
    iVar7 = 0;
    do {
      *(int *)(param_1 + 0x60) = iVar7;
      iVar6 = 0;
      local_40 = (X509_CRL *)0x0;
      a = (X509 *)sk_value(*(_STACK **)(param_1 + 0x54),iVar7);
      pXVar5 = *(X509_CRL **)(param_1 + 0x30);
      *(X509 **)(param_1 + 0x68) = a;
      *(undefined4 *)(param_1 + 0x6c) = 0;
      *(undefined4 *)(param_1 + 0x74) = 0;
      *(undefined4 *)(param_1 + 0x78) = 0;
      if (pXVar5 == (X509_CRL *)0x0) goto LAB_000c16b4;
LAB_000c1638:
      iVar1 = (*(code *)pXVar5)(param_1,&local_40,a);
      iVar3 = iVar6;
      pXVar5 = (X509_CRL *)0x0;
      if (iVar1 != 0) {
        do {
          *(X509_CRL **)(param_1 + 0x70) = local_40;
          iVar6 = (**(code **)(param_1 + 0x34))(param_1);
          if (iVar6 == 0) goto LAB_000c1738;
          if (pXVar5 == (X509_CRL *)0x0) {
LAB_000c167c:
            iVar6 = (**(code **)(param_1 + 0x38))(param_1,local_40,a);
            if (iVar6 == 0) {
LAB_000c1738:
              X509_CRL_free(local_40);
              X509_CRL_free(pXVar5);
              *(undefined4 *)(param_1 + 0x70) = 0;
              return 0;
            }
          }
          else {
            iVar6 = (**(code **)(param_1 + 0x34))(param_1,pXVar5);
            if ((iVar6 == 0) ||
               (iVar6 = (**(code **)(param_1 + 0x38))(param_1,pXVar5,a), iVar6 == 0))
            goto LAB_000c1738;
            if (iVar6 != 2) goto LAB_000c167c;
          }
          X509_CRL_free(local_40);
          X509_CRL_free(pXVar5);
          iVar6 = *(int *)(param_1 + 0x78);
          local_40 = (X509_CRL *)0x0;
          if (iVar6 == iVar3) break;
          if (iVar6 == 0x807f) {
            X509_CRL_free((X509_CRL *)0x0);
            X509_CRL_free((X509_CRL *)0x0);
            *(undefined4 *)(param_1 + 0x70) = 0;
            goto LAB_000c172c;
          }
          pXVar5 = *(X509_CRL **)(param_1 + 0x30);
          if (pXVar5 != (X509_CRL *)0x0) goto LAB_000c1638;
LAB_000c16b4:
          local_3c = pXVar5;
          local_38 = pXVar5;
          local_30 = pXVar5;
          local_2c[0] = pXVar5;
          pXVar2 = X509_get_issuer_name(a);
          local_34 = *(undefined4 *)(param_1 + 0x78);
          iVar3 = get_crl_sk(param_1,&local_30,local_2c,&local_3c,&local_38,&local_34,
                             *(undefined4 *)(param_1 + 0x10));
          if (iVar3 == 0) {
            st = (_STACK *)(**(code **)(param_1 + 0x44))(param_1,pXVar2);
            if ((st != (_STACK *)0x0) || (local_30 == (X509_CRL *)0x0)) {
              get_crl_sk(param_1,&local_30,local_2c,&local_3c,&local_38,&local_34,st);
              sk_pop_free(st,DAT_000c1794);
              goto LAB_000c16e6;
            }
          }
          else {
LAB_000c16e6:
            if (local_30 == (X509_CRL *)0x0) break;
          }
          *(X509_CRL **)(param_1 + 0x6c) = local_3c;
          *(X509_CRL **)(param_1 + 0x74) = local_38;
          *(undefined4 *)(param_1 + 0x78) = local_34;
          iVar3 = iVar6;
          pXVar5 = local_2c[0];
          local_40 = local_30;
        } while( true );
      }
      *(undefined4 *)(param_1 + 100) = 3;
      iVar6 = (**(code **)(param_1 + 0x20))(0,param_1);
      X509_CRL_free(local_40);
      X509_CRL_free((X509_CRL *)0x0);
      *(undefined4 *)(param_1 + 0x70) = 0;
      if (iVar6 == 0) {
        return 0;
      }
LAB_000c172c:
      iVar7 = iVar7 + 1;
    } while (iVar7 <= iVar4);
  }
  return 1;
}

