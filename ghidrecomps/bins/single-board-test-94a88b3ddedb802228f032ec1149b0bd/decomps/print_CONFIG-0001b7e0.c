
void print_CONFIG(void)

{
  puts("\n\nparameter processed after Reading Config.ini");
  printf("DataCount:%d\n",conf._0_4_);
  printf("PassCount1:%d\n",conf._4_4_);
  printf("PassCount2:%d\n",conf._8_4_);
  printf("PassCount3:%d\n",conf._12_4_);
  printf("Freq:%d\n",conf._16_4_);
  printf("Timeout:%d\n",conf._20_4_);
  printf("OpenCoreGap:%d\n",conf._72_4_);
  printf("CheckTemp:%d\n",conf._76_4_);
  printf("TestMode:%d\n",conf._36_4_);
  printf("CommandMode:%d\n",conf._40_4_);
  printf("ValidNonce1:%d\n",conf._44_4_);
  printf("ValidNonce2:%d\n",conf._48_4_);
  printf("ValidNonce3:%d\n",conf._52_4_);
  printf("Pic:%ud\n",conf._56_4_);
  printf("IICPic:%ud\n",conf._80_4_);
  printf("dac:%ud\n",conf._108_4_);
  printf("Voltage1:%ud\n",conf._60_4_);
  printf("Voltage2:%ud\n",conf._64_4_);
  printf("Voltage3:%ud\n",conf._68_4_);
  printf("OpenCoreNum1 = %ud = 0x%x\n",conf._92_4_,conf._92_4_);
  printf("OpenCoreNum2 = %ud = 0x%x\n",conf._96_4_,conf._96_4_);
  printf("OpenCoreNum3 = %ud = 0x%x\n",conf._100_4_,conf._100_4_);
  printf("OpenCoreNum4 = %ud = 0x%x\n",conf._104_4_,conf._104_4_);
  printf("GetTempFrom:%d\n",conf._112_4_);
  printf("TempSel:%d\n",conf._116_4_);
  printf("TempSensor1:%d\n",(uint)conf[120]);
  printf("TempSensor2:%d\n",(uint)conf[121]);
  printf("TempSensor3:%d\n",(uint)conf[122]);
  printf("TempSensor4:%d\n",(uint)conf[123]);
  printf("DefaultTempOffset:%d\n",(int)conf[124]);
  printf("StartTemp:%d\n",(int)conf[152]);
  printf("year:%04d\n",conf._156_4_);
  printf("month:%02d\n",conf._160_4_);
  printf("date:%02d\n",conf._164_4_);
  printf("hour:%02d\n",conf._168_4_);
  printf("minute:%02d\n",conf._172_4_);
  printf("second:%02d\n",conf._176_4_);
  puts("\n");
  return;
}

