
uchar reset_iic_pic(uchar chain)

{
  undefined4 uVar1;
  undefined4 in_stack_ffffffe4;
  uchar chain_local;
  uchar ret;
  
  send_pic_command(chain);
  uVar1 = 7;
  write_pic_iic(false,false,'\0',chain,'\a');
  cgsleep_us(CONCAT44(in_stack_ffffffe4,uVar1));
  return chain;
}

