
undefined4 EVP_CIPHER_CTX_reset(int *param_1)

{
  int iVar1;
  void *ptr;
  code *pcVar2;
  
  if (param_1 == (int *)0x0) {
    return 1;
  }
  if (*param_1 != 0) {
    pcVar2 = *(code **)(*param_1 + 0x1c);
    if ((pcVar2 != (code *)0x0) && (iVar1 = (*pcVar2)(), iVar1 == 0)) {
      return 0;
    }
    ptr = (void *)param_1[0x18];
    if ((ptr == (void *)0x0) || (*(size_t *)(*param_1 + 0x20) == 0)) goto LAB_0012b604;
    OPENSSL_cleanse(ptr,*(size_t *)(*param_1 + 0x20));
  }
  ptr = (void *)param_1[0x18];
LAB_0012b604:
  CRYPTO_free(ptr);
  ENGINE_finish((ENGINE *)param_1[1]);
  memset(param_1,0,0x8c);
  return 1;
}

