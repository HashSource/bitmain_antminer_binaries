
undefined4 main(void)

{
  int iVar1;
  int local_240 [8];
  int local_220;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  timeval local_178;
  timeval local_170;
  undefined auStack_168 [164];
  undefined auStack_c4 [168];
  
  memcpy(auStack_c4,DAT_00008588,0xa1);
  memcpy(auStack_168,auStack_c4,0xa1);
  local_1c0 = 0;
  local_1bc = 0;
  iVar1 = 0;
  local_1b8 = 0;
  local_1b4 = 0;
  local_1b0 = 0;
  local_1ac = 0;
  local_1a8 = 0;
  local_1a4 = 0;
  memset(local_240,0,0x50);
  hex2bin(local_240,auStack_168,0xa0);
  local_240[0] = local_240[0] + 5;
  gettimeofday(&local_178,(__timezone_ptr_t)0x0);
  do {
    iVar1 = iVar1 + 1;
    local_220 = iVar1;
    blake2b_hash(&local_1c0,local_240);
  } while (iVar1 != 1000000);
  gettimeofday(&local_170,(__timezone_ptr_t)0x0);
  local_170.tv_usec = local_170.tv_usec - local_178.tv_usec;
  local_170.tv_sec = local_170.tv_sec - local_178.tv_sec;
  if (local_170.tv_usec < 0) {
    local_170.tv_usec = local_170.tv_usec + 1000000;
    local_170.tv_sec = local_170.tv_sec + -1;
  }
  printf(DAT_0000858c,1000000,local_170.tv_sec,local_170.tv_usec);
  _IO_getc(*DAT_00008590);
  return 0;
}

