
int i2d_SCT_LIST(undefined4 param_1,uchar **param_2)

{
  int iVar1;
  ASN1_OCTET_STRING local_18;
  
  local_18.data = (uchar *)0x0;
  iVar1 = i2o_SCT_LIST(param_1,&local_18.data);
  if (iVar1 != -1) {
    local_18.length = iVar1;
    iVar1 = i2d_ASN1_OCTET_STRING(&local_18,param_2);
    CRYPTO_free(local_18.data);
  }
  return iVar1;
}

