
undefined4 trust_compat(undefined4 param_1,X509 *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = X509_check_purpose(param_2,-1,0);
  if ((iVar1 == 1) && (-1 < param_3 << 0x1d)) {
    uVar2 = 1;
    if ((param_2[1].references & 0x2000U) == 0) {
      uVar2 = 3;
    }
    return uVar2;
  }
  return 3;
}

