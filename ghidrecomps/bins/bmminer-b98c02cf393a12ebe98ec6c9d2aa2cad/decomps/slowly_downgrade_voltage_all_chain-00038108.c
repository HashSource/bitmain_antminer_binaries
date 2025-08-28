
void slowly_downgrade_voltage_all_chain(byte *param_1)

{
  bool bVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  FILE *pFVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  
  do {
    uVar6 = 0;
    pbVar7 = param_1;
    bVar3 = false;
    do {
      while (bVar1 = bVar3, *(int *)(dev + (uVar6 + 2) * 4) != 1) {
LAB_00038142:
        uVar6 = uVar6 + 1;
        pbVar7 = pbVar7 + 1;
        bVar3 = bVar1;
        if (uVar6 == 0x10) goto LAB_0003826e;
      }
      if (5 < log_level) {
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"%s:%d:%s: vol_list[%d] = %d\n","driver-btm-c5.c",0x2f28,
                  "slowly_downgrade_voltage_all_chain",uVar6,(uint)*pbVar7);
        }
        fclose(pFVar5);
      }
      iVar4 = write_EEPROM_iic(1,1,0x90,uVar6 & 0xff,0);
      iVar2 = (int)(longlong)(((364.0704 / ((double)*pbVar7 + 30.72) + 32.79) * 100.0) / 4.75) / 10;
      iVar4 = ((int)(longlong)
                    (((364.0704 / ((double)(longlong)iVar4 + 30.72) + 32.79) * 100.0) / 4.75) / 10)
              * 10;
      iVar8 = iVar2 * 10;
      if (5 < log_level) {
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"%s:%d:%s: chain[%d] current_voltage_value = %d\n","driver-btm-c5.c",0x2f2d
                  ,"slowly_downgrade_voltage_all_chain",uVar6,iVar4);
        }
        fclose(pFVar5);
        if (5 < log_level) {
          pFVar5 = fopen(log_file,"a+");
          if (pFVar5 != (FILE *)0x0) {
            fprintf(pFVar5,"%s:%d:%s: chain[%d] target_voltage_value = %d\n","driver-btm-c5.c",
                    0x2f2e,"slowly_downgrade_voltage_all_chain",uVar6,iVar8);
          }
          fclose(pFVar5);
        }
      }
      if (700 < iVar8 - 500U) {
        if (log_level < 2) {
          return;
        }
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"%s:%d:%s: target voltage invalid\n","driver-btm-c5.c",0x2f32,
                  "slowly_downgrade_voltage_all_chain");
        }
        fclose(pFVar5);
        return;
      }
      iVar4 = iVar4 + -10;
      if (iVar4 + iVar2 * -10 < 0 != SBORROW4(iVar4,iVar8)) goto LAB_00038142;
      pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
      pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
      if (log_level < 4) {
        bVar1 = true;
        goto LAB_00038142;
      }
      pFVar5 = fopen(log_file,"a+");
      if (pFVar5 != (FILE *)0x0) {
        fprintf(pFVar5,"%s:%d:%s: chain[%d] set voltage to %d\n","driver-btm-c5.c",0x2f3d,
                "slowly_downgrade_voltage_all_chain",uVar6,iVar4);
      }
      uVar6 = uVar6 + 1;
      fclose(pFVar5);
      bVar1 = true;
      pbVar7 = pbVar7 + 1;
      bVar3 = true;
    } while (uVar6 != 0x10);
LAB_0003826e:
    if (!bVar1) {
      return;
    }
    sleep(3);
  } while( true );
}

