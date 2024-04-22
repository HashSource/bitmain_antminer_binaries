
undefined4 check_chain(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  char local_9;
  
  printf("\n--- %s\n","check_chain",param_3,0,0);
  cgpu._131820_4_ = 0;
  uVar1 = read_axi_fpga(2);
  if ((((uVar1 == 1) || (uVar1 == 2)) || (uVar1 == 4)) || (uVar1 == 8)) {
    local_9 = '\0';
    while (local_9 == '\0') {
      chain_info._0_1_ = 0;
      chain_info._1_1_ = 0;
      if ((uVar1 & 1) == 0) {
        cgpu._131828_4_ = 0;
      }
      else {
        cgpu._131828_4_ = 1;
        cgpu._131820_4_ = cgpu._131820_4_ + 1;
        gChain_exist = 1;
        gChain_fd = 0;
        gChain = local_9;
        gI2c = 0;
        chain_info._0_1_ = 0;
        chain_info._1_1_ = 0;
        printf("%s: gChain = %d, gI2c = %d\n","check_chain",0,0);
      }
      local_9 = '\x01';
    }
    uVar2 = 0;
  }
  else {
    printf("%s: Test zhiju only support 1 plug, but now is 0x%08x\n","check_chain",uVar1);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

