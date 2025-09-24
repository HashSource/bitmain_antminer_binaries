
int ASN1_UTCTIME_print(BIO *fp,ASN1_UTCTIME *a)

{
  int iVar1;
  
  if (a->type != 0x17) {
    return 0;
  }
  iVar1 = ASN1_TIME_print(fp,a);
  return iVar1;
}

