
undefined4 ASN1_TIME_cmp_time_t(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_74;
  int local_70;
  int local_6c;
  undefined1 auStack_68 [44];
  undefined1 auStack_3c [48];
  
  local_74 = param_2;
  iVar1 = ASN1_TIME_to_tm(param_1,auStack_68);
  if (iVar1 != 0) {
    iVar1 = OPENSSL_gmtime(&local_74,auStack_3c);
    if ((iVar1 != 0) &&
       (iVar1 = OPENSSL_gmtime_diff(&local_70,&local_6c,auStack_3c,auStack_68), iVar1 != 0)) {
      if ((local_70 < 1) && (local_6c < 1)) {
        if (local_70 == 0 && local_6c == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = 0xffffffff;
        }
        return uVar2;
      }
      return 1;
    }
  }
  return 0xfffffffe;
}

