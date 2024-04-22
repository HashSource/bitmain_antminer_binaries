
void stop_mining(undefined4 param_1)

{
  FILE *__stream;
  
  if (1 < log_level) {
    __stream = fopen(log_file,(char *)&DAT_0005e760);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: %s\n","driver-btm-c5.c",0x2fb2,DAT_0003de54,param_1);
    }
    fclose(__stream);
  }
  do {
    processTEST();
    sleep(1);
  } while( true );
}

