
void register_parse_core_error(reg_status_t *reg_status)

{
  uint uVar1;
  FILE *pFVar2;
  uint uVar3;
  reg_status_t *reg_status_local;
  core_response_t core_response;
  core_error_t reg_value;
  FILE *pFile_4;
  FILE *pFile_3;
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
      fprintf(pFVar2,">> core_id[%d], CORE_REG[3] = 0x%02X, Core Error, %s\n",uVar3 >> 0x10,
              uVar3 & 0xff,uVar1 | 0xa0000);
    }
    fclose(pFVar2);
  }
  if (reg_status->found != '\0') {
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%-30s = 0x%X\n","BIT[7:5]  Reserved",(uVar3 << 0x18) >> 0x1d);
      }
      fclose(pFVar2);
    }
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%-30s = 0x%X\n","BIT[4]    INI_NONCE_ERR",(uVar3 << 0x1b) >> 0x1f);
      }
      fclose(pFVar2);
    }
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%-30s = 0x%X\n","BIT[3:0]  CMD_ERR_CNT",uVar3 & 0xf);
      }
      fclose(pFVar2);
    }
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

