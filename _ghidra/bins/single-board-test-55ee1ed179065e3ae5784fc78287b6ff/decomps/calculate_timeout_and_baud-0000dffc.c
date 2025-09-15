
void calculate_timeout_and_baud(void)

{
  undefined4 local_c;
  
  local_c = 0;
  printf("\n%s\n","calculate_timeout_and_baud");
  calculate_core_number(Conf._112_4_);
  switch(pattern_test_time) {
  case 0:
    local_c = Conf._72_4_;
    break;
  case 1:
    local_c = Conf._76_4_;
    break;
  case 2:
    local_c = Conf._80_4_;
    break;
  case 3:
    local_c = Conf._84_4_;
    break;
  case 4:
    local_c = Conf._88_4_;
    break;
  case 5:
    local_c = Conf._92_4_;
    break;
  case 6:
    local_c = Conf._96_4_;
    break;
  case 7:
    local_c = Conf._100_4_;
    break;
  case 8:
    local_c = Conf._104_4_;
    break;
  default:
    printf("%s: pattern_test_time = %d, error!!! \n","calculate_timeout_and_baud",
           (uint)pattern_test_time);
  }
  Conf._68_4_ = local_c;
  Conf._260_4_ = 0;
  return;
}

