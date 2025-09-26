
int ASN1_GENERALIZEDTIME_print(BIO *fp,ASN1_GENERALIZEDTIME *a)

{
  int iVar1;
  
  if (a->type != 0x18) {
    return 0;
  }
  iVar1 = ASN1_TIME_print(fp,a);
  return iVar1;
}

