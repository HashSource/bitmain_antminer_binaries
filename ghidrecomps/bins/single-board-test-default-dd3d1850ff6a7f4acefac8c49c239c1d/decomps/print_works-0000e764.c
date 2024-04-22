
uint print_works(void)

{
  int iVar1;
  int iVar2;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  int local_c;
  
  local_14 = 0;
  local_18 = Conf._204_4_;
  local_1c = Conf._208_4_;
  local_20 = Conf._212_4_;
  local_24 = Conf._216_4_;
  local_2c = 0;
  printf("\n--- %s begin\n\n","print_works");
  if (Conf._108_4_ == 1) {
    for (local_10 = 0; (int)local_10 < 0x20; local_10 = local_10 + 1) {
      if ((local_18 & 1) != 0) {
        iVar1 = *(int *)(cgpu + (local_14 + 0x402a) * 4 + 4);
        for (local_30 = 0; local_30 < (uint)Conf._64_4_; local_30 = local_30 + 1) {
          iVar2 = iVar1 + local_30 * 0x74;
          printf("core[%02d][%02d].midstate=0x",local_2c,local_30);
          for (local_c = 0; local_c < 0x20; local_c = local_c + 1) {
            printf("%02x",(uint)*(byte *)(iVar2 + local_c + 0x14));
          }
          printf(" data2=");
          for (local_c = 0; local_c < 0xc; local_c = local_c + 1) {
            printf("%02x",(uint)*(byte *)(iVar2 + local_c + 8));
          }
          printf(" nonce=0x%08x\n",*(undefined4 *)(iVar2 + 4));
        }
        putchar(10);
        local_14 = local_14 + 1;
      }
      local_18 = local_18 >> 1;
      local_2c = local_2c + 1;
    }
    for (local_10 = 0; (int)local_10 < 0x20; local_10 = local_10 + 1) {
      if ((local_1c & 1) != 0) {
        iVar1 = *(int *)(cgpu + (local_14 + 0x402a) * 4 + 4);
        for (local_30 = 0; local_30 < (uint)Conf._64_4_; local_30 = local_30 + 1) {
          iVar2 = iVar1 + local_30 * 0x74;
          printf("core[%02d][%02d].midstate=0x",local_2c,local_30);
          for (local_c = 0; local_c < 0x20; local_c = local_c + 1) {
            printf("%02x",(uint)*(byte *)(iVar2 + local_c + 0x14));
          }
          printf(" data2=");
          for (local_c = 0; local_c < 0xc; local_c = local_c + 1) {
            printf("%02x",(uint)*(byte *)(iVar2 + local_c + 8));
          }
          printf(" nonce=0x%08x\n",*(undefined4 *)(iVar2 + 4));
        }
        putchar(10);
        local_14 = local_14 + 1;
      }
      local_1c = local_1c >> 1;
      local_2c = local_2c + 1;
    }
    for (local_10 = 0; (int)local_10 < 0x20; local_10 = local_10 + 1) {
      if ((local_20 & 1) != 0) {
        iVar1 = *(int *)(cgpu + (local_14 + 0x402a) * 4 + 4);
        for (local_30 = 0; local_30 < (uint)Conf._64_4_; local_30 = local_30 + 1) {
          iVar2 = iVar1 + local_30 * 0x74;
          printf("core[%02d][%02d].midstate=0x",local_2c,local_30);
          for (local_c = 0; local_c < 0x20; local_c = local_c + 1) {
            printf("%02x",(uint)*(byte *)(iVar2 + local_c + 0x14));
          }
          printf(" data2=");
          for (local_c = 0; local_c < 0xc; local_c = local_c + 1) {
            printf("%02x",(uint)*(byte *)(iVar2 + local_c + 8));
          }
          printf(" nonce=0x%08x\n",*(undefined4 *)(iVar2 + 4));
        }
        putchar(10);
        local_14 = local_14 + 1;
      }
      local_20 = local_20 >> 1;
      local_2c = local_2c + 1;
    }
    for (local_10 = 0; (int)local_10 < 0x20; local_10 = local_10 + 1) {
      if ((local_24 & 1) != 0) {
        iVar1 = *(int *)(cgpu + (local_14 + 0x402a) * 4 + 4);
        for (local_30 = 0; local_30 < (uint)Conf._64_4_; local_30 = local_30 + 1) {
          iVar2 = iVar1 + local_30 * 0x74;
          printf("core[%02d][%02d].midstate=0x",local_2c,local_30);
          for (local_c = 0; local_c < 0x20; local_c = local_c + 1) {
            printf("%02x",(uint)*(byte *)(iVar2 + local_c + 0x14));
          }
          printf(" data2=");
          for (local_c = 0; local_c < 0xc; local_c = local_c + 1) {
            printf("%02x",(uint)*(byte *)(iVar2 + local_c + 8));
          }
          printf(" nonce=0x%08x\n",*(undefined4 *)(iVar2 + 4));
        }
        putchar(10);
        local_14 = local_14 + 1;
      }
      local_24 = local_24 >> 1;
      local_2c = local_2c + 1;
    }
    printf("\n--- %s end\n\n","print_works");
  }
  else {
    local_28 = 0;
    while( true ) {
      if ((uint)Conf._108_4_ <= local_28) break;
      iVar1 = *(int *)(cgpu + (local_28 + 0x402a) * 4 + 4);
      for (local_2c = 0; local_2c < (uint)Conf._112_4_; local_2c = local_2c + 1) {
        for (local_30 = 0; local_30 < (uint)Conf._64_4_; local_30 = local_30 + 1) {
          iVar2 = iVar1 + (local_2c * Conf._64_4_ + local_30) * 0x74;
          printf("asic[%02d][%02d][%02d].midstate=0x",local_28,local_2c,local_30);
          for (local_c = 0; local_c < 0x20; local_c = local_c + 1) {
            printf("%02x",(uint)*(byte *)(iVar2 + local_c + 0x14));
          }
          printf(" data2=");
          for (local_c = 0; local_c < 0xc; local_c = local_c + 1) {
            printf("%02x",(uint)*(byte *)(iVar2 + local_c + 8));
          }
          printf(" nonce=0x%08x\n",*(undefined4 *)(iVar2 + 4));
        }
      }
      putchar(10);
      local_28 = local_28 + 1;
    }
    printf("\n--- %s end\n\n","print_works");
    local_10 = local_28;
  }
  return local_10;
}

