
void get_data_from_pic_iic(undefined param_1,undefined param_2,int param_3,byte param_4)

{
  undefined uVar1;
  int local_14;
  
  pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
  write_pic_iic(0,0,0,param_1,param_2);
  for (local_14 = 0; local_14 < (int)(uint)param_4; local_14 = local_14 + 1) {
    uVar1 = write_pic_iic(1,0,0,param_1,0);
    *(undefined *)(param_3 + local_14) = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
  return;
}

