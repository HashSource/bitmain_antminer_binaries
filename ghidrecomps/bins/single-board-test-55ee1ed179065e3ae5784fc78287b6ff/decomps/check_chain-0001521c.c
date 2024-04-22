
undefined4 check_chain(void)

{
  int iVar1;
  undefined4 uVar2;
  uint local_12c;
  uint local_128;
  
  printf("--- %s\n","check_chain");
  iVar1 = platform_init();
  if (iVar1 == 0) {
    get_system_capability(&local_12c);
    if (local_12c == 1) {
      gChain = (byte)local_128;
      *(byte *)((int)&chain_info + (local_128 & 0xff) * 2) = gChain;
      *(undefined *)((int)&chain_info + (uint)gChain * 2 + 1) = 0;
      printf("gChain = %d\n",(uint)gChain);
      uVar2 = 0;
    }
    else if (local_12c < 2) {
      puts("no hash board inserted");
      uVar2 = 0xffffffff;
    }
    else {
      puts("test zhiju only support 1 plug");
      uVar2 = 0xffffffff;
    }
  }
  else {
    puts("platform init failed!");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

