
undefined4 EVP_PKEY_get0_siphash(EVP_PKEY *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1->type == 0x426) {
    puVar1 = (undefined4 *)EVP_PKEY_get0(param_1);
    uVar2 = puVar1[2];
    *param_2 = *puVar1;
    return uVar2;
  }
  ERR_put_error(6,0xac,0xaf,"crypto/evp/p_lib.c",0x1c5);
  return 0;
}

