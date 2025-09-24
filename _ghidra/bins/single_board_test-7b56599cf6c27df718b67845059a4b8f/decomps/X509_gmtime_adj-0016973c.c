
ASN1_TIME * X509_gmtime_adj(ASN1_TIME *s,long adj)

{
  ASN1_TIME *pAVar1;
  
  pAVar1 = X509_time_adj(s,adj,(time_t *)0x0);
  return pAVar1;
}

