
undefined4 isDisabledCore(int param_1,uint param_2,uint param_3)

{
  undefined1 *puVar1;
  
  param_1 = param_1 * 0x10;
  if ((disabledcore_pos_buf[param_1] == ',') && (disabledcore_pos_buf[param_1 + 1] == 'e')) {
    puVar1 = disabledcore_pos_buf + param_1;
    do {
      if (((byte)puVar1[2] == param_2) && ((byte)puVar1[3] == param_3)) {
        return 1;
      }
      puVar1 = puVar1 + 2;
    } while (puVar1 != (undefined1 *)(param_1 + 0x7e466));
  }
  return 0;
}

