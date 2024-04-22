
undefined4
Curl_hmac_md5(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5)

{
  int iVar1;
  
  iVar1 = Curl_HMAC_init(DAT_0005f910,param_1,param_2);
  if (iVar1 != 0) {
    Curl_HMAC_update(iVar1,param_3,param_4);
    Curl_HMAC_final(iVar1,param_5);
    return 0;
  }
  return 0x1b;
}

