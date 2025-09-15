
int i2c_init(void)

{
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  local_c = -1;
  if (platform_inited == 0) {
    printf("%s:%d","i2c_init",0x29);
    puts("please init platform first!!");
    local_c = -2;
  }
  else {
    if (i2c_index == 0) {
      i2c_ctx_map = new_c_map(0x2078d,0,0);
      pthread_mutex_init((pthread_mutex_t *)&i2c_mutex,(pthread_mutexattr_t *)0x0);
    }
    i2c_index = i2c_index + 1;
    local_14 = 0;
    local_10 = 0;
    local_c = i2c_index;
    insert_c_map(i2c_ctx_map,&local_c,4,&local_14,8);
  }
  return local_c;
}

