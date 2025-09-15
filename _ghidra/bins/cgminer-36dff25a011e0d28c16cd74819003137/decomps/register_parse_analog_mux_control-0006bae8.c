
void register_parse_analog_mux_control(reg_status_t *reg_status)

{
  uint uVar1;
  FILE *pFVar2;
  uint uVar3;
  reg_status_t *reg_status_local;
  analog_mux_control_t reg_value;
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
      fprintf(pFVar2,">> ASIC_REG[0x54] = 0x%08X, Analog Mux Control, %s\n",reg_status->reg_response
              ,uVar1 | 0xa0000);
    }
    fclose(pFVar2);
  }
  if (reg_status->found != '\0') {
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%-30s = 0x%X\n","BIT[31:3]  Reserved",uVar3 >> 3);
      }
      fclose(pFVar2);
    }
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%-30s = 0x%X\n","BIT[2:0]   DIODE_VDD_MUX_SEL",uVar3 & 7);
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

