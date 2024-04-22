
ASN1_TIME * ASN1_TIME_set(ASN1_TIME *s,time_t t)

{
  int iVar1;
  ASN1_TIME *pAVar2;
  time_t local_40;
  undefined auStack_3c [48];
  
  local_40 = t;
  iVar1 = OPENSSL_gmtime(&local_40,auStack_3c);
  if (iVar1 == 0) {
    ERR_put_error(0xd,0xd9,0xad,DAT_00105d10,0x73);
    pAVar2 = (ASN1_TIME *)0x0;
  }
  else if (*(int *)(iVar1 + 0x14) - 0x32U < 100) {
    pAVar2 = ASN1_UTCTIME_adj(s,local_40,0,0);
  }
  else {
    pAVar2 = ASN1_GENERALIZEDTIME_adj(s,local_40,0,0);
  }
  return pAVar2;
}

