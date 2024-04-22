
void init_exist_chain_table(void)

{
  bool bVar1;
  int iVar2;
  FILE *__stream;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  bVar1 = false;
  iVar2 = 0;
  piVar5 = (int *)(dev + 4);
  iVar6 = total_exist_chain_num;
  do {
    piVar5 = piVar5 + 1;
    if (*piVar5 != 0) {
      iVar4 = 0;
      piVar3 = DAT_000384f8;
      do {
        piVar3 = piVar3 + 1;
        if (*piVar3 == 0) {
          *(int *)(exist_chain + iVar4 * 4) = iVar2;
          break;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 != 0x10);
      iVar6 = iVar6 + 1;
      bVar1 = true;
    }
    iVar2 = iVar2 + 1;
    if (iVar2 == 0x10) {
      if (bVar1) {
        total_exist_chain_num = iVar6;
      }
      if (3 < log_level) {
        __stream = fopen(log_file,(char *)&DAT_0005e760);
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%s:%d:%s: total_exist_chain_num = %d\n","driver-btm-c5.c",0x2fad,
                  DAT_000384fc,total_exist_chain_num);
        }
        (*(code *)PTR_fclose_0007cfe8)(__stream);
        return;
      }
      return;
    }
  } while( true );
}

