
void nonce_calc(int chain,uint buf)

{
  uint32_t uVar1;
  uint32_t uVar2;
  FILE *pFVar3;
  uint buf_local;
  int chain_local;
  nonce_format_t nonce;
  FILE *pFile_1;
  FILE *pFile;
  uint whose_nonce;
  uint which_core_nonce;
  
  uVar1 = get_core_id((nonce_format_t)buf);
  uVar2 = get_asic_id((nonce_format_t)buf);
  if ((((chain < 0x10) && (uVar2 < 0x30)) && (uVar1 < 0x2a0)) && (buf != 0)) {
    calc_nonce_info.chain_asic_core_nonce_num[chain][uVar2][uVar1] =
         calc_nonce_info.chain_asic_core_nonce_num[chain][uVar2][uVar1] + 1;
  }
  else {
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d:%s: buf [%x] is error!\n","driver-btm-soc.c",0x1194,"nonce_calc",buf);
      }
      fclose(pFVar3);
    }
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d:%s: chain = %d,chip = %d,core = %d\n","driver-btm-soc.c",0x1195,
                "nonce_calc",chain,uVar2,uVar1);
      }
      fclose(pFVar3);
    }
  }
  return;
}

