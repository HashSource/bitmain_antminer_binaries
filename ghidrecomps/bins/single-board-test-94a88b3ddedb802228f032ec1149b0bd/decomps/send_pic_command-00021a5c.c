
void send_pic_command(undefined param_1)

{
  pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
  write_pic_iic(0,0,0,param_1,0x55);
  write_pic_iic(0,0,0,param_1,0xaa);
  pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
  return;
}

