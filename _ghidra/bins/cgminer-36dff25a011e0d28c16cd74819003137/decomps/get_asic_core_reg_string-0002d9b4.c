
char * get_asic_core_reg_string(uchar reg)

{
  char *pcVar1;
  uchar reg_local;
  
  switch(reg) {
  case '\0':
    pcVar1 = "CLOCK_DELAY_CTRL";
    break;
  case '\x01':
    pcVar1 = "PRO_MONI_CTRL";
    break;
  case '\x02':
    pcVar1 = "PRO_MONI_DATA";
    break;
  case '\x03':
    pcVar1 = "CORE_ERROR";
    break;
  case '\x04':
    pcVar1 = "CLOCK_EN_CTRL";
    break;
  case '\x05':
    pcVar1 = "HASH_CLOCK_CTRL";
    break;
  case '\x06':
    pcVar1 = "HASH_CLOCK_CNT";
    break;
  case '\a':
    pcVar1 = "SWEEP_CNTRL";
    break;
  default:
    pcVar1 = "UNKNOWN CORE REGISTER";
  }
  return pcVar1;
}

