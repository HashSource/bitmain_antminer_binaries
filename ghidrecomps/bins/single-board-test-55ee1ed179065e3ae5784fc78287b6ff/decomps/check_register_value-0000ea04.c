
undefined4 check_register_value(undefined param_1,void *param_2)

{
  undefined4 uVar1;
  size_t local_c;
  
  local_c = 0;
  if (Conf._116_4_ == 0x6ba) {
    local_c = 7;
  }
  else if (Conf._116_4_ == 0x6bd) {
    local_c = 8;
  }
  if (reg_value_buf[2] < 0x200) {
    memcpy((void *)((int)reg_value_buf + *reg_value_buf * 10 + 0x10),param_2,local_c);
    *(byte *)((int)reg_value_buf + *reg_value_buf * 10 + 0x18) =
         *(byte *)((int)param_2 + (local_c - 1)) & 0x1f;
    *(undefined *)((int)reg_value_buf + *reg_value_buf * 10 + 0x19) = param_1;
    *reg_value_buf = *reg_value_buf + 1;
    reg_value_buf[2] = reg_value_buf[2] + 1;
    if (0x200 < *reg_value_buf) {
      *reg_value_buf = 0;
    }
    uVar1 = 0;
  }
  else {
    printf("%s: reg_value_buf buffer is full!\n","check_register_value");
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

