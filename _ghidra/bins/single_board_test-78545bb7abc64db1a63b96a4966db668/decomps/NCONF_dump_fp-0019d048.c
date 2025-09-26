
int NCONF_dump_fp(CONF *conf,FILE *out)

{
  BIO *out_00;
  int iVar1;
  
  out_00 = BIO_new_fp(out,0);
  if (out_00 != (BIO *)0x0) {
    iVar1 = NCONF_dump_bio(conf,out_00);
    BIO_free(out_00);
    return iVar1;
  }
  ERR_put_error(0xe,0x6a,7,"crypto/conf/conf_lib.c",0x14c);
  return 0;
}

