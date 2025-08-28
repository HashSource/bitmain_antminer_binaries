
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
      piVar3 = (int *)&ENABLE_LIMIT_ON_SINGLE_BOARD;
      iVar4 = 0;
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
        __stream = fopen(log_file,"a+");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%s:%d:%s: total_exist_chain_num = %d\n","driver-btm-c5.c",0x2fad,
                  "init_exist_chain_table",total_exist_chain_num);
        }
        fclose(__stream);
        return;
      }
      return;
    }
  } while( true );
}

