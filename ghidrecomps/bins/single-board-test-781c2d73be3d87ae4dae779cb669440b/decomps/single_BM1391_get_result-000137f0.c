
/* WARNING: Unknown calling convention */

uint single_BM1391_get_result(uchar which_chain)

{
  uint (*pauVar1) [1];
  uint uVar2;
  int iVar3;
  char *pcVar4;
  uint OpenCoreNum2;
  uint OpenCoreNum3;
  uint OpenCoreNum4;
  uint OpenCoreNum5;
  uint OpenCoreNum6;
  uint OpenCoreNum7;
  work *pwVar5;
  work *works;
  undefined4 *puVar6;
  uint uVar7;
  uint *puVar8;
  uint OpenCoreNum8;
  uint uVar9;
  uchar *puVar10;
  uint OpenCoreNum1;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  
  uVar9 = Conf.OpenCoreNum8;
  uVar11 = Conf.OpenCoreNum1;
  uVar2 = (uint)which_chain;
  local_44 = Conf.OpenCoreNum2;
  puVar8 = (uint *)(gAsic_Core_Nonce_Num + uVar2);
  puVar6 = (undefined4 *)((int)&reg_mutex + uVar2 * 0x80000 + 0x14);
  local_40 = Conf.OpenCoreNum3;
  local_3c = Conf.OpenCoreNum4;
  local_38 = Conf.OpenCoreNum5;
  local_34 = Conf.OpenCoreNum6;
  local_30 = Conf.OpenCoreNum7;
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
  uVar7 = 0;
  do {
    if ((uVar7 & 7) == 0) {
      putchar(10);
    }
    puVar6 = puVar6 + 1;
    uVar12 = uVar7 + 1;
    printf("core[%03d]=%02d\t",uVar7,*puVar6);
    uVar7 = uVar12;
  } while (uVar12 != 0x100);
  iVar13 = 0;
  iVar3 = uVar2 * 4;
  uVar7 = 0;
  uVar12 = 3;
  puts("\n\n");
  do {
    while (0x1f < uVar7) {
      if (uVar7 - 0x20 < 0x20) {
        if ((int)(local_44 << 0x1f) < 0) {
          pwVar5 = cgpu.works[iVar13];
          if (*puVar8 < Conf.pattern_number) {
            printf("core[%03d] = %d,      lost these nonce : ",uVar7);
            if (Conf.pattern_number != 0) {
              puVar10 = pwVar5->data + iVar3 + -8;
              uVar12 = 0;
              do {
                pauVar1 = (uint (*) [1])(puVar10 + 0x34);
                puVar10 = puVar10 + 0x44;
                if ((*pauVar1)[0] == 0) {
                  printf("%d  ",uVar12);
                }
                uVar12 = uVar12 + 1;
              } while (uVar12 < Conf.pattern_number);
            }
            uVar12 = 2;
            putchar(10);
          }
          iVar13 = iVar13 + 1;
          local_44 = local_44 >> 1;
        }
        else {
          local_44 = local_44 >> 1;
        }
      }
      else if (uVar7 - 0x40 < 0x20) {
        if ((int)(local_40 << 0x1f) < 0) {
          pwVar5 = cgpu.works[iVar13];
          if (*puVar8 < Conf.pattern_number) {
            printf("core[%03d] = %d,      lost these nonce : ",uVar7);
            if (Conf.pattern_number != 0) {
              puVar10 = pwVar5->data + iVar3 + -8;
              uVar12 = 0;
              do {
                pauVar1 = (uint (*) [1])(puVar10 + 0x34);
                puVar10 = puVar10 + 0x44;
                if ((*pauVar1)[0] == 0) {
                  printf("%d  ",uVar12);
                }
                uVar12 = uVar12 + 1;
              } while (uVar12 < Conf.pattern_number);
            }
            uVar12 = 2;
            putchar(10);
          }
          iVar13 = iVar13 + 1;
          local_40 = local_40 >> 1;
        }
        else {
          local_40 = local_40 >> 1;
        }
      }
      else if (uVar7 - 0x60 < 0x20) {
        if ((int)(local_3c << 0x1f) < 0) {
          pwVar5 = cgpu.works[iVar13];
          if (*puVar8 < Conf.pattern_number) {
            printf("core[%03d] = %d,      lost these nonce : ",uVar7);
            if (Conf.pattern_number != 0) {
              puVar10 = pwVar5->data + iVar3 + -8;
              uVar12 = 0;
              do {
                pauVar1 = (uint (*) [1])(puVar10 + 0x34);
                puVar10 = puVar10 + 0x44;
                if ((*pauVar1)[0] == 0) {
                  printf("%d  ",uVar12);
                }
                uVar12 = uVar12 + 1;
              } while (uVar12 < Conf.pattern_number);
            }
            uVar12 = 2;
            putchar(10);
          }
          iVar13 = iVar13 + 1;
          local_3c = local_3c >> 1;
        }
        else {
          local_3c = local_3c >> 1;
        }
      }
      else if (uVar7 - 0x80 < 0x20) {
        if ((int)(local_38 << 0x1f) < 0) {
          pwVar5 = cgpu.works[iVar13];
          if (*puVar8 < Conf.pattern_number) {
            printf("core[%03d] = %d,      lost these nonce : ",uVar7);
            if (Conf.pattern_number != 0) {
              puVar10 = pwVar5->data + iVar3 + -8;
              uVar12 = 0;
              do {
                pauVar1 = (uint (*) [1])(puVar10 + 0x34);
                puVar10 = puVar10 + 0x44;
                if ((*pauVar1)[0] == 0) {
                  printf("%d  ",uVar12);
                }
                uVar12 = uVar12 + 1;
              } while (uVar12 < Conf.pattern_number);
            }
            uVar12 = 2;
            putchar(10);
          }
          iVar13 = iVar13 + 1;
          local_38 = local_38 >> 1;
        }
        else {
          local_38 = local_38 >> 1;
        }
      }
      else if (uVar7 - 0xa0 < 0x20) {
        if ((int)(local_34 << 0x1f) < 0) {
          pwVar5 = cgpu.works[iVar13];
          if (*puVar8 < Conf.pattern_number) {
            printf("core[%03d] = %d,      lost these nonce : ",uVar7);
            if (Conf.pattern_number != 0) {
              puVar10 = pwVar5->data + iVar3 + -8;
              uVar12 = 0;
              do {
                pauVar1 = (uint (*) [1])(puVar10 + 0x34);
                puVar10 = puVar10 + 0x44;
                if ((*pauVar1)[0] == 0) {
                  printf("%d  ",uVar12);
                }
                uVar12 = uVar12 + 1;
              } while (uVar12 < Conf.pattern_number);
            }
            uVar12 = 2;
            putchar(10);
          }
          iVar13 = iVar13 + 1;
          local_34 = local_34 >> 1;
        }
        else {
          local_34 = local_34 >> 1;
        }
      }
      else if (uVar7 - 0xc0 < 0x20) {
        if ((int)(local_30 << 0x1f) < 0) {
          pwVar5 = cgpu.works[iVar13];
          if (*puVar8 < Conf.pattern_number) {
            printf("core[%03d] = %d,      lost these nonce : ",uVar7);
            if (Conf.pattern_number != 0) {
              puVar10 = pwVar5->data + iVar3 + -8;
              uVar12 = 0;
              do {
                pauVar1 = (uint (*) [1])(puVar10 + 0x34);
                puVar10 = puVar10 + 0x44;
                if ((*pauVar1)[0] == 0) {
                  printf("%d  ",uVar12);
                }
                uVar12 = uVar12 + 1;
              } while (uVar12 < Conf.pattern_number);
            }
            uVar12 = 2;
            putchar(10);
          }
          iVar13 = iVar13 + 1;
          local_30 = local_30 >> 1;
        }
        else {
          local_30 = local_30 >> 1;
        }
      }
      else if ((int)(uVar9 << 0x1f) < 0) {
        pwVar5 = cgpu.works[iVar13];
        if (*puVar8 < Conf.pattern_number) {
          printf("core[%03d] = %d,      lost these nonce : ",uVar7);
          if (Conf.pattern_number != 0) {
            puVar10 = pwVar5->data + iVar3 + -8;
            uVar12 = 0;
            do {
              pauVar1 = (uint (*) [1])(puVar10 + 0x34);
              puVar10 = puVar10 + 0x44;
              if ((*pauVar1)[0] == 0) {
                printf("%d  ",uVar12);
              }
              uVar12 = uVar12 + 1;
            } while (uVar12 < Conf.pattern_number);
          }
          uVar12 = 2;
          putchar(10);
        }
        uVar9 = uVar9 >> 1;
        iVar13 = iVar13 + 1;
      }
      else {
        uVar9 = uVar9 >> 1;
      }
LAB_000139bc:
      uVar7 = uVar7 + 1;
      puVar8 = puVar8 + 1;
      if (uVar7 == 0x100) goto LAB_000139c8;
    }
    if ((uVar11 & 1) == 0) {
      uVar11 = uVar11 >> 1;
      goto LAB_000139bc;
    }
    if (*puVar8 < Conf.pattern_number) {
      pwVar5 = cgpu.works[iVar13];
      printf("core[%03d] = %d,      lost these nonce : ",uVar7);
      if (Conf.pattern_number != 0) {
        puVar10 = pwVar5->data + iVar3 + -8;
        uVar12 = 0;
        do {
          while (pauVar1 = (uint (*) [1])(puVar10 + 0x34), puVar10 = puVar10 + 0x44,
                (*pauVar1)[0] != 0) {
            uVar12 = uVar12 + 1;
            if (Conf.pattern_number <= uVar12) goto LAB_00013b8c;
          }
          printf("%d  ",uVar12);
          uVar12 = uVar12 + 1;
        } while (uVar12 < Conf.pattern_number);
      }
LAB_00013b8c:
      uVar12 = 2;
      putchar(10);
    }
    uVar7 = uVar7 + 1;
    uVar11 = uVar11 >> 1;
    iVar13 = iVar13 + 1;
    puVar8 = puVar8 + 1;
  } while (uVar7 != 0x100);
LAB_000139c8:
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
  printf("Chain%d total valid nonce number: %d\n\n",uVar2,gValid_Nonce_Num[uVar2]);
  if ((int)(uVar12 << 0x1f) < 0) {
    pcVar4 = "Pattern OK\n";
  }
  else {
    pcVar4 = "Pattern NG\n";
  }
  puts(pcVar4);
  if ((int)(uVar12 << 0x1e) < 0) {
    pcVar4 = "Sensor OK\n";
  }
  else {
    pcVar4 = "Sensor NG\n";
  }
  puts(pcVar4);
  printf("HW number = %d\n\n",gHw_Nonce_Num[uVar2]);
  return uVar12;
}

