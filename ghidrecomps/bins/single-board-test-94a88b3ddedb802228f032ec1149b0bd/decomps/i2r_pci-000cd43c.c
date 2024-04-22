
undefined4 i2r_pci(undefined4 param_1,ASN1_INTEGER **param_2,BIO *param_3,undefined4 param_4)

{
  int iVar1;
  
  BIO_printf(param_3,DAT_000cd4ac,param_4,DAT_000cd4b0);
  if (*param_2 == (ASN1_INTEGER *)0x0) {
    BIO_printf(param_3,DAT_000cd4c0);
  }
  else {
    i2a_ASN1_INTEGER(param_3,*param_2);
  }
  BIO_puts(param_3,DAT_000cd4b4);
  BIO_printf(param_3,DAT_000cd4b8,param_4,DAT_000cd4b0);
  i2a_ASN1_OBJECT(param_3,(ASN1_OBJECT *)param_2[1]->length);
  BIO_puts(param_3,DAT_000cd4b4);
  if ((param_2[1]->type != 0) && (iVar1 = *(int *)(param_2[1]->type + 8), iVar1 != 0)) {
    BIO_printf(param_3,DAT_000cd4bc,param_4,DAT_000cd4b0,iVar1);
  }
  return 1;
}

