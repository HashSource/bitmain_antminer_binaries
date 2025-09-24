
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

int32_t bitmain_power_open(void)

{
  uint64_t uVar1;
  uint32_t uVar2;
  int32_t iVar3;
  uint uVar4;
  undefined4 uVar5;
  int32_t iVar6;
  uint64_t *puVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  uint8_t *puVar12;
  anon_union_160_2_9472fda9_for_eeprom_data_t_2 *paVar13;
  uint uVar14;
  uint uVar15;
  undefined4 uVar16;
  byte *pbVar17;
  uint8_t *puVar18;
  byte *pbVar19;
  uint8_t uVar20;
  byte bVar21;
  uint64_t *puVar22;
  undefined1 unaff_r8;
  int iVar23;
  int iVar24;
  int iVar25;
  double *pdVar26;
  char *pcVar27;
  int iVar28;
  bool bVar29;
  bool bVar30;
  bool bVar31;
  double dVar32;
  double extraout_d4;
  iic_init_param_t iic;
  uint8_t send_data [8];
  uchar buffer [32];
  uint64_t u64;
  short local_860;
  uint8_t auStack_844 [20];
  char tmp42 [2048];
  
  if ((_g_power_state.power_fd != 0) && (_g_power_state.power_open != 0)) {
    return _g_power_state.power_fd;
  }
  iic.slave_high = '\x02';
  iic.chain_id = 0;
  iic.slave_low = '\0';
  iic.master_addr = 1;
  pthread_mutex_lock((pthread_mutex_t *)&power_mutex);
  uVar2 = iic_init(&iic);
  pthread_mutex_unlock((pthread_mutex_t *)&power_mutex);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  _g_power_state.power_open = 1;
  _g_power_state.power_fd = uVar2;
  uVar2 = bitmain_power_version();
  if ((int)uVar2 < 0) {
    builtin_strncpy(tmp42,"power open power_version < 0 will close powe",0x2c);
    tmp42[0x2c] = 'r';
    tmp42[0x2d] = '\n';
    tmp42[0x2e] = '\0';
    _applog(3,tmp42,false);
    if (_g_power_state.power_open == 0) {
      return uVar2;
    }
    bitmain_power_close();
    return uVar2;
  }
  _g_power_state.power_version = uVar2;
  snprintf(tmp42,0x800,"power open power_version = 0x%x\n",uVar2);
  _applog(3,tmp42,false);
  if (_g_power_state.power_version - 0xc1 < 2) {
    uVar2 = _bitmain_get_power_fw_version(_g_power_state.power_fd);
    snprintf(tmp42,0x800,"power fw_version = 0x%x\n",uVar2);
    _applog(3,tmp42,false);
    _g_power_state.power_fw_version = uVar2;
  }
  uVar2 = _g_power_state.power_version;
  memset(&_g_power_state.eeprom,0,0x160);
  uVar14 = uVar2 & 0xffff;
  if (uVar14 == 0x71) {
LAB_000cc24e:
    bVar31 = 0x61 < uVar2;
    if (uVar2 != 0x62) {
      bVar31 = 1 < uVar2 - 100;
    }
    if (bVar31 && (uVar2 != 0x62 && uVar2 - 100 != 2)) {
      unaff_r8 = 0x6c;
      uVar20 = '@';
      goto LAB_000cc262;
    }
    bVar21 = 0x40;
LAB_000cc56c:
    u64._0_4_ = 0x608aa55;
    u64._4_4_ = 0;
    local_860 = 0;
    memset(tmp42,0,0x48);
    local_860 = 0;
    u64._4_2_ = (ushort)bVar21;
    u64._4_4_ = (uint)CONCAT12(0x20,u64._4_2_);
    puVar22 = &u64;
    do {
      pbVar17 = (byte *)((int)puVar22 + 3);
      puVar22 = (uint64_t *)((int)puVar22 + 2);
      local_860 = local_860 + (ushort)*(byte *)puVar22 + (ushort)*pbVar17 * 0x100;
    } while ((uint64_t *)((int)&u64 + 6) != puVar22);
    iVar6 = exec_power_cmd_v2(_g_power_state.power_fd,(uint8_t *)&u64,10,(uint8_t *)tmp42,0x28);
    uVar5 = _g_power_state.eeprom.sn._0_4_;
    uVar8 = _g_power_state.eeprom.sn._4_4_;
    uVar11 = _g_power_state.eeprom.sn._8_4_;
    uVar16 = _g_power_state.eeprom.sn._12_4_;
    if (iVar6 != 0) goto LAB_000cc1be;
    puVar18 = (uint8_t *)(tmp42 + 5);
    puVar12 = send_data + 7;
    do {
      puVar18 = puVar18 + 1;
      puVar12 = puVar12 + 1;
      *puVar12 = *puVar18;
    } while ((uint8_t *)(tmp42 + 0x25) != puVar18);
  }
  else {
    uVar5 = _g_power_state.eeprom.sn._0_4_;
    uVar8 = _g_power_state.eeprom.sn._4_4_;
    uVar11 = _g_power_state.eeprom.sn._8_4_;
    uVar16 = _g_power_state.eeprom.sn._12_4_;
    if (uVar14 < 0x72) {
      if (uVar14 != 0x62) {
        if (uVar14 < 99) {
          if (uVar14 != 0x41) goto LAB_000cc1be;
          goto LAB_000cc24e;
        }
        if (2 < uVar14 - 100) goto LAB_000cc1be;
      }
    }
    else {
      if (uVar14 < 0x79) {
        if ((uVar14 < 0x75) && (uVar14 != 0x73)) goto LAB_000cc1be;
        goto LAB_000cc24e;
      }
      if (1 < uVar14 - 0xc1) goto LAB_000cc1be;
    }
    bVar31 = 0x61 < uVar2;
    bVar29 = uVar2 == 0x62;
    if (!bVar29) {
      bVar31 = 1 < uVar2 - 100;
    }
    bVar30 = uVar2 - 100 != 2;
    uVar20 = !bVar31 || (bVar29 || !bVar30);
    if (bVar31 && (!bVar29 && bVar30)) {
      unaff_r8 = 0x2c;
    }
    if (!bVar31 || (bVar29 || !bVar30)) {
      bVar21 = 0;
      goto LAB_000cc56c;
    }
LAB_000cc262:
    iVar6 = 0;
    send_data[4] = '\0';
    send_data[5] = '\0';
    send_data[6] = '\0';
    send_data[7] = '\0';
    memset(&u64,0,0x32);
    send_data[6] = unaff_r8;
    send_data[0] = 'U';
    send_data[1] = 0xaa;
    send_data[5] = ' ';
    send_data[4] = uVar20;
    send_data[2] = '\x06';
    send_data[3] = '\x06';
    if ((_g_power_state.power_open == 0) && (iVar6 = bitmain_power_open(), iVar6 < 0)) {
      snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
               "bitmain_power_read");
      _applog(0,tmp42,false);
      uVar5 = _g_power_state.eeprom.sn._0_4_;
      uVar8 = _g_power_state.eeprom.sn._4_4_;
      uVar11 = _g_power_state.eeprom.sn._8_4_;
      uVar16 = _g_power_state.eeprom.sn._12_4_;
      goto LAB_000cc1be;
    }
    iVar3 = exec_power_cmd(_g_power_state.power_fd,send_data,8,(uint8_t *)&u64,0x27);
    puVar18 = (uint8_t *)((int)&u64 + 4);
    puVar12 = send_data + 7;
    if (iVar3 != 0) {
      builtin_strncpy(tmp42,"set DA conversion N failed\n",0x1c);
      _applog(0,tmp42,false);
      uVar5 = _g_power_state.eeprom.sn._0_4_;
      uVar8 = _g_power_state.eeprom.sn._4_4_;
      uVar11 = _g_power_state.eeprom.sn._8_4_;
      uVar16 = _g_power_state.eeprom.sn._12_4_;
      goto LAB_000cc1be;
    }
    do {
      puVar18 = puVar18 + 1;
      puVar12 = puVar12 + 1;
      *puVar12 = *puVar18;
    } while (puVar18 != auStack_844);
    uVar5 = _g_power_state.eeprom.sn._0_4_;
    uVar8 = _g_power_state.eeprom.sn._4_4_;
    uVar11 = _g_power_state.eeprom.sn._8_4_;
    uVar16 = _g_power_state.eeprom.sn._12_4_;
    if (iVar6 != 0) goto LAB_000cc1be;
  }
  builtin_strncpy(tmp42,"power calibration data:",0x18);
  _applog(0,tmp42,false);
  puVar22 = (uint64_t *)buffer;
  do {
    pbVar17 = (byte *)((int)puVar22 + 2);
    uVar14 = (uint)*(byte *)((int)puVar22 + 1);
    pbVar19 = (byte *)((int)puVar22 + 3);
    uVar1 = *puVar22;
    puVar22 = (uint64_t *)((int)puVar22 + 4);
    snprintf(tmp42,0x800,"%2X %2X %2X %2X  ",(uint)(byte)uVar1,uVar14,(uint)*pbVar17,(uint)*pbVar19)
    ;
    _applog(0,tmp42,false);
  } while (&u64 != puVar22);
  uVar4 = 0xff;
  uVar10 = 0xff;
  puVar22 = (uint64_t *)buffer;
  do {
    puVar7 = (uint64_t *)((int)puVar22 + 1);
    uVar15 = (byte)*puVar22 ^ uVar10;
    uVar10 = ""[uVar15] ^ uVar4;
    uVar4 = (uint)""[uVar15];
    puVar22 = puVar7;
  } while (puVar7 != (uint64_t *)(buffer + 0x1e));
  if ((uint)CONCAT11(buffer[0x1e],buffer[0x1f]) == (uVar10 | uVar4 << 8)) {
    tmp42[0] = '\0';
    tmp42[1] = '\0';
    tmp42[2] = '\0';
    tmp42[3] = '\0';
    u64._0_4_ = buffer._4_4_ << 0x18 | ((uint)buffer._4_4_ >> 8 & 0xff) << 0x10 |
                ((uint)buffer._4_4_ >> 0x10 & 0xff) << 8 | (uint)buffer._4_4_ >> 0x18;
    u64._4_4_ = buffer._0_4_ << 0x18 | ((uint)buffer._0_4_ >> 8 & 0xff) << 0x10 |
                ((uint)buffer._0_4_ >> 0x10 & 0xff) << 8 | (uint)buffer._0_4_ >> 0x18;
    tmp42[4] = '\0';
    tmp42[5] = '\0';
    tmp42[6] = '\0';
    tmp42[7] = '\0';
    tmp42[8] = '\0';
    tmp42[9] = '\0';
    tmp42[10] = '\0';
    tmp42[0xb] = '\0';
    iVar25 = 0;
    tmp42[0xc] = '\0';
    tmp42[0xd] = '\0';
    tmp42[0xe] = '\0';
    tmp42[0xf] = '\0';
    pbVar19 = buffer + 0xd;
    tmp42._16_4_ = tmp42._16_4_ & 0xffff0000;
    ulltostr(tmp42,0xc,CONCAT44(u64._4_4_,(uint)u64) & 0x1ffffffffffffff,uVar14);
    ulltostr(tmp42 + 0xb,7,
             (ulonglong)
             (buffer._8_4_ << 0x18 | ((uint)buffer._8_4_ >> 8 & 0xff) << 0x10 |
              ((uint)buffer._8_4_ >> 0x10 & 0xff) << 8 | (uint)buffer._8_4_ >> 0x18),uVar14);
    iVar23 = 10000;
    uVar4 = (uint)CONCAT11(buffer[0x1c],buffer[0x1d]);
    uVar14 = uVar4 / 0x1f + (uVar4 - uVar4 / 0x1f >> 1) >> 4;
    uVar5._0_1_ = tmp42[0];
    uVar5._1_1_ = tmp42[1];
    uVar5._2_1_ = tmp42[2];
    uVar5._3_1_ = tmp42[3];
    uVar8._0_1_ = tmp42[4];
    uVar8._1_1_ = tmp42[5];
    uVar8._2_1_ = tmp42[6];
    uVar8._3_1_ = tmp42[7];
    uVar11._0_1_ = tmp42[8];
    uVar11._1_1_ = tmp42[9];
    uVar11._2_1_ = tmp42[10];
    uVar11._3_1_ = tmp42[0xb];
    uVar16._0_1_ = tmp42[0xc];
    uVar16._1_1_ = tmp42[0xd];
    uVar16._2_1_ = tmp42[0xe];
    uVar16._3_1_ = tmp42[0xf];
    _g_power_state.eeprom.sn[0] = tmp42[0];
    _g_power_state.eeprom.sn[1] = tmp42[1];
    _g_power_state.eeprom.sn[2] = tmp42[2];
    _g_power_state.eeprom.sn[3] = tmp42[3];
    _g_power_state.eeprom.sn[4] = tmp42[4];
    _g_power_state.eeprom.sn[5] = tmp42[5];
    _g_power_state.eeprom.sn[6] = tmp42[6];
    _g_power_state.eeprom.sn[7] = tmp42[7];
    _g_power_state.eeprom.sn[8] = tmp42[8];
    _g_power_state.eeprom.sn[9] = tmp42[9];
    _g_power_state.eeprom.sn[10] = tmp42[10];
    _g_power_state.eeprom.sn[0xb] = tmp42[0xb];
    _g_power_state.eeprom.sn[0xc] = tmp42[0xc];
    _g_power_state.eeprom.sn[0xd] = tmp42[0xd];
    _g_power_state.eeprom.sn[0xe] = tmp42[0xe];
    _g_power_state.eeprom.sn[0xf] = tmp42[0xf];
    _g_power_state.eeprom.sn._16_2_ = SUB42(tmp42._16_4_,0);
    _g_power_state.eeprom.c_date =
         (uVar4 + uVar14 * -0x1f & 0xffff) +
         ((uint)((int)((ulonglong)uVar4 * 0xb02c0b03 >> 0x20) << 8) >> 0x10) * 10000 +
         ((uVar14 & 0xffff) % 0xc) * 100 + 0x65;
    pbVar17 = pbVar19;
    do {
      pbVar17 = pbVar17 + 1;
      if (*pbVar17 == 0x80) {
        iVar28 = iVar25 + 1;
        goto LAB_000cc46c;
      }
      iVar25 = iVar25 + 1;
    } while (iVar25 != 0xe);
    iVar28 = 0xf;
LAB_000cc46c:
    uVar14 = _g_power_state.power_version - 100;
    bVar31 = 0x61 < _g_power_state.power_version;
    bVar29 = _g_power_state.power_version == 0x62;
    if (!bVar29) {
      bVar31 = 1 < uVar14;
    }
    bVar30 = uVar14 == 2;
    iVar9 = (int)(short)((ushort)buffer[0xd] + (ushort)buffer[0xc] * 0x100);
    if (!bVar31 || (bVar29 || bVar30)) {
      iVar23 = 1;
    }
    if (bVar31 && (!bVar29 && !bVar30)) {
      iVar23 = 0;
    }
    _g_power_state.eeprom.num = iVar28;
    if (!bVar31 || (bVar29 || bVar30)) {
      uVar5 = _g_power_state.eeprom.sn._0_4_;
      uVar8 = _g_power_state.eeprom.sn._4_4_;
      uVar11 = _g_power_state.eeprom.sn._8_4_;
      uVar16 = _g_power_state.eeprom.sn._12_4_;
      if ((iVar28 != 1) &&
         ((_g_power_state.power_version == 0x62 ||
          (((0x61 < _g_power_state.power_version && (uVar14 < 3)) &&
           ((_g_power_state.power_version == 0x62 || (0x61 < _g_power_state.power_version)))))))) {
        paVar13 = &_g_power_state.eeprom.field_2;
        iVar23 = 0;
        do {
          iVar24 = iVar23 + 1;
          paVar13->V[0] =
               21.6 - (double)(longlong)iVar23 *
                      (4.600000000000001 / (double)(longlong)(iVar28 + -1));
          paVar13 = (anon_union_160_2_9472fda9_for_eeprom_data_t_2 *)(paVar13->V + 1);
          iVar23 = iVar24;
        } while (iVar24 != iVar28);
        _g_power_state.eeprom.vol[0] =
             (double)CONCAT71(_g_power_state.eeprom.field_2._1_7_,_g_power_state.eeprom.field_2.N[0]
                             ) + (double)(longlong)iVar9 / 1000.0;
        if (iVar25 != 0) {
          paVar13 = &_g_power_state.eeprom.field_2;
          pdVar26 = _g_power_state.eeprom.vol;
          do {
            paVar13 = (anon_union_160_2_9472fda9_for_eeprom_data_t_2 *)(paVar13->V + 1);
            pdVar26 = pdVar26 + 1;
            pbVar19 = pbVar19 + 1;
            iVar9 = iVar9 + (char)*pbVar19;
            *pdVar26 = (double)(longlong)iVar9 / 1000.0 + paVar13->V[0];
          } while ((byte *)((int)buffer + iVar25 + 0xd) != pbVar19);
        }
        goto LAB_000cc536;
      }
    }
    else if (iVar25 - 1U < 0xff) {
      pcVar27 = (char *)((int)&_g_power_state.eeprom.num + 3);
      do {
        iVar24 = iVar23 + 1;
        dVar32 = round((double)(longlong)iVar23 * (255.0 / (double)(longlong)(iVar28 + -1)));
        pcVar27 = pcVar27 + 1;
        *pcVar27 = (0.0 < dVar32) * (char)(longlong)dVar32;
        iVar23 = iVar24;
      } while (iVar24 != iVar28);
      dVar32 = bitmain_convert_N_to_V_furmula((uint)_g_power_state.eeprom.field_2.N[0]);
      paVar13 = &_g_power_state.eeprom.field_2;
      pdVar26 = _g_power_state.eeprom.vol;
      _g_power_state.eeprom.vol[0] = (double)(longlong)iVar9 / 1000.0 + dVar32;
      do {
        pdVar26 = pdVar26 + 1;
        pbVar19 = pbVar19 + 1;
        paVar13 = (anon_union_160_2_9472fda9_for_eeprom_data_t_2 *)(paVar13->N + 1);
        iVar9 = iVar9 + (char)*pbVar19;
        dVar32 = bitmain_convert_N_to_V_furmula((uint)paVar13->N[0]);
        *pdVar26 = (double)(longlong)iVar9 / extraout_d4 + dVar32;
      } while (pbVar19 != (byte *)((int)buffer + iVar25 + 0xd));
LAB_000cc536:
      _g_power_state.power_Calibrated = true;
      builtin_strncpy(tmp42,"power is Calibrated\n",0x14);
      tmp42._20_4_ = tmp42._20_4_ & 0xffffff00;
      _applog(1,tmp42,false);
      return 0;
    }
  }
  else {
    builtin_strncpy(tmp42,"calibration data crc err",0x18);
    tmp42._24_4_ = tmp42._24_4_ & 0xffffff00;
    _applog(0,tmp42,false);
    uVar5 = _g_power_state.eeprom.sn._0_4_;
    uVar8 = _g_power_state.eeprom.sn._4_4_;
    uVar11 = _g_power_state.eeprom.sn._8_4_;
    uVar16 = _g_power_state.eeprom.sn._12_4_;
  }
LAB_000cc1be:
  _g_power_state.eeprom.sn._12_4_ = uVar16;
  _g_power_state.eeprom.sn._8_4_ = uVar11;
  _g_power_state.eeprom.sn._4_4_ = uVar8;
  _g_power_state.eeprom.sn._0_4_ = uVar5;
  _g_power_state.power_Calibrated = false;
  builtin_strncpy(tmp42,"power is not Calibrated\n",0x18);
  tmp42._24_4_ = tmp42._24_4_ & 0xffffff00;
  _applog(1,tmp42,false);
  return 0;
}

