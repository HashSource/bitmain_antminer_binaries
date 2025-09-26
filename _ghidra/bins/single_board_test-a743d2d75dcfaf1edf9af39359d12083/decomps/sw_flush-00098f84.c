
int sw_flush(float **matrix)

{
  int iVar1;
  float **matrix_local;
  size_t stacksize;
  pthread_attr_t attr;
  int ret;
  
  ret = pthread_attr_init((pthread_attr_t *)&attr);
  if (ret != 0) {
    fwrite("3: pthread_attr_init\n",1,0x15,stderr);
  }
  ret = pthread_attr_getstacksize((pthread_attr_t *)&attr,&stacksize);
  if (ret != 0) {
    fwrite("3: pthread_attr_getstacksize\n",1,0x1d,stderr);
  }
  printf("=====stack size: %u\n",stacksize);
  show_sweep_summary(*matrix);
  iVar1 = flush_eeprom_data(*matrix,(g_rt.config)->chain);
  return iVar1;
}

