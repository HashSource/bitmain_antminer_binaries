
void insert_reg_data(undefined4 *param_1)

{
  if (((uint)reg_value_buf._8_4_ < 0x1ff) && ((uint)reg_value_buf._0_4_ < 0x1ff)) {
    pthread_mutex_lock((pthread_mutex_t *)reg_mutex);
    *(undefined4 *)(reg_value_buf + (reg_value_buf._0_4_ + 1) * 8 + 4) = param_1[1];
    reg_value_buf[(reg_value_buf._0_4_ + 1) * 8 + 8] = *(byte *)((int)param_1 + 3) & 0x1f;
    reg_value_buf[(reg_value_buf._0_4_ + 1) * 8 + 9] = (byte)*param_1 & 0xf;
    if ((uint)reg_value_buf._0_4_ < 0x1fe) {
      reg_value_buf._0_4_ = reg_value_buf._0_4_ + 1;
    }
    else {
      reg_value_buf._0_4_ = 0;
    }
    if ((uint)reg_value_buf._8_4_ < 0x1ff) {
      reg_value_buf._8_4_ = reg_value_buf._8_4_ + 1;
    }
    else {
      reg_value_buf._8_4_ = 0x1ff;
    }
    pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
    return;
  }
  clear_register_value_buf();
  return;
}

