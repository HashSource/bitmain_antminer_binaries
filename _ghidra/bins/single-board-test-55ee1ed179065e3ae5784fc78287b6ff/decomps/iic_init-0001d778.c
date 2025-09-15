
int iic_init(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  int local_10;
  int local_c;
  
  local_10 = 0;
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
  if (iVar1 == 0) {
    if (param_1 == (undefined4 *)0x0) {
      printf("%s:%d","iic_init",0x19);
      puts("bad param");
      local_c = -3;
    }
    else {
      local_10 = i2c_init(0);
      if (local_10 < 0) {
        printf("%s:%d","iic_init",0x1f);
        puts("failed to i2c_init");
        local_c = -1;
      }
      else {
        printf("%s:%d","iic_init",0x23);
        uVar2 = (uint)*(byte *)((int)param_1 + 7);
        printf("i2c chain = %d, master = 0x%x, slave high= 0x%x, slave low = 0x%x\n",*param_1,
               (uint)*(ushort *)(param_1 + 1),(uint)*(byte *)((int)param_1 + 6),uVar2);
        iVar1 = i2c_select(local_10,*(undefined2 *)(param_1 + 1));
        if (iVar1 == 0) {
          iVar1 = i2c_ioctl(local_10,0x703,
                            (uint)*(byte *)((int)param_1 + 7) << 1 |
                            (uint)*(byte *)((int)param_1 + 6) << 4);
          if (iVar1 == 0) {
            pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
            return local_10;
          }
          printf("%s:%d","iic_init",0x2a,iVar1,uVar2);
          puts("failed to i2c_ioctl");
          local_c = -1;
        }
        else {
          printf("%s:%d","iic_init",0x25,iVar1,uVar2);
          puts("failed to i2c_select");
          local_c = -1;
        }
      }
    }
    if (0 < local_10) {
      i2c_uninit(local_10);
    }
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
  }
  else {
    printf("%s:%d","iic_init",0x13);
    puts("failed to iic lock");
    local_c = -4;
  }
  return local_c;
}

