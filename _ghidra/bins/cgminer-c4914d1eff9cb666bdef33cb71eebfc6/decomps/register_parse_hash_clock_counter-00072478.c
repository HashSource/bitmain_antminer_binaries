
void register_parse_hash_clock_counter(core_reg_status_t *core_reg_status)

{
  ushort uVar1;
  FILE *pFVar2;
  uint uVar3;
  char *pcVar4;
  core_reg_status_t *core_reg_status_local;
  core_response_t core_response;
  hash_clock_counter_t reg_value;
  FILE *pFile_1;
  FILE *pFile;
  
  uVar3 = core_reg_status->reg_response;
  uVar1 = (ushort)uVar3 & 0xff;
  if (4 < log_level) {
    pFVar2 = fopen(register_file_str,"a+");
    if (pFVar2 != (FILE *)0x0) {
      if (core_reg_status->found == '\0') {
        pcVar4 = "NOT FOUND";
      }
      else {
        pcVar4 = "FOUND";
      }
      fprintf(pFVar2,">> core_id[%d], CORE_REG[6] = 0x%02X, Hash Clock Counter, %s\n",uVar3 >> 0x18,
              (uint)uVar1,pcVar4);
    }
    fclose(pFVar2);
  }
  if ((core_reg_status->found != '\0') && (3 < log_level)) {
    pFVar2 = fopen(register_file_str,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"CLOCK_CNT = 0x%08x freq = %.2f\n",(uint)uVar1,(uint)uVar1 << 1,
              (double)((float)(longlong)(int)((uint)uVar1 << 1) * 6.25));
    }
    fclose(pFVar2);
  }
  return;
}

