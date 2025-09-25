
undefined4 cpy_bmp(undefined4 param_1,int *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)*param_2;
  puVar1[1] = (char)param_1;
  *puVar1 = (char)((uint)param_1 >> 8);
  *param_2 = *param_2 + 2;
  return 1;
}

