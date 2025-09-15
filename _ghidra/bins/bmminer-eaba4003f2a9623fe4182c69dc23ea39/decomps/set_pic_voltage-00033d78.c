
void set_pic_voltage(uchar chain,uchar voltage)

{
  uchar voltage_local;
  uchar chain_local;
  
  if ((fpga_version < 0xe) && (fpga_major_version < 0xc6)) {
    if ((uint)chain % 3 == 0) {
      set_pic_voltage_T9_18(chain);
    }
  }
  else if ((chain != '\0') && (chain < 4)) {
    set_pic_voltage_T9_18(chain);
  }
  return;
}

