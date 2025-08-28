
/* WARNING: Unknown calling convention */

void set_pic_voltage(uchar chain,uchar voltage)

{
  if (fpga_version < 0xe) {
    if ((uint)chain % 3 == 0) goto LAB_0002fb6a;
  }
  else if (chain - 1 < 3) {
LAB_0002fb6a:
    set_pic_voltage_T9_18(chain);
    return;
  }
  return;
}

