
void V9_calculate_timeout_and_baud(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_14;
  
  local_14 = 0;
  uVar1 = calculate_core_number(0x32);
  switch(pattern_test_time) {
  case 0:
    local_14 = Conf._72_4_;
    break;
  case 1:
    local_14 = Conf._76_4_;
    break;
  case 2:
    local_14 = Conf._80_4_;
    break;
  case 3:
    local_14 = Conf._84_4_;
    break;
  case 4:
    local_14 = Conf._88_4_;
    break;
  case 5:
    local_14 = Conf._92_4_;
    break;
  case 6:
    local_14 = Conf._96_4_;
    break;
  case 7:
    local_14 = Conf._100_4_;
    break;
  case 8:
    local_14 = Conf._104_4_;
    break;
  default:
    printf("%s: pattern_test_time = %d, error!!! \n","V9_calculate_timeout_and_baud",
           (uint)pattern_test_time);
  }
  iVar2 = __udivsi3(0x1000000,uVar1);
  iVar2 = __udivsi3(gChain_Asic_Interval * iVar2,local_14);
  Conf._196_4_ = (uint)(iVar2 * 0x5f) / 100;
  iVar2 = __udivsi3(0x196e6a,Conf._196_4_);
  iVar2 = __udivsi3(0x2faf08,iVar2 << 9);
  Conf._268_4_ = iVar2 - 1;
  if (0x1a < (uint)Conf._268_4_) {
    Conf._268_4_ = 0x1a;
  }
  if (((uint)Conf._268_4_ < 0x1b) && (Conf._268_4_ != 0)) {
    Conf._268_4_ = 1;
  }
  printf("\n--- %s: baud = %d, timeout = 0x%08x = %d\n","V9_calculate_timeout_and_baud",Conf._268_4_
         ,Conf._196_4_,Conf._196_4_);
  Conf._68_4_ = local_14;
  return;
}

