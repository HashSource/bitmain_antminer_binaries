
/* WARNING: Unknown calling convention */

void BM1391_soft_reset_sensor(uchar which_chain)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint which_sensor;
  int iVar4;
  
  iVar4 = 0;
  printf("\n--- %s\n",DAT_00014078);
LAB_00013f78:
  uVar3 = Conf.TempSensor1;
  if (((iVar4 != 0) && (uVar3 = Conf.TempSensor2, iVar4 != 1)) &&
     (uVar3 = Conf.TempSensor3, iVar4 != 2)) {
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
        BM1391_set_config(which_chain,(char)gChain_Asic_Interval * cVar1,'\x1c',0x10006,false);
        uVar3 = 0;
        goto LAB_00014038;
      }
    } while (uVar3 < read_loop);
    gNotReadOutTemp = true;
    printf("%s: Can\'t read out GENERAL_I2C_COMMAND. ret = 0x%08x\n",DAT_00014078,uVar2);
  }
  goto LAB_00013f94;
  while (uVar3 < read_loop) {
LAB_00014038:
    uVar3 = uVar3 + 1;
    uVar2 = check_BM1391_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar1,'\x1c',false);
    if ((uVar2 & 0xc0000000) == 0) break;
  }
LAB_00013f94:
  iVar4 = iVar4 + 1;
  if (iVar4 == 4) {
    (*(code *)PTR_usleep_00030148)(300000);
    return;
  }
  goto LAB_00013f78;
}

