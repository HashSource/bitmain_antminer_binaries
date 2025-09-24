
void X509V3_EXT_val_prn(BIO *out,stack_st_CONF_VALUE *val,int indent,int ml)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  if (val == (stack_st_CONF_VALUE *)0x0) {
    return;
  }
  iVar3 = ml;
  if ((ml == 0) || (iVar1 = OPENSSL_sk_num(val), iVar1 == 0)) {
    BIO_printf(out,"%*s",indent,"",iVar3);
    iVar1 = OPENSSL_sk_num(val);
    if (iVar1 == 0) {
      BIO_puts(out,"<EMPTY>\n");
    }
    if (ml == 0) {
      for (iVar3 = 0; iVar1 = OPENSSL_sk_num(val), iVar3 < iVar1; iVar3 = iVar3 + 1) {
        if (0 < iVar3) {
          BIO_printf(out,", ");
        }
        iVar1 = OPENSSL_sk_value(val,iVar3);
        pcVar4 = *(char **)(iVar1 + 4);
        if (pcVar4 == (char *)0x0) {
          BIO_puts(out,*(char **)(iVar1 + 8));
        }
        else if (*(int *)(iVar1 + 8) == 0) {
          BIO_puts(out,pcVar4);
        }
        else {
          BIO_printf(out,"%s:%s",pcVar4,*(int *)(iVar1 + 8));
        }
      }
      return;
    }
  }
  for (iVar1 = 0; iVar2 = OPENSSL_sk_num(val), iVar1 < iVar2; iVar1 = iVar1 + 1) {
    BIO_printf(out,"%*s",indent,"",iVar3);
    iVar2 = OPENSSL_sk_value(val,iVar1);
    pcVar4 = *(char **)(iVar2 + 4);
    if (pcVar4 == (char *)0x0) {
      BIO_puts(out,*(char **)(iVar2 + 8));
    }
    else if (*(int *)(iVar2 + 8) == 0) {
      BIO_puts(out,pcVar4);
    }
    else {
      BIO_printf(out,"%s:%s",pcVar4,*(int *)(iVar2 + 8));
    }
    BIO_puts(out,"\n");
  }
  return;
}

