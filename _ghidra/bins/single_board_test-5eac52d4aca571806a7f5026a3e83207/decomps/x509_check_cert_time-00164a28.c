
int x509_check_cert_time(int param_1,int param_2,uint param_3)

{
  ASN1_TIME *pAVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  time_t *t;
  
  uVar4 = *(uint *)(*(int *)(param_1 + 0x10) + 0xc);
  if ((int)(uVar4 << 0x1e) < 0) {
    t = (time_t *)(*(int *)(param_1 + 0x10) + 4);
  }
  else {
    if ((uVar4 & 0x200000) != 0) {
      return 1;
    }
    t = (time_t *)0x0;
  }
  uVar4 = param_3 >> 0x1f;
  pAVar1 = (ASN1_TIME *)X509_get0_notBefore(param_2);
  iVar2 = X509_cmp_time(pAVar1,t);
  uVar5 = uVar4;
  if (iVar2 < 0) {
    uVar5 = 0;
  }
  if (uVar5 != 0) {
    return 0;
  }
  iVar3 = param_2;
  if (iVar2 == 0) {
    *(uint *)(param_1 + 0x5c) = param_3;
    if (param_2 == 0) {
      iVar3 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),param_3);
    }
    uVar6 = 0xd;
  }
  else {
    if (iVar2 < 1) goto LAB_00164a82;
    *(uint *)(param_1 + 0x5c) = param_3;
    if (param_2 == 0) {
      iVar3 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),param_3);
    }
    uVar6 = 9;
  }
  *(int *)(param_1 + 100) = iVar3;
  *(undefined4 *)(param_1 + 0x60) = uVar6;
  iVar2 = (**(code **)(param_1 + 0x1c))(0,param_1);
  if (iVar2 == 0) {
    return 0;
  }
LAB_00164a82:
  pAVar1 = (ASN1_TIME *)X509_get0_notAfter(param_2);
  iVar2 = X509_cmp_time(pAVar1,t);
  if (0 < iVar2) {
    uVar4 = 0;
  }
  if (uVar4 != 0) {
    return 0;
  }
  if (iVar2 == 0) {
    *(uint *)(param_1 + 0x5c) = param_3;
    if (param_2 == 0) {
      param_2 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),param_3);
    }
    uVar6 = 0xe;
  }
  else {
    if (-1 < iVar2) {
      return 1;
    }
    *(uint *)(param_1 + 0x5c) = param_3;
    if (param_2 == 0) {
      param_2 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),param_3);
    }
    uVar6 = 10;
  }
  *(int *)(param_1 + 100) = param_2;
  *(undefined4 *)(param_1 + 0x60) = uVar6;
  iVar2 = (**(code **)(param_1 + 0x1c))(0,param_1);
  if (iVar2 != 0) {
    iVar2 = 1;
  }
  return iVar2;
}

