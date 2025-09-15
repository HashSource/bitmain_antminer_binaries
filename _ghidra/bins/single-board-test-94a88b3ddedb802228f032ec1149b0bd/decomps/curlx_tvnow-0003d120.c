
__time_t * curlx_tvnow(__time_t *param_1)

{
  int iVar1;
  timeval local_20;
  timespec local_18;
  
  iVar1 = clock_gettime(1,&local_18);
  if (iVar1 == 0) {
    local_20.tv_sec = local_18.tv_sec;
    local_20.tv_usec = local_18.tv_nsec / 1000;
  }
  else {
    gettimeofday(&local_20,(__timezone_ptr_t)0x0);
  }
  *param_1 = local_20.tv_sec;
  param_1[1] = local_20.tv_usec;
  return param_1;
}

