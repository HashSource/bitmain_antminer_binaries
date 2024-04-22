
undefined4
pkey_gost_mac_keygen(EVP_PKEY_CTX *param_1,EVP_PKEY *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *key;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = (int *)EVP_PKEY_CTX_get_data(param_1);
  if (*piVar1 != 0) {
    key = (int *)CRYPTO_malloc(0x20,DAT_000df994,0x217);
    iVar4 = piVar1[3];
    iVar3 = piVar1[4];
    iVar2 = piVar1[5];
    *key = piVar1[2];
    key[1] = iVar4;
    key[2] = iVar3;
    key[3] = iVar2;
    iVar4 = piVar1[7];
    iVar3 = piVar1[8];
    iVar2 = piVar1[9];
    key[4] = piVar1[6];
    key[5] = iVar4;
    key[6] = iVar3;
    key[7] = iVar2;
    EVP_PKEY_assign(param_2,0x32f,key);
    return 1;
  }
  ERR_GOST_error(0x82,0x74,DAT_000df994,0x214,param_4);
  return 0;
}

