
uint8_t read_pic_iic(uint8_t chain)

{
  _Bool _Var1;
  uint8_t uVar2;
  uint8_t chain_local;
  uchar reg_addr;
  _Bool reg_addr_valid;
  uchar which_iic;
  uchar dev_addr;
  
  _Var1 = is_T11a();
  chain_local = chain;
  if ((_Var1) && (chain_pcb_version[chain] < 0x21)) {
    if (chain == '\x01') {
      chain_local = '\x02';
    }
    else if (chain == '\x02') {
      chain_local = '\x01';
    }
  }
  uVar2 = zynq_set_iic(chain_local & 7 | 0x20,'\0',true,false,'\0','\0');
  return uVar2;
}

