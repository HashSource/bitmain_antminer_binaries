
undefined4 write_data_into_pic_flash(undefined param_1)

{
  send_pic_command(param_1);
  pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
  write_pic_iic(0,0,0,param_1,5);
  usleep(200000);
  pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
  return 0;
}

