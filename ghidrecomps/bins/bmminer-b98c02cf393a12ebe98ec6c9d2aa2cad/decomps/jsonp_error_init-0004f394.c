
void jsonp_error_init(undefined4 *param_1,int param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *(undefined *)(param_1 + 0x17) = 0;
    param_1[2] = 0;
    *param_1 = 0xffffffff;
    param_1[1] = 0xffffffff;
    if (param_2 != 0) {
      jsonp_error_set_source_part_0();
      return;
    }
    *(undefined *)(param_1 + 3) = 0;
  }
  return;
}

