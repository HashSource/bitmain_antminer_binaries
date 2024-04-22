
undefined4 platform_init(void)

{
  int iVar1;
  undefined4 uVar2;
  uint local_214;
  char acStack_210 [512];
  char *local_10;
  int local_c;
  
  if (platform_inited == 0) {
    iVar1 = fpga_init();
    if (iVar1 == 0) {
      iVar1 = gpio_init();
      if (iVar1 == 0) {
        memset(capability,0,0x124);
        local_10 = getenv("HAL_CONFIG_PATH");
        if (local_10 == (char *)0x0) {
          snprintf(acStack_210,0x200,"/media/card/%s","hal_conf.json");
        }
        else {
          snprintf(acStack_210,0x200,"%s/%s",local_10,"hal_conf.json");
        }
        printf("%s:%d","platform_init",0x41);
        printf("hal config path = %s\n",acStack_210);
        iVar1 = hal_load_conf(acStack_210);
        if (iVar1 == 0) {
          local_214 = 0;
          local_c = 0;
          fpga_read(2,&local_214);
          if (local_214 == 0) {
            printf("%s:%d","platform_init",0x4c);
            puts("Cannot Find Any Plug In!\r");
          }
          else if ((local_214 & 0xff000000) == 0) {
            platform_is_t9 = 0;
            local_214 = local_214 & 0xffff;
            printf("%s:%d","platform_init",0x57);
            printf("HASH_ON_PLUG V9 = 0x%x\n",local_214);
            for (; local_214 != 0; local_214 = local_214 >> 1) {
              if ((local_214 & 1) != 0) {
                printf("%s:%d","platform_init",0x5a);
                printf("slot %d pluged\n",local_c);
                *(int *)(capability + capability._0_4_ * 0x48 + 4) = local_c;
                *(int *)(capability +
                        (capability._0_4_ * 0x12 +
                         *(int *)(capability + capability._0_4_ * 0x48 + 8) + 2) * 4 + 4) = local_c;
                *(int *)(capability + capability._0_4_ * 0x48 + 8) =
                     *(int *)(capability + capability._0_4_ * 0x48 + 8) + 1;
                capability._0_4_ = capability._0_4_ + 1;
              }
              local_c = local_c + 1;
            }
          }
          else {
            platform_is_t9 = 1;
            local_214 = local_214 >> 0x18;
            printf("%s:%d","platform_init",0x51);
            printf("HASH_ON_PLUG T9 = 0x%x\n",local_214);
          }
          if (platform_is_t9 == 0) {
            fpga_read(v9_fpga_map._0_4_,&local_214);
          }
          else {
            fpga_read(t9_fpga_map,&local_214);
          }
          local_214 = local_214 | 0x20000000;
          printf("%s:%d","platform_init",0x68);
          printf("HARDWARE_VERSION = 0x%x\n",local_214);
          if (platform_is_t9 == 0) {
            fpga_write(v9_fpga_map._0_4_,local_214);
          }
          else {
            fpga_write(t9_fpga_map,local_214);
          }
          platform_dump_capability(capability);
          platform_inited = 1;
          fan_init();
          ui_init();
          uart_init();
          uVar2 = 0;
        }
        else {
          fpga_uninit();
          gpio_uninit();
          printf("%s:%d","platform_init",0x45);
          puts("failed to load hal config");
          uVar2 = 0xfffffffd;
        }
      }
      else {
        printf("%s:%d","platform_init",0x33);
        puts("gpio init failed");
        uVar2 = 0xfffffffe;
      }
    }
    else {
      printf("%s:%d","platform_init",0x2f);
      puts("fpga init failed");
      uVar2 = 0xffffffff;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

