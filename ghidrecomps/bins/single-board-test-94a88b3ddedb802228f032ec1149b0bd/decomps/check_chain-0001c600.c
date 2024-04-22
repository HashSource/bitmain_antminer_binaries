
void check_chain(void)

{
  int iVar1;
  FILE *pFVar2;
  uint local_c;
  
  cgpu._2562260_4_ = 0;
  iVar1 = get_hash_on_plug();
  if (3 < log_level) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d: get PLUG ON=0x%08x\n","driver-bitmain.c",0x755,iVar1);
    }
    fclose(pFVar2);
  }
  if (iVar1 < 0) {
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d: %s: get_hash_on_plug functions error\n","driver-bitmain.c",0x759,
                "check_chain");
      }
      fclose(pFVar2);
    }
  }
  else {
    for (local_c = 0; (int)local_c < 0x10; local_c = local_c + 1) {
      if ((iVar1 >> (local_c & 0xff) & 1U) == 0) {
        *(undefined4 *)(cgpu + (local_c + 0x9c638) * 4) = 0;
      }
      else {
        *(undefined4 *)(cgpu + (local_c + 0x9c638) * 4) = 1;
        cgpu._2562260_4_ = cgpu._2562260_4_ + 1;
        if (3 < log_level) {
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d: Find hashboard on Chain[%d]\n","driver-bitmain.c",0x79b,local_c);
          }
          fclose(pFVar2);
        }
      }
    }
  }
  return;
}

