
int X509V3_extensions_print
              (BIO *out,char *title,stack_st_X509_EXTENSION *exts,ulong flag,int indent)

{
  int iVar1;
  int iVar2;
  X509_EXTENSION *ex;
  ASN1_OBJECT *a;
  char *pcVar3;
  int iVar4;
  
  iVar1 = sk_num(&exts->stack);
  if (iVar1 < 1) {
LAB_001ab322:
    iVar1 = 1;
  }
  else {
    iVar1 = indent;
    if (title != (char *)0x0) {
      iVar1 = indent + 4;
      BIO_printf(out,"%*s%s:\n",indent,"",title);
    }
    iVar4 = 0;
    do {
      iVar2 = sk_num(&exts->stack);
      if (iVar2 <= iVar4) goto LAB_001ab322;
      ex = (X509_EXTENSION *)sk_value(&exts->stack,iVar4);
      if ((iVar1 != 0) && (iVar2 = BIO_printf(out,"%*s",iVar1,""), iVar2 < 1)) break;
      a = X509_EXTENSION_get_object(ex);
      i2a_ASN1_OBJECT(out,a);
      iVar2 = X509_EXTENSION_get_critical(ex);
      if (iVar2 == 0) {
        pcVar3 = "";
      }
      else {
        pcVar3 = "critical";
      }
      iVar2 = BIO_printf(out,": %s\n",pcVar3);
      if (iVar2 < 1) break;
      iVar2 = X509V3_EXT_print(out,ex,flag,iVar1 + 4);
      if (iVar2 == 0) {
        BIO_printf(out,"%*s",iVar1 + 4,"");
        ASN1_STRING_print(out,ex->value);
      }
      iVar2 = BIO_write(out,"\n",1);
      iVar4 = iVar4 + 1;
    } while (0 < iVar2);
    iVar1 = 0;
  }
  return iVar1;
}

