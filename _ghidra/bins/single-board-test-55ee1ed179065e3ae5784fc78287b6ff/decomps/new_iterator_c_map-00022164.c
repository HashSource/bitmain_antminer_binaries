
undefined4 * new_iterator_c_map(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)malloc(0x18);
  *puVar1 = 0x22099;
  puVar1[2] = 0x220f5;
  puVar1[1] = 0x22115;
  puVar1[3] = param_1;
  puVar1[4] = 0;
  puVar1[5] = 0;
  return puVar1;
}

