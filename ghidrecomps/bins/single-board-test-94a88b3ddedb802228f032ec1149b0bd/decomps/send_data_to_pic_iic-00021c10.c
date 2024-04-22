
void send_data_to_pic_iic(undefined param_1,undefined param_2,int param_3,byte param_4)

{
  int local_c;
  
  pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
  write_pic_iic(0,0,0,param_1,param_2);
  for (local_c = 0; local_c < (int)(uint)param_4; local_c = local_c + 1) {
    write_pic_iic(0,0,0,param_1,*(undefined *)(local_c + param_3));
  }
  pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
  return;
}

