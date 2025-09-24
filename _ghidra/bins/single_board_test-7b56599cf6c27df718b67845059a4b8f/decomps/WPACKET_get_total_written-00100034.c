
undefined4 WPACKET_get_total_written(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0xc);
    return 1;
  }
  return 0;
}

