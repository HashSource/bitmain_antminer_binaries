
ASN1_GENERALIZEDTIME * ASN1_TIME_to_generalizedtime(ASN1_TIME *t,ASN1_GENERALIZEDTIME **out)

{
  ASN1_GENERALIZEDTIME *pAVar1;
  undefined1 auStack_3c [48];
  
  pAVar1 = (ASN1_GENERALIZEDTIME *)ASN1_TIME_to_tm(t,auStack_3c);
  if (pAVar1 != (ASN1_GENERALIZEDTIME *)0x0) {
    if (out == (ASN1_GENERALIZEDTIME **)0x0) {
      pAVar1 = (ASN1_GENERALIZEDTIME *)asn1_time_from_tm(0,auStack_3c,0x18);
      return pAVar1;
    }
    pAVar1 = (ASN1_GENERALIZEDTIME *)asn1_time_from_tm(*out,auStack_3c,0x18);
    if (pAVar1 != (ASN1_GENERALIZEDTIME *)0x0) {
      *out = pAVar1;
    }
  }
  return pAVar1;
}

