
int sw_flush(float **matrix)

{
  int iVar1;
  float **matrix_local;
  char time_stamp [48];
  char tmp1 [256];
  size_t stacksize;
  pthread_attr_t attr;
  int ret;
  
  ret = pthread_attr_init((pthread_attr_t *)&attr);
  if (ret != 0) {
    fwrite("Error: pthread_attr_init\n",1,0x19,stderr);
  }
  ret = pthread_attr_getstacksize((pthread_attr_t *)&attr,&stacksize);
  if (ret != 0) {
    fwrite("Error: pthread_attr_getstacksize\n",1,0x21,stderr);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : =====stack size: %u\n\n","sw_flush",stacksize);
  snprintf(tmp1,0x100,"=====stack size: %u\n",stacksize);
  log_to_file(tmp1,time_stamp);
  show_sweep_summary(*matrix);
  iVar1 = flush_eeprom_data(*matrix,(g_rt.config)->chain);
  return iVar1;
}

