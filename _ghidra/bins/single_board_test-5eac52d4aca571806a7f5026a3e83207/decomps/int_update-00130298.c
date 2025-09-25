
int int_update(undefined4 param_1,uchar *param_2,size_t param_3)

{
  int iVar1;
  
  iVar1 = EVP_MD_CTX_pkey_ctx();
  iVar1 = HMAC_Update(*(HMAC_CTX **)(*(int *)(iVar1 + 0x14) + 0x14),param_2,param_3);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

