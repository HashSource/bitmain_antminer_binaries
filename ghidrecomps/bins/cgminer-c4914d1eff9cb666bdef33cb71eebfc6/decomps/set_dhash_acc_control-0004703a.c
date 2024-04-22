
void set_dhash_acc_control(uint value)

{
  FILE *pFVar1;
  uint uVar2;
  uint value_local;
  FILE *pFile_1;
  FILE *pFile;
  int a;
  
  a = 10;
  axi_fpga_addr[0x40] = value;
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: set DHASH_ACC_CONTROL is 0x%x\n","zynq.c",0x2bf,
              "set_dhash_acc_control",value);
    }
    fclose(pFVar1);
  }
  while ((0 < a && (uVar2 = get_dhash_acc_control(), (value | 0x80) != (uVar2 | 0x80)))) {
    axi_fpga_addr[0x40] = value;
    a = a + -1;
    cgsleep_ms(2);
  }
  if ((a == 0) && (4 < log_level)) {
    print_crt_time_to_file(log_file,4);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: set DHASH_ACC_CONTROL failed!","zynq.c",0x2c9,
              "set_dhash_acc_control");
    }
    fclose(pFVar1);
  }
  return;
}

