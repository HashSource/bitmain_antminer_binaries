
/* WARNING: Unknown calling convention */

void bitmain_reinit(void)

{
  byte bVar1;
  char cVar2;
  ushort frequency;
  int iVar3;
  uint *puVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  void **ppvVar9;
  void **ppvVar10;
  int *piVar11;
  char *pcVar12;
  uchar uVar13;
  int iVar14;
  void *pvVar15;
  void *pvVar16;
  uint uVar17;
  void *pvVar18;
  void *pvVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  uchar vol_pic;
  uchar temp_voltage;
  int iVar23;
  uint uVar24;
  double dVar25;
  char logstr [256];
  char tmp42 [2048];
  uchar chain;
  
  iVar21 = DAT_00036a50;
  ppvVar9 = DAT_00036a4c;
  iVar22 = DAT_00036a48;
  pthread_mutex_lock((pthread_mutex_t *)(DAT_00036a48 + 0x1e8));
  memset(*ppvVar9,0,0x301c);
  *(undefined4 *)*ppvVar9 = *(undefined4 *)(iVar22 + 0x208);
  set_reset_allhashboard(1);
  sleep(3);
  set_reset_allhashboard(0);
  sleep(1);
  set_reset_allhashboard(1);
  set_QN_write_data_command(0x8080800f);
  sleep(2);
  set_PWM('d');
  pvVar19 = *ppvVar9;
  **(undefined4 **)(DAT_00036a54 + 0x8d4) = 0x80000000;
  *(undefined *)((int)pvVar19 + 0x2fea) = 0x1a;
  set_nonce2_and_job_id_store_address(*(uint *)(iVar21 + 0x8c));
  set_job_start_address(*(int *)(iVar21 + 0x8c) + 0x200000);
  check_chain();
  set_reset_allhashboard(1);
  iVar22 = 0;
  do {
    while (*(int *)((int)*ppvVar9 + (iVar22 + 2) * 4) != 1) {
      iVar22 = iVar22 + 1;
      if (iVar22 == 0x10) goto LAB_0003689e;
    }
    reset_iic_pic((uchar)iVar22);
    iVar21 = iVar22 + 1;
    jump_to_app_CheckAndRestorePIC_T9_18(iVar22);
    iVar22 = iVar21;
  } while (iVar21 != 0x10);
LAB_0003689e:
  iVar22 = DAT_00036a68;
  piVar11 = DAT_00036a58;
  iVar21 = 0;
  sleep(1);
  do {
    while (*(int *)((int)*ppvVar9 + (iVar21 + 2) * 4) != 1) {
      iVar21 = iVar21 + 1;
      if (iVar21 == 0x10) goto LAB_000368fa;
    }
    chain = (uchar)iVar21;
    uVar13 = get_pic_voltage(chain);
    iVar20 = *piVar11;
    *(uchar *)(iVar22 + iVar21) = uVar13;
    if (iVar20 < 0xe) {
      if (iVar21 % 3 == 0) goto LAB_00036c54;
    }
    else if (iVar21 - 1U < 3) {
LAB_00036c54:
      set_voltage_T9_18_into_PIC(chain,'\x01');
    }
    iVar21 = iVar21 + 1;
    disable_pic_dac(chain);
  } while (iVar21 != 0x10);
LAB_000368fa:
  iVar22 = DAT_00036a68;
  cgsleep_ms(1000);
  dVar8 = DAT_00036a40;
  dVar7 = DAT_00036a38;
  dVar6 = DAT_00036a30;
  dVar5 = DAT_00036a28;
  iVar20 = 1;
  pvVar19 = *ppvVar9;
  iVar21 = 0;
  do {
    while (*(int *)((int)pvVar19 + (iVar21 + 2) * 4) != 1) {
      iVar21 = iVar21 + 1;
      iVar20 = iVar20 + 1;
      if (iVar21 == 0x10) goto LAB_000369a6;
    }
    uVar17 = (uint)*(byte *)(iVar22 + iVar21);
    iVar3 = (int)(longlong)
                 (((dVar6 / ((double)(longlong)(int)uVar17 + dVar5) + dVar7) * dVar8) / 4.75) / 10;
    iVar23 = iVar3 * 10;
    sprintf(logstr,DAT_00036a5c,iVar20,uVar17,iVar23);
    writeInitLogFile(logstr);
    iVar14 = getChainPICMagicNumber(iVar21);
    if ((iVar14 == 0x7d) &&
       (iVar14 = *(int *)(DAT_00036dc8 + iVar21 * 4),
       iVar14 != iVar23 && iVar14 + iVar3 * -10 < 0 == SBORROW4(iVar14,iVar23))) {
      dVar25 = dVar6 / (((double)(longlong)iVar14 * 4.75) / dVar8 - dVar7) - dVar5;
      uVar24 = (uint)(0.0 < dVar25) * (int)(longlong)dVar25;
      uVar17 = uVar24 & 0xff;
      sprintf(logstr,DAT_00036dcc,iVar20,iVar14,uVar17);
      writeInitLogFile(logstr);
      pcVar12 = DAT_00036dd0;
      *(char *)(iVar21 + iVar22) = (char)uVar24;
      sprintf(logstr,pcVar12,iVar20,uVar17);
      writeInitLogFile(logstr);
    }
    iVar21 = iVar21 + 1;
    pvVar19 = *ppvVar9;
    iVar20 = iVar20 + 1;
  } while (iVar21 != 0x10);
LAB_000369a6:
  iVar22 = 0;
  while( true ) {
    puVar4 = DAT_00036a60;
    if (*(int *)((int)pvVar19 + (iVar22 + 2) * 4) == 1) {
      enable_pic_dac((uchar)iVar22);
      puVar4 = DAT_00036a60;
    }
    DAT_00036a60 = puVar4;
    if (iVar22 == 0xf) break;
    iVar22 = iVar22 + 1;
    pvVar19 = *ppvVar9;
  }
  sleep(5);
  pthread_mutex_unlock(DAT_00036a64);
  cgsleep_ms(2000);
  set_reset_allhashboard(1);
  sleep(3);
  set_reset_allhashboard(0);
  sleep(1);
  if (*puVar4 != 0) {
    uVar17 = get_dhash_acc_control();
    set_dhash_acc_control((*puVar4 & 0xf) << 8 | 0x8000 | uVar17 & 0xffff7fdf);
  }
  ppvVar10 = DAT_00036a4c;
  cgsleep_ms(10);
  *(undefined *)((int)*ppvVar9 + 0x2fe7) = 0x72;
  check_asic_reg(0);
  cgsleep_ms(10);
  iVar22 = 1;
  do {
    while( true ) {
      iVar21 = iVar22 + 1;
      if (*(int *)((int)*ppvVar9 + iVar21 * 4) == 1) break;
LAB_00036a6c:
      iVar22 = iVar21;
      if (iVar21 == 0x11) goto LAB_00036ab6;
    }
    sprintf(logstr,DAT_00036db0,iVar22,(uint)*(byte *)((int)*ppvVar9 + iVar22 + 0x2fa9));
    writeInitLogFile(logstr);
    if (*(char *)((int)*ppvVar10 + iVar22 + 0x2fa9) != '\0') goto LAB_00036a6c;
    *(undefined4 *)((int)*ppvVar10 + iVar21 * 4) = 0;
    iVar22 = iVar21;
  } while (iVar21 != 0x11);
LAB_00036ab6:
  iVar22 = DAT_00036db4;
  software_set_address();
  cgsleep_ms(10);
  if ((int)((uint)*(byte *)(iVar22 + 0x950) << 0x1c) < 0) {
    frequency = *(ushort *)(iVar22 + 0x958);
    *(ushort *)((int)*ppvVar9 + 0x2fee) = frequency;
    set_frequency(frequency);
    sprintf((char *)((int)*ppvVar9 + 0x2ff0),DAT_00037024,(uint)*(ushort *)((int)*ppvVar9 + 0x2fee))
    ;
  }
  pcVar12 = DAT_00036dd4;
  cgsleep_ms(10);
  pvVar19 = *ppvVar9;
  bVar1 = *(byte *)(iVar22 + 0x956);
  cVar2 = *pcVar12;
  uVar17 = (uint)*(byte *)(iVar22 + 0x950) << 0x1e;
  *(byte *)((int)pvVar19 + 0x2fec) = (byte)(uVar17 >> 0x1f);
  *(byte *)((int)pvVar19 + 0x2fed) = bVar1;
  if ((cVar2 != '\0') &&
     (((*DAT_00036db8 != '\0' || (*DAT_00036dbc != '\0')) || (6 < *DAT_00037028)))) {
    snprintf(tmp42,0x800,DAT_00036dc0,DAT_00036dc4,uVar17 >> 0x1f,(uint)bVar1);
    _applog(7,tmp42,false);
  }
  if (((int)((uint)*(byte *)(iVar22 + 0x950) << 0x1e) < 0) &&
     (*(byte *)(DAT_00036db4 + 0x956) < 0x65)) {
    set_PWM(*(byte *)(DAT_00036db4 + 0x956));
  }
  else {
    set_PWM_according_to_temperature();
  }
  if ((int)((uint)*(byte *)(iVar22 + 0x950) << 0x1d) < 0) {
    if (*(short *)(DAT_00036db4 + 0x95e) == 0) {
      iVar22 = calculate_core_number((uint)*(byte *)((int)*ppvVar9 + 0x2fe7));
      pvVar19 = *ppvVar9;
      iVar22 = __aeabi_idiv(0x1000000,iVar22);
      iVar22 = __aeabi_idiv((uint)*(byte *)((int)pvVar19 + 0x2fe8) * iVar22,
                            *(undefined2 *)((int)pvVar19 + 0x2fee));
      cVar2 = *pcVar12;
      uVar17 = (iVar22 * 0x5a) / 100;
      *(uint *)((int)pvVar19 + 0x48) = uVar17;
      if ((cVar2 != '\0') &&
         (((*DAT_0003702c != '\0' || (*DAT_00037030 != '\0')) || (6 < *DAT_00037028)))) {
        snprintf(tmp42,0x800,DAT_00037034);
        _applog(7,tmp42,false);
        pvVar19 = *ppvVar9;
        uVar17 = *(uint *)((int)pvVar19 + 0x48);
      }
    }
    else {
      pvVar19 = *ppvVar9;
      uVar17 = (uint)*(byte *)(DAT_00036db4 + 0x95e) * 1000 + (uint)*(byte *)(DAT_00036db4 + 0x95f);
      *(uint *)((int)pvVar19 + 0x48) = uVar17;
    }
    if (0x1ffff < uVar17) {
      *(undefined4 *)((int)pvVar19 + 0x48) = 0x1ffff;
    }
  }
  init_uart_baud();
  iVar22 = 0;
  cgsleep_ms(10);
  pvVar19 = *ppvVar9;
  do {
    while ((*(int *)((int)pvVar19 + (iVar22 + 2) * 4) != 1 ||
           (*(char *)((int)pvVar19 + iVar22 + 0x2faa) != '\x12'))) {
      iVar22 = iVar22 + 1;
      if (iVar22 == 0x10) goto LAB_00036bbc;
    }
    calibration_sensor_offset(0x98,iVar22);
    iVar22 = iVar22 + 1;
    cgsleep_ms(10);
    pvVar19 = *ppvVar9;
  } while (iVar22 != 0x10);
LAB_00036bbc:
  iVar22 = *piVar11;
  uVar17 = 0;
  pvVar15 = pvVar19;
  pvVar16 = pvVar19;
  pvVar18 = pvVar19;
  do {
    if ((*(int *)((int)pvVar18 + 8) == 1) && (*(char *)((int)pvVar19 + uVar17 + 0x2faa) == '\x12'))
    {
      if (iVar22 < 0xe) {
        iVar21 = ((int)uVar17 / 3) * 3;
        if ((int)uVar17 % 3 != 1) {
          *(undefined *)((int)pvVar15 + 0x458) = *(undefined *)((int)pvVar19 + iVar21 + 0x459);
          *(undefined *)((int)pvVar16 + 0x4e8) = *(undefined *)((int)pvVar19 + (iVar21 + 0x9e) * 8);
          *(undefined *)((int)pvVar16 + 0x4e9) =
               *(undefined *)((int)pvVar19 + (iVar21 + 1) * 8 + 0x4e9);
        }
      }
      else if (uVar17 < 0xe) {
        uVar24 = 1 << (uVar17 & 0xff);
        if ((uVar24 & 0x2008) == 0) {
          if ((uVar24 & 0x804) == 0) {
            if ((uVar24 & 0x202) != 0) {
              *(undefined *)((int)pvVar15 + 0x458) = *(undefined *)((int)pvVar19 + 0x460);
              *(undefined *)((int)pvVar16 + 0x4e8) = *(undefined *)((int)pvVar19 + 0x528);
              *(undefined *)((int)pvVar16 + 0x4e9) = *(undefined *)((int)pvVar19 + 0x529);
            }
          }
          else {
            *(undefined *)((int)pvVar15 + 0x458) = *(undefined *)((int)pvVar19 + 0x462);
            *(undefined *)((int)pvVar16 + 0x4e8) = *(undefined *)((int)pvVar19 + 0x538);
            *(undefined *)((int)pvVar16 + 0x4e9) = *(undefined *)((int)pvVar19 + 0x539);
          }
        }
        else {
          *(undefined *)((int)pvVar15 + 0x458) = *(undefined *)((int)pvVar19 + 0x464);
          *(undefined *)((int)pvVar16 + 0x4e8) = *(undefined *)((int)pvVar19 + 0x548);
          *(undefined *)((int)pvVar16 + 0x4e9) = *(undefined *)((int)pvVar19 + 0x549);
        }
      }
    }
    uVar17 = uVar17 + 1;
    pvVar18 = (void *)((int)pvVar18 + 4);
    pvVar15 = (void *)((int)pvVar15 + 1);
    pvVar16 = (void *)((int)pvVar16 + 8);
  } while (uVar17 != 0x10);
  if (*puVar4 == 0) {
    set_time_out_control(*(uint *)((int)pvVar19 + 0x48) & 0x1ffff | 0x80000000);
  }
  else {
    set_time_out_control(*(uint *)((int)pvVar19 + 0x48) * *puVar4 & 0x1ffff | 0x80000000);
  }
  dVar8 = DAT_00036da8;
  dVar7 = DAT_00036da0;
  dVar6 = DAT_00036d98;
  dVar5 = DAT_00036d90;
  iVar21 = 1;
  iVar22 = 0;
  set_PWM('d');
  do {
    if (*(int *)((int)*ppvVar9 + (iVar22 + 2) * 4) == 1) {
      open_core_one_chain(iVar22,true);
      sleep(1);
      iVar20 = DAT_0003701c;
      if (*piVar11 < 0xe) {
        if (iVar22 % 3 == 2) {
          pthread_mutex_lock(DAT_00037038);
          set_pic_voltage((uchar)iVar22,*(uchar *)(iVar20 + iVar22));
          pthread_mutex_unlock(DAT_00037038);
        }
        bVar1 = *(byte *)(iVar20 + iVar22);
      }
      else {
        if (iVar22 == 1) {
          open_core_one_chain(8,true);
          sleep(1);
          open_core_one_chain(9,true);
          sleep(1);
        }
        else if (iVar22 == 2) {
          open_core_one_chain(10,true);
          sleep(1);
          open_core_one_chain(0xb,true);
          sleep(1);
        }
        else {
          if (iVar22 != 3) {
            return;
          }
          open_core_one_chain(0xc,true);
          sleep(1);
          open_core_one_chain(0xd,true);
          sleep(1);
        }
        iVar20 = DAT_0003701c;
        pthread_mutex_lock(DAT_00037038);
        set_pic_voltage((uchar)iVar22,*(uchar *)(iVar20 + iVar22));
        pthread_mutex_unlock(DAT_00037038);
        bVar1 = *(byte *)(iVar20 + iVar22);
      }
      sprintf(logstr,DAT_00037020,iVar21,
              ((int)(longlong)
                    (((dVar6 / ((double)(longlong)(int)(uint)bVar1 + dVar5) + dVar7) * dVar8) / 4.75
                    ) / 10) * 10,(uint)bVar1);
      writeInitLogFile(logstr);
    }
    iVar22 = iVar22 + 1;
    iVar21 = iVar21 + 1;
  } while (iVar22 != 0x10);
  return;
}

