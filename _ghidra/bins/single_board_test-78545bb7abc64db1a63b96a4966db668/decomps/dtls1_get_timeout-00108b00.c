
int * dtls1_get_timeout(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  timeval local_18;
  
  if ((*(int *)(*(int *)(param_1 + 0x80) + 0x184) == 0) &&
     (*(int *)(*(int *)(param_1 + 0x80) + 0x188) == 0)) {
    return (int *)0x0;
  }
  gettimeofday(&local_18,(__timezone_ptr_t)0x0);
  iVar1 = *(int *)(param_1 + 0x80);
  if ((local_18.tv_sec <= *(int *)(iVar1 + 0x184)) &&
     ((*(int *)(iVar1 + 0x184) != local_18.tv_sec || (local_18.tv_usec < *(int *)(iVar1 + 0x188)))))
  {
    iVar2 = *(int *)(iVar1 + 0x188);
    *param_2 = *(int *)(iVar1 + 0x184);
    param_2[1] = iVar2;
    iVar2 = param_2[1] - local_18.tv_usec;
    iVar1 = *param_2 - local_18.tv_sec;
    *param_2 = iVar1;
    param_2[1] = iVar2;
    if (iVar2 < 0) {
      iVar1 = iVar1 + -1;
      iVar2 = iVar2 + 1000000;
      *param_2 = iVar1;
      param_2[1] = iVar2;
    }
    if (iVar1 != 0) {
      return param_2;
    }
    if (14999 < iVar2) {
      return param_2;
    }
  }
  *param_2 = 0;
  param_2[1] = 0;
  return param_2;
}

