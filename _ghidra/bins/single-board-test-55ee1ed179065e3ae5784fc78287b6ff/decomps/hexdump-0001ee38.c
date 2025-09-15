
void hexdump(undefined4 param_1,int param_2,uint param_3)

{
  uint __c;
  uint local_1c;
  uint local_10;
  int local_c;
  
  printf("Dumping %u %s bytes from %p:\n",param_3,param_1,param_2);
  local_1c = param_3;
  local_c = param_2;
  while( true ) {
    if ((int)local_1c < 1) {
      return;
    }
    for (local_10 = 0; local_10 < 0x10; local_10 = local_10 + 1) {
      if (local_10 < local_1c) {
        printf("%02x ",(uint)*(byte *)(local_c + local_10));
      }
      else {
        printf("   ");
      }
    }
    for (local_10 = 0; local_10 < 0x10; local_10 = local_10 + 1) {
      if (local_10 < local_1c) {
        if ((*(byte *)(local_c + local_10) < 0x20) || (0x7e < *(byte *)(local_c + local_10))) {
          __c = 0x2e;
        }
        else {
          __c = (uint)*(byte *)(local_c + local_10);
        }
        putchar(__c);
      }
      else {
        putchar(0x20);
      }
    }
    putchar(10);
    local_c = local_c + 0x10;
    if ((int)local_1c < 0x11) break;
    local_1c = local_1c - 0x10;
  }
  return;
}

