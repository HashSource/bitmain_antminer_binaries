
void getMinerInfo(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  char *__s;
  undefined auStack_124 [256];
  uint local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  uVar1 = s_chainnum_0__001321e8._8_4_;
  uVar2 = s_chainnum_0__001321e8._4_4_;
  local_14 = 0;
  if (IsSomeBoardHasNoFreq == '\0') {
    getFileSysComplieTime(auStack_124);
    for (local_18 = 0; local_18 < 0x10; local_18 = local_18 + 1) {
      if (*(int *)(cgpu + (local_18 + 0x9c638) * 4) != 0) {
        local_1c = get_chain_number(local_18);
        if ((chain_pic_buf[local_18 * 0x80 + 1] == '}') &&
           (chain_pic_buf[local_18 * 0x80 + 0x28] == '#')) {
          local_20 = (((byte)chain_pic_buf[local_18 * 0x80 + 0x24] & 0xf) * 0x10 +
                     ((byte)chain_pic_buf[local_18 * 0x80 + 0x26] & 0xf)) * 10;
          iVar3 = sprintf((char *)((int)param_1 + local_14),"chain%d_voltage=%d;",local_1c + 1,
                          local_20);
          local_14 = local_14 + iVar3;
          iVar3 = sprintf((char *)((int)param_1 + local_14),"chain%d_voladded=%d;",local_1c + 1,
                          (byte)chain_pic_buf[local_18 * 0x80 + 10] & 0x3f);
          local_14 = local_14 + iVar3;
          local_24 = (uint)(byte)chain_pic_buf[local_18 * 0x80 + 2];
          iVar3 = sprintf((char *)((int)param_1 + local_14),"chain%d_basefreq=%s;",local_1c + 1,
                          *(undefined4 *)(freq_pll_1385 + local_24 * 0x10));
          local_14 = local_14 + iVar3;
          __s = (char *)((int)param_1 + local_14);
          iVar3 = local_1c + 1;
          uVar2 = getChainBadCoreNumUserMode(local_18);
          iVar3 = sprintf(__s,"chain%d_badcore=%d;",iVar3,uVar2);
          local_14 = local_14 + iVar3;
        }
      }
    }
    iVar3 = sprintf((char *)((int)param_1 + local_14),"chainnum=%d;",local_1c + 1);
    local_14 = local_14 + iVar3;
    sprintf((char *)(local_14 + (int)param_1),"version=%s;",auStack_124);
  }
  else {
    *param_1 = s_chainnum_0__001321e8._0_4_;
    param_1[1] = uVar2;
    param_1[2] = uVar1;
  }
  return;
}

