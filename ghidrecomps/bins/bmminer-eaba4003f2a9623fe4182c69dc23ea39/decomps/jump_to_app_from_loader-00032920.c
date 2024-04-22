
uchar jump_to_app_from_loader(uchar chain)

{
  undefined4 uVar1;
  undefined4 in_stack_ffffffe4;
  uchar chain_local;
  uchar ret;
  
  send_pic_command(chain);
  uVar1 = 6;
  write_pic_iic(false,false,'\0',chain,'\x06');
  cgsleep_us(CONCAT44(in_stack_ffffffe4,uVar1));
  return chain;
}

