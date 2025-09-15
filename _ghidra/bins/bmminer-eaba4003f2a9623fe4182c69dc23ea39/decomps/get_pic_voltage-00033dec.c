
uchar get_pic_voltage(uchar chain)

{
  uchar uVar1;
  uchar chain_local;
  int new_T9_PLUS_chainOffset;
  int new_T9_PLUS_chainIndex;
  
  if ((fpga_version < 0xe) && (fpga_major_version < 0xc6)) {
    uVar1 = AT24C02_read_voltage(chain / 3);
  }
  else {
    getPICChainIndexOffset((uint)chain,&new_T9_PLUS_chainIndex,&new_T9_PLUS_chainOffset);
    uVar1 = AT24C02_read_voltage((uchar)new_T9_PLUS_chainIndex);
  }
  return uVar1;
}

