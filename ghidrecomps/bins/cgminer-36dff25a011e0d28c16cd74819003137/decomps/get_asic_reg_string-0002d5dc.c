
char * get_asic_reg_string(uchar reg)

{
  char *pcVar1;
  uchar reg_local;
  
  switch(reg) {
  case '\0':
    pcVar1 = "CHIP_ADDRESS";
    break;
  default:
    pcVar1 = "UNKOWN REGISTER";
    break;
  case '\x04':
    pcVar1 = "HASH_RATE";
    break;
  case '\b':
    pcVar1 = "PLL_PARAMETER";
    break;
  case '\f':
    pcVar1 = "CHIP_NONCE_OFFSET";
    break;
  case '\x10':
    pcVar1 = "HASH_COUNTING_NUMBER";
    break;
  case '\x14':
    pcVar1 = "TICKET_MASK";
    break;
  case '\x18':
    pcVar1 = "MISC_CONTROL";
    break;
  case '\x1c':
    pcVar1 = "GENERAL_I2C_COMMAND";
    break;
  case ' ':
    pcVar1 = "ORDERED_CLOCK_ENABLE";
    break;
  case '8':
    pcVar1 = "TICKET_MASK_2";
    break;
  case '<':
    pcVar1 = "CORE_COMMAND";
    break;
  case '@':
    pcVar1 = "CORE_RESPONSE";
    break;
  case 'D':
    pcVar1 = "EXTERNAL_TEMPERATURE_SENSOR_READ";
    break;
  case 'H':
    pcVar1 = "ERROR_FLAG";
    break;
  case 'L':
    pcVar1 = "NONCE_ERROR_COUNTER";
    break;
  case 'P':
    pcVar1 = "NONCE_OVERFLOW_COUNTER";
    break;
  case 'T':
    pcVar1 = "ANALOG_MUX_CONTROL";
    break;
  case 'X':
    pcVar1 = "IO_DRIVE_STRENGTH_CONFIGURATION";
    break;
  case '\\':
    pcVar1 = "TIME_OUT_CONTROL_REG";
    break;
  case '`':
    pcVar1 = "PLL1_PARAMETER";
    break;
  case 'd':
    pcVar1 = "PLL2_PARAMETER";
    break;
  case 'h':
    pcVar1 = "PLL3_PARAMETER";
    break;
  case 'l':
    pcVar1 = "ORDERED_CLOCK_MONITOR";
    break;
  case 'p':
    pcVar1 = "PLL0_DIVIDER";
    break;
  case 't':
    pcVar1 = "PLL1_DIVIDER";
    break;
  case 'x':
    pcVar1 = "PLL2_DIVIDER";
    break;
  case '|':
    pcVar1 = "PLL3_DIVIDER";
    break;
  case 0x80:
    pcVar1 = "CLOCK_ORDER_0";
    break;
  case 0x84:
    pcVar1 = "CLOCK_ORDER_1";
    break;
  case 0x8c:
    pcVar1 = "CLOCK_ORDER_STATUS";
  }
  return pcVar1;
}

