
void set_BC_command_buffer(undefined4 *param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  FILE *local_c;
  
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  *(undefined4 *)(axi_fpga_addr + 0xc4) = *param_1;
  *(undefined4 *)(axi_fpga_addr + 200) = param_1[1];
  *(undefined4 *)(axi_fpga_addr + 0xcc) = param_1[2];
  if (7 < log_level) {
    local_c = fopen(log_file,"a+");
    if (local_c != (FILE *)0x0) {
      fprintf(local_c,
              "%s:%d: set BC_COMMAND_BUFFER value[0]: 0x%x, value[1]: 0x%x, value[2]: 0x%x\n",
              "znyq7010.c",0x1c3,*param_1,param_1[1],param_1[2]);
    }
    fclose(local_c);
  }
  get_BC_command_buffer(&local_1c);
  return;
}

