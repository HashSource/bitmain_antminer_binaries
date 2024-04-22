
void Nonce_Match_1(int chain,uint buf,uint which_pattern)

{
  uint uVar1;
  FILE *__stream;
  int iVar2;
  uint uVar3;
  SCAN_FREQ_WORK *pSVar4;
  uint which_pattern_local;
  uint buf_local;
  int chain_local;
  FILE *pFile;
  uint whose_nonce;
  uint which_core_nonce;
  
  uVar3 = buf & 0xff;
  uVar1 = __udivsi3(buf >> 0x18,dev->addrInterval);
  if ((uVar1 < 0x100) && (uVar3 < 0x100)) {
    scanfreq_info.asic_nonce_num[chain][uVar1] = scanfreq_info.asic_nonce_num[chain][uVar1] + 1;
    scanfreq_info.asic_core_nonce_num[chain][uVar1][uVar3] =
         scanfreq_info.asic_core_nonce_num[chain][uVar1][uVar3] + 1;
    scanfreq_info.valid_nonce_num[chain] = scanfreq_info.valid_nonce_num[chain] + 1;
    pSVar4 = scanfreq_info.works[uVar1];
    iVar2 = __aeabi_idiv(scanfreq_info.AsicWorkCount,scanfreq_info.CoreNum);
    pSVar4[which_pattern + uVar3 * iVar2].is_nonce_return_back[chain] = 1;
  }
  else if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: %s: buf [%x] is error!\n","freq_scan.c",0x17c,"Nonce_Match_1",
              "Nonce_Match_1",buf);
    }
    fclose(__stream);
  }
  return;
}

