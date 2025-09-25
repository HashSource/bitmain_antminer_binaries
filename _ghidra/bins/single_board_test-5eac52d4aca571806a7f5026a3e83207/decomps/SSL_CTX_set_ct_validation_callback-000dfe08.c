
undefined4 SSL_CTX_set_ct_validation_callback(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((param_2 != 0) && (iVar1 = SSL_CTX_has_client_custom_ext(param_1,0x12), iVar1 != 0)) {
    ERR_put_error(0x14,0x18c,0xce,"ssl/ssl_lib.c",0x135c);
    return 0;
  }
  *(int *)(param_1 + 0x10c) = param_2;
  *(undefined4 *)(param_1 + 0x110) = param_3;
  return 1;
}

