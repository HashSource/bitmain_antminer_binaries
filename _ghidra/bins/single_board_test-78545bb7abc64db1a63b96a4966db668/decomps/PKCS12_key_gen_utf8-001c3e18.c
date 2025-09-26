
int PKCS12_key_gen_utf8(int param_1,undefined4 param_2,uchar *param_3,int param_4,int param_5,
                       int param_6,int param_7,uchar *param_8,EVP_MD *param_9)

{
  int iVar1;
  uchar *local_18;
  int local_14;
  
  if (param_1 == 0) {
    local_18 = (uchar *)0x0;
    local_14 = 0;
  }
  else {
    iVar1 = OPENSSL_utf82uni(param_1,param_2,&local_18,&local_14);
    if (iVar1 == 0) {
      ERR_put_error(0x23,0x74,0x41,"crypto/pkcs12/p12_key.c",0x41);
      return 0;
    }
  }
  iVar1 = PKCS12_key_gen_uni(local_18,local_14,param_3,param_4,param_5,param_6,param_7,param_8,
                             param_9);
  if (iVar1 < 1) {
    iVar1 = 0;
  }
  else {
    CRYPTO_clear_free(local_18,local_14,"crypto/pkcs12/p12_key.c",0x48);
  }
  return iVar1;
}

