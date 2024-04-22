
void pubkey_show(undefined4 param_1,BIO *param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,BIGNUM *param_6)

{
  long lVar1;
  undefined4 local_3c;
  undefined auStack_38 [36];
  
  curl_msnprintf(auStack_38,0x20,"%s(%s)",param_4,param_5);
  BN_print(param_2,param_6);
  lVar1 = BIO_ctrl(param_2,3,0,&local_3c);
  Curl_ssl_push_certinfo_len(param_1,param_3,auStack_38,local_3c,lVar1);
  BIO_ctrl(param_2,1,0,(void *)0x0);
  return;
}

