
void clear_register_value_buf(void)

{
  pthread_mutex_lock((pthread_mutex_t *)reg_mutex);
  *reg_value_buf = 0;
  reg_value_buf[1] = 0;
  reg_value_buf[2] = 0;
  reg_value_buf[3] = 0;
  pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
  memset(reg_value_buf + 4,0,0x1400);
  return;
}

