
/* WARNING: Unknown calling convention */

int configMiner(void)

{
  int iVar1;
  
  read_config();
  puts("\n\nRead Config.ini");
  printf("DataCount:%d\n",Conf.DataCount);
  printf("PassCount1:%d\n",Conf.PassCount1);
  printf("PassCount2:%d\n",Conf.PassCount2);
  printf("PassCount3:%d\n",Conf.PassCount3);
  printf("Freq:%d\n",Conf.Freq);
  printf("Timeout:%d\n",Conf.Timeout);
  printf("OpenCoreGap:%d\n",Conf.OpenCoreGap);
  printf("CheckTemp:%d\n",Conf.checktemp);
  printf("CoreNum:%d\n",Conf.CoreNum);
  printf("freq_e:%d\n",Conf.freq_e);
  printf("AsicNum:%d\n",Conf.AsicNum);
  printf("TestMode:%d\n",Conf.TestMode);
  printf("CheckChain:%d\n",Conf.CheckChain);
  printf("CommandMode:%d\n",Conf.CommandMode);
  printf("AsicType:%d\n",Conf.AsicType);
  printf("ValidNonce1:%d\n",Conf.ValidNonce1);
  printf("ValidNonce2:%d\n",Conf.ValidNonce2);
  printf("ValidNonce3:%d\n",Conf.ValidNonce3);
  printf("Pic:%ud\n",Conf.Pic);
  printf("IICPic:%ud\n",Conf.IICPic);
  printf("dac = %ud\n",Conf.dac);
  printf("Voltage1:%ud\n",Conf.Voltage1);
  printf("Voltage2:%ud\n",Conf.Voltage2);
  printf("Voltage3:%ud\n",Conf.Voltage3);
  printf("OpenCoreNum1 = %ud = 0x%x\n",Conf.OpenCoreNum1,Conf.OpenCoreNum1);
  printf("OpenCoreNum2 = %ud = 0x%x\n",Conf.OpenCoreNum2,Conf.OpenCoreNum2);
  printf("OpenCoreNum3 = %ud = 0x%x\n",Conf.OpenCoreNum3,Conf.OpenCoreNum3);
  printf("OpenCoreNum4 = %ud = 0x%x\n",Conf.OpenCoreNum4,Conf.OpenCoreNum4);
  printf("GetTempFrom:%d\n",Conf.GetTempFrom);
  printf("TempSel:%d\n",Conf.TempSel);
  printf("TempSensor1:%d\n",Conf.TempSensor1);
  printf("TempSensor2:%d\n",Conf.TempSensor2);
  printf("TempSensor3:%d\n",Conf.TempSensor3);
  printf("TempSensor4:%d\n",Conf.TempSensor4);
  printf("DefaultTempOffset:%d\n",(int)Conf.DefaultTempOffset);
  printf("StartSensor:%d\n",Conf.StartSensor);
  printf("StartTemp:%d\n",Conf.StartTemp);
  printf("year:%04d\n",Conf.year);
  printf("month:%02d\n",Conf.month);
  printf("date:%02d\n",Conf.date);
  printf("hour:%02d\n",Conf.hour);
  printf("minute:%02d\n",Conf.minute);
  printf("second:%02d\n",Conf.second);
  puts("\n");
  iVar1 = process_config();
  if (-1 < iVar1) {
    puts("\n\nparameter processed after Reading Config.ini");
    printf("DataCount:%d\n",conf.dataCount);
    printf("PassCount1:%d\n",conf.passCount1);
    printf("PassCount2:%d\n",conf.passCount2);
    printf("PassCount3:%d\n",conf.passCount3);
    printf("Freq:%d\n",conf.freq);
    printf("Timeout:%d\n",conf.timeout);
    printf("OpenCoreGap:%d\n",conf.OpenCoreGap);
    printf("CheckTemp:%d\n",conf.checktemp);
    printf("CoreNum:%d\n",conf.core);
    printf("AsicNum:%d\n",conf.asicNum);
    printf("TestMode:%d\n",conf.testMode);
    printf("CommandMode:%d\n",conf.CommandMode);
    printf("AsicType:%d\n",conf.AsicType);
    printf("ValidNonce1:%d\n",conf.ValidNonce1);
    printf("ValidNonce2:%d\n",conf.ValidNonce2);
    printf("ValidNonce3:%d\n",conf.ValidNonce3);
    printf("Pic:%ud\n",conf.Pic);
    printf("IICPic:%ud\n",conf.IICPic);
    printf("dac:%ud\n",conf.dac);
    printf("Voltage1:%ud\n",conf.Voltage1);
    printf("Voltage2:%ud\n",conf.Voltage2);
    printf("Voltage3:%ud\n",conf.Voltage3);
    printf("OpenCoreNum1 = %ud = 0x%x\n",conf.OpenCoreNum1,conf.OpenCoreNum1);
    printf("OpenCoreNum2 = %ud = 0x%x\n",conf.OpenCoreNum2,conf.OpenCoreNum2);
    printf("OpenCoreNum3 = %ud = 0x%x\n",conf.OpenCoreNum3,conf.OpenCoreNum3);
    printf("OpenCoreNum4 = %ud = 0x%x\n",conf.OpenCoreNum4,conf.OpenCoreNum4);
    printf("GetTempFrom:%d\n",conf.GetTempFrom);
    printf("TempSel:%d\n",conf.TempSel);
    printf("TempSensor1:%d\n",(uint)conf.TempSensor1);
    printf("TempSensor2:%d\n",(uint)conf.TempSensor2);
    printf("TempSensor3:%d\n",(uint)conf.TempSensor3);
    printf("TempSensor4:%d\n",(uint)conf.TempSensor4);
    printf("DefaultTempOffset:%d\n",(int)conf.DefaultTempOffset);
    printf("StartSensor:%d\n",(uint)conf.StartSensor);
    printf("StartTemp:%d\n",(int)conf.StartTemp);
    printf("year:%04d\n",conf.year);
    printf("month:%02d\n",conf.month);
    printf("date:%02d\n",conf.date);
    printf("hour:%02d\n",conf.hour);
    printf("minute:%02d\n",conf.minute);
    printf("second:%02d\n",conf.second);
    puts("\n");
    iVar1 = get_works();
    if (-1 < iVar1) {
      return 0;
    }
  }
  return -0xe;
}

