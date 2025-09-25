
/* WARNING: Unknown calling convention */

int32_t pic_write_iic(uint8_t which_chain,uint8_t slave,uint8_t reg,uint8_t *data,int32_t size)

{
  uint uVar1;
  int32_t iVar2;
  char tmp42 [2048];
  
  uVar1 = (uint)which_chain;
  if (uVar1 < 0x10) {
    if ((g_bitmain_pic_state[uVar1].chain_has_opened == 0) &&
       (iVar2 = open_pic(which_chain), iVar2 < 0)) {
      snprintf(tmp42,0x800,"%s: auto exec open_pic, but chain %d open eeprom failed\n",
               "pic_write_iic",uVar1);
      _applog(0,tmp42,false);
    }
    else {
      iVar2 = _pic_write_iic(g_bitmain_pic_state[uVar1].pic_fd,slave,reg,data,size);
    }
  }
  else {
    snprintf(tmp42,0x800,"%s: Bad pic param, input chain is %d\n","pic_write_iic",uVar1);
    _applog(0,tmp42,false);
    iVar2 = -0x7ffffdff;
  }
  return iVar2;
}

