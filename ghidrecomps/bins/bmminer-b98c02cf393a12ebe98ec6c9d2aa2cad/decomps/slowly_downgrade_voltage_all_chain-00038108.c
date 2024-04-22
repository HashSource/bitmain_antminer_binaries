
void slowly_downgrade_voltage_all_chain(byte *param_1)

{
  bool bVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  bool bVar7;
  int iVar8;
  FILE *pFVar9;
  uint uVar10;
  byte *pbVar11;
  int iVar12;
  
  dVar6 = DAT_000383c8;
  dVar5 = DAT_000383c0;
  dVar4 = DAT_000383b8;
  dVar3 = DAT_000383b0;
  do {
    uVar10 = 0;
    pbVar11 = param_1;
    bVar7 = false;
    do {
      while (bVar1 = bVar7, *(int *)(dev + (uVar10 + 2) * 4) != 1) {
LAB_00038142:
        uVar10 = uVar10 + 1;
        pbVar11 = pbVar11 + 1;
        bVar7 = bVar1;
        if (uVar10 == 0x10) goto LAB_0003826e;
      }
      if (5 < log_level) {
        pFVar9 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar9 != (FILE *)0x0) {
          fprintf(pFVar9,"%s:%d:%s: vol_list[%d] = %d\n","driver-btm-c5.c",0x2f28,DAT_000383d4,
                  uVar10,(uint)*pbVar11);
        }
        fclose(pFVar9);
      }
      iVar8 = write_EEPROM_iic(1,1,0x90,uVar10 & 0xff,0);
      iVar2 = (int)(longlong)
                   (((dVar4 / ((double)(longlong)(int)(uint)*pbVar11 + dVar3) + dVar5) * dVar6) /
                   4.75) / 10;
      iVar8 = ((int)(longlong)(((dVar4 / ((double)(longlong)iVar8 + dVar3) + dVar5) * dVar6) / 4.75)
              / 10) * 10;
      iVar12 = iVar2 * 10;
      if (5 < log_level) {
        pFVar9 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar9 != (FILE *)0x0) {
          fprintf(pFVar9,"%s:%d:%s: chain[%d] current_voltage_value = %d\n","driver-btm-c5.c",0x2f2d
                  ,DAT_000383d4,uVar10,iVar8);
        }
        fclose(pFVar9);
        if (5 < log_level) {
          pFVar9 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar9 != (FILE *)0x0) {
            fprintf(pFVar9,"%s:%d:%s: chain[%d] target_voltage_value = %d\n","driver-btm-c5.c",
                    0x2f2e,DAT_000383d4,uVar10,iVar12);
          }
          fclose(pFVar9);
        }
      }
      if (700 < iVar12 - 500U) {
        if (log_level < 2) {
          return;
        }
        pFVar9 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar9 != (FILE *)0x0) {
          fprintf(pFVar9,"%s:%d:%s: target voltage invalid\n","driver-btm-c5.c",0x2f32,DAT_000383d4)
          ;
        }
        (*(code *)PTR_fclose_0007cfe8)(pFVar9);
        return;
      }
      iVar8 = iVar8 + -10;
      if (iVar8 + iVar2 * -10 < 0 != SBORROW4(iVar8,iVar12)) goto LAB_00038142;
      pthread_mutex_lock(DAT_000383d0);
      pthread_mutex_unlock(DAT_000383d0);
      if (log_level < 4) {
        bVar1 = true;
        goto LAB_00038142;
      }
      pFVar9 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar9 != (FILE *)0x0) {
        fprintf(pFVar9,"%s:%d:%s: chain[%d] set voltage to %d\n","driver-btm-c5.c",0x2f3d,
                DAT_000383d4,uVar10,iVar8);
      }
      uVar10 = uVar10 + 1;
      fclose(pFVar9);
      bVar1 = true;
      pbVar11 = pbVar11 + 1;
      bVar7 = true;
    } while (uVar10 != 0x10);
LAB_0003826e:
    if (!bVar1) {
      return;
    }
    sleep(3);
  } while( true );
}

