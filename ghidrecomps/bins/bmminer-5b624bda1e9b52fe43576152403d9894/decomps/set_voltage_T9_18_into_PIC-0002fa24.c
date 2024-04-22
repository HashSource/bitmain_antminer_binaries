
/* WARNING: Unknown calling convention */

void set_voltage_T9_18_into_PIC(uchar chain,uchar voltage)

{
  uchar which_iic;
  
  if (*DAT_0002fa54 < 0xe) {
    set_Voltage_S9_plus_plus_BM1387_54(chain / 3,voltage);
    return;
  }
  if (chain - 1 < 0xd) {
    which_iic = *(uchar *)(DAT_0002fa58 + (chain - 1) * 4 + 0x9b8);
  }
  else {
    which_iic = '\0';
  }
  set_Voltage_S9_plus_plus_BM1387_54(which_iic,voltage);
  return;
}

