
int ASN1_TIME_check(ASN1_TIME *t)

{
  int iVar1;
  
  if (t->type == 0x18) {
    iVar1 = ASN1_GENERALIZEDTIME_check(t);
    return iVar1;
  }
  if (t->type != 0x17) {
    return 0;
  }
  iVar1 = ASN1_UTCTIME_check(t);
  return iVar1;
}

