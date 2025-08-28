
UDItype __fixunsdfdi(DFtype a)

{
  undefined4 in_r0;
  undefined4 in_r1;
  USItype hi;
  uint uVar1;
  double dVar2;
  
  dVar2 = (double)CONCAT44(in_r1,in_r0) * 2.3283064365386963e-10;
  uVar1 = (uint)(0.0 < dVar2) * (int)(longlong)dVar2;
  dVar2 = (double)CONCAT44(in_r1,in_r0) - (double)uVar1 * 4294967296.0;
  return CONCAT44(uVar1,(uint)(0.0 < dVar2) * (int)(longlong)dVar2);
}

