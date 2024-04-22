
void applog_and_exit(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  pcVar1 = DAT_0001bdd0;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  vsnprintf(DAT_0001bdd0,0x200,param_1,&uStack_c);
  _applog(3,pcVar1,1);
                    /* WARNING: Subroutine does not return */
  exit(1);
}

