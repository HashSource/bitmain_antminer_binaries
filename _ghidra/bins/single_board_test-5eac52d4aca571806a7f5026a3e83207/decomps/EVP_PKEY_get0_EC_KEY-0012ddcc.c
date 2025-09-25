
int EVP_PKEY_get0_EC_KEY(EVP_PKEY *param_1)

{
  int iVar1;
  
  iVar1 = EVP_PKEY_base_id(param_1);
  if (iVar1 != 0x198) {
    ERR_put_error(6,0x83,0x8e,"crypto/evp/p_lib.c",0x211);
    return 0;
  }
  return param_1->save_parameters;
}

