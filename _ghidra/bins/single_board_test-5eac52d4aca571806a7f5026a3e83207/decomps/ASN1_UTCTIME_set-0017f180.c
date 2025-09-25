
ASN1_UTCTIME * ASN1_UTCTIME_set(ASN1_UTCTIME *s,time_t t)

{
  ASN1_UTCTIME *pAVar1;
  
  pAVar1 = ASN1_UTCTIME_adj(s,t,0,0);
  return pAVar1;
}

