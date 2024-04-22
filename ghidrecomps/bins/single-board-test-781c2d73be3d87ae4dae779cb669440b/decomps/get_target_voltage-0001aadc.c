
/* WARNING: Unknown calling convention */

uint get_target_voltage(void)

{
  uint uVar1;
  
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
    printf("!!!%s: not support Voltage%d, we use Voltage1 as default value\n","get_target_voltage");
  }
  *(uint *)(DAT_0001abb8 + 0x2f4) = uVar1;
  printf("\n--- %s: target voltage is %d\n","get_target_voltage",uVar1);
  return uVar1;
}

