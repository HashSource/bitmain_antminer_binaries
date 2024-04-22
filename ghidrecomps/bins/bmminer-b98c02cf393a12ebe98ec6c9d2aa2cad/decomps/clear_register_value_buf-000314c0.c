
void clear_register_value_buf(void)

{
  pthread_mutex_t *ppVar1;
  
  ppVar1 = DAT_000314e4;
  pthread_mutex_lock(DAT_000314e4);
  reg_value_buf._0_4_ = 0;
  reg_value_buf._4_4_ = 0;
  reg_value_buf._8_4_ = 0;
  (*(code *)PTR_pthread_mutex_unlock_0007ce1c)(ppVar1);
  return;
}

