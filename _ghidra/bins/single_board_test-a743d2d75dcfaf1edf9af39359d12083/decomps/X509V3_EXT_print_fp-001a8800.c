
int X509V3_EXT_print_fp(FILE *out,X509_EXTENSION *ext,int flag,int indent)

{
  BIO *out_00;
  int iVar1;
  
  out_00 = BIO_new_fp(out,0);
  if (out_00 != (BIO *)0x0) {
    iVar1 = X509V3_EXT_print(out_00,ext,flag,indent);
    BIO_free(out_00);
    return iVar1;
  }
  return 0;
}

