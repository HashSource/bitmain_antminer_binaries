
undefined4 EVP_PKEY_set_alias_type(EVP_PKEY *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1->type == param_2) {
    return 1;
  }
  iVar1 = EVP_PKEY_type(param_2);
  iVar2 = EVP_PKEY_base_id(param_1);
  if (iVar1 != iVar2) {
    ERR_put_error(6,0xce,0x9c,"crypto/evp/p_lib.c",0x178);
    return 0;
  }
  param_1->type = param_2;
  return 1;
}

