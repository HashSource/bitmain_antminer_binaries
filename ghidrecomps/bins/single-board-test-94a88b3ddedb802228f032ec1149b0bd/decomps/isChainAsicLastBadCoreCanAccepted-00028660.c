
undefined isChainAsicLastBadCoreCanAccepted(int param_1)

{
  int iVar1;
  FILE *__stream;
  undefined local_d;
  int local_c;
  
  local_d = 1;
  if ((*(int *)(Fmax + param_1 * 4) < 0x56) || (0x379 < *(int *)(chain_vol_value + param_1 * 4))) {
    for (local_c = 0; local_c < 0x54; local_c = local_c + 1) {
      iVar1 = getChainAsicLastBadCoreNum(param_1,local_c);
      if ((0 < iVar1) && (3 < log_level)) {
        __stream = fopen(log_file,"a+");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%s:%d: Chain[%d] Chip[%d] has %d bad cores.\n","main.c",0xb09,param_1,
                  local_c,iVar1);
        }
        fclose(__stream);
      }
      if (0xe < iVar1) {
        local_d = 0;
      }
    }
  }
  else {
    local_d = 0;
  }
  return local_d;
}

