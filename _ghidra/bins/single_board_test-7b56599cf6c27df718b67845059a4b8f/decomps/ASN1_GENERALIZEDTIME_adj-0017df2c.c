
ASN1_GENERALIZEDTIME *
ASN1_GENERALIZEDTIME_adj(ASN1_GENERALIZEDTIME *s,time_t t,int offset_day,long offset_sec)

{
  int iVar1;
  ASN1_GENERALIZEDTIME *pAVar2;
  int iVar3;
  time_t local_4c [2];
  undefined1 auStack_44 [48];
  
  local_4c[0] = t;
  iVar1 = OPENSSL_gmtime(local_4c,auStack_44);
  if ((iVar1 == 0) ||
     ((offset_sec != 0 || offset_day != 0 &&
      (iVar3 = OPENSSL_gmtime_adj(iVar1,offset_day,offset_sec), iVar3 == 0)))) {
    pAVar2 = (ASN1_GENERALIZEDTIME *)0x0;
  }
  else {
    pAVar2 = (ASN1_GENERALIZEDTIME *)asn1_time_from_tm(s,iVar1,0x18);
  }
  return pAVar2;
}

