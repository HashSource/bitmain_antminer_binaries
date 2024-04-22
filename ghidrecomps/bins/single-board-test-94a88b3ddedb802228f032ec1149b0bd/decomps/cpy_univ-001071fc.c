
undefined4 cpy_univ(undefined4 param_1,int *param_2)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)*param_2;
  puVar1[3] = (char)param_1;
  *puVar1 = (char)((uint)param_1 >> 0x18);
  puVar1[1] = (char)((uint)param_1 >> 0x10);
  puVar1[2] = (char)((uint)param_1 >> 8);
  *param_2 = *param_2 + 4;
  return 1;
}

