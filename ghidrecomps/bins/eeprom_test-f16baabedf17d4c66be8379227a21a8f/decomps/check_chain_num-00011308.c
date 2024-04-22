
/* WARNING: Unknown calling convention */

int check_chain_num(void)

{
  uint uVar1;
  int ret;
  int chain_num;
  int i;
  
  chain_num = 0;
  uVar1 = axi_fpga_addr[2];
  if ((int)uVar1 < 0) {
    chain_num = 0;
  }
  else {
    for (i = 0; i < 0x10; i = i + 1) {
      if (((int)uVar1 >> (i & 0xffU) & 1U) == 0) {
        chain_list[i] = 0;
      }
      else {
        chain_list[i] = 1;
        printf("chain[%d] ",i);
        chain_num = chain_num + 1;
      }
    }
    printf("found, %d chain total\n",chain_num);
  }
  return chain_num;
}

