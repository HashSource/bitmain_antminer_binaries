
void rand_pool_add_additional_data(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  timespec local_30;
  __pid_t local_28;
  pthread_t local_24;
  int local_20;
  int local_1c;
  
  iVar3 = 0;
  local_24 = 0;
  local_28 = 0;
  local_20 = 0;
  local_1c = 0;
  local_28 = openssl_get_fork_id();
  local_24 = CRYPTO_THREAD_get_current_id();
  iVar1 = OPENSSL_rdtsc();
  if (iVar1 == 0) {
    uVar2 = clock_gettime(7,&local_30);
    if ((uVar2 == 0) ||
       (uVar2 = gettimeofday((timeval *)&local_30,(__timezone_ptr_t)0x0), uVar2 == 0)) {
      iVar1 = uVar2 + local_30.tv_nsec;
      iVar3 = local_30.tv_sec + (local_30.tv_nsec >> 0x1f) + (uint)CARRY4(uVar2,local_30.tv_nsec);
    }
    else {
      iVar1 = time((time_t *)0x0);
      iVar3 = iVar1 >> 0x1f;
    }
  }
  local_20 = iVar1;
  local_1c = iVar3;
  rand_pool_add(param_1,&local_28,0x10,0);
  return;
}

