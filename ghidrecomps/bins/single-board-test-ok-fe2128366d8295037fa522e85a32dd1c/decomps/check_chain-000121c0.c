
undefined4 check_chain(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  byte local_9;
  
  printf("\n--- %s\n","check_chain",param_3,0,0);
  cgpu._131820_4_ = 0;
  iVar1 = read_axi_fpga(2);
  if ((((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 4)) || (iVar1 == 8)) {
    for (local_9 = 0; local_9 < 0x10; local_9 = local_9 + 1) {
      chain_info[(uint)local_9 * 2] = 0;
      chain_info[(uint)local_9 * 2 + 1] = 0;
      if ((iVar1 >> local_9 & 1U) == 0) {
        *(undefined4 *)(cgpu + (local_9 + 0x80bc) * 4 + 4) = 0;
      }
      else {
        *(undefined4 *)(cgpu + (local_9 + 0x80bc) * 4 + 4) = 1;
        cgpu._131820_4_ = cgpu._131820_4_ + 1;
        gChain = local_9;
        gI2c = 0;
        chain_info[(uint)local_9 * 2] = local_9;
        chain_info[(uint)local_9 * 2 + 1] = gI2c;
        printf("%s: gChain = %d, gI2c = %d\n","check_chain",(uint)gChain,(uint)gI2c);
      }
    }
    uVar2 = 0;
  }
  else {
    printf("%s: Test zhiju only support 1 plug, but now is 0x%08x\n","check_chain",iVar1);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

