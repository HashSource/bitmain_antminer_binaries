
/* WARNING: Unknown calling convention */

void BHB91603_calculate_timeout_and_baud(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = calculate_core_number(0x100);
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
    printf("%s: pattern_test_time = %d, error!!! \n",DAT_00016d7c);
    uVar2 = 0;
  }
  iVar1 = __udivsi3(0x1000000,iVar1);
  iVar1 = __udivsi3(gChain_Asic_Interval * iVar1,uVar2);
  Conf.timeout = ((uint)*(byte *)(DAT_00016d78 + 799) * iVar1) / 100;
  Conf.Freq = uVar2;
  printf("\n--- %s: baud = %d, timeout = 0x%08x = %d us, freq = %d\n",DAT_00016d7c,Conf.baud,
         Conf.timeout,Conf.timeout,uVar2);
  return;
}

