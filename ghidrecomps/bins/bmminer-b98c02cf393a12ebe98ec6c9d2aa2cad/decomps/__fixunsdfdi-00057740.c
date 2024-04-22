
UDItype __fixunsdfdi(DFtype a)

{
  undefined4 in_r0;
  undefined4 in_r1;
  USItype hi;
  uint uVar1;
  double dVar2;
  
  dVar2 = (double)CONCAT44(in_r1,in_r0) * DAT_00057778;
  uVar1 = (uint)(0.0 < dVar2) * (int)(longlong)dVar2;
  dVar2 = (double)CONCAT44(in_r1,in_r0) - (double)(ulonglong)uVar1 * DAT_00057780;
  return CONCAT44(uVar1,(uint)(0.0 < dVar2) * (int)(longlong)dVar2);
}

