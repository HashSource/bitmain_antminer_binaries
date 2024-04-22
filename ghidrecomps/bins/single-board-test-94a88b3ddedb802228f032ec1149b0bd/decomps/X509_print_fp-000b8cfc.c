
int X509_print_fp(FILE *bp,X509 *x)

{
  BIO_METHOD *type;
  BIO *bp_00;
  int iVar1;
  
  type = BIO_s_file();
  bp_00 = BIO_new(type);
  if (bp_00 == (BIO *)0x0) {
    ERR_put_error(0xb,0x76,7,DAT_000b8d48,0x5a);
    iVar1 = 0;
  }
  else {
    BIO_ctrl(bp_00,0x6a,0,bp);
    iVar1 = X509_print_ex(bp_00,x,0,0);
    BIO_free(bp_00);
  }
  return iVar1;
}

