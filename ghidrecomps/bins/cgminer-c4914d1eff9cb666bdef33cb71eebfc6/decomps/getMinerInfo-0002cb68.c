
void getMinerInfo(char *infoStr)

{
  _Bool _Var1;
  int iVar2;
  int iVar3;
  double dVar4;
  char *infoStr_local;
  int chain_num;
  double voltage;
  int retlen;
  int i;
  
  retlen = 0;
  voltage = 0.0;
  chain_num = 0;
  _Var1 = is_T11();
  if (_Var1) {
    for (i = 0; i < 0x10; i = i + 1) {
      if (dev->chain_exist[i] != 0) {
        dVar4 = get_working_voltage_by_chain((uint8_t)i);
        voltage = voltage + dVar4 * DAT_0002cd48;
      }
    }
    voltage = voltage / (double)(longlong)i;
  }
  else {
    dVar4 = get_working_voltage();
    voltage = dVar4 * DAT_0002cd48;
  }
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] != 0) {
      iVar3 = sprintf(infoStr + retlen,"chain%d_voltage=%d;",i + 1,(int)(longlong)voltage);
      iVar2 = sprintf(infoStr + retlen + iVar3,"chain%d_voladded=%d;",i + 1,0);
      iVar2 = retlen + iVar3 + iVar2;
      _Var1 = is_economic_mode();
      if (_Var1) {
        iVar3 = sprintf(infoStr + iVar2,"chain%d_basefreq=%d;",i + 1,
                        g_sweep_config_eco.sweep_max_freq);
      }
      else {
        iVar3 = sprintf(infoStr + iVar2,"chain%d_basefreq=%d;",i + 1,
                        g_sweep_config_hpf.sweep_max_freq);
      }
      retlen = iVar2 + iVar3;
      iVar3 = sprintf(infoStr + retlen,"chain%d_badcore=%d;",i + 1,0);
      retlen = retlen + iVar3;
      chain_num = chain_num + 1;
    }
  }
  iVar3 = sprintf(infoStr + retlen,"chainnum=%d;",chain_num);
  sprintf(infoStr + retlen + iVar3,"version=%s;",g_miner_compiletime);
  return;
}

