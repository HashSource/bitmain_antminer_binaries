
void bm1740_get_reg_table(undefined param_1,void *param_2)

{
  char acStack_108 [256];
  
  pthread_mutex_lock((pthread_mutex_t *)&g_reg_table_mutex);
  switch(param_1) {
  case 0:
    memcpy(param_2,g_reg_table,4);
    break;
  default:
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      snprintf(acStack_108,0x100,"error: %s unknow reg type\n","bm1740_get_reg_table");
      _applog(3,acStack_108,0);
    }
    break;
  case 8:
    memcpy(param_2,DAT_00016934,4);
    break;
  case 0xc:
    memcpy(param_2,DAT_00016938,4);
    break;
  case 0x14:
    memcpy(param_2,DAT_0001693c,4);
    break;
  case 0x1c:
    memcpy(param_2,DAT_00016940,4);
    break;
  case 0x20:
    memcpy(param_2,DAT_00016944,4);
    break;
  case 0x24:
    memcpy(param_2,DAT_00016948,4);
    break;
  case 0x28:
    memcpy(param_2,DAT_0001694c,4);
    break;
  case 0x30:
    memcpy(param_2,DAT_00016950,4);
    break;
  case 0x34:
    memcpy(param_2,DAT_00016954,4);
    break;
  case 0x38:
    memcpy(param_2,DAT_00016958,4);
    break;
  case 0x3c:
    memcpy(param_2,DAT_0001695c,4);
    break;
  case 0x40:
    memcpy(param_2,DAT_00016960,4);
    break;
  case 0x54:
    memcpy(param_2,DAT_00016964,4);
    break;
  case 0x58:
    memcpy(param_2,DAT_00016968,4);
  }
  pthread_mutex_unlock((pthread_mutex_t *)&g_reg_table_mutex);
  return;
}

