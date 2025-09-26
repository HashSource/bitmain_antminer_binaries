
/* WARNING: Unknown calling convention */

int32_t fpga_write(uint32_t address,uint32_t val)

{
  int32_t iVar1;
  uint32_t uVar2;
  
  if ((fpga_inited == 0) && (iVar1 = fpga_init(), iVar1 != 0)) {
    return -1;
  }
  if (platform_is_t9 == 0) {
    uVar2 = v9_fpga_map[address];
  }
  else {
    uVar2 = t9_fpga_map[address];
  }
  axi_fpga_addr[uVar2] = val;
  return 0;
}

