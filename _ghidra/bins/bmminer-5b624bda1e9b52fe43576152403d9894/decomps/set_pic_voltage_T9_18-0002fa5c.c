
/* WARNING: Unknown calling convention */

void set_pic_voltage_T9_18(uchar chain)

{
  byte voltage;
  uint chainIndex;
  char logstr [256];
  
  chainIndex = (uint)chain;
  voltage = getHighestVoltagePIC(chainIndex);
  sprintf(logstr,"set voltage=%d on chain[%d], the real voltage=%d\n",
          ((int)(longlong)
                (((364.0704 / ((double)chain_voltage_pic[chainIndex] + 30.72) + 32.79) * 100.0) /
                4.75) / 10) * 10,chainIndex,
          ((int)(longlong)(((364.0704 / ((double)voltage + 30.72) + 32.79) * 100.0) / 4.75) / 10) *
          10);
  writeInitLogFile(logstr);
  set_voltage_T9_18_into_PIC(chain,voltage);
  return;
}

