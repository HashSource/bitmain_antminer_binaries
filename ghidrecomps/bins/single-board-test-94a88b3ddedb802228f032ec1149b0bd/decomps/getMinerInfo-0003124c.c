
void getMinerInfo(char *param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *__s;
  undefined1 auStack_124 [256];
  uint local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  local_14 = 0;
  if (IsSomeBoardHasNoFreq == '\0') {
    getFileSysComplieTime(auStack_124);
    for (local_18 = 0; local_18 < 0x10; local_18 = local_18 + 1) {
      if (*(int *)(cgpu + (local_18 + 0x9c638) * 4) != 0) {
        local_1c = get_chain_number(local_18);
        if ((chain_pic_buf[local_18 * 0x80 + 1] == '}') &&
           (chain_pic_buf[local_18 * 0x80 + 0x28] == '#')) {
          local_20 = ((uint)(byte)(chain_pic_buf[local_18 * 0x80 + 0x24] << 4) +
                     ((byte)chain_pic_buf[local_18 * 0x80 + 0x26] & 0xf)) * 10;
          iVar2 = sprintf(param_1 + local_14,"chain%d_voltage=%d;",local_1c + 1,local_20);
          local_14 = local_14 + iVar2;
          iVar2 = sprintf(param_1 + local_14,"chain%d_voladded=%d;",local_1c + 1,
                          (byte)chain_pic_buf[local_18 * 0x80 + 10] & 0x3f);
          local_14 = local_14 + iVar2;
          local_24 = (uint)(byte)chain_pic_buf[local_18 * 0x80 + 2];
          iVar2 = sprintf(param_1 + local_14,"chain%d_basefreq=%s;",local_1c + 1,
                          *(undefined4 *)(freq_pll_1385 + local_24 * 0x10));
          local_14 = local_14 + iVar2;
          __s = param_1 + local_14;
          iVar2 = local_1c + 1;
          uVar1 = getChainBadCoreNumUserMode(local_18);
          iVar2 = sprintf(__s,"chain%d_badcore=%d;",iVar2,uVar1);
          local_14 = local_14 + iVar2;
        }
      }
    }
    iVar2 = sprintf(param_1 + local_14,"chainnum=%d;",local_1c + 1);
    local_14 = local_14 + iVar2;
    sprintf(param_1 + local_14,"version=%s;",auStack_124);
  }
  else {
    builtin_strncpy(param_1,"chainnum=0;",0xc);
  }
  return;
}

