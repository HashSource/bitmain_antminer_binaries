
void opt_log_stderr_exit(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  vfprintf(stderr,param_1,&uStack_c);
  fputc(10,stderr);
                    /* WARNING: Subroutine does not return */
  exit(1);
}

