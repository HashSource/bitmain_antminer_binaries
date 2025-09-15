
int get_bt8d_chip_divider(int baud)

{
  int iVar1;
  int baud_local;
  int base_clk;
  
  base_clk = 25000000;
  if (3000000 < baud) {
    base_clk = 400000000;
  }
  iVar1 = __aeabi_idiv(base_clk,baud << 3);
  return iVar1 + -1;
}

