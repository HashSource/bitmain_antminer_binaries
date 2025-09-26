
ASN1_TIME * X509_time_adj_ex(ASN1_TIME *s,int offset_day,long offset_sec,time_t *t)

{
  ASN1_TIME *pAVar1;
  ASN1_GENERALIZEDTIME *pAVar2;
  ASN1_UTCTIME *pAVar3;
  time_t local_14;
  
  if (t == (time_t *)0x0) {
    time(&local_14);
  }
  else {
    local_14 = *t;
  }
  if ((s != (ASN1_TIME *)0x0) && (-1 < s->flags << 0x19)) {
    if (s->type == 0x17) {
      pAVar3 = ASN1_UTCTIME_adj(s,local_14,offset_day,offset_sec);
      return pAVar3;
    }
    if (s->type == 0x18) {
      pAVar2 = ASN1_GENERALIZEDTIME_adj(s,local_14,offset_day,offset_sec);
      return pAVar2;
    }
  }
  pAVar1 = ASN1_TIME_adj(s,local_14,offset_day,offset_sec);
  return pAVar1;
}

