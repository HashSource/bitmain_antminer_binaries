
undefined4 SSL_dane_enable(SSL *param_1,void *param_2)

{
  undefined4 uVar1;
  int iVar2;
  cert_st *pcVar3;
  long lVar4;
  SSL_METHOD *pSVar5;
  
  if (*(char *)&param_1[3].method[4].ssl_write_bytes == '\0') {
    ERR_put_error(0x14,0x18b,0xa7,"ssl/ssl_lib.c",0x3f5);
    return 0;
  }
  if (param_1->cert == (cert_st *)0x0) {
    if ((param_1[3].param == (X509_VERIFY_PARAM *)0x0) &&
       (lVar4 = SSL_ctrl(param_1,0x37,0,param_2), lVar4 == 0)) {
      iVar2 = 0x404;
    }
    else {
      iVar2 = X509_VERIFY_PARAM_set1_host(param_1->write_hash,param_2,0);
      if (iVar2 != 0) {
        pSVar5 = param_1[3].method;
        param_1->sid_ctx[0xc] = 0xff;
        param_1->sid_ctx[0xd] = 0xff;
        param_1->sid_ctx[0xe] = 0xff;
        param_1->sid_ctx[0xf] = 0xff;
        param_1->sid_ctx[0x10] = 0xff;
        param_1->sid_ctx[0x11] = 0xff;
        param_1->sid_ctx[0x12] = 0xff;
        param_1->sid_ctx[0x13] = 0xff;
        param_1->compress = (COMP_CTX *)&pSVar5[4].ssl_get_message;
        pcVar3 = (cert_st *)OPENSSL_sk_new_null();
        param_1->cert = pcVar3;
        if (pcVar3 == (cert_st *)0x0) {
          ERR_put_error(0x14,0x18b,0x41,"ssl/ssl_lib.c",0x415);
          return 0xffffffff;
        }
        return 1;
      }
      iVar2 = 0x40b;
    }
    ERR_put_error(0x14,0x18b,0xcc,"ssl/ssl_lib.c",iVar2);
    uVar1 = 0xffffffff;
  }
  else {
    ERR_put_error(0x14,0x18b,0xac,"ssl/ssl_lib.c",0x3f9);
    uVar1 = 0;
  }
  return uVar1;
}

