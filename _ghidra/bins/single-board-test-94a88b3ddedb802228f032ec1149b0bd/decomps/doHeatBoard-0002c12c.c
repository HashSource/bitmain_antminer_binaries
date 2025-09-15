
void doHeatBoard(void)

{
  FILE *__stream;
  
  if (3 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: Error: S9+ can not call doHeatBoard!\n","main.c",0x1ca1);
    }
    fclose(__stream);
  }
  do {
    processTEST();
    sleep(1);
  } while( true );
}

