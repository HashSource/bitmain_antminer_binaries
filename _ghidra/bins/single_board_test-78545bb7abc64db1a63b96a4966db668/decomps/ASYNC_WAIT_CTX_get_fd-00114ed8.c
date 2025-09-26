
undefined4 ASYNC_WAIT_CTX_get_fd(int *param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  
  param_1 = (int *)*param_1;
  while( true ) {
    if (param_1 == (int *)0x0) {
      return 0;
    }
    if ((param_1[5] == 0) && (*param_1 == param_2)) break;
    param_1 = (int *)param_1[6];
  }
  iVar1 = param_1[2];
  *param_3 = param_1[1];
  *param_4 = iVar1;
  return 1;
}

