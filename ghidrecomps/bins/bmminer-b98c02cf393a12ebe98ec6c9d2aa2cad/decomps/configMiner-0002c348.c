
undefined4 configMiner(void)

{
  int iVar1;
  
  read_config();
  puts("\n\nRead Config.ini");
  printf("DataCount:%d\n",Conf._8_4_);
  printf("PassCount1:%d\n",Conf._12_4_);
  printf("PassCount2:%d\n",Conf._16_4_);
  printf("PassCount3:%d\n",Conf._20_4_);
  printf("Freq:%d\n",Conf._24_4_);
  printf("Timeout:%d\n",Conf._28_4_);
  printf("OpenCoreGap:%d\n",Conf._120_4_);
  printf("CheckTemp:%d\n",Conf._124_4_);
  printf("CoreNum:%d\n",Conf._48_4_);
  printf("freq_e:%d\n",Conf._180_4_);
  printf("AsicNum:%d\n",Conf._52_4_);
  printf("TestMode:%d\n",Conf._60_4_);
  printf("CheckChain:%d\n",Conf._64_4_);
  printf("CommandMode:%d\n",Conf._68_4_);
  printf("AsicType:%d\n",Conf._72_4_);
  printf("ValidNonce1:%d\n",Conf._76_4_);
  printf("ValidNonce2:%d\n",Conf._80_4_);
  printf("ValidNonce3:%d\n",Conf._84_4_);
  printf("Pic:%ud\n",Conf._88_4_);
  printf("IICPic:%ud\n",Conf._128_4_);
  printf("dac = %ud\n",Conf._148_4_);
  printf("Voltage1:%ud\n",Conf._92_4_);
  printf("Voltage2:%ud\n",Conf._96_4_);
  printf("Voltage3:%ud\n",Conf._100_4_);
  printf("OpenCoreNum1 = %ud = 0x%x\n",Conf._132_4_);
  printf("OpenCoreNum2 = %ud = 0x%x\n",Conf._136_4_);
  printf("OpenCoreNum3 = %ud = 0x%x\n",Conf._140_4_);
  printf("OpenCoreNum4 = %ud = 0x%x\n",Conf._144_4_);
  printf("GetTempFrom:%d\n",Conf._152_4_);
  printf("TempSel:%d\n",Conf._156_4_);
  printf("TempSensor1:%d\n",Conf._160_4_);
  printf("TempSensor2:%d\n",Conf._164_4_);
  printf("TempSensor3:%d\n",Conf._168_4_);
  printf("TempSensor4:%d\n",Conf._172_4_);
  printf("DefaultTempOffset:%d\n",(int)Conf[176]);
  printf("StartSensor:%d\n",Conf._204_4_);
  printf("StartTemp:%d\n",Conf._208_4_);
  printf("year:%04d\n",Conf._212_4_);
  printf("month:%02d\n",Conf._216_4_);
  printf("date:%02d\n",Conf._220_4_);
  printf("hour:%02d\n",Conf._224_4_);
  printf("minute:%02d\n",Conf._228_4_);
  printf("second:%02d\n",Conf._232_4_);
  puts((char *)&DAT_00065a34);
  iVar1 = process_config();
  if (-1 < iVar1) {
    puts("\n\nparameter processed after Reading Config.ini");
    printf("DataCount:%d\n",conf._0_4_);
    printf("PassCount1:%d\n",conf._4_4_);
    printf("PassCount2:%d\n",conf._8_4_);
    printf("PassCount3:%d\n",conf._12_4_);
    printf("Freq:%d\n",conf._20_4_);
    printf("Timeout:%d\n",conf._24_4_);
    printf("OpenCoreGap:%d\n",conf._88_4_);
    printf("CheckTemp:%d\n",conf._92_4_);
    printf("CoreNum:%d\n",conf._16_4_);
    printf("AsicNum:%d\n",conf._44_4_);
    printf("TestMode:%d\n",conf._48_4_);
    printf("CommandMode:%d\n",conf._52_4_);
    printf("AsicType:%d\n",conf._56_4_);
    printf("ValidNonce1:%d\n",conf._60_4_);
    printf("ValidNonce2:%d\n",conf._64_4_);
    printf("ValidNonce3:%d\n",conf._68_4_);
    printf("Pic:%ud\n",conf._72_4_);
    printf("IICPic:%ud\n",conf._96_4_);
    printf("dac:%ud\n",conf._124_4_);
    printf("Voltage1:%ud\n",conf._76_4_);
    printf("Voltage2:%ud\n",conf._80_4_);
    printf("Voltage3:%ud\n",conf._84_4_);
    printf("OpenCoreNum1 = %ud = 0x%x\n",conf._108_4_);
    printf("OpenCoreNum2 = %ud = 0x%x\n",conf._112_4_);
    printf("OpenCoreNum3 = %ud = 0x%x\n",conf._116_4_);
    printf("OpenCoreNum4 = %ud = 0x%x\n",conf._120_4_);
    printf("GetTempFrom:%d\n",conf._128_4_);
    printf("TempSel:%d\n",conf._132_4_);
    printf("TempSensor1:%d\n",(uint)conf[136]);
    printf("TempSensor2:%d\n",(uint)conf[137]);
    printf("TempSensor3:%d\n",(uint)conf[138]);
    printf("TempSensor4:%d\n",(uint)conf[139]);
    printf("DefaultTempOffset:%d\n",(int)conf[140]);
    printf("StartSensor:%d\n",(uint)conf[168]);
    printf("StartTemp:%d\n",(int)conf[169]);
    printf("year:%04d\n",conf._172_4_);
    printf("month:%02d\n",conf._176_4_);
    printf("date:%02d\n",conf._180_4_);
    printf("hour:%02d\n",conf._184_4_);
    printf("minute:%02d\n",conf._188_4_);
    printf("second:%02d\n",conf._192_4_);
    puts((char *)&DAT_00065a34);
    iVar1 = get_works();
    if (-1 < iVar1) {
      return 0;
    }
  }
  return 0xfffffff2;
}

