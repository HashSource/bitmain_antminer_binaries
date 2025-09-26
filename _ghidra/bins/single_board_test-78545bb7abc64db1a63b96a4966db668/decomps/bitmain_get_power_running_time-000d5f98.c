
/* WARNING: Unknown calling convention */

double bitmain_get_power_running_time(void)

{
  int32_t iVar1;
  uint uVar2;
  double dVar3;
  uint8_t send_data [6];
  uint8_t read_back_data [10];
  char tmp42 [2048];
  
  if ((_g_power_state.power_open == 0) && (iVar1 = bitmain_power_open(), iVar1 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
             "bitmain_get_power_running_time");
    _applog(0,tmp42,false);
    dVar3 = (double)(longlong)iVar1;
  }
  else {
    dVar3 = -1.0;
    if (_g_power_state.power_version - 0xc1 < 2) {
      send_data[0] = 'U';
      send_data[1] = 0xaa;
      send_data[3] = '\f';
      read_back_data[4] = '\0';
      read_back_data[5] = '\0';
      read_back_data[6] = '\0';
      read_back_data[7] = '\0';
      read_back_data[8] = '\0';
      read_back_data[9] = '\0';
      send_data[2] = '\x04';
      send_data[4] = '\x10';
      send_data[5] = '\0';
      read_back_data[0] = '\0';
      read_back_data[1] = '\0';
      read_back_data[2] = '\0';
      read_back_data[3] = '\0';
      iVar1 = exec_power_cmd(_g_power_state.power_fd,send_data,6,read_back_data,10);
      if (iVar1 == 0) {
        uVar2 = ((uint)read_back_data._4_4_ >> 0x10 & 0xff) << 0x10 |
                read_back_data._4_4_ & 0xff000000 | read_back_data._4_4_ & 0xff |
                ((uint)read_back_data._4_4_ >> 8 & 0xff) << 8;
        if (uVar2 != 0x80000300) {
          return (double)(longlong)(int)uVar2 * 0.20000000298023224;
        }
      }
      else {
        builtin_strncpy(tmp42,"get power run time faile",0x18);
        tmp42[0x18] = 'd';
        tmp42[0x19] = '\n';
        tmp42[0x1a] = '\0';
        _applog(0,tmp42,false);
      }
      snprintf(tmp42,0x800,"can\'t get power running time ret = 0x%x\n",0x80000300);
      _applog(0,tmp42,false);
      dVar3 = -2147482880.0;
    }
  }
  return dVar3;
}

