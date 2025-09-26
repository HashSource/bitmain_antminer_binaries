
undefined4 check_revocation(int param_1)

{
  X509 *a;
  X509_NAME *pXVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  X509_CRL *pXVar5;
  uint uVar6;
  X509_CRL *a_00;
  int local_50;
  X509_CRL *local_40;
  X509_CRL *local_3c;
  X509_CRL *local_38;
  undefined4 local_34;
  X509_CRL *local_30;
  X509_CRL *local_2c [2];
  
  iVar4 = *(int *)(*(int *)(param_1 + 0x10) + 0xc);
  if (iVar4 << 0x1d < 0) {
    if (iVar4 << 0x1c < 0) {
      local_50 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x50));
      local_50 = local_50 + -1;
      if (local_50 < 0) {
        return 1;
      }
    }
    else {
      if (*(int *)(param_1 + 0x78) != 0) {
        return 1;
      }
      local_50 = 0;
    }
    iVar4 = 0;
    do {
      while( true ) {
        *(int *)(param_1 + 0x5c) = iVar4;
        local_40 = (X509_CRL *)0x0;
        a = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar4);
        uVar6 = a[1].references;
        *(X509 **)(param_1 + 100) = a;
        *(undefined4 *)(param_1 + 0x68) = 0;
        *(undefined4 *)(param_1 + 0x70) = 0;
        *(undefined4 *)(param_1 + 0x74) = 0;
        if ((uVar6 & 0x400) != 0) break;
        iVar3 = 0;
        do {
          pXVar5 = *(X509_CRL **)(param_1 + 0x2c);
          if (pXVar5 != (X509_CRL *)0x0) {
            a_00 = (X509_CRL *)0x0;
            iVar2 = (*(code *)pXVar5)(param_1,&local_40,a);
            if (iVar2 != 0) goto LAB_001731ba;
LAB_0017326c:
            *(undefined4 *)(param_1 + 0x60) = 3;
            iVar3 = (**(code **)(param_1 + 0x1c))(0,param_1);
            X509_CRL_free(local_40);
            X509_CRL_free((X509_CRL *)0x0);
            *(undefined4 *)(param_1 + 0x6c) = 0;
            if (iVar3 == 0) {
              return 0;
            }
            goto LAB_00173290;
          }
          local_3c = pXVar5;
          local_38 = pXVar5;
          local_30 = pXVar5;
          local_2c[0] = pXVar5;
          pXVar1 = X509_get_issuer_name(a);
          local_34 = *(undefined4 *)(param_1 + 0x74);
          iVar2 = get_crl_sk(param_1,&local_30,local_2c,&local_3c,&local_38,&local_34,
                             *(undefined4 *)(param_1 + 0xc));
          if (iVar2 == 0) {
            iVar2 = (**(code **)(param_1 + 0x40))(param_1,pXVar1);
            if ((iVar2 != 0) || (local_30 == (X509_CRL *)0x0)) {
              get_crl_sk(param_1,&local_30,local_2c,&local_3c,&local_38,&local_34,iVar2);
              OPENSSL_sk_pop_free(iVar2,(undefined *)0x176e4d);
              goto LAB_00173252;
            }
          }
          else {
LAB_00173252:
            if (local_30 == (X509_CRL *)0x0) goto LAB_0017326c;
          }
          *(X509_CRL **)(param_1 + 0x68) = local_3c;
          *(X509_CRL **)(param_1 + 0x70) = local_38;
          *(undefined4 *)(param_1 + 0x74) = local_34;
          a_00 = local_2c[0];
          local_40 = local_30;
LAB_001731ba:
          *(X509_CRL **)(param_1 + 0x6c) = local_40;
          iVar2 = (**(code **)(param_1 + 0x30))(param_1);
          if (iVar2 == 0) goto LAB_0017329c;
          if (a_00 == (X509_CRL *)0x0) {
LAB_001731e8:
            iVar2 = (**(code **)(param_1 + 0x34))(param_1,local_40,a);
            if (iVar2 == 0) {
LAB_0017329c:
              X509_CRL_free(local_40);
              X509_CRL_free(a_00);
              *(undefined4 *)(param_1 + 0x6c) = 0;
              return 0;
            }
          }
          else {
            iVar2 = (**(code **)(param_1 + 0x30))(param_1,a_00);
            if ((iVar2 == 0) || (iVar2 = (**(code **)(param_1 + 0x34))(param_1,a_00,a), iVar2 == 0))
            goto LAB_0017329c;
            if (iVar2 != 2) goto LAB_001731e8;
          }
          X509_CRL_free(local_40);
          X509_CRL_free(a_00);
          iVar2 = *(int *)(param_1 + 0x74);
          local_40 = (X509_CRL *)0x0;
          if (iVar3 == iVar2) goto LAB_0017326c;
          iVar3 = iVar2;
        } while (iVar2 != 0x807f);
        X509_CRL_free((X509_CRL *)0x0);
        X509_CRL_free((X509_CRL *)0x0);
        iVar4 = iVar4 + 1;
        *(undefined4 *)(param_1 + 0x6c) = 0;
        if (local_50 < iVar4) {
          return 1;
        }
      }
LAB_00173290:
      iVar4 = iVar4 + 1;
    } while (iVar4 <= local_50);
  }
  return 1;
}

