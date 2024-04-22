
void register_parse_core_enable(core_reg_status_t *core_reg_status)

{
  FILE *pFVar1;
  uint uVar2;
  char *pcVar3;
  core_reg_status_t *core_reg_status_local;
  core_response_t core_response;
  core_enable_t reg_value;
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
      fprintf(pFVar1,">> core_id[%d], CORE_REG[4] = 0x%04X, Core Enable, %s\n",uVar2 >> 0x18,
              uVar2 & 0xff,pcVar3);
    }
    fclose(pFVar1);
  }
  if ((core_reg_status->found != '\0') && (3 < log_level)) {
    pFVar1 = fopen(register_file_str,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%-30s = 0x%X\n","BIT[7:0]  CORE_EN_I",uVar2 & 0xff);
    }
    fclose(pFVar1);
  }
  return;
}

