
undefined4 __aeabi_uldivmod(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  UDItype UVar2;
  UDItype local_8;
  
  if ((param_4 == 0) && (param_3 == 0)) {
    if (param_2 != 0 || param_1 != 0) {
      param_2 = -1;
      param_1 = -1;
    }
    uVar1 = __aeabi_ldiv0(param_1,param_2);
    return uVar1;
  }
  UVar2 = __udivmoddi4(CONCAT44(param_2,param_1),CONCAT44(param_4,param_3),&local_8);
  return (int)UVar2;
}

