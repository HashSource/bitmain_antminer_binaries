
void scanfreq_set_voltage_75j(int voltage)

{
  int voltage_local;
  int i;
  
  if (0x6ad < voltage) {
    if (voltage < 0x7da) goto LAB_00044b4a;
  }
  printf("wrong vol setting,[%d]",voltage);
LAB_00044b4a:
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
      scanfreq_info.scan_pic_voltage[i] = voltage;
      pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
      printf("Chain[%d] read pic voltage=%d\n",i,voltage);
      pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
      set_voltage_s11_into_PIC((uchar)i,voltage);
      pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    }
  }
  return;
}

