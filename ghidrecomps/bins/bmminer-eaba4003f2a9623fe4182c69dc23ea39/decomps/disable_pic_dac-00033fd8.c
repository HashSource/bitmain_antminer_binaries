
void disable_pic_dac(uchar chain)

{
  uchar chain_local;
  
  dsPIC33EP16GS202_enable_pic_dc_dc(chain,'\0');
  return;
}

