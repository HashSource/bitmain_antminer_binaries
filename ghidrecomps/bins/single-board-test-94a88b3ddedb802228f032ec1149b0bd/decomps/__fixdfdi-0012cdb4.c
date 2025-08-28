
DItype __fixdfdi(DFtype a)

{
  undefined4 in_r0;
  undefined4 in_r1;
  UDItype UVar1;
  
  if (-1 < (int)((uint)((double)CONCAT44(in_r1,in_r0) < 0.0) << 0x1f)) {
    UVar1 = __fixunsdfdi(a);
    return UVar1;
  }
  UVar1 = __fixunsdfdi(a);
  return CONCAT44(-(int)(UVar1 >> 0x20) - (uint)((int)UVar1 != 0),-(int)UVar1);
}

