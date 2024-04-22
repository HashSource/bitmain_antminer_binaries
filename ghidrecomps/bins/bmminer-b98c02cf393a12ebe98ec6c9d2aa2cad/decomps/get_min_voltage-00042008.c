
double get_min_voltage(void)

{
  FILE *pFVar1;
  undefined1 *puVar2;
  int iVar3;
  double dVar4;
  double dVar5;
  
  if (total_exist_chain_num < 1) {
    dVar5 = 20.0;
  }
  else {
    puVar2 = exist_chain;
    iVar3 = 0;
    dVar5 = 20.0;
    do {
      iVar3 = iVar3 + 1;
      pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
      dVar4 = (double)dsPIC33EP16GS202_pic_get_an_voltage2(*puVar2);
      pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
      if (3 < log_level) {
        pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: board[%d] voltage: %f\n","power.c",0x24b,DAT_00042134,
                  *(undefined4 *)puVar2,dVar4);
        }
        fclose(pFVar1);
      }
      puVar2 = (undefined1 *)((int)puVar2 + 4);
      if ((int)((uint)(dVar4 < dVar5) << 0x1f) < 0) {
        dVar5 = dVar4;
      }
    } while (iVar3 < total_exist_chain_num);
  }
  if (log_level < 4) {
    return dVar5;
  }
  pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
  if (pFVar1 != (FILE *)0x0) {
    fprintf(pFVar1,"%s:%d:%s: min voltage: %f\n","power.c",0x251,DAT_00042134);
  }
  fclose(pFVar1);
  return dVar5;
}

