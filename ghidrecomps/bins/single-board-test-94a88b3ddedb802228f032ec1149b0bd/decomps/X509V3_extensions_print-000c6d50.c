
int X509V3_extensions_print
              (BIO *out,char *title,stack_st_X509_EXTENSION *exts,ulong flag,int indent)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  X509_EXTENSION *ex;
  ASN1_OBJECT *a;
  int iVar4;
  
  iVar2 = sk_num(&exts->stack);
  if (iVar2 < 1) {
LAB_000c6e1a:
    iVar2 = 1;
  }
  else {
    iVar2 = indent;
    if (title != (char *)0x0) {
      iVar2 = indent + 4;
      BIO_printf(out,DAT_000c6e20,indent,DAT_000c6e24,title);
    }
    iVar4 = 0;
    do {
      uVar1 = DAT_000c6e24;
      iVar3 = sk_num(&exts->stack);
      if (iVar3 <= iVar4) goto LAB_000c6e1a;
      ex = (X509_EXTENSION *)sk_value(&exts->stack,iVar4);
      if ((iVar2 != 0) && (iVar3 = BIO_printf(out,DAT_000c6e2c,iVar2,DAT_000c6e24), iVar3 < 1))
      break;
      a = X509_EXTENSION_get_object(ex);
      i2a_ASN1_OBJECT(out,a);
      X509_EXTENSION_get_critical(ex);
      iVar3 = BIO_printf(out,DAT_000c6e30);
      if (iVar3 < 1) break;
      iVar3 = X509V3_EXT_print(out,ex,flag,iVar2 + 4);
      if (iVar3 == 0) {
        BIO_printf(out,DAT_000c6e2c,iVar2 + 4,uVar1);
        ASN1_STRING_print(out,ex->value);
      }
      iVar3 = BIO_write(out,DAT_000c6e28,1);
      iVar4 = iVar4 + 1;
    } while (0 < iVar3);
    iVar2 = 0;
  }
  return iVar2;
}

