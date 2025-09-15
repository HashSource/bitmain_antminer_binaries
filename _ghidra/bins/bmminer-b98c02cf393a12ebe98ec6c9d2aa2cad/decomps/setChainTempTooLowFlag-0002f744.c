
void setChainTempTooLowFlag(void)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  FILE *local_2c;
  
  puVar3 = chain_temp_toolow;
  puVar4 = lowest_testOK_temp;
  iVar2 = 0;
  do {
    iVar1 = dev;
    *(undefined4 *)puVar3 = 0;
    if (*(int *)(iVar1 + (iVar2 + 2) * 4) == 1) {
      iVar5 = iVar2 + 0x12d;
      iVar1 = (int)*(short *)(iVar1 + iVar5 * 8);
      if (0 < iVar1) {
        if (*(int *)puVar4 < 1) {
          if (iVar1 < 0x50) {
            if (3 < log_level) {
              local_2c = fopen(log_file,"a+");
              if (local_2c != (FILE *)0x0) {
                fprintf(local_2c,"%s:%d:%s: Detect Chain[%d] temp too low, will ignore: temp=%d\n",
                        "driver-btm-c5.c",0xc3b,"setChainTempTooLowFlag",iVar2,
                        (int)*(short *)(dev + iVar5 * 8));
              }
              goto LAB_0002f84c;
            }
            goto LAB_0002f7ae;
          }
        }
        else if (iVar1 < *(int *)puVar4) {
          if (3 < log_level) {
            local_2c = fopen(log_file,"a+");
            if (local_2c != (FILE *)0x0) {
              fprintf(local_2c,
                      "%s:%d:%s: Detect Chain[%d] temp too low, will ignore: temp=%d < %d\n",
                      "driver-btm-c5.c",0xc43,"setChainTempTooLowFlag",iVar2,
                      (int)*(short *)(dev + iVar5 * 8),*(int *)puVar4);
            }
LAB_0002f84c:
            fclose(local_2c);
          }
LAB_0002f7ae:
          *(undefined4 *)puVar3 = 1;
        }
      }
    }
    puVar4 = (undefined1 *)((int)puVar4 + 4);
    puVar3 = (undefined1 *)((int)puVar3 + 4);
    iVar2 = iVar2 + 1;
    if (iVar2 == 0x10) {
      CheckChainTempTooLowFlag();
      return;
    }
  } while( true );
}

