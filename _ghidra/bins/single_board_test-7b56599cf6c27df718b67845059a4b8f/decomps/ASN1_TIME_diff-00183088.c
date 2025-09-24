
undefined4
ASN1_TIME_diff(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_70 [44];
  undefined1 auStack_44 [44];
  
  iVar1 = ASN1_TIME_to_tm(param_3,auStack_70);
  if (iVar1 != 0) {
    iVar1 = ASN1_TIME_to_tm(param_4,auStack_44);
    if (iVar1 != 0) {
      uVar2 = OPENSSL_gmtime_diff(param_1,param_2,auStack_70,auStack_44);
      return uVar2;
    }
  }
  return 0;
}

