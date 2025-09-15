
void * heart_beat_func_one_chain(void *arg)

{
  pthread_t __th;
  FILE *__stream;
  void *arg_local;
  FILE *pFile;
  int chain;
  
  __th = pthread_self();
  pthread_detach(__th);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: for chain %d\n","driver-btm-soc.c",0xc88,
              "heart_beat_func_one_chain",arg);
    }
    fclose(__stream);
  }
  do {
    pic_set_heart_beat((uint8_t)arg);
    sleep(10);
  } while( true );
}

