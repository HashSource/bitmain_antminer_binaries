
void applog_and_exit(char *fmt,...)

{
  char *str;
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  va_list ap;
  char *fmt_local;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  str = DAT_0001e200;
  uStack_c = in_r1;
  uStack_8 = in_r2;
  uStack_4 = in_r3;
  vsnprintf(DAT_0001e200,0x200,fmt,&uStack_c);
  _applog(3,str,true);
                    /* WARNING: Subroutine does not return */
  exit(1);
}

