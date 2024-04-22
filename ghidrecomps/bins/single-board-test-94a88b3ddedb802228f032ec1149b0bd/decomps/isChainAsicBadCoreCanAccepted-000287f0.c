
undefined isChainAsicBadCoreCanAccepted(undefined4 param_1)

{
  int iVar1;
  FILE *__stream;
  undefined local_d;
  int local_c;
  
  local_d = 1;
  for (local_c = 0; local_c < 0x54; local_c = local_c + 1) {
    iVar1 = getChainAsicBadCoreNum(param_1,local_c);
    if ((0 < iVar1) && (3 < log_level)) {
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d: Chain[%d] Chip[%d] has %d bad cores.\n","main.c",0xb39,param_1,
                local_c,iVar1);
      }
      fclose(__stream);
    }
    if (0xe < iVar1) {
      local_d = 0;
    }
  }
  return local_d;
}

