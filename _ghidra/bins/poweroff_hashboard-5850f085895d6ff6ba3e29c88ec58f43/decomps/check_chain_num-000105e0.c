
int check_chain_num(void)

{
  int iVar1;
  int local_10;
  uint local_c;
  
  local_10 = 0;
  iVar1 = *(int *)(axi_fpga_addr + 8);
  if (iVar1 < 0) {
    local_10 = 0;
  }
  else {
    for (local_c = 0; (int)local_c < 0x10; local_c = local_c + 1) {
      if ((iVar1 >> (local_c & 0xff) & 1U) == 0) {
        *(undefined4 *)(chain_list + local_c * 4) = 0;
      }
      else {
        *(undefined4 *)(chain_list + local_c * 4) = 1;
        printf("chain[%d] ",local_c);
        local_10 = local_10 + 1;
      }
    }
    printf("found, %d chain total\n",local_10);
  }
  return local_10;
}

