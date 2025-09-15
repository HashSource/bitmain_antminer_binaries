
void get_pic_iic_flash_addr_pointer(uchar chain,uchar *addr_H,uchar *addr_L)

{
  uchar uVar1;
  uchar *addr_L_local;
  uchar *addr_H_local;
  uchar chain_local;
  
  send_pic_command(chain);
  write_pic_iic(false,false,'\0',chain,'\b');
  uVar1 = write_pic_iic(true,false,'\0',chain,'\0');
  *addr_H = uVar1;
  uVar1 = write_pic_iic(true,false,'\0',chain,'\0');
  *addr_L = uVar1;
  return;
}

