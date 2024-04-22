
/* WARNING: Unknown calling convention */

uint single_BM1397_get_result(uchar which_chain)

{
  uint (*pauVar1) [1];
  undefined4 uVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  uint OpenCoreNum2;
  uint OpenCoreNum3;
  uint OpenCoreNum4;
  uint OpenCoreNum5;
  uint OpenCoreNum6;
  uint OpenCoreNum7;
  uint OpenCoreNum8;
  undefined4 *puVar6;
  uint *puVar7;
  uchar *puVar8;
  uint uVar9;
  uint OpenCoreNum1;
  uint uVar10;
  int iVar11;
  uint uVar12;
  work *pwVar13;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  
  uVar10 = Conf.OpenCoreNum1;
  uVar3 = (uint)which_chain;
  local_4c = Conf.OpenCoreNum2;
  puVar7 = (uint *)(gAsic_Core_Nonce_Num + uVar3);
  puVar6 = (undefined4 *)((int)&reg_mutex + uVar3 * 0x80000 + 0x14);
  local_48 = Conf.OpenCoreNum3;
  local_44 = Conf.OpenCoreNum4;
  local_40 = Conf.OpenCoreNum5;
  local_3c = Conf.OpenCoreNum6;
  local_38 = Conf.OpenCoreNum7;
  local_34 = Conf.OpenCoreNum8;
  puts(
      "\n\n------------------------------------------------------------------------------------------------------\n"
      );
  printf("every CORE require nonce number: %u\n\n",Conf.pattern_number);
  printf("Open core number : Conf.OpenCoreNum1 = %u = 0x%08x\n",Conf.OpenCoreNum1);
  printf("Open core number : Conf.OpenCoreNum2 = %u = 0x%08x\n",Conf.OpenCoreNum2);
  printf("Open core number : Conf.OpenCoreNum3 = %u = 0x%08x\n",Conf.OpenCoreNum3);
  printf("Open core number : Conf.OpenCoreNum4 = %u = 0x%08x\n",Conf.OpenCoreNum4);
  printf("Open core number : Conf.OpenCoreNum5 = %u = 0x%08x\n",Conf.OpenCoreNum5);
  printf("Open core number : Conf.OpenCoreNum6 = %u = 0x%08x\n",Conf.OpenCoreNum6);
  printf("Open core number : Conf.OpenCoreNum7 = %u = 0x%08x\n",Conf.OpenCoreNum7);
  printf("Open core number : Conf.OpenCoreNum8 = %u = 0x%08x\n\n",Conf.OpenCoreNum8);
  uVar12 = 0;
  do {
    if ((uVar12 & 7) == 0) {
      putchar(10);
    }
    puVar6 = puVar6 + 1;
    uVar9 = uVar12 + 1;
    printf("core[%03d]=%02d\t",uVar12,*puVar6);
    uVar2 = DAT_00027410;
    uVar12 = uVar9;
  } while (uVar9 != 0x2a0);
  iVar11 = 0;
  iVar5 = uVar3 * 4;
  uVar9 = 0;
  uVar12 = 3;
  puts("\n\n");
  do {
    if (uVar9 < 0x20) {
      if ((uVar10 & 1) == 0) {
        uVar10 = uVar10 >> 1;
      }
      else {
        if (*puVar7 < Conf.pattern_number) {
          pwVar13 = cgpu.works[iVar11];
          printf("core[%03d] = %d,      lost these nonce : ",uVar9);
          if (Conf.pattern_number != 0) {
            puVar8 = pwVar13->data + iVar5 + -8;
            uVar12 = 0;
            do {
              while (pauVar1 = (uint (*) [1])(puVar8 + 0x34), puVar8 = puVar8 + 0x44,
                    (*pauVar1)[0] != 0) {
                uVar12 = uVar12 + 1;
                if (Conf.pattern_number <= uVar12) goto LAB_00027346;
              }
              printf("%d  ",uVar12);
              uVar12 = uVar12 + 1;
            } while (uVar12 < Conf.pattern_number);
          }
LAB_00027346:
          uVar12 = 2;
          putchar(10);
        }
        uVar10 = uVar10 >> 1;
        iVar11 = iVar11 + 1;
      }
    }
    else if (uVar9 - 0x20 < 0x20) {
      if ((int)(local_4c << 0x1f) < 0) {
        pwVar13 = cgpu.works[iVar11];
        if (*puVar7 < Conf.pattern_number) {
          printf("core[%03d] = %d,      lost these nonce : ",uVar9);
          if (Conf.pattern_number != 0) {
            puVar8 = pwVar13->data + iVar5 + -8;
            uVar12 = 0;
            do {
              pauVar1 = (uint (*) [1])(puVar8 + 0x34);
              puVar8 = puVar8 + 0x44;
              if ((*pauVar1)[0] == 0) {
                printf("%d  ",uVar12);
              }
              uVar12 = uVar12 + 1;
            } while (uVar12 < Conf.pattern_number);
          }
          uVar12 = 2;
          putchar(10);
        }
        iVar11 = iVar11 + 1;
        local_4c = local_4c >> 1;
      }
      else {
        local_4c = local_4c >> 1;
      }
    }
    else if (uVar9 - 0x40 < 0x20) {
      if ((int)(local_48 << 0x1f) < 0) {
        pwVar13 = cgpu.works[iVar11];
        if (*puVar7 < Conf.pattern_number) {
          printf("core[%03d] = %d,      lost these nonce : ",uVar9);
          if (Conf.pattern_number != 0) {
            puVar8 = pwVar13->data + iVar5 + -8;
            uVar12 = 0;
            do {
              pauVar1 = (uint (*) [1])(puVar8 + 0x34);
              puVar8 = puVar8 + 0x44;
              if ((*pauVar1)[0] == 0) {
                printf("%d  ",uVar12);
              }
              uVar12 = uVar12 + 1;
            } while (uVar12 < Conf.pattern_number);
          }
          uVar12 = 2;
          putchar(10);
        }
        iVar11 = iVar11 + 1;
        local_48 = local_48 >> 1;
      }
      else {
        local_48 = local_48 >> 1;
      }
    }
    else if (uVar9 - 0x60 < 0x20) {
      if ((int)(local_44 << 0x1f) < 0) {
        pwVar13 = cgpu.works[iVar11];
        if (*puVar7 < Conf.pattern_number) {
          printf("core[%03d] = %d,      lost these nonce : ",uVar9);
          if (Conf.pattern_number != 0) {
            puVar8 = pwVar13->data + iVar5 + -8;
            uVar12 = 0;
            do {
              pauVar1 = (uint (*) [1])(puVar8 + 0x34);
              puVar8 = puVar8 + 0x44;
              if ((*pauVar1)[0] == 0) {
                printf("%d  ",uVar12);
              }
              uVar12 = uVar12 + 1;
            } while (uVar12 < Conf.pattern_number);
          }
          uVar12 = 2;
          putchar(10);
        }
        iVar11 = iVar11 + 1;
        local_44 = local_44 >> 1;
      }
      else {
        local_44 = local_44 >> 1;
      }
    }
    else if (uVar9 - 0x80 < 0x20) {
      if ((int)(local_40 << 0x1f) < 0) {
        pwVar13 = cgpu.works[iVar11];
        if (*puVar7 < Conf.pattern_number) {
          printf("core[%03d] = %d,      lost these nonce : ",uVar9);
          if (Conf.pattern_number != 0) {
            puVar8 = pwVar13->data + iVar5 + -8;
            uVar12 = 0;
            do {
              pauVar1 = (uint (*) [1])(puVar8 + 0x34);
              puVar8 = puVar8 + 0x44;
              if ((*pauVar1)[0] == 0) {
                printf("%d  ",uVar12);
              }
              uVar12 = uVar12 + 1;
            } while (uVar12 < Conf.pattern_number);
          }
          uVar12 = 2;
          putchar(10);
        }
        iVar11 = iVar11 + 1;
        local_40 = local_40 >> 1;
      }
      else {
        local_40 = local_40 >> 1;
      }
    }
    else if (uVar9 - 0xa0 < 0x20) {
      if ((int)(local_3c << 0x1f) < 0) {
        pwVar13 = cgpu.works[iVar11];
        if (*puVar7 < Conf.pattern_number) {
          printf("core[%03d] = %d,      lost these nonce : ",uVar9);
          if (Conf.pattern_number != 0) {
            puVar8 = pwVar13->data + iVar5 + -8;
            uVar12 = 0;
            do {
              pauVar1 = (uint (*) [1])(puVar8 + 0x34);
              puVar8 = puVar8 + 0x44;
              if ((*pauVar1)[0] == 0) {
                printf("%d  ",uVar12);
              }
              uVar12 = uVar12 + 1;
            } while (uVar12 < Conf.pattern_number);
          }
          uVar12 = 2;
          putchar(10);
        }
        iVar11 = iVar11 + 1;
        local_3c = local_3c >> 1;
      }
      else {
        local_3c = local_3c >> 1;
      }
    }
    else if (uVar9 - 0xc0 < 0x20) {
      if ((int)(local_38 << 0x1f) < 0) {
        pwVar13 = cgpu.works[iVar11];
        if (*puVar7 < Conf.pattern_number) {
          printf("core[%03d] = %d,      lost these nonce : ",uVar9);
          if (Conf.pattern_number != 0) {
            puVar8 = pwVar13->data + iVar5 + -8;
            uVar12 = 0;
            do {
              pauVar1 = (uint (*) [1])(puVar8 + 0x34);
              puVar8 = puVar8 + 0x44;
              if ((*pauVar1)[0] == 0) {
                printf("%d  ",uVar12);
              }
              uVar12 = uVar12 + 1;
            } while (uVar12 < Conf.pattern_number);
          }
          uVar12 = 2;
          putchar(10);
        }
        iVar11 = iVar11 + 1;
        local_38 = local_38 >> 1;
      }
      else {
        local_38 = local_38 >> 1;
      }
    }
    else if (uVar9 - 0xe0 < 0x20) {
      if ((int)(local_34 << 0x1f) < 0) {
        pwVar13 = cgpu.works[iVar11];
        if (*puVar7 < Conf.pattern_number) {
          printf("core[%03d] = %d,      lost these nonce : ",uVar9);
          if (Conf.pattern_number != 0) {
            puVar8 = pwVar13->data + iVar5 + -8;
            uVar12 = 0;
            do {
              pauVar1 = (uint (*) [1])(puVar8 + 0x34);
              puVar8 = puVar8 + 0x44;
              if ((*pauVar1)[0] == 0) {
                printf("%d  ",uVar12);
              }
              uVar12 = uVar12 + 1;
            } while (uVar12 < Conf.pattern_number);
          }
          uVar12 = 2;
          putchar(10);
        }
        iVar11 = iVar11 + 1;
        local_34 = local_34 >> 1;
      }
      else {
        local_34 = local_34 >> 1;
      }
    }
    else {
      printf("%s: which_core = %d, error!!!\n",uVar2,uVar9);
    }
    puVar7 = puVar7 + 1;
    uVar9 = uVar9 + 1;
    if (uVar9 == 0x2a0) {
      if (Conf.TempSensor1 != 0) {
        if (((Sensor1_temp == 0) || (Sensor1_OK == '\0')) || (gNotReadOutTemp != false)) {
          uVar12 = uVar12 & 0xfffffffd;
          puts("temperature1 check error");
        }
        else {
          printf("temperature1 = %d\n");
        }
      }
      if (Conf.TempSensor2 != 0) {
        if (((Sensor2_temp == 0) || (Sensor2_OK == '\0')) || (gNotReadOutTemp != false)) {
          uVar12 = uVar12 & 0xfffffffd;
          puts("temperature2 check error");
        }
        else {
          printf("temperature2 = %d\n");
        }
      }
      if (Conf.TempSensor3 != 0) {
        if (((Sensor3_temp == 0) || (Sensor3_OK == '\0')) || (gNotReadOutTemp != false)) {
          uVar12 = uVar12 & 0xfffffffd;
          puts("temperature3 check error");
        }
        else {
          printf("temperature3 = %d\n");
        }
      }
      puts(
          "\n------------------------------------------------------------------------------------------------------\n"
          );
      printf("Chain%d total valid nonce number: %d\n\n",uVar3,gValid_Nonce_Num[uVar3]);
      if ((uVar12 & 1) == 0) {
        pcVar4 = "Pattern NG\n";
      }
      else {
        pcVar4 = "Pattern OK\n";
      }
      puts(pcVar4);
      if ((uVar12 & 2) == 0) {
        pcVar4 = "Sensor NG\n";
      }
      else {
        pcVar4 = "Sensor OK\n";
      }
      puts(pcVar4);
      printf("HW number = %d\n\n",gHw_Nonce_Num[uVar3]);
      return uVar12;
    }
  } while( true );
}

