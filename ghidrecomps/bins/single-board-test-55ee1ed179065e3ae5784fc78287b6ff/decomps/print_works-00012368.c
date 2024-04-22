
uint print_works(void)

{
  int iVar1;
  int iVar2;
  uint local_18;
  uint local_14;
  uint local_10;
  int local_c;
  
  printf("\n%s begin\n\n","print_works");
  if (Conf._108_4_ == 1) {
    local_14 = 0;
    while( true ) {
      if ((uint)Conf._112_4_ <= local_14) break;
      iVar1 = *(int *)(cgpu + (local_14 + 0x20028) * 4);
      for (local_18 = 0; local_18 < (uint)Conf._64_4_; local_18 = local_18 + 1) {
        iVar2 = iVar1 + local_18 * 0xcc;
        printf("core[%02d][%02d].work=0x",local_14,local_18);
        for (local_c = 0; local_c < 0xb4; local_c = local_c + 1) {
          printf("%02x",(uint)*(byte *)(iVar2 + local_c + 8));
        }
        printf(" nonce=0x%08x\n",*(undefined4 *)(iVar2 + 4));
      }
      putchar(10);
      local_14 = local_14 + 1;
    }
    printf("\n%s end\n\n","print_works");
  }
  else {
    local_10 = 0;
    while( true ) {
      if ((uint)Conf._108_4_ <= local_10) break;
      iVar1 = *(int *)(cgpu + (local_10 + 0x20028) * 4);
      for (local_14 = 0; local_14 < (uint)Conf._112_4_; local_14 = local_14 + 1) {
        for (local_18 = 0; local_18 < (uint)Conf._64_4_; local_18 = local_18 + 1) {
          iVar2 = iVar1 + (local_14 * Conf._64_4_ + local_18) * 0xcc;
          printf("asic[%02d][%02d][%02d].work=0x",local_10,local_14,local_18);
          for (local_c = 0; local_c < 0xb4; local_c = local_c + 1) {
            printf("%02x",(uint)*(byte *)(iVar2 + local_c + 8));
          }
          printf(" nonce=0x%08x\n",*(undefined4 *)(iVar2 + 4));
        }
        putchar(10);
      }
      putchar(10);
      local_10 = local_10 + 1;
    }
    printf("\n%s end\n\n","print_works");
    local_14 = local_10;
  }
  return local_14;
}

