
int X509V3_extensions_print
              (BIO *out,char *title,stack_st_X509_EXTENSION *exts,ulong flag,int indent)

{
  int iVar1;
  int iVar2;
  X509_EXTENSION *ex;
  ASN1_OBJECT *a;
  ASN1_OCTET_STRING *v;
  char *pcVar3;
  int iVar4;
  char *local_2c;
  
  iVar1 = OPENSSL_sk_num(exts);
  if (0 < iVar1) {
    iVar1 = indent;
    if (title != (char *)0x0) {
      iVar1 = indent + 4;
      BIO_printf(out,"%*s%s:\n",indent,"",title);
    }
    local_2c = "critical";
    for (iVar4 = 0; iVar2 = OPENSSL_sk_num(exts), iVar4 < iVar2; iVar4 = iVar4 + 1) {
      ex = (X509_EXTENSION *)OPENSSL_sk_value(exts,iVar4);
      if ((iVar1 != 0) && (iVar2 = BIO_printf(out,"%*s",iVar1,""), iVar2 < 1)) {
        return 0;
      }
      a = X509_EXTENSION_get_object(ex);
      i2a_ASN1_OBJECT(out,a);
      iVar2 = X509_EXTENSION_get_critical(ex);
      pcVar3 = local_2c;
      if (iVar2 == 0) {
        pcVar3 = "";
      }
      iVar2 = BIO_printf(out,": %s\n",pcVar3);
      if (iVar2 < 1) {
        return 0;
      }
      iVar2 = X509V3_EXT_print(out,ex,flag,iVar1 + 4);
      if (iVar2 == 0) {
        BIO_printf(out,"%*s",iVar1 + 4,"");
        v = X509_EXTENSION_get_data(ex);
        ASN1_STRING_print(out,v);
      }
      iVar2 = BIO_write(out,"\n",1);
      if (iVar2 < 1) {
        return 0;
      }
    }
  }
  return 1;
}

