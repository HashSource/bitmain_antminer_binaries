
ASN1_TIME * X509_time_adj(ASN1_TIME *s,long adj,time_t *t)

{
  ASN1_TIME *pAVar1;
  
  pAVar1 = X509_time_adj_ex(s,0,adj,t);
  return pAVar1;
}

