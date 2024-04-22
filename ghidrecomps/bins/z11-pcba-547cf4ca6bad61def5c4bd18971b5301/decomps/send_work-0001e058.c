
void send_work(undefined4 param_1,uint param_2,byte param_3)

{
  undefined auStack_12c [140];
  undefined auStack_a0 [2];
  byte local_9e;
  char local_9d;
  undefined auStack_9c [144];
  int local_c;
  
  memset(auStack_a0,0,0x92);
  local_9e = local_9e & 0xee | (byte)((param_2 & 1) << 4) | param_3 & 1;
  local_9d = total_work;
  total_work = total_work + '\x01';
  memset(auStack_12c,0,0x8c);
  hex2bin(auStack_12c,param_1,0x8c);
  memcpy(auStack_9c,auStack_12c,0x8c);
  memcpy(g_work_header,auStack_12c,0x8c);
  g_new_work = 1;
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    midd_ioctl(*(undefined4 *)(g_chain + local_c * 0x20),2,auStack_a0);
  }
  return;
}

