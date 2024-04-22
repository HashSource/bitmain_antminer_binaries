
undefined8 bitmain_c5_scanhash(void *param_1)

{
  pthread_t local_14;
  
  h = 0;
  DAT_00704ab4 = 0;
  pthread_create(&local_14,(pthread_attr_t *)0x0,bitmain_scanhash + 1,param_1);
  pthread_join(local_14,(void **)0x0);
  return CONCAT44(DAT_00704ab4,h);
}

