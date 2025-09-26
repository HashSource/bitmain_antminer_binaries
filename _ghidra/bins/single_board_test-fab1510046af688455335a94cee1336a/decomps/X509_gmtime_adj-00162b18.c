
ASN1_TIME * X509_gmtime_adj(ASN1_TIME *s,long adj)

{
  ASN1_TIME *pAVar1;
  ASN1_GENERALIZEDTIME *pAVar2;
  ASN1_UTCTIME *pAVar3;
  time_t local_14 [2];
  
  time(local_14);
  if ((s != (ASN1_TIME *)0x0) && ((s->flags & 0x40U) == 0)) {
    if (s->type == 0x17) {
      pAVar3 = ASN1_UTCTIME_adj(s,local_14[0],0,adj);
      return pAVar3;
    }
    if (s->type == 0x18) {
      pAVar2 = ASN1_GENERALIZEDTIME_adj(s,local_14[0],0,adj);
      return pAVar2;
    }
  }
  pAVar1 = ASN1_TIME_adj(s,local_14[0],0,adj);
  return pAVar1;
}

