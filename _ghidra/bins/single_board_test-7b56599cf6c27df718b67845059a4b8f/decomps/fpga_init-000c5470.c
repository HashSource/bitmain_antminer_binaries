
/* WARNING: Unknown calling convention */

int32_t fpga_init(void)

{
  int32_t iVar1;
  
  if (fpga_inited != 0) {
    return 0;
  }
  iVar1 = fpga_init();
  return iVar1;
}

