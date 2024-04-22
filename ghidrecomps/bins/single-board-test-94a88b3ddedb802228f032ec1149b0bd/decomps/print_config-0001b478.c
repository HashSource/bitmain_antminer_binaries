
void print_config(void)

{
  puts("\n\nRead Config.ini");
  printf("Name:%s\n",Conf);
  printf("DataCount:%d\n",Conf._72_4_);
  printf("PassCount1:%d\n",Conf._76_4_);
  printf("PassCount2:%d\n",Conf._80_4_);
  printf("PassCount3:%d\n",Conf._84_4_);
  printf("Freq:%d\n",Conf._88_4_);
  printf("Timeout:%d\n",Conf._92_4_);
  printf("OpenCoreGap:%d\n",Conf._176_4_);
  printf("CheckTemp:%d\n",Conf._180_4_);
  printf("freq_e:%d\n",Conf._236_4_);
  printf("AsicNum:%d\n",Conf._112_4_);
  printf("TestMode:%d\n",Conf._120_4_);
  printf("CheckChain:%d\n",Conf._124_4_);
  printf("CommandMode:%d\n",Conf._128_4_);
  printf("ValidNonce1:%d\n",Conf._132_4_);
  printf("ValidNonce2:%d\n",Conf._136_4_);
  printf("ValidNonce3:%d\n",Conf._140_4_);
  printf("Pic:%ud\n",Conf._144_4_);
  printf("IICPic:%ud\n",Conf._184_4_);
  printf("dac = %ud\n",Conf._204_4_);
  printf("Voltage1:%ud\n",Conf._148_4_);
  printf("Voltage2:%ud\n",Conf._152_4_);
  printf("Voltage3:%ud\n",Conf._156_4_);
  printf("OpenCoreNum1 = %ud = 0x%x\n",Conf._188_4_,Conf._188_4_);
  printf("OpenCoreNum2 = %ud = 0x%x\n",Conf._192_4_,Conf._192_4_);
  printf("OpenCoreNum3 = %ud = 0x%x\n",Conf._196_4_,Conf._196_4_);
  printf("OpenCoreNum4 = %ud = 0x%x\n",Conf._200_4_,Conf._200_4_);
  printf("GetTempFrom:%d\n",Conf._208_4_);
  printf("TempSel:%d\n",Conf._212_4_);
  printf("TempSensor1:%d\n",Conf._216_4_);
  printf("TempSensor2:%d\n",Conf._220_4_);
  printf("TempSensor3:%d\n",Conf._224_4_);
  printf("TempSensor4:%d\n",Conf._228_4_);
  printf("DefaultTempOffset:%d\n",(int)Conf[232]);
  printf("StartTemp:%d\n",Conf._260_4_);
  printf("year:%04d\n",Conf._264_4_);
  printf("month:%02d\n",Conf._268_4_);
  printf("date:%02d\n",Conf._272_4_);
  printf("hour:%02d\n",Conf._276_4_);
  printf("minute:%02d\n",Conf._280_4_);
  printf("second:%02d\n",Conf._284_4_);
  puts("\n");
  return;
}

