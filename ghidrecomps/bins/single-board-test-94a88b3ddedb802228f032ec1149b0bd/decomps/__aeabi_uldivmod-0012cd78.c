
undefined4 __aeabi_uldivmod(UDItype *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 in_lr;
  UDItype UVar2;
  UDItype in_stack_fffffff8;
  
  if ((param_4 == 0) && (param_3 == 0)) {
    if (param_2 != 0 || param_1 != (UDItype *)0x0) {
      param_2 = -1;
      param_1 = (UDItype *)0xffffffff;
    }
    uVar1 = __aeabi_ldiv0(param_1,param_2);
    return uVar1;
  }
  UVar2 = __udivmoddi4(CONCAT44(in_lr,&stack0xfffffff8),in_stack_fffffff8,param_1);
  return (int)UVar2;
}

