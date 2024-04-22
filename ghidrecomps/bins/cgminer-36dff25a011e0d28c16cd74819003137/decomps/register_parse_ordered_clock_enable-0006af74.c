
void register_parse_ordered_clock_enable(reg_status_t *reg_status)

{
  uint uVar1;
  FILE *pFVar2;
  uint uVar3;
  reg_status_t *reg_status_local;
  ordered_clock_enable_t reg_value;
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
      fprintf(pFVar2,">> ASIC_REG[0x20] = 0x%08X, Ordered Clock Enable, %s\n",
              reg_status->reg_response,uVar1 | 0xa0000);
    }
    fclose(pFVar2);
  }
  if (reg_status->found != '\0') {
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%-30s = 0x%X\n","BIT[31:16]  Reserved",uVar3 >> 0x10);
      }
      fclose(pFVar2);
    }
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%-30s = 0x%X\n","BIT[15:0]   CLKEN",uVar3 & 0xffff);
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

