
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void clear_register_value_buf(void)

{
  pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
  reg_value_buf->p_wr = 0;
  reg_value_buf->p_rd = 0;
  reg_value_buf->reg_value_num = 0;
  reg_value_buf->loop_back = 0;
  pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
  memset(reg_value_buf->reg_buffer,0,0x13fec);
  return;
}

