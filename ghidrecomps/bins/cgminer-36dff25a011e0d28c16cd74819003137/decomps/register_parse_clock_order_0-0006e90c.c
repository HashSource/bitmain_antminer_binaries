
void register_parse_clock_order_0(reg_status_t *reg_status)

{
  uint uVar1;
  FILE *pFVar2;
  uint uVar3;
  reg_status_t *reg_status_local;
  clock_order_control0_t reg_value;
  FILE *pFile_9;
  FILE *pFile_8;
  FILE *pFile_7;
  FILE *pFile_6;
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
      fprintf(pFVar2,">> ASIC_REG[0x80] = 0x%08X, Clock Order Control0, %s\n",
              reg_status->reg_response,uVar1 | 0xa0000);
    }
    fclose(pFVar2);
  }
  if (reg_status->found != '\0') {
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%-30s = 0x%X\n","BIT[31:28]  CLK7_SEL",uVar3 >> 0x1c);
      }
      fclose(pFVar2);
    }
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%-30s = 0x%X\n","BIT[27:24]  CLK6_SEL",uVar3 >> 0x18 & 0xf);
      }
      fclose(pFVar2);
    }
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%-30s = 0x%X\n","BIT[23:20]  CLK5_SEL",((uVar3 >> 0x10) << 0x18) >> 0x1c);
      }
      fclose(pFVar2);
    }
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%-30s = 0x%X\n","BIT[19:16]  CLK4_SEL",uVar3 >> 0x10 & 0xf);
      }
      fclose(pFVar2);
    }
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%-30s = 0x%X\n","BIT[15:12]  CLK3_SEL",((uVar3 >> 8) << 0x18) >> 0x1c);
      }
      fclose(pFVar2);
    }
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%-30s = 0x%X\n","BIT[11:8]   CLK2_SEL",uVar3 >> 8 & 0xf);
      }
      fclose(pFVar2);
    }
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%-30s = 0x%X\n","BIT[7:4]    CLK1_SEL",(uVar3 << 0x18) >> 0x1c);
      }
      fclose(pFVar2);
    }
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%-30s = 0x%X\n","BIT[3:0]    CLK0_SEL",uVar3 & 0xf);
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

