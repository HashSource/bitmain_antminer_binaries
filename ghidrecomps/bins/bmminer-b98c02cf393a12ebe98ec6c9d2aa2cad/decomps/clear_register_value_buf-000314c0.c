
void clear_register_value_buf(void)

{
  pthread_mutex_lock((pthread_mutex_t *)reg_mutex);
  reg_value_buf._0_4_ = 0;
  reg_value_buf._4_4_ = 0;
  reg_value_buf._8_4_ = 0;
  pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
  return;
}

