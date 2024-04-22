
void check_fan_beforeInit(void)

{
  int iVar1;
  FILE *pFVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int local_38;
  byte local_2d;
  int local_2c [2];
  
  local_2d = 0;
  local_38 = 2;
  do {
    iVar6 = 8;
    do {
      while (iVar1 = get_fan_speed(&local_2d,local_2c), iVar4 = dev, iVar1 == -1) {
LAB_0002f360:
        iVar6 = iVar6 + -1;
        if (iVar6 == 0) goto LAB_0002f40a;
      }
      uVar3 = (uint)local_2d;
      iVar1 = dev + uVar3;
      iVar8 = dev + uVar3 * 4;
      uVar5 = local_2c[0] * 0x78;
      *(uint *)(iVar8 + 0x538c) = uVar5;
      if (local_2c[0] == 0) {
        if (*(char *)(iVar1 + 0x5384) == '\x01') {
          *(undefined *)(iVar1 + 0x5384) = 0;
          uVar5 = *(uint *)(iVar4 + 0x4c) & 1;
          if (1 << uVar3 != 0) {
            uVar5 = 0;
          }
          *(char *)(iVar4 + 0x53fe) = *(char *)(iVar4 + 0x53fe) + -1;
          *(uint *)(iVar4 + 0x4c) = uVar5;
          uVar5 = *(uint *)(iVar8 + 0x538c);
        }
      }
      else {
        if (*(char *)(iVar1 + 0x5384) == '\0') {
          *(undefined *)(iVar1 + 0x5384) = 1;
          *(uint *)(iVar4 + 0x4c) = *(uint *)(iVar4 + 0x4c) | 1 << uVar3;
          *(char *)(iVar4 + 0x53fe) = *(char *)(iVar4 + 0x53fe) + '\x01';
        }
        else if (*(char *)(iVar1 + 0x5384) != '\x01') goto LAB_0002f338;
        if ((print_num_13028 < 100) && (print_num_13028 = print_num_13028 + 1, 3 < log_level)) {
          pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: get fan[%d] speed=%d\n","driver-btm-c5.c",0xbbe,DAT_0002f578,
                    (uint)local_2d,*(undefined4 *)(dev + (local_2d + 0x14e2) * 4 + 4));
          }
          fclose(pFVar2);
          if ((print_num_13028 < 100) || (log_level < 4)) {
            uVar3 = (uint)local_2d;
            uVar5 = *(uint *)(dev + (uVar3 + 0x14e2) * 4 + 4);
            iVar4 = dev;
          }
          else {
            pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"%s:%d:%s: Fatal Error: some Fan lost or Fan speed low!\n",
                      "driver-btm-c5.c",0xbc2,DAT_0002f578);
            }
            fclose(pFVar2);
            uVar3 = (uint)local_2d;
            uVar5 = *(uint *)(dev + (uVar3 + 0x14e2) * 4 + 4);
            iVar4 = dev;
          }
        }
        else {
          uVar5 = *(uint *)(iVar8 + 0x538c);
        }
      }
LAB_0002f338:
      iVar1 = print_num_13028;
      if (*(uint *)(iVar4 + 0x5400) < uVar5) {
        *(uint *)(iVar4 + 0x5400) = uVar5;
      }
      uVar7 = *(uint *)(iVar4 + 0x5404);
      if (((uVar5 == 0 || uVar5 <= uVar7) && (uVar5 != 0 && uVar7 != uVar5)) || (uVar7 == 0)) {
        *(uint *)(iVar4 + 0x5404) = uVar5;
        if (iVar1 == 0x1e) goto LAB_0002f3ec;
        goto LAB_0002f360;
      }
      if (iVar1 != 0x1e) goto LAB_0002f360;
LAB_0002f3ec:
      if (3 < log_level) {
        pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: waiting fans become stable...\n","driver-btm-c5.c",0xbcf,
                  DAT_0002f578);
        }
        fclose(pFVar2);
        if (5 < log_level) {
          pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: reset dev->fan_speed_low1\n","driver-btm-c5.c",0xbd0,
                    DAT_0002f578);
          }
          fclose(pFVar2);
        }
        uVar3 = (uint)local_2d;
      }
      iVar6 = iVar6 + -1;
      *(undefined4 *)(dev + 0x5404) = *(undefined4 *)(dev + (uVar3 + 0x14e2) * 4 + 4);
    } while (iVar6 != 0);
LAB_0002f40a:
    sleep(1);
    local_38 = local_38 + -1;
    if (local_38 == 0) {
      return;
    }
  } while( true );
}

