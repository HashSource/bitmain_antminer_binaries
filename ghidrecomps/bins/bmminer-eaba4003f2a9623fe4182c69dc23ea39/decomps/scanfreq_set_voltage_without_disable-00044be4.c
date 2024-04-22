
void scanfreq_set_voltage_without_disable(int voltage)

{
  int voltage_local;
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
      scanfreq_info.scan_pic_voltage[i] = voltage;
      pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
      printf("Chain[%d] read pic voltage=%d\n",i,voltage);
      pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
      set_voltage_T9_18_into_PIC_without_disable((uchar)i,(uchar)voltage);
      pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    }
  }
  return;
}

