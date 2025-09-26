
/* WARNING: Unknown calling convention */

void json_object_seed(size_t seed)

{
  bool bVar1;
  char cVar2;
  int __fd;
  ssize_t sVar3;
  uint uVar4;
  char data [4];
  uint uStack_1c;
  
  cVar2 = seed_initialized;
  if (hashtable_seed != 0) {
    return;
  }
  do {
    ExclusiveAccess(0x21b60f0);
    bVar1 = (bool)hasExclusiveAccess(0x21b60f0);
  } while (!bVar1);
  seed_initialized = '\x01';
  if (cVar2 != '\0') {
    do {
      sched_yield();
      DataMemoryBarrier(0x1f);
      if (hashtable_seed != 0) {
        return;
      }
      sched_yield();
      DataMemoryBarrier(0x1f);
    } while (hashtable_seed == 0);
    return;
  }
  if (seed != 0) goto LAB_000db668;
  __fd = open("/dev/urandom",0);
  if (__fd == -1) {
LAB_000db6d0:
    gettimeofday((timeval *)data,(__timezone_ptr_t)0x0);
    uVar4 = getpid();
    seed = uVar4 ^ (uint)data ^ uStack_1c;
  }
  else {
    sVar3 = read(__fd,data,4);
    close(__fd);
    if (sVar3 != 4) goto LAB_000db6d0;
    seed = CONCAT31(CONCAT21(CONCAT11(data[0],data[1]),data[2]),data[3]);
  }
  if (seed == 0) {
    seed = 1;
  }
LAB_000db668:
  DataMemoryBarrier(0x1f);
  hashtable_seed = seed;
  return;
}

