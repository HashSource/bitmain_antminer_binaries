
/* WARNING: Unknown calling convention */

void fan_control(uchar level)

{
  uint data;
  
  if (level < 0xb) {
    data = *(uint *)(&CSWTCH_3 + (uint)level * 4);
  }
  else {
    data = 0x640000;
  }
  write_axi_fpga(0x21,data);
  return;
}

