
/* WARNING: Unknown calling convention */

int process_config(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char tmp42 [2048];
  
  uVar1 = tmp42._36_4_;
  conf.CommandMode = Conf.CommandMode;
  conf.TempSel = Conf.TempSel;
  conf.GetTempFrom = Conf.GetTempFrom;
  if (Conf.CommandMode == 1) {
    if (Conf.GetTempFrom == 1) {
      if (((!use_syslog) && (!opt_log_output)) && (opt_log_level < 3)) {
        conf.CommandMode = Conf.CommandMode;
        conf.GetTempFrom = Conf.GetTempFrom;
        conf.TempSel = Conf.TempSel;
        return -1;
      }
      builtin_strncpy(tmp42,"Can\'t get temperature from ASIC in FIL mode!",0x2c);
      tmp42[0x2c] = '\n';
      tmp42[0x2d] = '\0';
      _applog(3,tmp42,false);
      return -1;
    }
  }
  else if ((Conf.CommandMode == 0) && (Conf.GetTempFrom == 1)) {
    cgpu.temp_sel = (uchar)Conf.TempSel;
    cgpu.rfs = '\x01';
    cgpu.tfs = '\x03';
    if (Conf.TempSensor2 + Conf.TempSensor1 + Conf.TempSensor3 + Conf.TempSensor4 == 0) {
      if (((!use_syslog) && (!opt_log_output)) && (opt_log_level < 3)) {
        cgpu.rfs = '\x01';
        cgpu.tfs = '\x03';
        conf.CommandMode = Conf.CommandMode;
        conf.GetTempFrom = Conf.GetTempFrom;
        conf.TempSel = Conf.TempSel;
        return -1;
      }
      builtin_strncpy(tmp42,"Must set temperature sensor address!\n",0x26);
      tmp42._38_2_ = SUB42(uVar1,2);
      _applog(3,tmp42,false);
      return -1;
    }
    cgpu.T1_offset_value = Conf.DefaultTempOffset;
    conf.TempSensor1 = (uchar)Conf.TempSensor1;
    conf.TempSensor2 = (uchar)Conf.TempSensor2;
    conf.TempSensor3 = (uchar)Conf.TempSensor3;
    conf.TempSensor4 = (uchar)Conf.TempSensor4;
    conf.StartSensor = (uchar)Conf.StartSensor;
    conf.StartTemp = (char)Conf.StartTemp;
    cgpu.rfs = '\x01';
    cgpu.T2_offset_value = cgpu.T1_offset_value;
    cgpu.T3_offset_value = cgpu.T1_offset_value;
    cgpu.T4_offset_value = cgpu.T1_offset_value;
    conf.DefaultTempOffset = cgpu.T1_offset_value;
  }
  conf.freq_e = Conf.freq_e;
  conf.freq_t = Conf.freq_t;
  conf.freq_m = Conf.freq_m;
  conf.force_freq = Conf.force_freq;
  conf.UseConfigVol = Conf.UseConfigVol;
  conf.OpenCoreNum1 = Conf.OpenCoreNum1;
  conf.OpenCoreNum2 = Conf.OpenCoreNum2;
  conf.core = Conf.CoreNum;
  conf.freq_a = Conf.freq_a;
  conf.OpenCoreNum3 = Conf.OpenCoreNum3;
  conf.OpenCoreNum4 = Conf.OpenCoreNum4;
  conf.AsicType = 0x56b;
  conf.asicNum = 0x20;
  Conf.AddrInterval = 4;
  conf.addrInterval = 4;
  iVar3 = Conf.CoreNum;
  if (((Conf.CoreNum != 1) && (Conf.CoreNum != 2)) && (iVar3 = 4, 1 < Conf.CoreNum - 3U)) {
    if (Conf.CoreNum - 5U < 4) {
      iVar3 = 8;
    }
    else if (Conf.CoreNum - 9U < 8) {
      iVar3 = 0x10;
    }
    else if (Conf.CoreNum - 0x11U < 0x10) {
      iVar3 = 0x20;
    }
    else if (Conf.CoreNum - 0x21U < 0x20) {
      iVar3 = 0x40;
    }
    else if (Conf.CoreNum - 0x41U < 0x40) {
      iVar3 = 0x80;
    }
    else if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"actual_core_number = %d, but it is error\n",Conf.CoreNum);
      _applog(7,tmp42,false);
      iVar3 = -1;
    }
    else {
      iVar3 = -1;
    }
  }
  iVar4 = Conf.Freq;
  conf.IICPic = Conf.IICPic;
  conf.dac = Conf.dac;
  conf.ValidNonce1 = Conf.ValidNonce1;
  conf.Voltage1 = Conf.Voltage1;
  conf.testMode = Conf.TestMode;
  conf.Voltage2 = Conf.Voltage2;
  conf.ValidNonce2 = Conf.ValidNonce2;
  conf.Voltage3 = Conf.Voltage3;
  conf.ValidNonce3 = Conf.ValidNonce3;
  conf.Pic = Conf.Pic;
  conf.OpenCoreGap = Conf.OpenCoreGap;
  conf.month = Conf.month;
  conf.date = Conf.date;
  conf.checktemp = Conf.checktemp;
  conf.freq = Conf.Freq;
  conf.year = Conf.year;
  conf.hour = Conf.hour;
  conf.minute = Conf.minute;
  conf.second = Conf.second;
  if (Conf.Timeout < 1) {
    iVar3 = __aeabi_idiv(0x1000000,iVar3);
    iVar3 = __aeabi_idiv(conf.addrInterval * iVar3,iVar4);
    conf.timeout = (iVar3 * 0x5f) / 100;
  }
  else {
    conf.timeout = Conf.Timeout;
  }
  iVar3 = __aeabi_idiv(0x196e6a);
  iVar4 = __aeabi_uidiv(0x2faf08,iVar3 << 9);
  conf.baud = iVar4 + -1;
  iVar3 = conf.baud;
  if (0x1a < conf.baud) {
    iVar3 = 0x1a;
  }
  iVar2 = iVar3;
  if ((conf.baud == 0x1a || iVar4 + -0x1b < 0 != SBORROW4(conf.baud,0x1a)) &&
     (iVar2 = conf.baud, iVar3 < 1)) {
    if ((use_syslog == false) && ((opt_log_output == false && (opt_log_level < 3)))) {
      return -1;
    }
    snprintf(tmp42,0x800,"$$$$Config argument Baudrate:%d err\n");
    _applog(3,tmp42,false);
    return -1;
  }
  conf.baud = iVar2;
  if (Conf.DataCount - 1U < 5000) {
    conf.dataCount = Conf.DataCount;
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
    snprintf(tmp42,0x800,"$$$$Config argument DataCount:%d err\n");
    _applog(3,tmp42,false);
  }
  if ((conf.dataCount < Conf.PassCount1) || (Conf.PassCount1 < 0)) {
    if ((use_syslog == false) && ((opt_log_output == false && (opt_log_level < 3))))
    goto LAB_00017376;
    snprintf(tmp42,0x800,"$$$$Config argument DataCount:%d err\n",Conf.DataCount);
    _applog(3,tmp42,false);
    if (Conf.PassCount2 <= conf.dataCount) goto LAB_0001737e;
LAB_000173fe:
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3))
    goto LAB_00017388;
    snprintf(tmp42,0x800,"$$$$Config argument DataCount:%d err\n",Conf.DataCount);
    _applog(3,tmp42,false);
    if (conf.dataCount < Conf.PassCount3) goto LAB_00017434;
  }
  else {
    conf.passCount1 = Conf.PassCount1;
LAB_00017376:
    if (conf.dataCount < Conf.PassCount2) goto LAB_000173fe;
LAB_0001737e:
    if (Conf.PassCount2 < 0) goto LAB_000173fe;
    conf.passCount2 = Conf.PassCount2;
LAB_00017388:
    if (conf.dataCount < Conf.PassCount3) goto LAB_00017434;
  }
  if (-1 < Conf.PassCount3) {
    conf.passCount3 = Conf.PassCount3;
    return 0;
  }
LAB_00017434:
  if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3)) {
    return 0;
  }
  snprintf(tmp42,0x800,"$$$$Config argument DataCount:%d err\n",Conf.DataCount);
  _applog(3,tmp42,false);
  return 0;
}

