
void fix_vol_toPIC(void)

{
  FILE *__stream;
  
  GetTotalRate();
  if (3 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: Error: S9+ can not call fix_vol_toPIC!\n","main.c",0x111c);
    }
    fclose(__stream);
  }
  do {
    processTEST();
    sleep(1);
  } while( true );
}

