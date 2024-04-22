
void disable_pic_dac(uint8_t chain)

{
  uint8_t chain_local;
  
  dsPIC33EP16GS202_enable_pic_dc_dc(chain,'\0');
  return;
}

