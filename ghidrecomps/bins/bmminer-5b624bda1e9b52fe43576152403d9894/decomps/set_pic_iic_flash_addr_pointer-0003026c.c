
/* WARNING: Unknown calling convention */

void set_pic_iic_flash_addr_pointer(uchar chain,uchar addr_H,uchar addr_L)

{
  int iVar1;
  uchar check_addr_H;
  uchar check_addr_L;
  char logstr [256];
  
  iVar1 = 4;
  while( true ) {
    send_pic_command(chain);
    write_pic_iic(false,false,'\0',chain,'\x01');
    write_pic_iic(false,false,'\0',chain,addr_H);
    write_pic_iic(false,false,'\0',chain,addr_L);
    get_pic_iic_flash_addr_pointer(chain,&check_addr_H,&check_addr_L);
    if (((uint)check_addr_H == (uint)addr_H) && ((uint)check_addr_L == (uint)addr_L)) break;
    sprintf(logstr,DAT_000302fc,(uint)addr_H,(uint)check_addr_H,(uint)addr_L,(uint)check_addr_L,
            (uint)chain);
    writeInitLogFile(logstr);
    iVar1 = iVar1 + -1;
    if (iVar1 == 0) {
      return;
    }
    reset_iic_pic(chain);
    sleep(5);
  }
  return;
}

