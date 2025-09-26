
/* WARNING: Unknown calling convention */

int64_t bitmain_clear_power_status(void)

{
  byte bVar1;
  int32_t iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  double a;
  DItype DVar7;
  uint8_t send_data [8];
  uint8_t read_back_data [14];
  char tmp42 [2048];
  
  if (_g_power_state.power_open == 0) {
    iVar2 = bitmain_power_open();
    iVar3 = iVar2 >> 0x1f;
    if (iVar3 < 0) {
      snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
               "bitmain_clear_power_status");
      _applog(0,tmp42,false);
      goto LAB_000d663a;
    }
  }
  if (_g_power_state.power_version - 0xc1 < 2) {
    send_data[0] = 'U';
    send_data[1] = 0xaa;
    send_data[3] = 0x8a;
    read_back_data[4] = '\0';
    read_back_data[5] = '\0';
    read_back_data[6] = '\0';
    read_back_data[7] = '\0';
    read_back_data[8] = '\0';
    read_back_data[9] = '\0';
    read_back_data[10] = '\0';
    read_back_data[0xb] = '\0';
    read_back_data[0xc] = '\0';
    read_back_data[0xd] = '\0';
    send_data[2] = '\x04';
    send_data[4] = 0x8e;
    send_data[5] = '\0';
    send_data[6] = '\0';
    send_data[7] = '\0';
    read_back_data[0] = '\0';
    read_back_data[1] = '\0';
    read_back_data[2] = '\0';
    read_back_data[3] = '\0';
    iVar2 = exec_power_cmd(_g_power_state.power_fd,send_data,8,read_back_data,0xe);
    if (iVar2 == 0) {
      uVar5 = 0x80000300;
      pbVar6 = read_back_data + 3;
      iVar3 = 0;
      do {
        pbVar6 = pbVar6 + 1;
        bVar1 = *pbVar6;
        iVar4 = iVar3 + 8;
        a = pow(2.0,(double)(longlong)iVar3);
        DVar7 = __fixdfdi(a);
        uVar5 = uVar5 | (uint)bVar1 * (int)DVar7;
        iVar3 = iVar4;
      } while (iVar4 != 0x40);
      return (int64_t)(int)uVar5;
    }
    builtin_strncpy(tmp42,"clear power status faile",0x18);
    tmp42[0x18] = 'd';
    tmp42[0x19] = '\n';
    tmp42[0x1a] = '\0';
    _applog(0,tmp42,false);
    snprintf(tmp42,0x800,"can nont clear power status; ret = 0x%x\n",0x80000300);
    _applog(0,tmp42,false);
  }
  iVar2 = -1;
  iVar3 = -1;
LAB_000d663a:
  return CONCAT44(iVar3,iVar2);
}

