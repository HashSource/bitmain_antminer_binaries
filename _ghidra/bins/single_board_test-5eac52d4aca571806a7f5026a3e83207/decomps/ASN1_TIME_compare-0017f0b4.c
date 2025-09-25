
undefined4 ASN1_TIME_compare(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_10;
  int local_c [2];
  
  iVar1 = ASN1_TIME_diff(&local_10,local_c,param_2,param_1);
  if (iVar1 == 0) {
    uVar2 = 0xfffffffe;
  }
  else {
    if ((local_10 < 1) && (local_c[0] < 1)) {
      if (local_10 == 0 && local_c[0] == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 0xffffffff;
      }
      return uVar2;
    }
    uVar2 = 1;
  }
  return uVar2;
}

