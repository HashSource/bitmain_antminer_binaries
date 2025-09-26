
int ASN1_UTCTIME_check(ASN1_UTCTIME *a)

{
  int iVar1;
  
  iVar1 = asn1_utctime_to_tm(0,a);
  return iVar1;
}

