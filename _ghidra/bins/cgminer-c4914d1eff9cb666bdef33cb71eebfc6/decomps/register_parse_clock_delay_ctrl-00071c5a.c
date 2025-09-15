
void register_parse_clock_delay_ctrl(core_reg_status_t *core_reg_status)

{
  FILE *pFVar1;
  uint uVar2;
  char *pcVar3;
  core_reg_status_t *core_reg_status_local;
  core_response_t core_response;
  clock_delay_ctrl_t reg_value;
  FILE *pFile_6;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  
  uVar2 = core_reg_status->reg_response;
  if (3 < log_level) {
    pFVar1 = fopen(register_file_str,"a+");
    if (pFVar1 != (FILE *)0x0) {
      if (core_reg_status->found == '\0') {
        pcVar3 = "NOT FOUND";
      }
      else {
        pcVar3 = "FOUND";
      }
      fprintf(pFVar1,">> core_id[%d], CORE_REG[0] = 0x%02X, Clock Delay Ctrl, %s\n",uVar2 >> 0x18,
              uVar2 & 0xff,pcVar3);
    }
    fclose(pFVar1);
  }
  if (core_reg_status->found != '\0') {
    if (3 < log_level) {
      pFVar1 = fopen(register_file_str,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%-30s = 0x%X\n","BIT[7:6]  CCDLY_SEL",(uVar2 << 0x18) >> 0x1e);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      pFVar1 = fopen(register_file_str,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%-30s = 0x%X\n","BIT[5:4]  PWTH_SEL",(uVar2 << 0x1a) >> 0x1e);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      pFVar1 = fopen(register_file_str,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%-30s = 0x%X\n","BIT[3]    HASH_CLKEN",(uVar2 << 0x1c) >> 0x1f);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      pFVar1 = fopen(register_file_str,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%-30s = 0x%X\n","BIT[2]    MMEN",(uVar2 << 0x1d) >> 0x1f);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      pFVar1 = fopen(register_file_str,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%-30s = 0x%X\n","BIT[1]    Reserved",(uVar2 << 0x1e) >> 0x1f);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      pFVar1 = fopen(register_file_str,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%-30s = 0x%X\n","BIT[0]    SWPF_MODE",uVar2 & 1);
      }
      fclose(pFVar1);
    }
  }
  return;
}

