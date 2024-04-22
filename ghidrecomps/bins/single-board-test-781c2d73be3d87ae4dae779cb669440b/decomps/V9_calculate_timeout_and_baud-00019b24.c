
/* WARNING: Unknown calling convention */

void V9_calculate_timeout_and_baud(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = calculate_core_number(0x32);
  switch(pattern_test_time) {
  case '\0':
    uVar2 = Conf.Freq1;
    break;
  case '\x01':
    uVar2 = Conf.Freq2;
    break;
  case '\x02':
    uVar2 = Conf.Freq3;
    break;
  case '\x03':
    uVar2 = Conf.Freq4;
    break;
  case '\x04':
    uVar2 = Conf.Freq5;
    break;
  case '\x05':
    uVar2 = Conf.Freq6;
    break;
  case '\x06':
    uVar2 = Conf.Freq7;
    break;
  case '\a':
    uVar2 = Conf.Freq8;
    break;
  case '\b':
    uVar2 = Conf.Freq9;
    break;
  default:
    printf("%s: pattern_test_time = %d, error!!! \n",DAT_00019c38);
    uVar2 = 0;
  }
  iVar1 = __udivsi3(0x1000000,iVar1);
  iVar1 = __udivsi3(gChain_Asic_Interval * iVar1,uVar2);
  Conf.timeout = (uint)(iVar1 * 0x5f) / 100;
  iVar1 = __udivsi3(0x196e6a,Conf.timeout,iVar1 * 0x66666681);
  iVar1 = __udivsi3(0x2faf08,iVar1 << 9);
  Conf.baud = iVar1 - 1;
  if ((0x1a < Conf.baud) || (iVar1 - 2U < 0x1a)) {
    Conf.baud = 1;
  }
  printf("\n--- %s: baud = %d, timeout = 0x%08x = %d\n",DAT_00019c38);
  Conf.Freq = uVar2;
  return;
}

