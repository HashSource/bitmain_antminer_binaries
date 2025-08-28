
int ASN1_TIME_print(BIO *fp,ASN1_TIME *a)

{
  int iVar1;
  
  if (a->type == 0x17) {
    iVar1 = ASN1_UTCTIME_print(fp,a);
    return iVar1;
  }
  if (a->type != 0x18) {
    BIO_write(fp,"Bad time value",0xe);
    return 0;
  }
  iVar1 = ASN1_GENERALIZEDTIME_print(fp,a);
  return iVar1;
}

