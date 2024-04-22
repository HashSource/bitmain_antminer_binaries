
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void set_nonce2_jobid_phy_addr(void)

{
  char tmp42 [2048];
  sysinfo si;
  
  sysinfo((sysinfo *)&si);
  if (si.totalram < 0x3b9aca01) {
    if (si.totalram < 0x1dcd6501) {
      PHY_MEM_NONCE2_JOBID_ADDRESS = 0xf000000;
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        tmp42[0] = s_Detect_256MB_control_board_of_XI_00077b74[0];
        tmp42[1] = s_Detect_256MB_control_board_of_XI_00077b74[1];
        tmp42[2] = s_Detect_256MB_control_board_of_XI_00077b74[2];
        tmp42[3] = s_Detect_256MB_control_board_of_XI_00077b74[3];
        tmp42[4] = s_Detect_256MB_control_board_of_XI_00077b74[4];
        tmp42[5] = s_Detect_256MB_control_board_of_XI_00077b74[5];
        tmp42[6] = s_Detect_256MB_control_board_of_XI_00077b74[6];
        tmp42[7] = s_Detect_256MB_control_board_of_XI_00077b74[7];
        tmp42[8] = s_Detect_256MB_control_board_of_XI_00077b74[8];
        tmp42[9] = s_Detect_256MB_control_board_of_XI_00077b74[9];
        tmp42[10] = s_Detect_256MB_control_board_of_XI_00077b74[10];
        tmp42[11] = s_Detect_256MB_control_board_of_XI_00077b74[11];
        tmp42[12] = s_Detect_256MB_control_board_of_XI_00077b74[12];
        tmp42[13] = s_Detect_256MB_control_board_of_XI_00077b74[13];
        tmp42[14] = s_Detect_256MB_control_board_of_XI_00077b74[14];
        tmp42[15] = s_Detect_256MB_control_board_of_XI_00077b74[15];
        tmp42[16] = s_Detect_256MB_control_board_of_XI_00077b74[16];
        tmp42[17] = s_Detect_256MB_control_board_of_XI_00077b74[17];
        tmp42[18] = s_Detect_256MB_control_board_of_XI_00077b74[18];
        tmp42[19] = s_Detect_256MB_control_board_of_XI_00077b74[19];
        tmp42[20] = s_Detect_256MB_control_board_of_XI_00077b74[20];
        tmp42[21] = s_Detect_256MB_control_board_of_XI_00077b74[21];
        tmp42[22] = s_Detect_256MB_control_board_of_XI_00077b74[22];
        tmp42[23] = s_Detect_256MB_control_board_of_XI_00077b74[23];
        tmp42[24] = s_Detect_256MB_control_board_of_XI_00077b74[24];
        tmp42[25] = s_Detect_256MB_control_board_of_XI_00077b74[25];
        tmp42[26] = s_Detect_256MB_control_board_of_XI_00077b74[26];
        tmp42[27] = s_Detect_256MB_control_board_of_XI_00077b74[27];
        tmp42[28] = s_Detect_256MB_control_board_of_XI_00077b74[28];
        tmp42[29] = s_Detect_256MB_control_board_of_XI_00077b74[29];
        tmp42[30] = s_Detect_256MB_control_board_of_XI_00077b74[30];
        tmp42[31] = s_Detect_256MB_control_board_of_XI_00077b74[31];
        tmp42[32] = s_Detect_256MB_control_board_of_XI_00077b74[32];
        tmp42[33] = s_Detect_256MB_control_board_of_XI_00077b74[33];
        tmp42[34] = s_Detect_256MB_control_board_of_XI_00077b74[34];
        tmp42[35] = s_Detect_256MB_control_board_of_XI_00077b74[35];
        tmp42._36_2_ = (undefined2)ram0x00077b98;
        _applog(5,tmp42,false);
      }
    }
    else {
      PHY_MEM_NONCE2_JOBID_ADDRESS = 0x1f000000;
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        tmp42[0] = s_Detect_512MB_control_board_of_XI_00077b4c[0];
        tmp42[1] = s_Detect_512MB_control_board_of_XI_00077b4c[1];
        tmp42[2] = s_Detect_512MB_control_board_of_XI_00077b4c[2];
        tmp42[3] = s_Detect_512MB_control_board_of_XI_00077b4c[3];
        tmp42[4] = s_Detect_512MB_control_board_of_XI_00077b4c[4];
        tmp42[5] = s_Detect_512MB_control_board_of_XI_00077b4c[5];
        tmp42[6] = s_Detect_512MB_control_board_of_XI_00077b4c[6];
        tmp42[7] = s_Detect_512MB_control_board_of_XI_00077b4c[7];
        tmp42[8] = s_Detect_512MB_control_board_of_XI_00077b4c[8];
        tmp42[9] = s_Detect_512MB_control_board_of_XI_00077b4c[9];
        tmp42[10] = s_Detect_512MB_control_board_of_XI_00077b4c[10];
        tmp42[11] = s_Detect_512MB_control_board_of_XI_00077b4c[11];
        tmp42[12] = s_Detect_512MB_control_board_of_XI_00077b4c[12];
        tmp42[13] = s_Detect_512MB_control_board_of_XI_00077b4c[13];
        tmp42[14] = s_Detect_512MB_control_board_of_XI_00077b4c[14];
        tmp42[15] = s_Detect_512MB_control_board_of_XI_00077b4c[15];
        tmp42[16] = s_Detect_512MB_control_board_of_XI_00077b4c[16];
        tmp42[17] = s_Detect_512MB_control_board_of_XI_00077b4c[17];
        tmp42[18] = s_Detect_512MB_control_board_of_XI_00077b4c[18];
        tmp42[19] = s_Detect_512MB_control_board_of_XI_00077b4c[19];
        tmp42[20] = s_Detect_512MB_control_board_of_XI_00077b4c[20];
        tmp42[21] = s_Detect_512MB_control_board_of_XI_00077b4c[21];
        tmp42[22] = s_Detect_512MB_control_board_of_XI_00077b4c[22];
        tmp42[23] = s_Detect_512MB_control_board_of_XI_00077b4c[23];
        tmp42[24] = s_Detect_512MB_control_board_of_XI_00077b4c[24];
        tmp42[25] = s_Detect_512MB_control_board_of_XI_00077b4c[25];
        tmp42[26] = s_Detect_512MB_control_board_of_XI_00077b4c[26];
        tmp42[27] = s_Detect_512MB_control_board_of_XI_00077b4c[27];
        tmp42[28] = s_Detect_512MB_control_board_of_XI_00077b4c[28];
        tmp42[29] = s_Detect_512MB_control_board_of_XI_00077b4c[29];
        tmp42[30] = s_Detect_512MB_control_board_of_XI_00077b4c[30];
        tmp42[31] = s_Detect_512MB_control_board_of_XI_00077b4c[31];
        tmp42[32] = s_Detect_512MB_control_board_of_XI_00077b4c[32];
        tmp42[33] = s_Detect_512MB_control_board_of_XI_00077b4c[33];
        tmp42[34] = s_Detect_512MB_control_board_of_XI_00077b4c[34];
        tmp42[35] = s_Detect_512MB_control_board_of_XI_00077b4c[35];
        tmp42._36_2_ = (undefined2)ram0x00077b70;
        _applog(5,tmp42,false);
      }
    }
  }
  else {
    PHY_MEM_NONCE2_JOBID_ADDRESS = 0x3f000000;
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      tmp42[0] = s_Detect_1GB_control_board_of_XILI_00077b28[0];
      tmp42[1] = s_Detect_1GB_control_board_of_XILI_00077b28[1];
      tmp42[2] = s_Detect_1GB_control_board_of_XILI_00077b28[2];
      tmp42[3] = s_Detect_1GB_control_board_of_XILI_00077b28[3];
      tmp42[4] = s_Detect_1GB_control_board_of_XILI_00077b28[4];
      tmp42[5] = s_Detect_1GB_control_board_of_XILI_00077b28[5];
      tmp42[6] = s_Detect_1GB_control_board_of_XILI_00077b28[6];
      tmp42[7] = s_Detect_1GB_control_board_of_XILI_00077b28[7];
      tmp42[8] = s_Detect_1GB_control_board_of_XILI_00077b28[8];
      tmp42[9] = s_Detect_1GB_control_board_of_XILI_00077b28[9];
      tmp42[10] = s_Detect_1GB_control_board_of_XILI_00077b28[10];
      tmp42[11] = s_Detect_1GB_control_board_of_XILI_00077b28[11];
      tmp42[12] = s_Detect_1GB_control_board_of_XILI_00077b28[12];
      tmp42[13] = s_Detect_1GB_control_board_of_XILI_00077b28[13];
      tmp42[14] = s_Detect_1GB_control_board_of_XILI_00077b28[14];
      tmp42[15] = s_Detect_1GB_control_board_of_XILI_00077b28[15];
      tmp42[16] = s_Detect_1GB_control_board_of_XILI_00077b28[16];
      tmp42[17] = s_Detect_1GB_control_board_of_XILI_00077b28[17];
      tmp42[18] = s_Detect_1GB_control_board_of_XILI_00077b28[18];
      tmp42[19] = s_Detect_1GB_control_board_of_XILI_00077b28[19];
      tmp42[20] = s_Detect_1GB_control_board_of_XILI_00077b28[20];
      tmp42[21] = s_Detect_1GB_control_board_of_XILI_00077b28[21];
      tmp42[22] = s_Detect_1GB_control_board_of_XILI_00077b28[22];
      tmp42[23] = s_Detect_1GB_control_board_of_XILI_00077b28[23];
      tmp42[24] = s_Detect_1GB_control_board_of_XILI_00077b28[24];
      tmp42[25] = s_Detect_1GB_control_board_of_XILI_00077b28[25];
      tmp42[26] = s_Detect_1GB_control_board_of_XILI_00077b28[26];
      tmp42[27] = s_Detect_1GB_control_board_of_XILI_00077b28[27];
      tmp42[28] = s_Detect_1GB_control_board_of_XILI_00077b28[28];
      tmp42[29] = s_Detect_1GB_control_board_of_XILI_00077b28[29];
      tmp42[30] = s_Detect_1GB_control_board_of_XILI_00077b28[30];
      tmp42[31] = s_Detect_1GB_control_board_of_XILI_00077b28[31];
      tmp42[32] = s_Detect_1GB_control_board_of_XILI_00077b28[32];
      tmp42[33] = s_Detect_1GB_control_board_of_XILI_00077b28[33];
      tmp42[34] = s_Detect_1GB_control_board_of_XILI_00077b28[34];
      tmp42[35] = s_Detect_1GB_control_board_of_XILI_00077b28[35];
      _applog(5,tmp42,false);
    }
  }
  return;
}

