
/* WARNING: Unknown calling convention */

void init_fpga(void)

{
  printf("\n--- %s\n",DAT_00025d8c);
  axi_fpga_addr[0x20] = 0x80008000;
  do {
    usleep(10000);
  } while ((int)axi_fpga_addr[0x20] < 0);
  (*(code *)PTR_usleep_00030148)(100000);
  return;
}

