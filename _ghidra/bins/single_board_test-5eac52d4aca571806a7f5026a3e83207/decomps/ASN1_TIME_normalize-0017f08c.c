
int ASN1_TIME_normalize(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_3c [48];
  
  iVar1 = ASN1_TIME_to_tm(param_1,auStack_3c);
  if ((iVar1 != 0) && (iVar1 = asn1_time_from_tm(param_1,auStack_3c,0xffffffff), iVar1 != 0)) {
    iVar1 = 1;
  }
  return iVar1;
}

