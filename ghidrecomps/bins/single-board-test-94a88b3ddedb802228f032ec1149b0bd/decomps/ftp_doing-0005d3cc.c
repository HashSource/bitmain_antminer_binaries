
int ftp_doing(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = ftp_multi_statemach();
  if ((iVar1 == 0) && (*param_2 != '\0')) {
    iVar1 = ftp_dophase_done(param_1,0,*param_2,param_4);
    return iVar1;
  }
  return iVar1;
}

