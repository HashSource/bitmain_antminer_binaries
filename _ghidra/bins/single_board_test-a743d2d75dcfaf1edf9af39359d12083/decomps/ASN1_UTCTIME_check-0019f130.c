
int ASN1_UTCTIME_check(ASN1_UTCTIME *a)

{
  int iVar1;
  
  if (a->type != 0x17) {
    return 0;
  }
  iVar1 = asn1_utctime_to_tm_part_0(0,a);
  return iVar1;
}

