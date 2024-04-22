
void X509V3_EXT_val_prn(BIO *out,stack_st_CONF_VALUE *val,int indent,int ml)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  char *pcVar5;
  
  if (val != (stack_st_CONF_VALUE *)0x0) {
    iVar2 = ml;
    if ((ml == 0) || (iVar1 = sk_num(&val->stack), iVar1 == 0)) {
      BIO_printf(out,DAT_000c6bc8,indent,DAT_000c6bcc,iVar2);
      iVar1 = sk_num(&val->stack);
      if (iVar1 == 0) {
        BIO_puts(out,DAT_000c6bdc);
      }
    }
    if (ml == 0) {
      for (; iVar2 = sk_num(&val->stack), ml < iVar2; ml = ml + 1) {
        if (0 < ml) {
          BIO_printf(out,DAT_000c6bd0);
        }
        pvVar4 = sk_value(&val->stack,ml);
        pcVar5 = *(char **)((int)pvVar4 + 4);
        if (pcVar5 == (char *)0x0) {
          BIO_puts(out,*(char **)((int)pvVar4 + 8));
        }
        else if (*(int *)((int)pvVar4 + 8) == 0) {
          BIO_puts(out,pcVar5);
        }
        else {
          BIO_printf(out,DAT_000c6bd4,pcVar5,*(int *)((int)pvVar4 + 8));
        }
      }
    }
    else {
      for (iVar1 = 0; iVar3 = sk_num(&val->stack), iVar1 < iVar3; iVar1 = iVar1 + 1) {
        BIO_printf(out,DAT_000c6bc8,indent,DAT_000c6bcc,iVar2);
        pvVar4 = sk_value(&val->stack,iVar1);
        pcVar5 = *(char **)((int)pvVar4 + 4);
        if (pcVar5 == (char *)0x0) {
          BIO_puts(out,*(char **)((int)pvVar4 + 8));
        }
        else if (*(int *)((int)pvVar4 + 8) == 0) {
          BIO_puts(out,pcVar5);
        }
        else {
          BIO_printf(out,DAT_000c6bd4,pcVar5);
        }
        BIO_puts(out,DAT_000c6bd8);
      }
    }
  }
  return;
}

