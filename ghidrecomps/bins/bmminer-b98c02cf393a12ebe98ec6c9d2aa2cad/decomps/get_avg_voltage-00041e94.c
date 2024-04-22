
double get_avg_voltage(void)

{
  longlong lVar1;
  FILE *pFVar2;
  undefined1 *puVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  
  dVar6 = DAT_00041fd0;
  if (0 < total_exist_chain_num) {
    puVar3 = exist_chain;
    iVar4 = 0;
    do {
      while( true ) {
        iVar4 = iVar4 + 1;
        pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
        dVar5 = (double)dsPIC33EP16GS202_pic_get_an_voltage2(*puVar3);
        pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
        if (log_level < 4) break;
        pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: board[%d] voltage: %f\n","power.c",0x235,DAT_00041fd8,
                  *(undefined4 *)puVar3,dVar5);
        }
        puVar3 = (undefined1 *)((int)puVar3 + 4);
        fclose(pFVar2);
        dVar6 = dVar6 + dVar5;
        if (total_exist_chain_num <= iVar4) goto LAB_00041f52;
      }
      puVar3 = (undefined1 *)((int)puVar3 + 4);
      dVar6 = dVar6 + dVar5;
    } while (iVar4 < total_exist_chain_num);
  }
LAB_00041f52:
  lVar1 = (longlong)total_exist_chain_num;
  if (3 < log_level) {
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: avg voltage: %f\n","power.c",0x23b,DAT_00041fd8);
    }
    fclose(pFVar2);
    return dVar6 / (double)lVar1;
  }
  return dVar6 / (double)lVar1;
}

