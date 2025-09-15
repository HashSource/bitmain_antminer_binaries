
void read_fpga_id(char *pFpgaID)

{
  char *pFpgaID_local;
  uint fpga_chip_id_h;
  uint fpga_chip_id_l;
  
  sprintf(pFpgaID,"%08x%08x",axi_fpga_addr[0x3d],axi_fpga_addr[0x3c]);
  return;
}

