
void nonce_scanhash_loop(void)

{
  pthread_t local_c;
  
  do {
    pthread_create(&local_c,(pthread_attr_t *)0x0,(__start_routine *)0x1b681,(void *)0x0);
    pthread_join(local_c,(void **)0x0);
    usleep(1000);
  } while( true );
}

