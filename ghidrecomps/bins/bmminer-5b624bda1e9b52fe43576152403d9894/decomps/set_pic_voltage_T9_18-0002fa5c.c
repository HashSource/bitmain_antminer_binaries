
/* WARNING: Unknown calling convention */

void set_pic_voltage_T9_18(uchar chain)

{
  byte voltage;
  uchar vol_pic;
  uint chainIndex;
  char logstr [256];
  
  chainIndex = (uint)chain;
  voltage = getHighestVoltagePIC(chainIndex);
  sprintf(logstr,"set voltage=%d on chain[%d], the real voltage=%d\n",
          ((int)(longlong)
                (((DAT_0002fb28 /
                   ((double)(longlong)(int)(uint)chain_voltage_pic[chainIndex] + DAT_0002fb20) +
                  DAT_0002fb30) * DAT_0002fb38) / 4.75) / 10) * 10,chainIndex,
          ((int)(longlong)
                (((DAT_0002fb28 / ((double)(longlong)(int)(uint)voltage + DAT_0002fb20) +
                  DAT_0002fb30) * DAT_0002fb38) / 4.75) / 10) * 10);
  writeInitLogFile(logstr);
  set_voltage_T9_18_into_PIC(chain,voltage);
  return;
}

