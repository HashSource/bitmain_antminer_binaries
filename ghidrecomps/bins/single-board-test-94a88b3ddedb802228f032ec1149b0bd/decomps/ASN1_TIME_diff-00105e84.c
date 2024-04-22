
undefined4 ASN1_TIME_diff(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  time_t tStack_74;
  undefined auStack_70 [44];
  undefined auStack_44 [44];
  
  if (param_3 == 0) {
    time(&tStack_74);
    iVar1 = OPENSSL_gmtime(&tStack_74,auStack_70);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  else if (*(int *)(param_3 + 4) == 0x17) {
    iVar1 = asn1_utctime_to_tm(auStack_70,param_3);
  }
  else {
    if (*(int *)(param_3 + 4) != 0x18) {
      return 0;
    }
    iVar1 = asn1_generalizedtime_to_tm(auStack_70,param_3);
  }
  if (iVar1 != 0) {
    if (param_4 == 0) {
      time(&tStack_74);
      iVar1 = OPENSSL_gmtime(&tStack_74,auStack_44);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
    }
    else if (*(int *)(param_4 + 4) == 0x17) {
      iVar1 = asn1_utctime_to_tm(auStack_44,param_4);
    }
    else {
      if (*(int *)(param_4 + 4) != 0x18) {
        return 0;
      }
      iVar1 = asn1_generalizedtime_to_tm(auStack_44,param_4);
    }
    if (iVar1 != 0) {
      uVar2 = OPENSSL_gmtime_diff(param_1,param_2,auStack_70,auStack_44);
      return uVar2;
    }
  }
  return 0;
}

