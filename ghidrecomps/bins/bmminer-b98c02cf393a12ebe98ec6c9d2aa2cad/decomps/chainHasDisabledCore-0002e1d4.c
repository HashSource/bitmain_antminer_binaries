
undefined4 chainHasDisabledCore(int param_1)

{
  undefined4 uVar1;
  
  if ((disabledcore_pos_buf[param_1 * 0x10] == ',') &&
     (disabledcore_pos_buf[param_1 * 0x10 + 1] == 'e')) {
    uVar1 = chainHasDisabledCore_part_5();
    return uVar1;
  }
  return 0;
}

