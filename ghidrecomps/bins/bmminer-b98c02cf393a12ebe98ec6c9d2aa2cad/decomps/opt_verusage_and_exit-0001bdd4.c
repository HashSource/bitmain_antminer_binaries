
void opt_verusage_and_exit
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  printf("%s\nBuilt with bitmain_c5 mining support.\n",DAT_0001be18,param_3,param_4,param_4);
  uVar1 = opt_usage(opt_argv0,param_1);
  printf("%s",uVar1);
  fflush(stdout);
                    /* WARNING: Subroutine does not return */
  exit(0);
}

