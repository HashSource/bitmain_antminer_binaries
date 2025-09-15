
void set_pic_iic_flash_addr_pointer(uchar chain,uchar addr_H,uchar addr_L)

{
  uchar addr_L_local;
  uchar addr_H_local;
  uchar chain_local;
  char tmp42 [2048];
  char logstr [1024];
  uchar check_addr_L;
  uchar check_addr_H;
  int try_count;
  
  try_count = 0;
  while( true ) {
    send_pic_command(chain);
    write_pic_iic(false,false,'\0',chain,'\x01');
    write_pic_iic(false,false,'\0',chain,addr_H);
    write_pic_iic(false,false,'\0',chain,addr_L);
    get_pic_iic_flash_addr_pointer(chain,&check_addr_H,&check_addr_L);
    if ((addr_H == check_addr_H) && (addr_L == check_addr_L)) {
      return;
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"Error of set PIC FLASH addr: addr_H=%x(%x) addr_L=%x(%x) on Chain[%d]\n"
               ,(uint)addr_H,(uint)check_addr_H,(uint)addr_L,(uint)check_addr_L,(uint)chain);
      _applog(5,tmp42,false);
    }
    try_count = try_count + 1;
    if (3 < try_count) break;
    reset_iic_pic(chain);
    sleep(5);
  }
  return;
}

