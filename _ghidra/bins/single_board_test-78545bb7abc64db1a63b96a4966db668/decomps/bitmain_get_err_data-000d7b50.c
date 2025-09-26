
/* WARNING: Unknown calling convention */

int32_t bitmain_get_err_data(_Bool print,uint8_t *raw_data)

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
  uint8_t auStack_870 [8];
  byte abStack_868 [4];
  undefined1 auStack_864 [60];
  byte bStack_828;
  byte bStack_827;
  byte bStack_826;
  byte bStack_825;
  byte bStack_824;
  byte bStack_823;
  byte bStack_822;
  byte bStack_821;
  char acStack_818 [20];
  undefined4 uStack_804;
  char acStack_800 [2028];
  
  uVar3 = _g_power_state.power_version & 0xfffffff7;
  bVar11 = 0x61 < uVar3;
  if (uVar3 != 0x62) {
    bVar11 = 1 < _g_power_state.power_version - 100;
  }
  if (!bVar11 || (uVar3 == 0x62 || _g_power_state.power_version - 100 == 2)) {
    auStack_870[0] = 'U';
    auStack_870[1] = 0xaa;
    auStack_870[2] = '\x04';
    auStack_870[3] = '\x0f';
    auStack_870[4] = '\x04';
    auStack_870[5] = '\x0f';
    memset(abStack_868,0,0x50);
    iVar1 = exec_power_cmd_v2(_g_power_state.power_fd,auStack_870,6,abStack_868,0x4a);
    if (iVar1 == 0) {
      memcpy(raw_data,auStack_864,0x44);
      if (print) {
        builtin_strncpy(acStack_818,"Get power error data",0x14);
        uStack_804 = CONCAT13(uStack_804._3_1_,0xa3a);
        _applog(3,acStack_818,false);
        iVar2 = 0;
        pbVar4 = abStack_868;
        do {
          iVar5 = iVar2 + 0xc;
          uVar8 = (uint)pbVar4[0xf];
          uVar3 = (uint)pbVar4[0xe];
          uVar9 = (uint)pbVar4[0xd];
          uVar6 = (uint)pbVar4[0xc];
          uVar10 = (uint)pbVar4[0xb];
          uVar7 = (uint)pbVar4[10];
          snprintf(acStack_818,0x800,
                   "data[%02d-%02d]: %02x%02x%02x%02x %02x%02x%02x%02x %02x%02x%02x%02x\n",iVar2,
                   iVar2 + 0xb,(uint)pbVar4[4],(uint)pbVar4[5],(uint)pbVar4[6],(uint)pbVar4[7],
                   (uint)pbVar4[8],(uint)pbVar4[9],uVar7,uVar10,uVar6,uVar9,uVar3,uVar8);
          _applog(3,acStack_818,false);
          iVar2 = iVar5;
          pbVar4 = pbVar4 + 0xc;
        } while (iVar5 != 0x3c);
        snprintf(acStack_818,0x800,"data[60-67]: %02x%02x%02x%02x %02x%02x%02x%02x\n",
                 (uint)bStack_828,(uint)bStack_827,(uint)bStack_826,(uint)bStack_825,
                 (uint)bStack_824,(uint)bStack_823,(uint)bStack_822,(uint)bStack_821,uVar7,uVar10,
                 uVar6,uVar9,uVar3,uVar8);
        _applog(3,acStack_818,false);
      }
      return 0;
    }
    builtin_strncpy(acStack_818,"Get power error data",0x14);
    uStack_804._0_1_ = ' ';
    uStack_804._1_1_ = 'f';
    uStack_804._2_1_ = 'a';
    uStack_804._3_1_ = 'i';
    builtin_strncpy(acStack_800,"led\n",4);
    acStack_800[4] = 0;
    _applog(3,acStack_818,false);
  }
  return -1;
}

