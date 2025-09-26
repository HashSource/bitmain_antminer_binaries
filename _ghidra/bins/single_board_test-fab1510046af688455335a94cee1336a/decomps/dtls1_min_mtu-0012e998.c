
int dtls1_min_mtu(SSL *param_1)

{
  BIO *bp;
  long lVar1;
  
  bp = SSL_get_wbio(param_1);
  lVar1 = BIO_ctrl(bp,0x31,0,(void *)0x0);
  return 0x100 - lVar1;
}

