
void set_dhash_acc_control(uint param_1)

{
  FILE *pFVar1;
  uint uVar2;
  int local_14;
  
  local_14 = 10;
  *(uint *)(axi_fpga_addr + 0x100) = param_1;
  if (5 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: set DHASH_ACC_CONTROL is 0x%x\n","znyq7010.c",0x2c2,param_1);
    }
    fclose(pFVar1);
  }
  while ((0 < local_14 && (uVar2 = get_dhash_acc_control(), (param_1 | 0x80) != (uVar2 | 0x80)))) {
    *(uint *)(axi_fpga_addr + 0x100) = param_1;
    local_14 = local_14 + -1;
    usleep(2000);
  }
  if ((local_14 == 0) && (5 < log_level)) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: set DHASH_ACC_CONTROL failed!","znyq7010.c",0x2cc);
    }
    fclose(pFVar1);
  }
  return;
}

