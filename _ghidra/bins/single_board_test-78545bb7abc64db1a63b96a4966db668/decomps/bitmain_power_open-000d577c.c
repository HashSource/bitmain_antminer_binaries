
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

int32_t bitmain_power_open(void)

{
  byte *pbVar1;
  byte bVar2;
  short sVar3;
  int32_t iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint8_t addr;
  uint32_t uVar14;
  int iVar15;
  uint uVar16;
  byte *pbVar17;
  uint uVar18;
  anon_union_160_2_9472fda9_for_eeprom_data_t_2 *paVar19;
  uint uVar20;
  uint uVar21;
  uchar *puVar22;
  int iVar23;
  int iVar24;
  byte *pbVar25;
  uchar *puVar26;
  int iVar27;
  double *pdVar28;
  int iVar29;
  char *pcVar30;
  int iVar31;
  bool bVar32;
  double dVar33;
  double dVar34;
  uint64_t u64;
  iic_init_param_t iic;
  char SN [18];
  uchar buffer2 [20];
  uchar buffer [32];
  char tmp42 [2048];
  
  if ((_g_power_state.power_fd != 0) && (_g_power_state.power_open != 0)) {
    return _g_power_state.power_fd;
  }
  iic.chain_id = 0;
  iic.i2c_path = (char *)0x0;
  iic.master_addr = 1;
  iic.slave_high = '\x02';
  iic.slave_low = '\0';
  pthread_mutex_lock((pthread_mutex_t *)&power_mutex);
  uVar14 = iic_init(&iic);
  pthread_mutex_unlock((pthread_mutex_t *)&power_mutex);
  if ((int)uVar14 < 0) {
    return uVar14;
  }
  _g_power_state.power_open = 1;
  _g_power_state.power_fd = uVar14;
  uVar14 = bitmain_power_version();
  if ((int)uVar14 < 0) {
    builtin_strncpy(tmp42,"power open power_version < 0 will close powe",0x2c);
    tmp42[0x2c] = 'r';
    tmp42[0x2d] = '\n';
    tmp42[0x2e] = '\0';
    _applog(3,tmp42,false);
    if (_g_power_state.power_open == 0) {
      return uVar14;
    }
    bitmain_power_close();
    return uVar14;
  }
  _g_power_state.power_version = uVar14;
  snprintf(tmp42,0x800,"power open power_version = 0x%x\n",uVar14);
  _applog(3,tmp42,false);
  if (_g_power_state.power_version - 0xc1 < 2) {
    uVar14 = _bitmain_get_power_fw_version(_g_power_state.power_fd);
    snprintf(tmp42,0x800,"power fw_version = 0x%x\n",uVar14);
    _applog(0,tmp42,false);
    _g_power_state.power_fw_version = uVar14;
  }
  uVar14 = _g_power_state.power_version;
  memset(&_g_power_state.eeprom,0,0x160);
  uVar20 = uVar14 & 0xffff;
  if (uVar20 == 0x6a) {
LAB_000d5c56:
    addr = '\0';
  }
  else {
    uVar6 = _g_calibration_data._0_4_;
    uVar7 = _g_calibration_data._4_4_;
    uVar8 = _g_calibration_data._8_4_;
    uVar9 = _g_calibration_data._12_4_;
    uVar10 = _g_calibration_data._16_4_;
    uVar11 = _g_calibration_data._20_4_;
    uVar12 = _g_calibration_data._24_4_;
    uVar13 = _g_calibration_data._28_4_;
    if (uVar20 < 0x6b) {
      if (uVar20 != 0x62) {
        if (uVar20 < 99) {
          if (uVar20 != 0x1a) {
            if (uVar20 != 0x41) goto switchD_000d5bcc_caseD_63;
            goto LAB_000d584e;
          }
        }
        else if (2 < uVar20 - 100) goto switchD_000d5bcc_caseD_63;
      }
      goto LAB_000d5c56;
    }
    if (0x78 < uVar20) {
      if (1 < uVar20 - 0xc1) goto switchD_000d5bcc_caseD_63;
      goto LAB_000d5c56;
    }
    if (((uVar20 < 0x75) && (uVar20 != 0x71)) && (uVar20 != 0x73)) goto switchD_000d5bcc_caseD_63;
LAB_000d584e:
    addr = '@';
  }
  uVar20 = uVar14 & 0xfffffff7;
  bVar32 = 0x61 < uVar20;
  if (uVar20 != 0x62) {
    bVar32 = 1 < uVar14 - 100;
  }
  if (!bVar32 || (uVar20 == 0x62 || uVar14 - 100 == 2)) {
    iVar15 = bitmain_power_read_v2(addr,buffer,' ');
    uVar6 = _g_calibration_data._0_4_;
    uVar7 = _g_calibration_data._4_4_;
    uVar8 = _g_calibration_data._8_4_;
    uVar9 = _g_calibration_data._12_4_;
    uVar10 = _g_calibration_data._16_4_;
    uVar11 = _g_calibration_data._20_4_;
    uVar12 = _g_calibration_data._24_4_;
    uVar13 = _g_calibration_data._28_4_;
    _g_calibration_data._0_4_ = buffer._0_4_;
    _g_calibration_data._4_4_ = buffer._4_4_;
    _g_calibration_data._8_4_ = buffer._8_4_;
    _g_calibration_data._12_4_ = buffer._12_4_;
    _g_calibration_data._16_4_ = buffer._16_4_;
    _g_calibration_data._20_4_ = buffer._20_4_;
    _g_calibration_data._24_4_ = buffer._24_4_;
    _g_calibration_data._28_4_ = buffer._28_4_;
  }
  else {
    iVar15 = bitmain_power_read(addr,buffer,' ');
    uVar6 = _g_calibration_data._0_4_;
    uVar7 = _g_calibration_data._4_4_;
    uVar8 = _g_calibration_data._8_4_;
    uVar9 = _g_calibration_data._12_4_;
    uVar10 = _g_calibration_data._16_4_;
    uVar11 = _g_calibration_data._20_4_;
    uVar12 = _g_calibration_data._24_4_;
    uVar13 = _g_calibration_data._28_4_;
    _g_calibration_data._0_4_ = buffer._0_4_;
    _g_calibration_data._4_4_ = buffer._4_4_;
    _g_calibration_data._8_4_ = buffer._8_4_;
    _g_calibration_data._12_4_ = buffer._12_4_;
    _g_calibration_data._16_4_ = buffer._16_4_;
    _g_calibration_data._20_4_ = buffer._20_4_;
    _g_calibration_data._24_4_ = buffer._24_4_;
    _g_calibration_data._28_4_ = buffer._28_4_;
  }
  if (iVar15 != 0) goto switchD_000d5bcc_caseD_63;
  builtin_strncpy(tmp42,"power calibration data:",0x18);
  buffer._0_4_ = _g_calibration_data._0_4_;
  buffer._4_4_ = _g_calibration_data._4_4_;
  buffer._8_4_ = _g_calibration_data._8_4_;
  buffer._12_4_ = _g_calibration_data._12_4_;
  buffer._28_4_ = _g_calibration_data._28_4_;
  _applog(0,tmp42,false);
  pbVar25 = buffer;
  do {
    pbVar17 = pbVar25 + 3;
    pbVar1 = pbVar25 + 2;
    uVar20 = (uint)pbVar25[1];
    bVar2 = *pbVar25;
    pbVar25 = pbVar25 + 4;
    snprintf(tmp42,0x800,"%2X %2X %2X %2X  ",(uint)bVar2,uVar20,(uint)*pbVar1,(uint)*pbVar17);
    _applog(0,tmp42,false);
    uVar6 = tmp42._32_4_;
    uVar5 = buffer._0_4_;
  } while (pbVar25 != (byte *)tmp42);
  uVar16 = 0xff;
  uVar18 = 0xff;
  pbVar25 = buffer;
  do {
    pbVar17 = pbVar25 + 1;
    uVar21 = uVar18 ^ *pbVar25;
    uVar18 = ""[uVar21] ^ uVar16;
    uVar16 = (uint)""[uVar21];
    pbVar25 = pbVar17;
  } while (pbVar17 != buffer + 0x1e);
  if ((uint)CONCAT11(buffer[0x1e],buffer[0x1f]) != (uVar18 | uVar16 << 8)) {
LAB_000d5dfe:
    builtin_strncpy(tmp42,"calibration data crc err",0x18);
    tmp42._24_4_ = tmp42._24_4_ & 0xffffff00;
    _applog(0,tmp42,false);
    uVar6 = _g_calibration_data._0_4_;
    uVar7 = _g_calibration_data._4_4_;
    uVar8 = _g_calibration_data._8_4_;
    uVar9 = _g_calibration_data._12_4_;
    uVar10 = _g_calibration_data._16_4_;
    uVar11 = _g_calibration_data._20_4_;
    uVar12 = _g_calibration_data._24_4_;
    uVar13 = _g_calibration_data._28_4_;
    goto switchD_000d5bcc_caseD_63;
  }
  if ((_g_calibration_mode != 0) && ((buffer._0_4_ & 0xfe) == 8)) {
    if (_g_calibration_mode != 1) {
      builtin_strncpy(tmp42,"calibration  current not supported",0x23);
      tmp42[0x23] = SUB41(uVar6,3);
      _applog(0,tmp42,false);
      uVar6 = _g_calibration_data._0_4_;
      uVar7 = _g_calibration_data._4_4_;
      uVar8 = _g_calibration_data._8_4_;
      uVar9 = _g_calibration_data._12_4_;
      uVar10 = _g_calibration_data._16_4_;
      uVar11 = _g_calibration_data._20_4_;
      uVar12 = _g_calibration_data._24_4_;
      uVar13 = _g_calibration_data._28_4_;
      goto switchD_000d5bcc_caseD_63;
    }
    uVar16 = _g_power_state.power_version & 0xfffffff7;
    bVar32 = 0x61 < uVar16;
    if (uVar16 != 0x62) {
      bVar32 = 1 < _g_power_state.power_version - 100;
    }
    if (!bVar32 || (uVar16 == 0x62 || _g_power_state.power_version - 100 == 2)) {
      iVar15 = bitmain_power_read_v2(' ',buffer2,'\x14');
    }
    else {
      iVar15 = bitmain_power_read(' ',buffer2,'\x14');
    }
    uVar6 = _g_calibration_data._0_4_;
    uVar7 = _g_calibration_data._4_4_;
    uVar8 = _g_calibration_data._8_4_;
    uVar9 = _g_calibration_data._12_4_;
    uVar10 = _g_calibration_data._16_4_;
    uVar11 = _g_calibration_data._20_4_;
    uVar12 = _g_calibration_data._24_4_;
    uVar13 = _g_calibration_data._28_4_;
    if (iVar15 != 0) goto switchD_000d5bcc_caseD_63;
    uVar16 = 0xff;
    uVar18 = 0xff;
    pbVar25 = buffer2;
    do {
      pbVar17 = pbVar25 + 1;
      uVar21 = *pbVar25 ^ uVar18;
      uVar18 = ""[uVar21] ^ uVar16;
      uVar16 = (uint)""[uVar21];
      pbVar25 = pbVar17;
    } while (pbVar17 != buffer2 + 0x11);
    if ((uint)CONCAT11(buffer2[0x11],buffer2[0x12]) != (uVar18 | uVar16 << 8)) goto LAB_000d5dfe;
  }
  iVar4 = _g_calibration_mode;
  SN[4] = '\0';
  SN[5] = '\0';
  SN[6] = '\0';
  SN[7] = '\0';
  SN[8] = '\0';
  SN[9] = '\0';
  SN[10] = '\0';
  SN[0xb] = '\0';
  SN[0xc] = '\0';
  SN[0xd] = '\0';
  SN[0xe] = '\0';
  SN[0xf] = '\0';
  stack0xfffff798 = stack0xfffff798 & 0xffff0000;
  SN[0] = '\0';
  SN[1] = '\0';
  SN[2] = '\0';
  SN[3] = '\0';
  ulltostr(SN,0xc,CONCAT44(buffer._0_4_ << 0x18 | ((uint)buffer._0_4_ >> 8 & 0xff) << 0x10 |
                           ((uint)buffer._0_4_ >> 0x10 & 0xff) << 8 | (uint)buffer._0_4_ >> 0x18,
                           buffer._4_4_ << 0x18 | ((uint)buffer._4_4_ >> 8 & 0xff) << 0x10 |
                           ((uint)buffer._4_4_ >> 0x10 & 0xff) << 8 | (uint)buffer._4_4_ >> 0x18) &
                  0x1ffffffffffffff,uVar20);
  ulltostr(SN + 0xb,7,
           (ulonglong)
           (buffer._8_4_ << 0x18 | ((uint)buffer._8_4_ >> 8 & 0xff) << 0x10 |
            ((uint)buffer._8_4_ >> 0x10 & 0xff) << 8 | (uint)buffer._8_4_ >> 0x18),uVar20);
  uVar20 = (uint)CONCAT11(buffer[0x1c],buffer[0x1d]);
  sVar3 = ((ushort)buffer._12_2_ >> 8) + buffer._12_2_ * 0x100;
  uVar16 = uVar20 / 0x1f + (uVar20 - uVar20 / 0x1f >> 1) >> 4;
  _g_power_state.eeprom.sn[0] = SN[0];
  _g_power_state.eeprom.sn[1] = SN[1];
  _g_power_state.eeprom.sn[2] = SN[2];
  _g_power_state.eeprom.sn[3] = SN[3];
  _g_power_state.eeprom.sn[4] = SN[4];
  _g_power_state.eeprom.sn[5] = SN[5];
  _g_power_state.eeprom.sn[6] = SN[6];
  _g_power_state.eeprom.sn[7] = SN[7];
  _g_power_state.eeprom.sn[8] = SN[8];
  _g_power_state.eeprom.sn[9] = SN[9];
  _g_power_state.eeprom.sn[10] = SN[10];
  _g_power_state.eeprom.sn[0xb] = SN[0xb];
  _g_power_state.eeprom.sn[0xc] = SN[0xc];
  _g_power_state.eeprom.sn[0xd] = SN[0xd];
  _g_power_state.eeprom.sn[0xe] = SN[0xe];
  _g_power_state.eeprom.sn[0xf] = SN[0xf];
  _g_power_state.eeprom.sn._16_2_ = SUB42(stack0xfffff798,0);
  _g_power_state.eeprom.c_date =
       (uVar20 + uVar16 * -0x1f & 0xffff) + 1 +
       ((uint)((int)((ulonglong)uVar20 * 0xb02c0b03 >> 0x20) << 8) >> 0x10) * 10000 +
       ((uVar16 & 0xffff) % 0xc + 1) * 100;
  if ((iVar4 == 0) || ((uVar5 & 0xfe) != 8)) {
    puVar26 = buffer + 0xe;
  }
  else {
    puVar26 = buffer2 + 3;
    sVar3 = (ushort)buffer2[2] + (ushort)buffer2[1] * 0x100;
  }
  iVar31 = (int)sVar3;
  puVar26 = puVar26 + -1;
  iVar15 = 0;
  puVar22 = puVar26;
  do {
    puVar22 = puVar22 + 1;
    uVar6 = _g_calibration_data._0_4_;
    uVar7 = _g_calibration_data._4_4_;
    uVar8 = _g_calibration_data._8_4_;
    uVar9 = _g_calibration_data._12_4_;
    uVar10 = _g_calibration_data._16_4_;
    uVar11 = _g_calibration_data._20_4_;
    uVar12 = _g_calibration_data._24_4_;
    uVar13 = _g_calibration_data._28_4_;
    if (*puVar22 == 0x80) {
      _g_power_state.eeprom.num = iVar15 + 1;
      uVar20 = _g_power_state.power_version & 0xfffffff7;
      bVar32 = 0x61 < uVar20;
      if (uVar20 != 0x62) {
        bVar32 = 1 < _g_power_state.power_version - 100;
      }
      if (bVar32 && (uVar20 != 0x62 && _g_power_state.power_version - 100 != 2)) {
        if (iVar15 - 1U < 0xff) goto LAB_000d5a76;
        goto switchD_000d5bcc_caseD_63;
      }
      if (_g_power_state.eeprom.num != 1) goto LAB_000d5bc2;
      goto switchD_000d5bcc_caseD_63;
    }
    iVar15 = iVar15 + 1;
  } while (iVar15 != 0xe);
  _g_power_state.eeprom.num = 0xf;
  uVar20 = _g_power_state.power_version & 0xfffffff7;
  bVar32 = 0x61 < uVar20;
  if (uVar20 != 0x62) {
    bVar32 = 1 < _g_power_state.power_version - 100;
  }
  if (!bVar32 || (uVar20 == 0x62 || _g_power_state.power_version - 100 == 2)) {
LAB_000d5bc2:
    iVar29 = _g_power_state.eeprom.num;
    switch(_g_power_state.power_version) {
    case 0x62:
    case 100:
    case 0x65:
    case 0x66:
      if ((_g_power_state.power_version != 0x62) &&
         ((_g_power_state.power_version < 0x62 || (2 < _g_power_state.power_version - 100))))
      goto switchD_000d5bcc_caseD_63;
      dVar33 = 21.6;
      dVar34 = 17.0;
      break;
    default:
switchD_000d5bcc_caseD_63:
      _g_calibration_data._28_4_ = uVar13;
      _g_calibration_data._24_4_ = uVar12;
      _g_calibration_data._20_4_ = uVar11;
      _g_calibration_data._16_4_ = uVar10;
      _g_calibration_data._12_4_ = uVar9;
      _g_calibration_data._8_4_ = uVar8;
      _g_calibration_data._4_4_ = uVar7;
      _g_calibration_data._0_4_ = uVar6;
      _g_power_state.power_Calibrated = false;
      builtin_strncpy(tmp42,"power is not Calibrated\n",0x18);
      tmp42._24_4_ = tmp42._24_4_ & 0xffffff00;
      _applog(1,tmp42,false);
      return 0;
    case 0x6a:
      dVar33 = 16.0;
      dVar34 = 12.0;
    }
    iVar23 = _g_power_state.eeprom.num + -1;
    paVar19 = &_g_power_state.eeprom.field_2;
    iVar24 = 0;
    do {
      iVar27 = iVar24 + 1;
      paVar19->V[0] =
           dVar33 - ((dVar33 - dVar34) / (double)(longlong)iVar23) * (double)(longlong)iVar24;
      paVar19 = (anon_union_160_2_9472fda9_for_eeprom_data_t_2 *)(paVar19->V + 1);
      iVar24 = iVar27;
    } while (iVar27 < iVar29);
    _g_power_state.eeprom.vol[0] =
         (double)CONCAT71(_g_power_state.eeprom.field_2._1_7_,_g_power_state.eeprom.field_2.N[0]) +
         (double)(longlong)iVar31 / 1000.0;
    if (iVar15 != 0) {
      pdVar28 = _g_power_state.eeprom.vol;
      iVar29 = 0;
      paVar19 = &_g_power_state.eeprom.field_2;
      do {
        pdVar28 = pdVar28 + 1;
        paVar19 = (anon_union_160_2_9472fda9_for_eeprom_data_t_2 *)(paVar19->V + 1);
        puVar26 = puVar26 + 1;
        iVar29 = iVar29 + 1;
        iVar31 = iVar31 + (char)*puVar26;
        dVar33 = (double)(longlong)iVar31 / 1000.0 + paVar19->V[0];
        *pdVar28 = dVar33;
        snprintf(tmp42,0x800,"calibration data %d  %f    %f    ",iVar29,dVar33,paVar19->V[0]);
        _applog(0,tmp42,false);
      } while (iVar29 != iVar15);
    }
  }
  else {
LAB_000d5a76:
    iVar29 = _g_power_state.eeprom.num;
    iVar23 = _g_power_state.eeprom.num + -1;
    pcVar30 = (char *)((int)&_g_power_state.eeprom.num + 3);
    iVar24 = 0;
    do {
      iVar27 = iVar24 + 1;
      dVar33 = round((255.0 / (double)(longlong)iVar23) * (double)(longlong)iVar24);
      pcVar30 = pcVar30 + 1;
      *pcVar30 = (0.0 < dVar33) * (char)(longlong)dVar33;
      iVar24 = iVar27;
    } while (iVar27 != iVar29);
    dVar33 = bitmain_convert_N_to_V_furmula((uint)_g_power_state.eeprom.field_2.N[0]);
    _g_power_state.eeprom.vol[0] = dVar33 + (double)(longlong)iVar31 / 1000.0;
    if (iVar15 != 0) {
      paVar19 = &_g_power_state.eeprom.field_2;
      pdVar28 = _g_power_state.eeprom.vol;
      do {
        pdVar28 = pdVar28 + 1;
        puVar26 = puVar26 + 1;
        paVar19 = (anon_union_160_2_9472fda9_for_eeprom_data_t_2 *)(paVar19->N + 1);
        iVar31 = iVar31 + (char)*puVar26;
        dVar33 = bitmain_convert_N_to_V_furmula((uint)paVar19->N[0]);
        *pdVar28 = dVar33 + (double)(longlong)iVar31 / 1000.0;
      } while (paVar19 !=
               (anon_union_160_2_9472fda9_for_eeprom_data_t_2 *)
               (_g_power_state.eeprom.sn + iVar15 + 0x18));
    }
  }
  _g_power_state.power_Calibrated = true;
  builtin_strncpy(tmp42,"power is Calibrated\n",0x14);
  tmp42._20_4_ = tmp42._20_4_ & 0xffffff00;
  _applog(1,tmp42,false);
  return 0;
}

