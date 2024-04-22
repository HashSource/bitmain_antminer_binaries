
void register_parse_hash_clock_counter(reg_status_t *reg_status)

{
  uint uVar1;
  FILE *pFVar2;
  uint uVar3;
  reg_status_t *reg_status_local;
  core_response_t core_response;
  hash_clock_counter_t reg_value;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  
  uVar3 = reg_status->reg_response;
  if (3 < log_level) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      if (reg_status->found == '\0') {
        uVar1 = 0x8d14;
      }
      else {
        uVar1 = 0x8d0c;
      }
      fprintf(pFVar2,">> core_id[%d], CORE_REG[6] = 0x%02X, Hash Clock Counter, %s\n",uVar3 >> 0x10,
              uVar3 & 0xff,uVar1 | 0xa0000);
    }
    fclose(pFVar2);
  }
  if ((reg_status->found != '\0') && (3 < log_level)) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%-30s = 0x%X\n","BIT[7:0]  CLOCK_CNT",uVar3 & 0xff);
    }
    fclose(pFVar2);
  }
  if (3 < log_level) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fputc(10,pFVar2);
    }
    fclose(pFVar2);
  }
  return;
}

