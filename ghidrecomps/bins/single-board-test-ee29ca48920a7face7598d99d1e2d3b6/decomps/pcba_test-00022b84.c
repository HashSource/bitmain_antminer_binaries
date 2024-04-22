
void pcba_test(void)

{
  pthread_t local_c;
  
  singleboard_set_address_test();
  pthread_create(&local_c,(pthread_attr_t *)0x0,singleboard_sensor_test + 1,(void *)0x0);
  singleboard_patten_test();
  pthread_cancel(local_c);
  pthread_join(local_c,(void **)0x0);
  return;
}

