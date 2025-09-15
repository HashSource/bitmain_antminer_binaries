
bool isChainSingleAsicBadCoreCanAccepted(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  FILE *__stream;
  
  iVar1 = getChainAsicBadCoreNum(param_1,param_2);
  if ((0 < iVar1) && (3 < log_level)) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: Chain[%d] Chip[%d] has %d bad cores.\n","main.c",0xb4b,param_1,
              param_2,iVar1);
    }
    fclose(__stream);
  }
  return iVar1 < 0xf;
}

