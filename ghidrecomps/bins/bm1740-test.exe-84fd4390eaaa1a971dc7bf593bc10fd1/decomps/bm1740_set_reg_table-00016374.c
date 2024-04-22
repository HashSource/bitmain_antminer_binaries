
void bm1740_set_reg_table(undefined param_1,undefined4 param_2)

{
  char acStack_108 [256];
  
  pthread_mutex_lock((pthread_mutex_t *)&g_reg_table_mutex);
  switch(param_1) {
  case 0:
    g_reg_table._0_4_ = param_2;
    break;
  default:
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      snprintf(acStack_108,0x100,"error: %s unknow reg type\n","bm1740_set_reg_table");
      _applog(3,acStack_108,0);
    }
    break;
  case 8:
    g_reg_table._4_4_ = param_2;
    break;
  case 0xc:
    g_reg_table._8_4_ = param_2;
    break;
  case 0x14:
    g_reg_table._12_4_ = param_2;
    break;
  case 0x1c:
    g_reg_table._16_4_ = param_2;
    break;
  case 0x20:
    g_reg_table._20_4_ = param_2;
    break;
  case 0x24:
    g_reg_table._24_4_ = param_2;
    break;
  case 0x28:
    g_reg_table._28_4_ = param_2;
    break;
  case 0x30:
    g_reg_table._32_4_ = param_2;
    break;
  case 0x34:
    g_reg_table._36_4_ = param_2;
    break;
  case 0x38:
    g_reg_table._40_4_ = param_2;
    break;
  case 0x3c:
    g_reg_table._44_4_ = param_2;
    break;
  case 0x40:
    g_reg_table._48_4_ = param_2;
    break;
  case 0x54:
    g_reg_table._52_4_ = param_2;
    break;
  case 0x58:
    g_reg_table._56_4_ = param_2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&g_reg_table_mutex);
  return;
}

