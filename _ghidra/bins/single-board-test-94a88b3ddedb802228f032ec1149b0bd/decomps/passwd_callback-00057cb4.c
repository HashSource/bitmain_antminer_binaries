
int passwd_callback(void *param_1,int param_2,int param_3,char *param_4)

{
  int iVar1;
  
  if (param_3 == 0) {
    strlen(param_4);
    iVar1 = curlx_uztosi();
    if (iVar1 < param_2) {
      memcpy(param_1,param_4,iVar1 + 1);
      return iVar1;
    }
  }
  return 0;
}

