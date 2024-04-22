
undefined4 single_BM1385_check_register_value(undefined param_1,byte *param_2)

{
  undefined4 uVar1;
  
  if (reg_value_buf[2] < 0x1ff) {
    reg_value_buf[(*reg_value_buf + 2) * 2] =
         (uint)param_2[3] |
         (uint)*param_2 << 0x18 | (uint)param_2[1] << 0x10 | (uint)param_2[2] << 8;
    *(byte *)(reg_value_buf + (*reg_value_buf + 2) * 2 + 1) = param_2[4] & 0x1f;
    *(undefined *)((int)reg_value_buf + (*reg_value_buf + 2) * 8 + 5) = param_1;
    *reg_value_buf = *reg_value_buf + 1;
    reg_value_buf[2] = reg_value_buf[2] + 1;
    if (0x1ff < *reg_value_buf) {
      *reg_value_buf = 0;
    }
    uVar1 = 0;
  }
  else {
    printf("%s: reg_value_buf buffer is full!\n","single_BM1385_check_register_value");
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

