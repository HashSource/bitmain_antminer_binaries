
undefined4 main(void)

{
  int iVar1;
  int iVar2;
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
  undefined1 auStack_168 [164];
  undefined1 auStack_c4 [168];
  
  memcpy(auStack_c4,
         "002800270026002500240023002200210020001f001e001d001c001b001a0019630999000016001500140013001200110010000f000e000d000c000b000a000900080007000600050004000300020001"
         ,0xa1);
  memcpy(auStack_168,auStack_c4,0xa1);
  local_1c0 = 0;
  local_1bc = 0;
  iVar2 = 0;
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
    iVar2 = iVar2 + 1;
    local_220 = iVar2;
    blake2b_hash(&local_1c0,local_240);
  } while (iVar2 != 1000000);
  gettimeofday(&local_170,(__timezone_ptr_t)0x0);
  iVar2 = local_170.tv_usec - local_178.tv_usec;
  iVar1 = local_170.tv_sec - local_178.tv_sec;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 1000000;
    iVar1 = iVar1 + -1;
  }
  printf("%d %d:%d\n",1000000,iVar1,iVar2);
  _IO_getc(stdin);
  return 0;
}

