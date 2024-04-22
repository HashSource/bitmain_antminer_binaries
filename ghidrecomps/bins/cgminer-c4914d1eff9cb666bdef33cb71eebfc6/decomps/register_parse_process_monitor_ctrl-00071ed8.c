
void register_parse_process_monitor_ctrl(core_reg_status_t *core_reg_status)

{
  FILE *pFVar1;
  uint uVar2;
  char *pcVar3;
  core_reg_status_t *core_reg_status_local;
  core_response_t core_response;
  process_monitor_ctrl_t reg_value;
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
      fprintf(pFVar1,">> core_id[%d], CORE_REG[1] = 0x%02X, Process Monitor Ctrl, %s\n",
              uVar2 >> 0x18,uVar2 & 0xff,pcVar3);
    }
    fclose(pFVar1);
  }
  if (core_reg_status->found != '\0') {
    if (3 < log_level) {
      pFVar1 = fopen(register_file_str,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%-30s = 0x%X\n","BIT[7:3]  Reserved",(uVar2 << 0x18) >> 0x1b);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      pFVar1 = fopen(register_file_str,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%-30s = 0x%X\n","BIT[2]    PM_START",(uVar2 << 0x1d) >> 0x1f);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      pFVar1 = fopen(register_file_str,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%-30s = 0x%X\n","BIT[1:0]  PM_SEL",uVar2 & 3);
      }
      fclose(pFVar1);
    }
  }
  return;
}

