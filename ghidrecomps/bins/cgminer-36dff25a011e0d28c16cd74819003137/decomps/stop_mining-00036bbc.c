
void stop_mining(char *str)

{
  FILE *__stream;
  char *str_local;
  FILE *pFile;
  
  if (1 < log_level) {
    print_crt_time_to_file(log_file,1);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: fetal error: stop ming: %s\n","power.c",0x6c,"stop_mining",str);
    }
    fclose(__stream);
  }
  do {
    sleep(1);
  } while( true );
}

