
ASN1_TIME * ASN1_TIME_set(ASN1_TIME *s,time_t t)

{
  ASN1_TIME *pAVar1;
  
  pAVar1 = ASN1_TIME_adj(s,t,0,0);
  return pAVar1;
}

