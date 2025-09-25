
int dtls1_is_timer_expired(undefined4 param_1)

{
  int iVar1;
  int local_10;
  int local_c;
  
  iVar1 = dtls1_get_timeout(param_1,&local_10);
  if (iVar1 != 0) {
    if (local_10 < 1) {
      if (local_c < 1) {
        iVar1 = 1;
      }
      else {
        iVar1 = 0;
      }
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}

