
/* WARNING: Unknown calling convention */

void V9_set_voltage(uchar which_chain,uchar which_i2c,_Bool whether_add_voltage)

{
  uint uVar1;
  double dVar2;
  
  uVar1 = Conf.Voltage1;
  switch(pattern_test_time) {
  case '\0':
    break;
  case '\x01':
    uVar1 = Conf.Voltage2;
    break;
  case '\x02':
    uVar1 = Conf.Voltage3;
    break;
  case '\x03':
    uVar1 = Conf.Voltage4;
    break;
  case '\x04':
    uVar1 = Conf.Voltage5;
    break;
  case '\x05':
    uVar1 = Conf.Voltage6;
    break;
  case '\x06':
    uVar1 = Conf.Voltage7;
    break;
  case '\a':
    uVar1 = Conf.Voltage8;
    break;
  case '\b':
    uVar1 = Conf.Voltage9;
    break;
  default:
    printf("\n--- Can\'t find voltage%d\n");
  }
  if (whether_add_voltage) {
    uVar1 = uVar1 + Conf.add_voltage_value;
  }
  dVar2 = DAT_00019b18 - ((double)(ulonglong)uVar1 * DAT_00019b08) / DAT_00019b10;
  printf("\n--- %s: real voltage = %d, temp_voltage = %.6f, Pic_Voltage = %d\n",DAT_00019b20,uVar1);
  set_PIC16F1704_voltage((uint)which_chain,which_i2c,(0.0 < dVar2) * (char)(longlong)dVar2);
  (*(code *)PTR_usleep_00030148)(100000);
  return;
}

