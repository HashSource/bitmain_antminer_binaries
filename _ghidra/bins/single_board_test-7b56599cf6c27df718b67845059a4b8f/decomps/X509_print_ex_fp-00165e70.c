
int X509_print_ex_fp(FILE *bp,X509 *x,ulong nmflag,ulong cflag)

{
  BIO_METHOD *type;
  BIO *bp_00;
  int iVar1;
  
  type = BIO_s_file();
  bp_00 = BIO_new(type);
  if (bp_00 != (BIO *)0x0) {
    BIO_ctrl(bp_00,0x6a,0,bp);
    iVar1 = X509_print_ex(bp_00,x,nmflag,cflag);
    BIO_free(bp_00);
    return iVar1;
  }
  ERR_put_error(0xb,0x76,7,"crypto/x509/t_x509.c",0x20);
  return 0;
}

