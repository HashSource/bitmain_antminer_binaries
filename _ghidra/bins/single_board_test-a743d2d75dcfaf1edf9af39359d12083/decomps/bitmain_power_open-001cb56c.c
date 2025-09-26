
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

int32_t bitmain_power_open(void)

{
  uint32_t uVar1;
  int32_t iVar2;
  undefined4 uVar3;
  int32_t iVar4;
  byte *pbVar5;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  uint64_t *puVar11;
  uint8_t *puVar12;
  anon_union_160_2_9472fda9_for_eeprom_data_t_2 *paVar13;
  uint uVar14;
  uint uVar15;
  undefined4 uVar16;
  uint8_t *puVar17;
  uint8_t uVar18;
  byte bVar19;
  undefined1 unaff_r8;
  int iVar20;
  int iVar21;
  double *pdVar22;
  char *pcVar23;
  int iVar24;
  bool bVar25;
  bool bVar26;
  bool bVar27;
  double dVar28;
  int iVar29;
  iic_init_param_t iic;
  uint8_t send_data [8];
  uchar buffer [32];
  uint64_t u64;
  short local_860;
  uint8_t auStack_844 [20];
  char tmp42 [2048];
  byte *pbVar6;
  
  if ((_g_power_state.power_fd != 0) && (_g_power_state.power_open != 0)) {
    return _g_power_state.power_fd;
  }
  iic.slave_high = '\x02';
  iic.chain_id = 0;
  iic.slave_low = '\0';
  iic.master_addr = 1;
  pthread_mutex_lock((pthread_mutex_t *)&power_mutex);
  uVar1 = iic_init(&iic);
  pthread_mutex_unlock((pthread_mutex_t *)&power_mutex);
  if ((int)uVar1 < 0) {
    return uVar1;
  }
  _g_power_state.power_open = 1;
  _g_power_state.power_fd = uVar1;
  uVar1 = bitmain_power_version();
  if ((int)uVar1 < 0) {
    builtin_strncpy(tmp42,"power open power_version < 0 will close powe",0x2c);
    tmp42[0x2c] = 'r';
    tmp42[0x2d] = '\n';
    tmp42[0x2e] = '\0';
    _applog(3,tmp42,false);
    if (_g_power_state.power_open == 0) {
      return uVar1;
    }
    bitmain_power_close();
    return uVar1;
  }
  _g_power_state.power_version = uVar1;
  snprintf(tmp42,0x800,"power open power_version = 0x%x\n",uVar1);
  _applog(3,tmp42,false);
  if (_g_power_state.power_version == 0xc1) {
    iVar4 = _bitmain_get_power_fw_version(_g_power_state.power_fd);
    snprintf(tmp42,0x800,"power fw_version = 0x%x\n",iVar4);
    _applog(3,tmp42,false);
  }
  uVar1 = _g_power_state.power_version;
  memset(&_g_power_state.eeprom,0,0x160);
  uVar14 = uVar1 & 0xffff;
  if (uVar14 == 0x71) {
LAB_001cb6e2:
    bVar27 = 0x61 < uVar1;
    if (uVar1 != 0x62) {
      bVar27 = 1 < uVar1 - 100;
    }
    if (bVar27 && (uVar1 != 0x62 && uVar1 - 100 != 2)) {
      unaff_r8 = 0x6c;
      uVar18 = '@';
      goto LAB_001cb6f6;
    }
    bVar19 = 0x40;
LAB_001cb9a0:
    u64._0_4_ = 0x608aa55;
    u64._4_4_ = 0;
    local_860 = 0;
    memset(tmp42,0,0x48);
    local_860 = 0;
    u64._4_2_ = (ushort)bVar19;
    u64._4_4_ = (uint)CONCAT12(0x20,u64._4_2_);
    puVar11 = &u64;
    do {
      pbVar6 = (byte *)((int)puVar11 + 3);
      puVar11 = (uint64_t *)((int)puVar11 + 2);
      local_860 = local_860 + (ushort)*(byte *)puVar11 + (ushort)*pbVar6 * 0x100;
    } while (puVar11 != (uint64_t *)((int)&u64 + 6));
    iVar29 = 0x28;
    iVar4 = exec_power_cmd_v2(_g_power_state.power_fd,(uint8_t *)&u64,10,(uint8_t *)tmp42,0x28);
    uVar3 = _g_power_state.eeprom.sn._0_4_;
    uVar7 = _g_power_state.eeprom.sn._4_4_;
    uVar10 = _g_power_state.eeprom.sn._8_4_;
    uVar16 = _g_power_state.eeprom.sn._12_4_;
    if (iVar4 != 0) goto LAB_001cb652;
    puVar17 = (uint8_t *)(tmp42 + 5);
    puVar12 = send_data + 7;
    do {
      puVar17 = puVar17 + 1;
      puVar12 = puVar12 + 1;
      *puVar12 = *puVar17;
    } while ((uint8_t *)(tmp42 + 0x25) != puVar17);
  }
  else {
    uVar3 = _g_power_state.eeprom.sn._0_4_;
    uVar7 = _g_power_state.eeprom.sn._4_4_;
    uVar10 = _g_power_state.eeprom.sn._8_4_;
    uVar16 = _g_power_state.eeprom.sn._12_4_;
    if (uVar14 < 0x72) {
      if (uVar14 != 0x62) {
        if (uVar14 < 99) {
          if (uVar14 != 0x41) goto LAB_001cb652;
          goto LAB_001cb6e2;
        }
        if (2 < uVar14 - 100) goto LAB_001cb652;
      }
    }
    else {
      if (uVar14 < 0x79) {
        if ((uVar14 < 0x75) && (uVar14 != 0x73)) goto LAB_001cb652;
        goto LAB_001cb6e2;
      }
      if (uVar14 != 0xc1) goto LAB_001cb652;
    }
    bVar27 = 0x61 < uVar1;
    bVar25 = uVar1 == 0x62;
    if (!bVar25) {
      bVar27 = 1 < uVar1 - 100;
    }
    bVar26 = uVar1 - 100 != 2;
    if (!bVar27 || (bVar25 || !bVar26)) {
      uVar1 = 1;
    }
    uVar18 = (uint8_t)uVar1;
    if (bVar27 && (!bVar25 && bVar26)) {
      uVar18 = '\0';
    }
    if (bVar27 && (!bVar25 && bVar26)) {
      unaff_r8 = 0x2c;
    }
    if (!bVar27 || (bVar25 || !bVar26)) {
      bVar19 = 0;
      goto LAB_001cb9a0;
    }
LAB_001cb6f6:
    iVar4 = 0;
    send_data[4] = '\0';
    send_data[5] = '\0';
    send_data[6] = '\0';
    send_data[7] = '\0';
    memset(&u64,0,0x32);
    send_data[6] = unaff_r8;
    send_data[0] = 'U';
    send_data[1] = 0xaa;
    send_data[5] = ' ';
    send_data[4] = uVar18;
    send_data[2] = '\x06';
    send_data[3] = '\x06';
    if ((_g_power_state.power_open == 0) && (iVar4 = bitmain_power_open(), iVar4 < 0)) {
      snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
               "bitmain_power_read");
      _applog(0,tmp42,false);
      uVar3 = _g_power_state.eeprom.sn._0_4_;
      uVar7 = _g_power_state.eeprom.sn._4_4_;
      uVar10 = _g_power_state.eeprom.sn._8_4_;
      uVar16 = _g_power_state.eeprom.sn._12_4_;
      goto LAB_001cb652;
    }
    iVar29 = 0x27;
    iVar2 = exec_power_cmd(_g_power_state.power_fd,send_data,8,(uint8_t *)&u64,0x27);
    puVar17 = (uint8_t *)((int)&u64 + 4);
    puVar12 = send_data + 7;
    if (iVar2 != 0) {
      builtin_strncpy(tmp42,"set DA conversion N failed\n",0x1c);
      _applog(0,tmp42,false);
      uVar3 = _g_power_state.eeprom.sn._0_4_;
      uVar7 = _g_power_state.eeprom.sn._4_4_;
      uVar10 = _g_power_state.eeprom.sn._8_4_;
      uVar16 = _g_power_state.eeprom.sn._12_4_;
      goto LAB_001cb652;
    }
    do {
      puVar17 = puVar17 + 1;
      puVar12 = puVar12 + 1;
      *puVar12 = *puVar17;
    } while (puVar17 != auStack_844);
    uVar3 = _g_power_state.eeprom.sn._0_4_;
    uVar7 = _g_power_state.eeprom.sn._4_4_;
    uVar10 = _g_power_state.eeprom.sn._8_4_;
    uVar16 = _g_power_state.eeprom.sn._12_4_;
    if (iVar4 != 0) goto LAB_001cb652;
  }
  uVar14 = 0xff;
  uVar9 = 0xff;
  pbVar6 = buffer;
  do {
    pbVar5 = pbVar6 + 1;
    uVar15 = *pbVar6 ^ uVar9;
    uVar9 = ""[uVar15] ^ uVar14;
    uVar14 = (uint)""[uVar15];
    pbVar6 = pbVar5;
  } while (pbVar5 != buffer + 0x1e);
  uVar3 = _g_power_state.eeprom.sn._0_4_;
  uVar7 = _g_power_state.eeprom.sn._4_4_;
  uVar10 = _g_power_state.eeprom.sn._8_4_;
  uVar16 = _g_power_state.eeprom.sn._12_4_;
  if ((uint)CONCAT11(buffer[0x1e],buffer[0x1f]) == (uVar9 | uVar14 << 8)) {
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
    iVar21 = 0;
    tmp42[8] = '\0';
    tmp42[9] = '\0';
    tmp42[10] = '\0';
    tmp42[0xb] = '\0';
    pbVar5 = buffer + 0xd;
    tmp42[0xc] = '\0';
    tmp42[0xd] = '\0';
    tmp42[0xe] = '\0';
    tmp42[0xf] = '\0';
    tmp42._16_4_ = (uint)(ushort)tmp42._18_2_ << 0x10;
    ulltostr(tmp42,0xc,CONCAT44(u64._4_4_,(uint)u64) & 0x1ffffffffffffff,iVar29);
    ulltostr(tmp42 + 0xb,7,
             (ulonglong)
             (buffer._8_4_ << 0x18 | ((uint)buffer._8_4_ >> 8 & 0xff) << 0x10 |
              ((uint)buffer._8_4_ >> 0x10 & 0xff) << 8 | (uint)buffer._8_4_ >> 0x18),iVar29);
    uVar9 = (uint)CONCAT11(buffer[0x1c],buffer[0x1d]);
    uVar14 = uVar9 / 0x1f + (uVar9 - uVar9 / 0x1f >> 1) >> 4;
    uVar3._0_1_ = tmp42[0];
    uVar3._1_1_ = tmp42[1];
    uVar3._2_1_ = tmp42[2];
    uVar3._3_1_ = tmp42[3];
    uVar7._0_1_ = tmp42[4];
    uVar7._1_1_ = tmp42[5];
    uVar7._2_1_ = tmp42[6];
    uVar7._3_1_ = tmp42[7];
    uVar10._0_1_ = tmp42[8];
    uVar10._1_1_ = tmp42[9];
    uVar10._2_1_ = tmp42[10];
    uVar10._3_1_ = tmp42[0xb];
    uVar16._0_1_ = tmp42[0xc];
    uVar16._1_1_ = tmp42[0xd];
    uVar16._2_1_ = tmp42[0xe];
    uVar16._3_1_ = tmp42[0xf];
    iVar29 = ((uint)((int)((ulonglong)uVar9 * 0xb02c0b03 >> 0x20) << 8) >> 0x10) * 10000 +
             ((uVar14 & 0xffff) % 0xc) * 100 + 100;
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
    _g_power_state.eeprom.c_date = iVar29 + (uVar9 + uVar14 * -0x1f & 0xffff) + 1;
    pbVar6 = pbVar5;
    do {
      pbVar6 = pbVar6 + 1;
      if (*pbVar6 == 0x80) {
        iVar24 = iVar21 + 1;
        goto LAB_001cb89e;
      }
      iVar21 = iVar21 + 1;
    } while (iVar21 != 0xe);
    iVar24 = 0xf;
LAB_001cb89e:
    uVar14 = _g_power_state.power_version - 100;
    bVar27 = 0x61 < _g_power_state.power_version;
    bVar25 = _g_power_state.power_version == 0x62;
    if (!bVar25) {
      bVar27 = 1 < uVar14;
    }
    bVar26 = uVar14 == 2;
    iVar8 = (int)(short)((ushort)buffer[0xd] + (ushort)buffer[0xc] * 0x100);
    if (!bVar27 || (bVar25 || bVar26)) {
      iVar29 = 1;
    }
    if (bVar27 && (!bVar25 && !bVar26)) {
      iVar29 = 0;
    }
    _g_power_state.eeprom.num = iVar24;
    if (!bVar27 || (bVar25 || bVar26)) {
      uVar3 = _g_power_state.eeprom.sn._0_4_;
      uVar7 = _g_power_state.eeprom.sn._4_4_;
      uVar10 = _g_power_state.eeprom.sn._8_4_;
      uVar16 = _g_power_state.eeprom.sn._12_4_;
      if ((iVar24 != 1) &&
         ((_g_power_state.power_version == 0x62 ||
          (((0x61 < _g_power_state.power_version && (uVar14 < 3)) &&
           ((_g_power_state.power_version == 0x62 || (0x61 < _g_power_state.power_version)))))))) {
        paVar13 = &_g_power_state.eeprom.field_2;
        iVar29 = 0;
        do {
          iVar20 = iVar29 + 1;
          paVar13->V[0] =
               21.6 - (double)(longlong)iVar29 *
                      (4.600000000000001 / (double)(longlong)(iVar24 + -1));
          paVar13 = (anon_union_160_2_9472fda9_for_eeprom_data_t_2 *)(paVar13->V + 1);
          iVar29 = iVar20;
        } while (iVar20 != iVar24);
        _g_power_state.eeprom.vol[0] =
             (double)CONCAT71(_g_power_state.eeprom.field_2._1_7_,_g_power_state.eeprom.field_2.N[0]
                             ) + (double)(longlong)iVar8 / 1000.0;
        if (iVar21 != 0) {
          paVar13 = &_g_power_state.eeprom.field_2;
          pdVar22 = _g_power_state.eeprom.vol;
          do {
            paVar13 = (anon_union_160_2_9472fda9_for_eeprom_data_t_2 *)(paVar13->V + 1);
            pdVar22 = pdVar22 + 1;
            pbVar5 = pbVar5 + 1;
            iVar8 = iVar8 + (char)*pbVar5;
            *pdVar22 = (double)(longlong)iVar8 / 1000.0 + paVar13->V[0];
          } while (buffer + iVar21 + 0xd != pbVar5);
        }
        goto LAB_001cb968;
      }
    }
    else if (iVar21 - 1U < 0xff) {
      pcVar23 = (char *)((int)&_g_power_state.eeprom.num + 3);
      do {
        iVar20 = iVar29 + 1;
        dVar28 = round((double)(longlong)iVar29 * (255.0 / (double)(longlong)(iVar24 + -1)));
        pcVar23 = pcVar23 + 1;
        *pcVar23 = (0.0 < dVar28) * (char)(longlong)dVar28;
        iVar29 = iVar20;
      } while (iVar20 != iVar24);
      dVar28 = bitmain_convert_N_to_V_furmula((uint)_g_power_state.eeprom.field_2.N[0]);
      paVar13 = &_g_power_state.eeprom.field_2;
      pdVar22 = _g_power_state.eeprom.vol;
      _g_power_state.eeprom.vol[0] = (double)(longlong)iVar8 / 1000.0 + dVar28;
      do {
        pdVar22 = pdVar22 + 1;
        pbVar5 = pbVar5 + 1;
        paVar13 = (anon_union_160_2_9472fda9_for_eeprom_data_t_2 *)(paVar13->N + 1);
        iVar8 = iVar8 + (char)*pbVar5;
        dVar28 = bitmain_convert_N_to_V_furmula((uint)paVar13->N[0]);
        *pdVar22 = (double)(longlong)iVar8 / 1000.0 + dVar28;
      } while (pbVar5 != buffer + iVar21 + 0xd);
LAB_001cb968:
      _g_power_state.power_Calibrated = true;
      builtin_strncpy(tmp42,"power is Calibrated\n",0x14);
      tmp42._20_4_ = tmp42._20_4_ & 0xffffff00;
      _applog(3,tmp42,false);
      return 0;
    }
  }
LAB_001cb652:
  _g_power_state.eeprom.sn._12_4_ = uVar16;
  _g_power_state.eeprom.sn._8_4_ = uVar10;
  _g_power_state.eeprom.sn._4_4_ = uVar7;
  _g_power_state.eeprom.sn._0_4_ = uVar3;
  _g_power_state.power_Calibrated = false;
  builtin_strncpy(tmp42,"power is not Calibrated\n",0x18);
  tmp42._24_4_ = tmp42._24_4_ & 0xffffff00;
  _applog(3,tmp42,false);
  return 0;
}

