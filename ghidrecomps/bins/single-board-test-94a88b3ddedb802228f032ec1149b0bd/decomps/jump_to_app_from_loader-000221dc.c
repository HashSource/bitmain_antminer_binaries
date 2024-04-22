
undefined4 jump_to_app_from_loader(undefined param_1)

{
  puts("jump_to_app_from_loader");
  send_pic_command(param_1);
  pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
  write_pic_iic(0,0,0,param_1,6);
  usleep(1000000);
  pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
  return 0;
}

