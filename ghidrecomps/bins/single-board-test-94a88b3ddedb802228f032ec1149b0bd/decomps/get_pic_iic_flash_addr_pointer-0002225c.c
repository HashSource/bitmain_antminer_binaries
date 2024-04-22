
void get_pic_iic_flash_addr_pointer(undefined param_1,byte *param_2,byte *param_3)

{
  byte bVar1;
  
  puts("get_pic_iic_flash_addr_pointer");
  send_pic_command(param_1);
  pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
  write_pic_iic(0,0,0,param_1,8);
  bVar1 = write_pic_iic(1,0,0,param_1,0);
  *param_2 = bVar1;
  bVar1 = write_pic_iic(1,0,0,param_1,0);
  *param_3 = bVar1;
  pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
  printf("%s: *addr_H = 0x%02x, *addr_L = 0x%02x\n","get_pic_iic_flash_addr_pointer",(uint)*param_2,
         (uint)*param_3);
  return;
}

