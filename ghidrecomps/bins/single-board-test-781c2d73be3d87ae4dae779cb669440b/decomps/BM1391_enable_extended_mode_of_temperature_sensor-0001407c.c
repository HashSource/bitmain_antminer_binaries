
/* WARNING: Unknown calling convention */

void BM1391_enable_extended_mode_of_temperature_sensor(uchar which_chain)

{
  char cVar1;
  uint uVar2;
  uint which_sensor;
  uint uVar3;
  uint i;
  
  i = 0;
  printf("\n--- %s\n",DAT_00014254);
LAB_000140cc:
  uVar3 = Conf.TempSensor1;
  if (((i != 0) && (uVar3 = Conf.TempSensor2, i != 1)) && (uVar3 = Conf.TempSensor3, i != 2)) {
    uVar3 = Conf.TempSensor4;
  }
  if (uVar3 != 0) {
    cVar1 = (char)uVar3 + -1;
    uVar3 = 0;
    BM1391_set_config(which_chain,(char)gChain_Asic_Interval * cVar1,'\x18',
                      gBM1391_MISC_CONTROL_reg | 0x4030,false);
    check_BM1391_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar1,'\x18',false);
    do {
      uVar3 = uVar3 + 1;
      uVar2 = check_BM1391_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar1,'\x1c',false);
      if ((uVar2 & 0xc0000000) == 0) {
        BM1391_set_config(which_chain,(char)gChain_Asic_Interval * cVar1,'\x1c',
                          gSensor_i2c_addr_high_4_bit | 0x1010904,false);
        uVar3 = 0;
        goto LAB_00014190;
      }
    } while (uVar3 < read_loop);
    gNotReadOutTemp = true;
    printf("\n!!! %s: Can\'t read out GENERAL_I2C_COMMAND. ret = 0x%08x\n",DAT_00014254,uVar2);
  }
  goto LAB_000140f0;
  while (uVar3 < read_loop) {
LAB_00014190:
    uVar3 = uVar3 + 1;
    uVar2 = check_BM1391_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar1,'\x1c',false);
    if ((uVar2 & 0xc0000000) == 0) break;
  }
  usleep(10000);
  uVar3 = 0;
  BM1391_set_config(which_chain,(char)gChain_Asic_Interval * cVar1,'\x1c',
                    gSensor_i2c_addr_high_4_bit & 0xfefefcff | 0x1000300,false);
  do {
    uVar3 = uVar3 + 1;
    uVar2 = check_BM1391_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar1,'\x1c',false);
    if ((uVar2 & 0xc0000000) == 0) break;
  } while (uVar3 < read_loop);
  if ((uVar2 & 0xc0000004) != 4) {
    gNotReadOutTemp = true;
    printf("\n!!! %s: Can\'t set extended mode. ret = 0x%08x\n",DAT_00014254,uVar2);
  }
LAB_000140f0:
  i = i + 1;
  if (i == 4) {
    return;
  }
  goto LAB_000140cc;
}

