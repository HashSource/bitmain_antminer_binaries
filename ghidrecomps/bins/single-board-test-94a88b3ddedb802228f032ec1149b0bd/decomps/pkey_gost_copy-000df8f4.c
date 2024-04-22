
int pkey_gost_copy(EVP_PKEY_CTX *param_1,EVP_PKEY_CTX *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  iVar1 = pkey_gost_init();
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)EVP_PKEY_CTX_get_data(param_2);
    puVar3 = (undefined4 *)EVP_PKEY_CTX_get_data(param_1);
    uVar4 = puVar2[1];
    uVar5 = puVar2[2];
    uVar6 = puVar2[3];
    *puVar3 = *puVar2;
    puVar3[1] = uVar4;
    puVar3[2] = uVar5;
    puVar3[3] = uVar6;
    if (puVar2[2] != 0) {
      puVar3[2] = 0;
      return 1;
    }
    iVar1 = 1;
  }
  return iVar1;
}

