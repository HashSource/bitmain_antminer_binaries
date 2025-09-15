
void enable_pic_dac(uchar chain)

{
  uchar chain_local;
  
  dsPIC33EP16GS202_enable_pic_dc_dc(chain,'\x01');
  return;
}

