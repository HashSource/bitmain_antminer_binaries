
void * check_nonce_loop(void *args)

{
  void *args_local;
  pthread_t send_id;
  runtime_base_t *runtime;
  
  runtime = (runtime_base_t *)args;
  do {
    while (runtime->start_recv == 0) {
      usleep(100000);
    }
    pthread_create(&send_id,(pthread_attr_t *)0x0,check_nonce + 1,args);
    pthread_join(send_id,(void **)0x0);
    usleep(5000);
  } while( true );
}

