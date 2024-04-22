
/* WARNING: Unknown calling convention */

_Bool scan_freq_is_all_chain_finished(void)

{
  FILE *__stream;
  undefined uVar1;
  bool bVar2;
  FILE *pFile;
  int chain_num;
  int done_num;
  int i;
  
  done_num = 0;
  chain_num = 0;
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] != 0) &&
       (chain_num = chain_num + 1, scanfreq_info.test_done[i] != false)) {
      done_num = done_num + 1;
    }
  }
  if (3 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"\nfinished %d of %d\n",done_num,chain_num);
    }
    fclose(__stream);
  }
  bVar2 = done_num == chain_num;
  if (bVar2) {
    chain_num = 1;
  }
  uVar1 = (undefined)chain_num;
  if (!bVar2) {
    uVar1 = 0;
  }
  return (_Bool)uVar1;
}

