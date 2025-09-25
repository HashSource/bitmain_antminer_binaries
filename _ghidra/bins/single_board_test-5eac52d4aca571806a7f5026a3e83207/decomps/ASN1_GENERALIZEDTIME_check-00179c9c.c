
int ASN1_GENERALIZEDTIME_check(ASN1_GENERALIZEDTIME *a)

{
  int iVar1;
  
  iVar1 = asn1_generalizedtime_to_tm(0,a);
  return iVar1;
}

