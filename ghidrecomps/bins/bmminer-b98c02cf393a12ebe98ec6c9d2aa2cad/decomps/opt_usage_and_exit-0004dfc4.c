
void opt_usage_and_exit(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = opt_usage(opt_argv0,param_1,param_3,&opt_argv0,param_4);
  printf("%s",uVar1);
  fflush(stdout);
                    /* WARNING: Subroutine does not return */
  exit(0);
}

