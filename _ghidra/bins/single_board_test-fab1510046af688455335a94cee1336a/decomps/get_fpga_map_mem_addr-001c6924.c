
/* WARNING: Unknown calling convention */

uint32_t * get_fpga_map_mem_addr(void)

{
  int32_t iVar1;
  
  if ((fpga_inited == 0) && (iVar1 = fpga_init(), iVar1 != 0)) {
    return (uint32_t *)0x0;
  }
  return fpga_mem_addr_hal;
}

