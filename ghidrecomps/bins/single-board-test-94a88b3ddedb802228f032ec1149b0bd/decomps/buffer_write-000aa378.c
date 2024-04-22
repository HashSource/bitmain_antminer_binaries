
undefined4 buffer_write(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  bool bVar2;
  
  bVar2 = param_2 < 0;
  if (param_2 != 0) {
    bVar2 = param_3 < 0;
  }
  if ((param_2 != 0 && param_3 != 0) && !bVar2) {
    uVar1 = buffer_write_part_0();
    return uVar1;
  }
  return 0;
}

