
undefined8 __fixunsdfdi(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  double dVar2;
  
  dVar2 = (double)CONCAT44(param_2,param_1) * DAT_00043a18;
  uVar1 = (uint)(0.0 < dVar2) * (int)(longlong)dVar2;
  dVar2 = (double)CONCAT44(param_2,param_1) - (double)(ulonglong)uVar1 * DAT_00043a20;
  return CONCAT44(uVar1,(uint)(0.0 < dVar2) * (int)(longlong)dVar2);
}

