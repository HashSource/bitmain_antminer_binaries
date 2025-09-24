
undefined4
try_decode_PUBKEY(char *param_1,undefined4 param_2,uchar *param_3,long param_4,undefined4 param_5,
                 undefined4 *param_6)

{
  int iVar1;
  EVP_PKEY *pEVar2;
  undefined4 uVar3;
  uchar *local_14 [2];
  
  local_14[0] = param_3;
  if (param_1 != (char *)0x0) {
    iVar1 = strcmp(param_1,"PUBLIC KEY");
    if (iVar1 != 0) {
      return 0;
    }
    *param_6 = 1;
  }
  pEVar2 = d2i_PUBKEY((EVP_PKEY **)0x0,local_14,param_4);
  if (pEVar2 == (EVP_PKEY *)0x0) {
    return 0;
  }
  *param_6 = 1;
  uVar3 = OSSL_STORE_INFO_new_PKEY();
  return uVar3;
}

