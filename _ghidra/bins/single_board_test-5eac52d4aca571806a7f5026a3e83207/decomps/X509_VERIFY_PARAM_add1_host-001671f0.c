
undefined4 X509_VERIFY_PARAM_add1_host(int param_1,char *param_2,size_t param_3,undefined4 param_4)

{
  void *pvVar1;
  size_t sVar2;
  int iVar3;
  
  if (param_2 == (char *)0x0 || param_3 == 0) {
    if (param_2 == (char *)0x0) {
      return 1;
    }
    param_3 = strlen(param_2);
    if (param_3 == 0) {
      return 1;
    }
    sVar2 = param_3 - 1;
    if (param_2[sVar2] == '\0') goto LAB_0016729c;
  }
  else {
    if (param_3 < 2) {
      sVar2 = 1;
    }
    else {
      sVar2 = param_3 - 1;
    }
    pvVar1 = memchr(param_2,0,sVar2);
    if (pvVar1 != (void *)0x0) {
      return 0;
    }
    sVar2 = param_3 - 1;
    if (param_2[sVar2] != '\0') goto LAB_0016724c;
LAB_0016729c:
    param_3 = sVar2;
  }
  if (param_3 == 0 || param_2 == (char *)0x0) {
    return 1;
  }
LAB_0016724c:
  pvVar1 = (void *)CRYPTO_strndup(param_2,param_3,"crypto/x509/x509_vpm.c",0x3b,param_4);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0x24);
  if (iVar3 == 0) {
    iVar3 = OPENSSL_sk_new_null();
    *(int *)(param_1 + 0x24) = iVar3;
    if (iVar3 == 0) {
      CRYPTO_free(pvVar1);
      return 0;
    }
  }
  iVar3 = OPENSSL_sk_push(iVar3,pvVar1);
  if (iVar3 != 0) {
    return 1;
  }
  CRYPTO_free(pvVar1);
  iVar3 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x24));
  if (iVar3 != 0) {
    return 0;
  }
  OPENSSL_sk_free(*(undefined4 *)(param_1 + 0x24));
  *(undefined4 *)(param_1 + 0x24) = 0;
  return 0;
}

