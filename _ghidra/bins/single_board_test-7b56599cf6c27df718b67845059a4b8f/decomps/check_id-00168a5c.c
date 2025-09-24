
int check_id(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar5 = *(int *)(param_1 + 0x10);
  uVar6 = *(undefined4 *)(param_1 + 4);
  if (*(int *)(iVar5 + 0x24) == 0) {
LAB_00168ab6:
    if ((*(int *)(iVar5 + 0x30) != 0) &&
       (iVar1 = X509_check_email(uVar6,*(int *)(iVar5 + 0x30),*(undefined4 *)(iVar5 + 0x34),0),
       iVar1 < 1)) {
      iVar1 = *(int *)(param_1 + 4);
      *(undefined4 *)(param_1 + 0x5c) = 0;
      if (iVar1 == 0) {
        iVar1 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50));
      }
      *(int *)(param_1 + 100) = iVar1;
      *(undefined4 *)(param_1 + 0x60) = 0x3f;
      iVar1 = (**(code **)(param_1 + 0x1c))(0,param_1);
      if (iVar1 == 0) goto LAB_00168b36;
    }
    if ((*(int *)(iVar5 + 0x38) != 0) &&
       (iVar5 = X509_check_ip(uVar6,*(int *)(iVar5 + 0x38),*(undefined4 *)(iVar5 + 0x3c),0),
       iVar5 < 1)) {
      iVar5 = *(int *)(param_1 + 4);
      *(undefined4 *)(param_1 + 0x5c) = 0;
      if (iVar5 == 0) {
        iVar5 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50));
      }
      *(int *)(param_1 + 100) = iVar5;
      *(undefined4 *)(param_1 + 0x60) = 0x40;
      iVar5 = (**(code **)(param_1 + 0x1c))(0,param_1);
      if (iVar5 != 0) {
        iVar5 = 1;
      }
      return iVar5;
    }
    iVar5 = 1;
  }
  else {
    iVar1 = OPENSSL_sk_num();
    if (*(void **)(iVar5 + 0x2c) != (void *)0x0) {
      CRYPTO_free(*(void **)(iVar5 + 0x2c));
      *(undefined4 *)(iVar5 + 0x2c) = 0;
    }
    if (iVar1 < 1) {
      if (iVar1 == 0) goto LAB_00168ab6;
    }
    else {
      iVar4 = 0;
      do {
        uVar2 = OPENSSL_sk_value(*(undefined4 *)(iVar5 + 0x24),iVar4);
        iVar4 = iVar4 + 1;
        iVar3 = X509_check_host(uVar6,uVar2,0,*(undefined4 *)(iVar5 + 0x28),iVar5 + 0x2c);
        if (0 < iVar3) goto LAB_00168ab6;
      } while (iVar1 != iVar4);
    }
    iVar1 = *(int *)(param_1 + 4);
    *(undefined4 *)(param_1 + 0x5c) = 0;
    if (iVar1 == 0) {
      iVar1 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50));
    }
    *(int *)(param_1 + 100) = iVar1;
    *(undefined4 *)(param_1 + 0x60) = 0x3e;
    iVar1 = (**(code **)(param_1 + 0x1c))(0,param_1);
    if (iVar1 != 0) goto LAB_00168ab6;
LAB_00168b36:
    iVar5 = 0;
  }
  return iVar5;
}

