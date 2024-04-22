
undefined4 hal_load_conf(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined auStack_140 [252];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  void *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  uint local_18;
  uint local_14;
  
  local_1c = (int *)0x0;
  local_20 = (int *)0x0;
  local_24 = (int *)0x0;
  local_28 = (void *)0x0;
  memset(chains,0xff,0x100);
  memset(fans,0xff,0x48);
  local_1c = (int *)json_load_file(param_1,0,auStack_140);
  if ((local_1c == (int *)0x0) || (*local_1c != 0)) {
    printf("%s:%d","hal_load_conf",0x2a);
    printf("%s,%d bad json format\n","platform/7007/src/hal_conf.c",0x2a);
    uVar3 = 0xffffffff;
  }
  else {
    local_28 = (void *)json_dumps(local_1c,0);
    printf("%s:%d","hal_load_conf",0x2e);
    printf("json = %s \n",local_28);
    free(local_28);
    local_20 = (int *)json_object_get(local_1c,"chain");
    if ((local_20 == (int *)0x0) || (*local_20 != 1)) {
      printf("%s:%d","hal_load_conf",0x34);
      printf("%s,%d bad chain format\n","platform/7007/src/hal_conf.c",0x34);
      json_decref(local_1c);
      uVar3 = 0xfffffffe;
    }
    else {
      local_14 = 0;
      while ((uVar1 = local_14, uVar2 = json_array_size(local_20), uVar1 < uVar2 &&
             ((int)local_14 < 0x10))) {
        local_24 = (int *)json_array_get(local_20,local_14);
        if ((local_24 == (int *)0x0) || (*local_24 != 0)) {
          printf("%s:%d","hal_load_conf",0x3e);
          printf("%s,%d bad object in chain\n","platform/7007/src/hal_conf.c",0x3e);
          json_decref(local_1c);
          return 0xfffffffd;
        }
        local_2c = json_object_get(local_24,&DAT_0002cb80);
        uVar3 = json_integer_value(local_2c);
        *(undefined4 *)(chains + local_14 * 0x10) = uVar3;
        local_30 = json_object_get(local_24,&DAT_0002cb84);
        uVar3 = json_integer_value(local_30);
        *(undefined4 *)(chains + local_14 * 0x10 + 4) = uVar3;
        local_34 = json_object_get(local_24,&DAT_0002cb8c);
        uVar3 = json_integer_value(local_34);
        *(undefined4 *)(chains + local_14 * 0x10 + 8) = uVar3;
        local_38 = json_object_get(local_24,"reset");
        uVar3 = json_integer_value(local_38);
        *(undefined4 *)(chains + local_14 * 0x10 + 0xc) = uVar3;
        local_14 = local_14 + 1;
      }
      local_20 = (int *)json_object_get(local_1c,&DAT_0002cb9c);
      if ((local_20 == (int *)0x0) || (*local_20 != 1)) {
        printf("%s:%d","hal_load_conf",0x4f);
        printf("%s,%d bad fan format\n","platform/7007/src/hal_conf.c",0x4f);
        json_decref(local_1c);
        uVar3 = 0xfffffffc;
      }
      else {
        local_18 = 0;
        while ((uVar1 = local_18, uVar2 = json_array_size(local_20), uVar1 < uVar2 &&
               ((int)local_18 < 6))) {
          local_24 = (int *)json_array_get(local_20,local_18);
          if ((local_24 == (int *)0x0) || (*local_24 != 0)) {
            printf("%s:%d","hal_load_conf",0x58);
            printf("%s,%d bad object in fan\n","platform/7007/src/hal_conf.c",0x58);
            json_decref(local_1c);
            return 0xfffffffb;
          }
          local_3c = json_object_get(local_24,&DAT_0002cb80);
          uVar3 = json_integer_value(local_3c);
          *(undefined4 *)(fans + local_18 * 0xc) = uVar3;
          local_40 = json_object_get(local_24,&DAT_0002cbd4);
          uVar3 = json_integer_value(local_40);
          *(undefined4 *)(fans + local_18 * 0xc + 4) = uVar3;
          local_44 = json_object_get(local_24,&DAT_0002cbdc);
          uVar3 = json_integer_value(local_44);
          *(undefined4 *)(fans + local_18 * 0xc + 8) = uVar3;
          local_18 = local_18 + 1;
        }
        local_24 = (int *)json_object_get(local_1c,&DAT_0002cbe0);
        if ((local_24 == (int *)0x0) || (*local_24 != 3)) {
          printf("%s:%d","hal_load_conf",0x67);
          printf("%s,%d bad red\n","platform/7007/src/hal_conf.c",0x67);
          json_decref(local_1c);
          uVar3 = 0xfffffffa;
        }
        else {
          red_addr = json_integer_value(local_24);
          local_24 = (int *)json_object_get(local_1c,"green");
          if ((local_24 == (int *)0x0) || (*local_24 != 3)) {
            printf("%s:%d","hal_load_conf",0x6f);
            printf("%s,%d bad green\n","platform/7007/src/hal_conf.c",0x6f);
            json_decref(local_1c);
            uVar3 = 0xfffffff9;
          }
          else {
            green_addr = json_integer_value(local_24);
            local_24 = (int *)json_object_get(local_1c,"reset");
            if ((local_24 == (int *)0x0) || (*local_24 != 3)) {
              printf("%s:%d","hal_load_conf",0x77);
              printf("%s,%d bad reset\n","platform/7007/src/hal_conf.c",0x77);
              json_decref(local_1c);
              uVar3 = 0xfffffff8;
            }
            else {
              reset_addr = json_integer_value(local_24);
              local_24 = (int *)json_object_get(local_1c,"ipreport");
              if ((local_24 == (int *)0x0) || (*local_24 != 3)) {
                printf("%s:%d","hal_load_conf",0x7f);
                printf("%s,%d bad ipreport\n","platform/7007/src/hal_conf.c",0x7f);
                json_decref(local_1c);
                uVar3 = 0xfffffff7;
              }
              else {
                ipreport_addr = json_integer_value(local_24);
                json_decref(local_1c);
                conf_loaded = 1;
                uVar3 = 0;
              }
            }
          }
        }
      }
    }
  }
  return uVar3;
}

