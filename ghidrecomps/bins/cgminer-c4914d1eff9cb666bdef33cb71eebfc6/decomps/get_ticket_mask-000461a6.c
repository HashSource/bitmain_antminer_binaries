
/* WARNING: Unknown calling convention */

int get_ticket_mask(void)

{
  FILE *__stream;
  uint uVar1;
  FILE *pFile;
  int ret;
  
  uVar1 = axi_fpga_addr[0x23];
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: TICKET_MASK_FPGA is 0x%x\n","zynq.c",0x1d7,"get_ticket_mask",uVar1
             );
    }
    fclose(__stream);
  }
  return uVar1;
}

