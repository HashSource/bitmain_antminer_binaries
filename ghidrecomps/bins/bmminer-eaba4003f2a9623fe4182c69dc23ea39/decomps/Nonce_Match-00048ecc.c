
void Nonce_Match(int chain,uint buf,uint which_pattern)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  SCAN_FREQ_WORK *pSVar4;
  uint which_pattern_local;
  uint buf_local;
  int chain_local;
  char tmp42 [2048];
  uint whose_nonce;
  uint which_core_nonce;
  
  uVar3 = buf & 0xff;
  uVar1 = __aeabi_uidiv(buf >> 0x18,dev->addrInterval);
  if ((uVar1 < 0x100) && (uVar3 < 0x100)) {
    scanfreq_info.asic_nonce_num[chain][uVar1] = scanfreq_info.asic_nonce_num[chain][uVar1] + 1;
    scanfreq_info.asic_core_nonce_num[chain][uVar1][uVar3] =
         scanfreq_info.asic_core_nonce_num[chain][uVar1][uVar3] + 1;
    scanfreq_info.valid_nonce_num[chain] = scanfreq_info.valid_nonce_num[chain] + 1;
    pSVar4 = scanfreq_info.works[uVar1];
    iVar2 = __aeabi_idiv(scanfreq_info.AsicWorkCount,scanfreq_info.CoreNum);
    pSVar4[uVar3 * iVar2 + which_pattern].is_nonce_return_back[chain] = 1;
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"%s: buf [%x] is error!\n","Nonce_Match",buf);
    _applog(5,tmp42,false);
  }
  return;
}

