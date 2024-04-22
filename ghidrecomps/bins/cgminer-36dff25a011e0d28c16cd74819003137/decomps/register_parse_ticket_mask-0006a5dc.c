
void register_parse_ticket_mask(reg_status_t *reg_status)

{
  uint uVar1;
  FILE *pFVar2;
  uint uVar3;
  reg_status_t *reg_status_local;
  ticket_mask_t reg_value;
  FILE *pFile_5;
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
      fprintf(pFVar2,">> ASIC_REG[0x14] = 0x%08X, Ticket Mask, %s\n",reg_status->reg_response,
              uVar1 | 0xa0000);
    }
    fclose(pFVar2);
  }
  if (reg_status->found != '\0') {
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%-30s = 0x%X\n","BIT[31:24]  TM3",uVar3 >> 0x18);
      }
      fclose(pFVar2);
    }
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%-30s = 0x%X\n","BIT[23:16]  TM2",uVar3 >> 0x10 & 0xff);
      }
      fclose(pFVar2);
    }
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%-30s = 0x%X\n","BIT[15:8]   TM1",uVar3 >> 8 & 0xff);
      }
      fclose(pFVar2);
    }
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%-30s = 0x%X\n","BIT[7:0]    TM0",uVar3 & 0xff);
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

