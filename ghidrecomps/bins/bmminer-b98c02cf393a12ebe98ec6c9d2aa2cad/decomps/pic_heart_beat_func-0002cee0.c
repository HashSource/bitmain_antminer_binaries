
void pic_heart_beat_func(void)

{
  int iVar1;
  FILE *pFVar2;
  uint uVar3;
  int *piVar4;
  int local_68 [17];
  
  memset(local_68,0,0x40);
  do {
    piVar4 = local_68;
    uVar3 = 0;
LAB_0002cf2e:
    do {
      if (*(int *)(dev + (uVar3 + 2) * 4) != 0) {
        pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
        cgsleep_ms(10);
        iVar1 = dsPIC33EP16GS202_pic_heart_beat(uVar3 & 0xff);
        if (iVar1 == 1) {
          *piVar4 = 0;
          pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
        }
        else {
          iVar1 = *piVar4 + 1;
          *piVar4 = iVar1;
          if (1 < log_level) {
            pFVar2 = fopen(log_file,"a+");
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"%s:%d:%s: chain[%d] heart beat fail %d times.\n","driver-btm-c5.c",
                      0x2641,"pic_heart_beat_func",uVar3,iVar1);
            }
            fclose(pFVar2);
          }
          pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
          if (6 < iVar1) {
            if (1 < log_level) {
              pFVar2 = fopen(log_file,"a+");
              if (pFVar2 != (FILE *)0x0) {
                fprintf(pFVar2,"%s:%d:%s: chain[%d] is dead, rebooting...\n","driver-btm-c5.c",
                        0x2647,"pic_heart_beat_func",uVar3);
              }
              fclose(pFVar2);
            }
            uVar3 = uVar3 + 1;
            system("sync");
            piVar4 = piVar4 + 1;
            sleep(5);
            system("reboot");
            if (uVar3 == 0x10) break;
            goto LAB_0002cf2e;
          }
        }
      }
      uVar3 = uVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar3 != 0x10);
    sleep(10);
  } while( true );
}

