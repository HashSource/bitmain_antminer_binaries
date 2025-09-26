
/* WARNING: Unknown calling convention */

int32_t _get_power_err_data(_Bool print,uint8_t *raw_data)

{
  int32_t iVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  uint8_t cmd [6];
  uint8_t reply [80];
  char tmp42 [2048];
  
  uVar3 = _g_power_state.power_version & 0xfffffff7;
  bVar11 = 0x61 < uVar3;
  if (uVar3 != 0x62) {
    bVar11 = 1 < _g_power_state.power_version - 100;
  }
  if (!bVar11 || (uVar3 == 0x62 || _g_power_state.power_version - 100 == 2)) {
    cmd[0] = 'U';
    cmd[1] = 0xaa;
    cmd[2] = '\x04';
    cmd[3] = '\x0f';
    cmd[4] = '\x04';
    cmd[5] = '\x0f';
    memset(reply,0,0x50);
    iVar1 = exec_power_cmd_v2(_g_power_state.power_fd,cmd,6,reply,0x4a);
    if (iVar1 == 0) {
      memcpy(raw_data,reply + 4,0x44);
      if (print) {
        builtin_strncpy(tmp42,"Get power error data:\n",0x17);
        _applog(3,tmp42,false);
        iVar2 = 0;
        pbVar4 = reply;
        do {
          iVar5 = iVar2 + 0xc;
          uVar8 = (uint)pbVar4[0xf];
          uVar3 = (uint)pbVar4[0xe];
          uVar9 = (uint)pbVar4[0xd];
          uVar6 = (uint)pbVar4[0xc];
          uVar10 = (uint)pbVar4[0xb];
          uVar7 = (uint)pbVar4[10];
          snprintf(tmp42,0x800,
                   "data[%02d-%02d]: %02x%02x%02x%02x %02x%02x%02x%02x %02x%02x%02x%02x\n",iVar2,
                   iVar2 + 0xb,(uint)pbVar4[4],(uint)pbVar4[5],(uint)pbVar4[6],(uint)pbVar4[7],
                   (uint)pbVar4[8],(uint)pbVar4[9],uVar7,uVar10,uVar6,uVar9,uVar3,uVar8);
          _applog(3,tmp42,false);
          iVar2 = iVar5;
          pbVar4 = pbVar4 + 0xc;
        } while (iVar5 != 0x3c);
        snprintf(tmp42,0x800,"data[60-67]: %02x%02x%02x%02x %02x%02x%02x%02x\n",(uint)reply[0x40],
                 (uint)reply[0x41],(uint)reply[0x42],(uint)reply[0x43],(uint)reply[0x44],
                 (uint)reply[0x45],(uint)reply[0x46],(uint)reply[0x47],uVar7,uVar10,uVar6,uVar9,
                 uVar3,uVar8);
        _applog(3,tmp42,false);
      }
      return 0;
    }
    builtin_strncpy(tmp42,"Get power error data failed\n",0x1c);
    tmp42[0x1c] = '\0';
    _applog(3,tmp42,false);
  }
  return -1;
}

