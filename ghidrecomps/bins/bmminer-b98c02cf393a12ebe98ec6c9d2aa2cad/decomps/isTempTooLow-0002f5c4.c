
undefined4 isTempTooLow(void)

{
  int iVar1;
  FILE *pFVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  piVar3 = (int *)(dev + 4);
  iVar4 = dev;
  do {
    piVar3 = piVar3 + 1;
    if (((*piVar3 == 1) && (*(int *)(chain_temp_toolow + iVar5 * 4) == 0)) &&
       (iVar1 = (int)*(short *)(iVar4 + 0x570), 0 < iVar1)) {
      if (*(int *)(lowest_testOK_temp + iVar5 * 4) < 1) {
        if (iVar1 < 0x50) {
          if (3 < log_level) {
            pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"%s:%d:%s: Detect temp too low: Chain[%d] curtemp=%d\n",
                      "driver-btm-c5.c",0xc03,DAT_0002f6ec,iVar5,
                      (int)*(short *)(dev + iVar5 * 0x40 + 0x570));
            }
            fclose(pFVar2);
          }
          return 1;
        }
      }
      else if (iVar1 < *(int *)(lowest_testOK_temp + iVar5 * 4)) {
        if (3 < log_level) {
          pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,
                    "%s:%d:%s: Detect temp too low: Chain[%d] lowest_testOK_temp=%d curtemp=%d\n",
                    "driver-btm-c5.c",0xc0a,DAT_0002f6ec,iVar5,
                    *(undefined4 *)(lowest_testOK_temp + iVar5 * 4),
                    (int)*(short *)(dev + iVar5 * 0x40 + 0x570));
          }
          fclose(pFVar2);
          return 1;
        }
        return 1;
      }
    }
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 0x40;
  } while (iVar5 != 0x10);
  return 0;
}

