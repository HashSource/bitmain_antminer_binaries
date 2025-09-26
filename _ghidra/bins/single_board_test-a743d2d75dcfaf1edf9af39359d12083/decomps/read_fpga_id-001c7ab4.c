
/* WARNING: Unknown calling convention */

void read_fpga_id(char *pFpgaID,int len)

{
  uint32_t fpga_chip_id_l;
  uint32_t fpga_chip_id_h;
  
  fpga_chip_id_l = 0;
  fpga_chip_id_h = 0;
  fpga_read(0x1f,&fpga_chip_id_l);
  fpga_read(0x20,&fpga_chip_id_h);
  snprintf(pFpgaID,len,"%08x%08x",fpga_chip_id_h,fpga_chip_id_l);
  return;
}

