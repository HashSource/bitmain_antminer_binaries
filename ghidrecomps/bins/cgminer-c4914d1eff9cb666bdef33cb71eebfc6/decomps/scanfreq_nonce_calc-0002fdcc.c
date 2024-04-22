
void scanfreq_nonce_calc(int chain,uint buf)

{
  uint uVar1;
  FILE *pFVar2;
  uint uVar3;
  uint buf_local;
  int chain_local;
  FILE *pFile_1;
  FILE *pFile;
  uint whose_nonce;
  uint which_core_nonce;
  
  uVar3 = buf & 0xff;
  uVar1 = __udivsi3(buf >> 0x18,dev->addrInterval);
  if ((((chain < 0x10) && (uVar1 < 0x3c)) && (uVar3 < 0xd0)) && (buf != 0)) {
    scanfreq_calc_nonce_info.chain_asic_core_nonce_num[chain][uVar1][uVar3] =
         scanfreq_calc_nonce_info.chain_asic_core_nonce_num[chain][uVar1][uVar3] + 1;
  }
  else {
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: buf [%x] is error!\n","freq_scan.c",0xec,"scanfreq_nonce_calc",buf
               );
      }
      fclose(pFVar2);
    }
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: chain = %d,chip = %d,core = %d\n","freq_scan.c",0xed,
                "scanfreq_nonce_calc",chain,uVar1,uVar3);
      }
      fclose(pFVar2);
    }
  }
  return;
}

