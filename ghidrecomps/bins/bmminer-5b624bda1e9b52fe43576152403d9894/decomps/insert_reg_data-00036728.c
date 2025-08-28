
/* WARNING: Unknown calling convention */

void insert_reg_data(uint *buf)

{
  undefined4 extraout_r1;
  undefined4 in_r3;
  undefined4 unaff_lr;
  
  if ((reg_value_buf.reg_value_num < 0x1ff) && (reg_value_buf.p_wr < 0x1ff)) {
    pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
    reg_value_buf.reg_buffer[reg_value_buf.p_wr].reg_value = buf[1];
    reg_value_buf.reg_buffer[reg_value_buf.p_wr].crc = *(byte *)((int)buf + 3) & 0x1f;
    reg_value_buf.reg_buffer[reg_value_buf.p_wr].chain_number = (byte)*buf & 0xf;
    if (reg_value_buf.p_wr < 0x1ff) {
      reg_value_buf.p_wr = reg_value_buf.p_wr + 1;
    }
    else {
      reg_value_buf.p_wr = 0;
    }
    if (reg_value_buf.reg_value_num < 0x1ff) {
      reg_value_buf.reg_value_num = reg_value_buf.reg_value_num + 1;
    }
    else {
      reg_value_buf.reg_value_num = 0x1ff;
    }
    (*(code *)(undefined *)0x0)(&reg_mutex,extraout_r1,reg_value_buf.reg_value_num,in_r3,unaff_lr);
    return;
  }
  clear_register_value_buf();
  return;
}

