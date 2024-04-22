
void register_parse_process_monitor_data(core_reg_status_t *core_reg_status)

{
  FILE *pFVar1;
  uint uVar2;
  char *pcVar3;
  core_reg_status_t *core_reg_status_local;
  core_response_t core_response;
  process_monitor_data_t reg_value;
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
      fprintf(pFVar1,">> core_id[%d], CORE_REG[2] = 0x%04X, Process Monitor Data, %s\n",
              uVar2 >> 0x18,uVar2 & 0xffff,pcVar3);
    }
    fclose(pFVar1);
  }
  if ((core_reg_status->found != '\0') && (3 < log_level)) {
    pFVar1 = fopen(register_file_str,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%-30s = 0x%X\n","BIT[15:0] FREQ_CNT",uVar2 & 0xffff);
    }
    fclose(pFVar1);
  }
  return;
}

