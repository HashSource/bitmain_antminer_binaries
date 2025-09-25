
undefined4 check_trust(int param_1,int param_2)

{
  int iVar1;
  X509 *x;
  X509_NAME *pXVar2;
  X509 *a;
  int iVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0x80);
  iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x50));
  if (((((iVar6 != 0) && ((*(uint *)(iVar6 + 0x14) & 5) != 0)) && (param_2 < iVar1 && 0 < param_2))
      && ((*(int *)(param_1 + 0x80) != 0 && ((*(uint *)(*(int *)(param_1 + 0x80) + 0x14) & 5) != 0))
         )) && (iVar4 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),param_2), iVar4 != 0)) {
    iVar4 = dane_match_isra_1(*(undefined4 *)(param_1 + 0x4c),*(undefined4 *)(param_1 + 0x80),iVar4,
                              param_2);
    if (iVar4 < 0) {
      return 2;
    }
    if (iVar4 != 0) {
      *(int *)(param_1 + 0x4c) = param_2 + -1;
      return 1;
    }
  }
  iVar4 = param_2;
  if (param_2 < iVar1) {
    do {
      x = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar4);
      iVar3 = X509_check_trust(x,*(int *)(*(int *)(param_1 + 0x10) + 0x14),0);
      if (iVar3 == 1) goto LAB_001646b0;
      if (iVar3 == 2) goto LAB_0016478a;
      iVar4 = iVar4 + 1;
    } while (iVar4 != iVar1);
    if (-1 < *(int *)(*(int *)(param_1 + 0x10) + 0xc) << 0xc) {
      return 3;
    }
  }
  else {
    if (param_2 != iVar1) {
      return 3;
    }
    if (-1 < *(int *)(*(int *)(param_1 + 0x10) + 0xc) << 0xc) {
      return 3;
    }
    x = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),0);
    pcVar5 = *(code **)(param_1 + 0x3c);
    pXVar2 = X509_get_subject_name(x);
    iVar1 = (*pcVar5)(param_1,pXVar2);
    if (iVar1 == 0) {
      return 3;
    }
    iVar4 = 0;
    do {
      iVar3 = OPENSSL_sk_num(iVar1);
      if (iVar3 <= iVar4) goto LAB_00164770;
      a = (X509 *)OPENSSL_sk_value(iVar1,iVar4);
      iVar3 = X509_cmp(a,x);
      iVar4 = iVar4 + 1;
    } while (iVar3 != 0);
    if ((a == (X509 *)0x0) || (iVar4 = X509_up_ref(a), iVar4 == 0)) {
LAB_00164770:
      OPENSSL_sk_pop_free(iVar1,(undefined *)0x16a341);
      return 3;
    }
    OPENSSL_sk_pop_free(iVar1,(undefined *)0x16a341);
    iVar1 = X509_check_trust(a,*(int *)(*(int *)(param_1 + 0x10) + 0x14),0);
    if (iVar1 == 2) {
      X509_free(a);
      iVar4 = 0;
LAB_0016478a:
      *(int *)(param_1 + 0x5c) = iVar4;
      if (x == (X509 *)0x0) {
        x = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar4);
      }
      *(X509 **)(param_1 + 100) = x;
      *(undefined4 *)(param_1 + 0x60) = 0x1c;
      iVar1 = (**(code **)(param_1 + 0x1c))(0,param_1);
      if (iVar1 != 0) {
        return 3;
      }
      return 2;
    }
    OPENSSL_sk_set(*(undefined4 *)(param_1 + 0x50),0,a);
    X509_free(x);
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
LAB_001646b0:
  if ((iVar6 != 0) && (iVar1 = OPENSSL_sk_num(*(undefined4 *)(iVar6 + 4)), 0 < iVar1)) {
    if (*(int *)(iVar6 + 0x1c) < 0) {
      *(int *)(iVar6 + 0x1c) = param_2;
    }
    if (*(int *)(iVar6 + 0x18) < 0) {
      return 3;
    }
  }
  return 1;
}

