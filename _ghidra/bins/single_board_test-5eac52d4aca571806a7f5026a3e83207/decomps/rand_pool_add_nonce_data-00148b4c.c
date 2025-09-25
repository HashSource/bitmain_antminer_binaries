
void rand_pool_add_nonce_data(undefined4 param_1)

{
  uint uVar1;
  timespec local_30;
  __pid_t local_28;
  pthread_t local_24;
  time_t local_20;
  int local_1c;
  
  local_24 = 0;
  local_28 = 0;
  local_20 = 0;
  local_1c = 0;
  local_28 = getpid();
  local_24 = CRYPTO_THREAD_get_current_id();
  uVar1 = clock_gettime(0,&local_30);
  if ((uVar1 == 0) || (uVar1 = gettimeofday((timeval *)&local_30,(__timezone_ptr_t)0x0), uVar1 == 0)
     ) {
    local_20 = uVar1 + local_30.tv_nsec;
    local_1c = local_30.tv_sec + (local_30.tv_nsec >> 0x1f) + (uint)CARRY4(uVar1,local_30.tv_nsec);
  }
  else {
    local_20 = time((time_t *)0x0);
    local_1c = local_20 >> 0x1f;
  }
  rand_pool_add(param_1,&local_28,0x10,0);
  return;
}

