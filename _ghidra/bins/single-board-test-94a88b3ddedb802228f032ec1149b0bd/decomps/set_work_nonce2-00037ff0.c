
void set_work_nonce2(undefined4 *param_1)

{
  undefined4 local_14;
  undefined4 local_10;
  FILE *local_c;
  
  local_14 = 0;
  local_10 = 0;
  *(undefined4 *)(axi_fpga_addr + 0x108) = *param_1;
  *(undefined4 *)(axi_fpga_addr + 0x10c) = param_1[1];
  if (5 < log_level) {
    local_c = fopen(log_file,"a+");
    if (local_c != (FILE *)0x0) {
      fprintf(local_c,"%s:%d: set WORK_NONCE_2 value[0]: 0x%x, value[1]: 0x%x\n","znyq7010.c",0x293,
              *param_1,param_1[1]);
    }
    fclose(local_c);
  }
  get_work_nonce2(&local_14);
  return;
}

