
void insert_reg_data(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  pthread_mutex_t *ppVar1;
  undefined4 extraout_r1;
  uint uVar2;
  
  if (((uint)reg_value_buf._8_4_ < 0x1ff) && ((uint)reg_value_buf._0_4_ < 0x1ff)) {
    pthread_mutex_lock(DAT_00037c14);
    ppVar1 = DAT_00037c14;
    *(uint *)(reg_value_buf + (reg_value_buf._0_4_ + 1) * 8 + 4) = param_1[1];
    reg_value_buf[(reg_value_buf._0_4_ + 1) * 8 + 8] = *(byte *)((int)param_1 + 3) & 0x1f;
    uVar2 = *param_1;
    reg_value_buf[(reg_value_buf._0_4_ + 1) * 8 + 9] = (char)(uVar2 & 0xf);
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
    (*(code *)PTR_pthread_mutex_unlock_0007ce1c)(ppVar1,extraout_r1,uVar2 & 0xf,param_4);
    return;
  }
  clear_register_value_buf();
  return;
}

