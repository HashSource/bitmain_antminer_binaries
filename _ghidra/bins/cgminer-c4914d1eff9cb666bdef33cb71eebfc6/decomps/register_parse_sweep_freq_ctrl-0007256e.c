
void register_parse_sweep_freq_ctrl(core_reg_status_t *core_reg_status)

{
  FILE *pFVar1;
  uint uVar2;
  char *pcVar3;
  core_reg_status_t *core_reg_status_local;
  core_response_t core_response;
  sweep_freq_ctrl_t reg_value;
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
      fprintf(pFVar1,">> core_id[%d], CORE_REG[7] = 0x%04X, Sweep Clock Control, %s\n",uVar2 >> 0x18
              ,uVar2 & 0xffff,pcVar3);
    }
    fclose(pFVar1);
  }
  if (core_reg_status->found != '\0') {
    if (3 < log_level) {
      pFVar1 = fopen(register_file_str,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%-30s = 0x%X\n","BIT[15:8] Reserved",uVar2 >> 8 & 0xff);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      pFVar1 = fopen(register_file_str,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%-30s = 0x%X\n","BIT[7]    SWPF_MODE",(uVar2 << 0x18) >> 0x1f);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      pFVar1 = fopen(register_file_str,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%-30s = 0x%X\n","BIT[6:4]  Reserved",(uVar2 << 0x19) >> 0x1d);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      pFVar1 = fopen(register_file_str,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%-30s = 0x%X\n","BIT[3:0]  CLK_SEL",uVar2 & 0xf);
      }
      fclose(pFVar1);
    }
  }
  return;
}

