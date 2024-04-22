
void sweep_freq_set_column_freq_from_minfreq(int chain,int column)

{
  FILE *pFVar1;
  uint uVar2;
  int iVar3;
  int column_local;
  int chain_local;
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile;
  int freq_step;
  int init_freq;
  int chip_freq;
  int chip;
  int steps;
  int step;
  int freq_tmp;
  int row;
  
  iVar3 = scanfreq_info.freq_step * (uint)scanfreq_info.domain_freq_level[chain][column] +
          scanfreq_info.base_freq[chain];
  steps = __aeabi_idiv(iVar3 + -0x96,0x19);
  if (steps * 0x19 + 0x96 < iVar3) {
    steps = steps + 1;
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"chain %d set column %d freq %dM\n",chain,column,iVar3);
    }
    fclose(pFVar1);
  }
  for (step = 0; step < steps; step = step + 1) {
    freq_tmp = (step + 1) * 0x19 + 0x96;
    if (iVar3 < freq_tmp) {
      freq_tmp = iVar3;
    }
    for (row = 0; row < 6; row = row + 1) {
      uVar2 = get_physical_chip_no(row,column);
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"[chip%d %d] ",uVar2,freq_tmp);
        }
        fclose(pFVar1);
      }
      scan_freq_set_freq_by_chip
                ((uint8_t)chain,(uint8_t)((uVar2 & 0xff) << 2),(float)(longlong)freq_tmp);
    }
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fputc(10,pFVar1);
      }
      fclose(pFVar1);
    }
  }
  return;
}

