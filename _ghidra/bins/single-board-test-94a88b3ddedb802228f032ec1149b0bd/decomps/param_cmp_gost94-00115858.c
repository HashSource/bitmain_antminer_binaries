
int param_cmp_gost94(EVP_PKEY *param_1,EVP_PKEY *param_2)

{
  void *pvVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  
  pvVar1 = EVP_PKEY_get0(param_1);
  pvVar2 = EVP_PKEY_get0(param_2);
  uVar3 = BN_cmp(*(BIGNUM **)((int)pvVar1 + 0x10),*(BIGNUM **)((int)pvVar2 + 0x10));
  iVar4 = 1 - uVar3;
  if (1 < uVar3) {
    iVar4 = 0;
  }
  return iVar4;
}

