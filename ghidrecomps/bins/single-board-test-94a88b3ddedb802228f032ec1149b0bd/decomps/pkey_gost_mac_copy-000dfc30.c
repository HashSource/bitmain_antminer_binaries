
void * pkey_gost_mac_copy(EVP_PKEY_CTX *param_1,EVP_PKEY_CTX *param_2)

{
  void *__s;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  __s = CRYPTO_malloc(0x28,DAT_000dfc7c,0x19a);
  if (__s != (void *)0x0) {
    memset(__s,0,0x28);
    EVP_PKEY_CTX_set_data(param_1,__s);
    __s = (void *)0x1;
    puVar1 = (undefined4 *)EVP_PKEY_CTX_get_data(param_2);
    puVar2 = (undefined4 *)EVP_PKEY_CTX_get_data(param_1);
    uVar3 = puVar1[1];
    uVar4 = puVar1[2];
    uVar5 = puVar1[3];
    *puVar2 = *puVar1;
    puVar2[1] = uVar3;
    puVar2[2] = uVar4;
    puVar2[3] = uVar5;
    uVar3 = puVar1[5];
    uVar4 = puVar1[6];
    uVar5 = puVar1[7];
    puVar2[4] = puVar1[4];
    puVar2[5] = uVar3;
    puVar2[6] = uVar4;
    puVar2[7] = uVar5;
    uVar3 = puVar1[9];
    puVar2[8] = puVar1[8];
    puVar2[9] = uVar3;
  }
  return __s;
}

