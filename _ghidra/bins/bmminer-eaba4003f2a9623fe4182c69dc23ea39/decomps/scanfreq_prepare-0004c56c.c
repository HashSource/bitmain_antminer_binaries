
/* WARNING: Unknown calling convention */

int scanfreq_prepare(void)

{
  int iVar1;
  char tmp42 [2048];
  int ret;
  
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    builtin_strncpy(tmp42,"scanfreq prepare",0x10);
    tmp42[0x10] = '\n';
    tmp42[0x11] = '\0';
    _applog(5,tmp42,false);
  }
  memset(&scanfreq_info,0,0x84a334);
  scanfreq_info.AsicNum = 0x6c;
  scanfreq_info.CoreNum = 0xd0;
  scanfreq_info.AsicWorkCount = 0x680;
  scanfreq_info.RequiredChainNonce = 0x2be00;
  scanfreq_info.PassNonceRate = 98.0;
  builtin_strncpy(scanfreq_info.workdataPathPrefix,"/mnt/card/minertest64-BM1393/btc-asi",0x24);
  scanfreq_info.workdataPathPrefix[0x24] = 'c';
  scanfreq_info.workdataPathPrefix[0x25] = '-';
  scanfreq_info.workdataPathPrefix[0x26] = '\0';
  builtin_strncpy(scanfreq_info.workdataFilePrefix,"/btc-cor",8);
  scanfreq_info.workdataFilePrefix[8] = 'e';
  scanfreq_info.workdataFilePrefix[9] = '-';
  scanfreq_info.workdataFilePrefix[10] = '\0';
  scanfreq_info.RequiredAsicNonce = scanfreq_info.AsicWorkCount;
  scanfreq_init_freq_level();
  set_nonce2_jobid_phy_addr();
  bitmain_axi_init();
  check_chain();
  iVar1 = scanfreq_get_works();
  if (iVar1 < 0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      builtin_strncpy(tmp42,"scanfreq get works faile",0x18);
      tmp42[0x18] = 'd';
      tmp42[0x19] = '\n';
      tmp42[0x1a] = '\0';
      _applog(5,tmp42,false);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

