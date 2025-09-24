
int dtls1_read_failed(SSL *param_1,int param_2)

{
  int iVar1;
  BIO *b;
  
  if (0 < param_2) {
    ossl_statem_fatal(param_1,0x50,0x153,0x44,"ssl/statem/statem_dtls.c",0x3cc);
    return 0;
  }
  iVar1 = dtls1_is_timer_expired();
  if ((iVar1 != 0) && (iVar1 = ossl_statem_in_error(param_1), iVar1 == 0)) {
    iVar1 = SSL_in_init(param_1);
    if (iVar1 != 0) {
      iVar1 = dtls1_handle_timeout(param_1);
      return iVar1;
    }
    b = SSL_get_rbio(param_1);
    BIO_set_flags(b,1);
  }
  return param_2;
}

