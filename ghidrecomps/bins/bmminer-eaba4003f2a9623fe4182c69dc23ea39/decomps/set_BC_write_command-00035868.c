
void set_BC_write_command(uint value)

{
  int iVar1;
  uint value_local;
  char tmp42 [2048];
  char logstr [1024];
  int wait_count;
  
  wait_count = 0;
  axi_fpga_addr[0x30] = value;
  if ((int)value < 0) {
    do {
      iVar1 = get_BC_write_command();
      if (-1 < iVar1) {
        return;
      }
      cgsleep_ms(1);
      wait_count = wait_count + 1;
    } while (wait_count < 0xbb9);
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      tmp42[0] = s_Error__set_BC_write_command_wait_00076554[0];
      tmp42[1] = s_Error__set_BC_write_command_wait_00076554[1];
      tmp42[2] = s_Error__set_BC_write_command_wait_00076554[2];
      tmp42[3] = s_Error__set_BC_write_command_wait_00076554[3];
      tmp42[4] = s_Error__set_BC_write_command_wait_00076554[4];
      tmp42[5] = s_Error__set_BC_write_command_wait_00076554[5];
      tmp42[6] = s_Error__set_BC_write_command_wait_00076554[6];
      tmp42[7] = s_Error__set_BC_write_command_wait_00076554[7];
      tmp42[8] = s_Error__set_BC_write_command_wait_00076554[8];
      tmp42[9] = s_Error__set_BC_write_command_wait_00076554[9];
      tmp42[10] = s_Error__set_BC_write_command_wait_00076554[10];
      tmp42[11] = s_Error__set_BC_write_command_wait_00076554[11];
      tmp42[12] = s_Error__set_BC_write_command_wait_00076554[12];
      tmp42[13] = s_Error__set_BC_write_command_wait_00076554[13];
      tmp42[14] = s_Error__set_BC_write_command_wait_00076554[14];
      tmp42[15] = s_Error__set_BC_write_command_wait_00076554[15];
      tmp42[16] = s_Error__set_BC_write_command_wait_00076554[16];
      tmp42[17] = s_Error__set_BC_write_command_wait_00076554[17];
      tmp42[18] = s_Error__set_BC_write_command_wait_00076554[18];
      tmp42[19] = s_Error__set_BC_write_command_wait_00076554[19];
      tmp42[20] = s_Error__set_BC_write_command_wait_00076554[20];
      tmp42[21] = s_Error__set_BC_write_command_wait_00076554[21];
      tmp42[22] = s_Error__set_BC_write_command_wait_00076554[22];
      tmp42[23] = s_Error__set_BC_write_command_wait_00076554[23];
      tmp42[24] = s_Error__set_BC_write_command_wait_00076554[24];
      tmp42[25] = s_Error__set_BC_write_command_wait_00076554[25];
      tmp42[26] = s_Error__set_BC_write_command_wait_00076554[26];
      tmp42[27] = s_Error__set_BC_write_command_wait_00076554[27];
      tmp42[28] = s_Error__set_BC_write_command_wait_00076554[28];
      tmp42[29] = s_Error__set_BC_write_command_wait_00076554[29];
      tmp42[30] = s_Error__set_BC_write_command_wait_00076554[30];
      tmp42[31] = s_Error__set_BC_write_command_wait_00076554[31];
      tmp42[32] = s_Error__set_BC_write_command_wait_00076554[32];
      tmp42[33] = s_Error__set_BC_write_command_wait_00076554[33];
      tmp42[34] = s_Error__set_BC_write_command_wait_00076554[34];
      tmp42[35] = s_Error__set_BC_write_command_wait_00076554[35];
      tmp42[36] = s_Error__set_BC_write_command_wait_00076554[36];
      tmp42[37] = s_Error__set_BC_write_command_wait_00076554[37];
      tmp42[38] = s_Error__set_BC_write_command_wait_00076554[38];
      tmp42[39] = s_Error__set_BC_write_command_wait_00076554[39];
      tmp42[40] = s_Error__set_BC_write_command_wait_00076554[40];
      tmp42[41] = s_Error__set_BC_write_command_wait_00076554[41];
      tmp42[42] = s_Error__set_BC_write_command_wait_00076554[42];
      tmp42[43] = s_Error__set_BC_write_command_wait_00076554[43];
      tmp42[44] = s_Error__set_BC_write_command_wait_00076554[44];
      tmp42[45] = s_Error__set_BC_write_command_wait_00076554[45];
      tmp42[46] = s_Error__set_BC_write_command_wait_00076554[46];
      tmp42[47] = s_Error__set_BC_write_command_wait_00076554[47];
      tmp42[48] = s_Error__set_BC_write_command_wait_00076554[48];
      tmp42[49] = s_Error__set_BC_write_command_wait_00076554[49];
      tmp42[50] = s_Error__set_BC_write_command_wait_00076554[50];
      tmp42[51] = s_Error__set_BC_write_command_wait_00076554[51];
      tmp42[52] = s_Error__set_BC_write_command_wait_00076554[52];
      tmp42[53] = s_Error__set_BC_write_command_wait_00076554[53];
      tmp42[54] = s_Error__set_BC_write_command_wait_00076554[54];
      tmp42[55] = s_Error__set_BC_write_command_wait_00076554[55];
      _applog(5,tmp42,false);
    }
  }
  else {
    get_BC_write_command();
  }
  return;
}

