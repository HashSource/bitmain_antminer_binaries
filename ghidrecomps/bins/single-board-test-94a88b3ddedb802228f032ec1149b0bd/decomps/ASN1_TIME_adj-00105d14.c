
ASN1_TIME * ASN1_TIME_adj(ASN1_TIME *s,time_t t,int offset_day,long offset_sec)

{
  int iVar1;
  ASN1_TIME *pAVar2;
  int iVar3;
  time_t local_4c [2];
  undefined auStack_44 [48];
  
  local_4c[0] = t;
  iVar1 = OPENSSL_gmtime(local_4c,auStack_44);
  if (iVar1 == 0) {
    ERR_put_error(0xd,0xd9,0xad,DAT_00105d80,0x73);
    pAVar2 = (ASN1_TIME *)0x0;
  }
  else if ((offset_day == 0 && offset_sec == 0) ||
          (iVar3 = OPENSSL_gmtime_adj(iVar1,offset_day,offset_sec), iVar3 != 0)) {
    if (*(int *)(iVar1 + 0x14) - 0x32U < 100) {
      pAVar2 = ASN1_UTCTIME_adj(s,local_4c[0],offset_day,offset_sec);
    }
    else {
      pAVar2 = ASN1_GENERALIZEDTIME_adj(s,local_4c[0],offset_day,offset_sec);
    }
  }
  else {
    pAVar2 = (ASN1_TIME *)0x0;
  }
  return pAVar2;
}

