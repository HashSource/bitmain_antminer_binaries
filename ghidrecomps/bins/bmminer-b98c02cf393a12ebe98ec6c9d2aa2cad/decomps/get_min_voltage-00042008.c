
undefined4 get_min_voltage(void)

{
  FILE *pFVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_s1;
  double dVar6;
  double dVar5;
  
  if (total_exist_chain_num < 1) {
    dVar6 = 0.0;
  }
  else {
    puVar2 = exist_chain;
    iVar3 = 0;
    dVar6 = 20.0;
    do {
      iVar3 = iVar3 + 1;
      pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
      uVar4 = dsPIC33EP16GS202_pic_get_an_voltage2(*puVar2);
      dVar5 = (double)CONCAT44(extraout_s1,uVar4);
      pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: board[%d] voltage: %f\n","power.c",0x24b,"get_min_voltage",
                  *(undefined4 *)puVar2,dVar5);
        }
        fclose(pFVar1);
      }
      puVar2 = (undefined1 *)((int)puVar2 + 4);
      if ((int)((uint)(dVar5 < dVar6) << 0x1f) < 0) {
        dVar6 = dVar5;
      }
    } while (iVar3 < total_exist_chain_num);
  }
  if (log_level < 4) {
    return SUB84(dVar6,0);
  }
  pFVar1 = fopen(log_file,"a+");
  if (pFVar1 != (FILE *)0x0) {
    fprintf(pFVar1,"%s:%d:%s: min voltage: %f\n","power.c",0x251,"get_min_voltage");
  }
  fclose(pFVar1);
  return SUB84(dVar6,0);
}

