
int SSL_set_wfd(SSL *s,int fd)

{
  BIO *pBVar1;
  int iVar2;
  BIO_METHOD *type;
  long lVar3;
  
  pBVar1 = SSL_get_rbio(s);
  if (((pBVar1 == (BIO *)0x0) || (iVar2 = BIO_method_type(pBVar1), iVar2 != 0x505)) ||
     (lVar3 = BIO_ctrl(pBVar1,0x69,0,(void *)0x0), lVar3 != fd)) {
    type = BIO_s_socket();
    pBVar1 = BIO_new(type);
    if (pBVar1 == (BIO *)0x0) {
      ERR_put_error(0x14,0xc4,7,"ssl/ssl_lib.c",0x562);
      return 0;
    }
    BIO_int_ctrl(pBVar1,0x68,0,fd);
    SSL_set0_wbio(s,pBVar1);
  }
  else {
    BIO_up_ref(pBVar1);
    SSL_set0_wbio(s,pBVar1);
  }
  return 1;
}

