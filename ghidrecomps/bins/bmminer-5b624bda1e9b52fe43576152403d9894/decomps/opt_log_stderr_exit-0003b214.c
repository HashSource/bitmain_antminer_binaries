
void opt_log_stderr_exit(char *fmt,...)

{
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  va_list ap;
  char *fmt_local;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = in_r1;
  uStack_8 = in_r2;
  uStack_4 = in_r3;
  vfprintf(stderr,fmt,&uStack_c);
  fputc(10,stderr);
                    /* WARNING: Subroutine does not return */
  exit(1);
}

