
undefined4 SSL_enable_ct(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = SSL_set_ct_validation_callback(param_1,0xe92b1,0);
    return uVar1;
  }
  if (param_2 == 1) {
    uVar1 = SSL_set_ct_validation_callback(param_1,0xe9375,0);
    return uVar1;
  }
  ERR_put_error(0x14,0x192,0xd4,"ssl/ssl_lib.c",0x13e6);
  return 0;
}

