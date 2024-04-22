
void setChainTempTooLowFlag(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  FILE *local_2c;
  
  piVar4 = DAT_0002f854 + 0x10;
  iVar2 = 0;
  puVar3 = DAT_0002f854;
  do {
    iVar1 = dev;
    *puVar3 = 0;
    if (*(int *)(iVar1 + (iVar2 + 2) * 4) == 1) {
      iVar5 = iVar2 + 0x12d;
      iVar1 = (int)*(short *)(iVar1 + iVar5 * 8);
      if (0 < iVar1) {
        if (*piVar4 < 1) {
          if (iVar1 < 0x50) {
            if (3 < log_level) {
              local_2c = fopen(log_file,(char *)&DAT_0005e760);
              if (local_2c != (FILE *)0x0) {
                fprintf(local_2c,"%s:%d:%s: Detect Chain[%d] temp too low, will ignore: temp=%d\n",
                        "driver-btm-c5.c",0xc3b,DAT_0002f858,iVar2,(int)*(short *)(dev + iVar5 * 8))
                ;
              }
              goto LAB_0002f84c;
            }
            goto LAB_0002f7ae;
          }
        }
        else if (iVar1 < *piVar4) {
          if (3 < log_level) {
            local_2c = fopen(log_file,(char *)&DAT_0005e760);
            if (local_2c != (FILE *)0x0) {
              fprintf(local_2c,
                      "%s:%d:%s: Detect Chain[%d] temp too low, will ignore: temp=%d < %d\n",
                      "driver-btm-c5.c",0xc43,DAT_0002f858,iVar2,(int)*(short *)(dev + iVar5 * 8),
                      *piVar4);
            }
LAB_0002f84c:
            fclose(local_2c);
          }
LAB_0002f7ae:
          *puVar3 = 1;
        }
      }
    }
    piVar4 = piVar4 + 1;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + 1;
    if (iVar2 == 0x10) {
      CheckChainTempTooLowFlag();
      return;
    }
  } while( true );
}

