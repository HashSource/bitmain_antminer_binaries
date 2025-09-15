
undefined4 get_avg_voltage(void)

{
  FILE *pFVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_s1;
  double dVar6;
  double dVar5;
  
  dVar6 = 0.0;
  if (0 < total_exist_chain_num) {
    puVar2 = exist_chain;
    iVar3 = 0;
    do {
      while( true ) {
        iVar3 = iVar3 + 1;
        pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
        uVar4 = dsPIC33EP16GS202_pic_get_an_voltage2(*puVar2);
        dVar5 = (double)CONCAT44(extraout_s1,uVar4);
        pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
        if (log_level < 4) break;
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: board[%d] voltage: %f\n","power.c",0x235,"get_avg_voltage",
                  *(undefined4 *)puVar2,dVar5);
        }
        puVar2 = (undefined1 *)((int)puVar2 + 4);
        fclose(pFVar1);
        dVar6 = dVar6 + dVar5;
        if (total_exist_chain_num <= iVar3) goto LAB_00041f52;
      }
      puVar2 = (undefined1 *)((int)puVar2 + 4);
      dVar6 = dVar6 + dVar5;
    } while (iVar3 < total_exist_chain_num);
  }
LAB_00041f52:
  uVar4 = SUB84(dVar6 / (double)(longlong)total_exist_chain_num,0);
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: avg voltage: %f\n","power.c",0x23b,"get_avg_voltage");
    }
    fclose(pFVar1);
    return uVar4;
  }
  return uVar4;
}

