
int __aeabi_ldivmod(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  UDItype UVar2;
  UDItype local_8;
  
  if ((param_4 == 0) && (param_3 == 0)) {
    if (param_2 < 0) {
      param_1 = 0;
      param_2 = -0x80000000;
    }
    else if (param_2 != 0 || param_1 != 0) {
      param_2 = 0x7fffffff;
      param_1 = -1;
    }
    iVar1 = __aeabi_ldiv0(param_1,param_2);
    return iVar1;
  }
  if (param_2 < 0) {
    iVar1 = -param_2 - (uint)(param_1 != 0);
    if (param_4 < 0) {
      UVar2 = __udivmoddi4(CONCAT44(iVar1,-param_1),
                           CONCAT44(-param_4 - (uint)(param_3 != 0),-param_3),&local_8);
      return (int)UVar2;
    }
    UVar2 = __udivmoddi4(CONCAT44(iVar1,-param_1),CONCAT44(param_4,param_3),&local_8);
    return -(int)UVar2;
  }
  if (param_4 < 0) {
    UVar2 = __udivmoddi4(CONCAT44(param_2,param_1),
                         CONCAT44(-param_4 - (uint)(param_3 != 0),-param_3),&local_8);
    return -(int)UVar2;
  }
  UVar2 = __udivmoddi4(CONCAT44(param_2,param_1),CONCAT44(param_4,param_3),&local_8);
  return (int)UVar2;
}

