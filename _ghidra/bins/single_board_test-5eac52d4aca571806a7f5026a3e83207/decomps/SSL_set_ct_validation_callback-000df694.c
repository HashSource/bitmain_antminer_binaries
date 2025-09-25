
undefined4 SSL_set_ct_validation_callback(SSL *param_1,ulong param_2,long param_3)

{
  int iVar1;
  long lVar2;
  
  if (param_2 != 0) {
    iVar1 = SSL_CTX_has_client_custom_ext(param_1[3].method,0x12);
    if (iVar1 != 0) {
      ERR_put_error(0x14,399,0xce,"ssl/ssl_lib.c",0x133f);
      return 0;
    }
    lVar2 = SSL_ctrl(param_1,0x41,1,(void *)0x0);
    if (lVar2 == 0) {
      return 0;
    }
  }
  param_1[3].mode = param_2;
  param_1[3].max_cert_list = param_3;
  return 1;
}

