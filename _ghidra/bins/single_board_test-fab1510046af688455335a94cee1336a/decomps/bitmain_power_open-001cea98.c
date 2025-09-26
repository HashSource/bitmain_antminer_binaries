
/* WARNING: Variable defined which should be unmapped: u64 */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: stack */
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
  bitmain_power_t *pbVar25;
  uchar *puVar26;
  byte *pbVar27;
  int iVar28;
  double *pdVar29;
  uchar *puVar30;
  int iVar31;
  int iVar32;
  char *pcVar33;
  int iVar34;
  bool bVar35;
  double dVar36;
  double extraout_d4;
  double dVar37;
  uint64_t u64;
  iic_init_param_t iic;
  char SN [18];
  undefined2 uStack_866;
  uchar buffer2 [20];
  uchar buffer [32];
  char tmp42 [2048];
  
  pbVar25 = &_g_power_state;
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
  if (_g_power_state.power_version - 0xc1 < 2 ||
      (_g_power_state.power_version == 0x6a || _g_power_state.power_version == 0x73)) {
    uVar14 = _bitmain_get_power_fw_version(_g_power_state.power_fd);
    snprintf(tmp42,0x800,"power fw_version = 0x%x\n",uVar14);
    _applog(0,tmp42,false);
    _g_power_state.power_fw_version = uVar14;
  }
  uVar14 = _g_power_state.power_version;
  memset(&_g_power_state.eeprom,0,0x160);
  uVar20 = uVar14 & 0xffff;
  if (uVar20 == 0x6a) {
LAB_001cef98:
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
            if (uVar20 != 0x41) goto switchD_001cef4a_caseD_1;
            goto LAB_001ceb94;
          }
        }
        else if (2 < uVar20 - 100) goto switchD_001cef4a_caseD_1;
      }
      goto LAB_001cef98;
    }
    if (0x78 < uVar20) {
      if (1 < uVar20 - 0xc1) goto switchD_001cef4a_caseD_1;
      goto LAB_001cef98;
    }
    if (((uVar20 < 0x75) && (uVar20 != 0x71)) && (uVar20 != 0x73)) goto switchD_001cef4a_caseD_1;
LAB_001ceb94:
    addr = '@';
  }
  uVar20 = uVar14 & 0xfffffff7;
  bVar35 = 0x61 < uVar20;
  if (uVar20 != 0x62) {
    bVar35 = 1 < uVar14 - 100;
  }
  if (!bVar35 || (uVar20 == 0x62 || uVar14 - 100 == 2)) {
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
  if (iVar15 != 0) goto switchD_001cef4a_caseD_1;
  builtin_strncpy(tmp42,"power calibration data:",0x18);
  buffer._0_4_ = _g_calibration_data._0_4_;
  buffer._4_4_ = _g_calibration_data._4_4_;
  buffer._8_4_ = _g_calibration_data._8_4_;
  buffer._12_4_ = _g_calibration_data._12_4_;
  buffer._28_4_ = _g_calibration_data._28_4_;
  _applog(0,tmp42,false);
  pbVar27 = buffer;
  do {
    pbVar17 = pbVar27 + 3;
    pbVar1 = pbVar27 + 2;
    uVar20 = (uint)pbVar27[1];
    bVar2 = *pbVar27;
    pbVar27 = pbVar27 + 4;
    snprintf(tmp42,0x800,"%2X %2X %2X %2X  ",(uint)bVar2,uVar20,(uint)*pbVar1,(uint)*pbVar17);
    _applog(0,tmp42,false);
    uVar6 = tmp42._32_4_;
    uVar5 = buffer._0_4_;
  } while ((byte *)tmp42 != pbVar27);
  uVar16 = 0xff;
  uVar18 = 0xff;
  pbVar27 = buffer;
  do {
    pbVar17 = pbVar27 + 1;
    uVar21 = *pbVar27 ^ uVar18;
    uVar18 = ""[uVar21] ^ uVar16;
    uVar16 = (uint)""[uVar21];
    pbVar27 = pbVar17;
  } while (pbVar17 != buffer + 0x1e);
  if ((uint)CONCAT11(buffer[0x1e],buffer[0x1f]) != (uVar18 | uVar16 << 8)) {
LAB_001cf13e:
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
    goto switchD_001cef4a_caseD_1;
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
      goto switchD_001cef4a_caseD_1;
    }
    uVar16 = _g_power_state.power_version & 0xfffffff7;
    bVar35 = 0x61 < uVar16;
    if (uVar16 != 0x62) {
      bVar35 = 1 < _g_power_state.power_version - 100;
    }
    if (!bVar35 || (uVar16 == 0x62 || _g_power_state.power_version - 100 == 2)) {
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
    if (iVar15 != 0) goto switchD_001cef4a_caseD_1;
    uVar16 = 0xff;
    uVar18 = 0xff;
    pbVar27 = buffer2;
    do {
      pbVar17 = pbVar27 + 1;
      uVar21 = *pbVar27 ^ uVar18;
      uVar18 = ""[uVar21] ^ uVar16;
      uVar16 = (uint)""[uVar21];
      pbVar27 = pbVar17;
    } while (pbVar17 != buffer2 + 0x11);
    if ((uint)CONCAT11(buffer2[0x11],buffer2[0x12]) != (uVar18 | uVar16 << 8)) goto LAB_001cf13e;
  }
  iVar4 = _g_calibration_mode;
  SN[0] = '\0';
  SN[1] = '\0';
  SN[2] = '\0';
  SN[3] = '\0';
  uVar16 = buffer._4_4_ << 0x18 | ((uint)buffer._4_4_ >> 8 & 0xff) << 0x10 |
           ((uint)buffer._4_4_ >> 0x10 & 0xff) << 8 | (uint)buffer._4_4_ >> 0x18;
  uVar21 = buffer._0_4_ << 0x18 | ((uint)buffer._0_4_ >> 8 & 0xff) << 0x10 |
           ((uint)buffer._0_4_ >> 0x10 & 0xff) << 8 | (uint)buffer._0_4_ >> 0x18;
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
  ulltostr(SN,0xc,CONCAT44(uVar21,uVar16) & 0x1ffffffffffffff,uVar20);
  ulltostr(SN + 0xb,7,
           (ulonglong)
           (buffer._8_4_ << 0x18 | ((uint)buffer._8_4_ >> 8 & 0xff) << 0x10 |
            ((uint)buffer._8_4_ >> 0x10 & 0xff) << 8 | (uint)buffer._8_4_ >> 0x18),uVar20);
  uVar18 = (uint)CONCAT11(buffer[0x1c],buffer[0x1d]);
  sVar3 = ((ushort)buffer._12_2_ >> 8) + buffer._12_2_ * 0x100;
  uVar20 = uVar18 / 0x1f + (uVar18 - uVar18 / 0x1f >> 1) >> 4;
  iVar15 = (uVar18 + uVar20 * -0x1f & 0xffff) + 1;
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
  pcVar33 = SN + 0x10;
  _g_power_state.eeprom.sn._16_2_ = SUB42(stack0xfffff798,0);
  _g_power_state.eeprom.c_date =
       ((uint)((int)((ulonglong)uVar18 * 0xb02c0b03 >> 0x20) << 8) >> 0x10) * 10000 +
       ((uVar20 & 0xffff) % 0xc) * 100 + 100 + iVar15;
  if ((iVar4 == 0) || ((uVar5 & 0xfe) != 8)) {
    puVar30 = buffer + 0xe;
  }
  else {
    puVar30 = buffer2 + 3;
    sVar3 = (ushort)buffer2[2] + (ushort)buffer2[1] * 0x100;
  }
  iVar34 = (int)sVar3;
  puVar26 = puVar30 + -1;
  iVar28 = 0;
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
      _g_power_state.eeprom.num = iVar28 + 1;
      uVar20 = _g_power_state.power_version & 0xfffffff7;
      bVar35 = 0x61 < uVar20;
      if (uVar20 != 0x62) {
        bVar35 = 1 < _g_power_state.power_version - 100;
      }
      if (bVar35 && (uVar20 != 0x62 && _g_power_state.power_version - 100 != 2)) {
        if (iVar28 - 1U < 0xff) goto LAB_001cedba;
        goto switchD_001cef4a_caseD_1;
      }
      if (_g_power_state.eeprom.num != 1) goto LAB_001cef42;
      goto switchD_001cef4a_caseD_1;
    }
    iVar28 = iVar28 + 1;
  } while (iVar28 != 0xe);
  _g_power_state.eeprom.num = 0xf;
  uVar20 = _g_power_state.power_version & 0xfffffff7;
  bVar35 = 0x61 < uVar20;
  if (uVar20 != 0x62) {
    bVar35 = 1 < _g_power_state.power_version - 100;
  }
  if (!bVar35 || (uVar20 == 0x62 || _g_power_state.power_version - 100 == 2)) {
LAB_001cef42:
    iVar31 = _g_power_state.eeprom.num;
    switch(_g_power_state.power_version - 0x62) {
    case 0:
    case 2:
    case 3:
    case 4:
      dVar36 = 21.6;
      break;
    default:
      goto switchD_001cef4a_caseD_1;
    case 8:
      dVar36 = 16.0;
    }
    switch(_g_power_state.power_version - 0x62) {
    case 0:
    case 2:
    case 3:
    case 4:
      dVar37 = 17.0;
      break;
    default:
switchD_001cef4a_caseD_1:
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
    case 8:
      if ((int)((uint)(dVar36 < 0.0) << 0x1f) < 0) goto switchD_001cef4a_caseD_1;
      dVar37 = 12.0;
    }
    iVar32 = _g_power_state.eeprom.num + -1;
    paVar19 = &_g_power_state.eeprom.field_2;
    iVar23 = 0;
    do {
      iVar24 = iVar23 + 1;
      paVar19->V[0] =
           dVar36 - (double)(longlong)iVar23 * ((dVar36 - dVar37) / (double)(longlong)iVar32);
      paVar19 = (anon_union_160_2_9472fda9_for_eeprom_data_t_2 *)(paVar19->V + 1);
      iVar23 = iVar24;
    } while (iVar24 != iVar31);
    _g_power_state.eeprom.vol[0] =
         _g_power_state.eeprom.field_2.V[0] + (double)(longlong)iVar34 / 1000.0;
    if (iVar28 != 0) {
      paVar19 = &_g_power_state.eeprom.field_2;
      iVar31 = 0;
      do {
        paVar19 = (anon_union_160_2_9472fda9_for_eeprom_data_t_2 *)(paVar19->V + 1);
        puVar26 = puVar26 + 1;
        iVar31 = iVar31 + 1;
        iVar34 = iVar34 + (char)*puVar26;
        dVar36 = (double)(longlong)iVar34 / 1000.0 + paVar19->V[0];
        paVar19->V[0x14] = dVar36;
        snprintf(tmp42,0x800,"calibration data %d  %f    %f    ",iVar31,dVar36,paVar19->V[0],pcVar33
                 ,iVar15,uVar16,uVar21);
        _applog(0,tmp42,false);
      } while (puVar30 + iVar28 + -1 != puVar26);
    }
  }
  else {
LAB_001cedba:
    iVar15 = _g_power_state.eeprom.num;
    iVar23 = _g_power_state.eeprom.num + -1;
    pcVar33 = (char *)((int)&_g_power_state.eeprom.num + 3);
    pbVar25 = &_g_power_state;
    iVar31 = 0;
    do {
      iVar32 = iVar31 + 1;
      dVar36 = round((double)(longlong)iVar31 * (255.0 / (double)(longlong)iVar23));
      pcVar33 = pcVar33 + 1;
      *pcVar33 = (0.0 < dVar36) * (char)(longlong)dVar36;
      iVar31 = iVar32;
    } while (iVar15 != iVar32);
    dVar36 = bitmain_convert_N_to_V_furmula((uint)(pbVar25->eeprom).field_2.N[0]);
    (pbVar25->eeprom).vol[0] = (double)(longlong)iVar34 / 1000.0 + dVar36;
    if (iVar28 != 0) {
      paVar19 = &_g_power_state.eeprom.field_2;
      pdVar29 = _g_power_state.eeprom.vol;
      do {
        pdVar29 = pdVar29 + 1;
        puVar26 = puVar26 + 1;
        paVar19 = (anon_union_160_2_9472fda9_for_eeprom_data_t_2 *)(paVar19->N + 1);
        iVar34 = iVar34 + (char)*puVar26;
        dVar36 = bitmain_convert_N_to_V_furmula((uint)paVar19->N[0]);
        *pdVar29 = (double)(longlong)iVar34 / extraout_d4 + dVar36;
      } while (puVar26 != puVar30 + iVar28 + -1);
    }
  }
  pbVar25->power_Calibrated = true;
  builtin_strncpy(tmp42,"power is Calibrated\n",0x14);
  tmp42._20_4_ = tmp42._20_4_ & 0xffffff00;
  _applog(1,tmp42,false);
  return 0;
}

