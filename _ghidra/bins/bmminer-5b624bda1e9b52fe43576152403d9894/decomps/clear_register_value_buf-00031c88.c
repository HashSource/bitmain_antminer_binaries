
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void clear_register_value_buf(void)

{
  pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
  reg_value_buf.p_wr = 0;
  reg_value_buf.p_rd = 0;
  reg_value_buf.reg_value_num = 0;
  (*(code *)(undefined *)0x0)(&reg_mutex);
  return;
}

