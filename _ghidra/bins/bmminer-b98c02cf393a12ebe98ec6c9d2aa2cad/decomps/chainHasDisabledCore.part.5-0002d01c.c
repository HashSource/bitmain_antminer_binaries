
undefined4 chainHasDisabledCore_part_5(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = disabledcore_pos_buf + param_1 * 0x10;
  while ((0x53 < (byte)puVar1[2] || (0x71 < (byte)puVar1[3]))) {
    puVar1 = puVar1 + 2;
    if (puVar1 == (undefined1 *)(param_1 * 0x10 + 0x7e466)) {
      return 0;
    }
  }
  return 1;
}

