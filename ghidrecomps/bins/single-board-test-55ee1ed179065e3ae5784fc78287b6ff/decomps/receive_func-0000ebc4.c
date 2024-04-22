
void * receive_func(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  void *pvVar3;
  int iVar4;
  uint local_48;
  uint local_44;
  void *local_40;
  void *local_3c;
  void *local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  byte local_26;
  byte local_25;
  byte *local_24;
  size_t local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  
  local_25 = *param_1;
  local_26 = param_1[1];
  local_14 = 0;
  local_18 = 0;
  local_44 = 0;
  local_48 = 0;
  local_2c = 0;
  local_1c = 0;
  local_30 = 0;
  local_34 = 0;
  local_20 = 0;
  if (Conf._116_4_ == 0x6ba) {
    local_20 = 9;
  }
  else if (Conf._116_4_ == 0x6bd) {
    local_20 = 10;
  }
  local_24 = param_1;
  pvVar3 = malloc(local_20 * 200);
  local_38 = pvVar3;
  if (pvVar3 == (void *)0x0) {
    printf("%s, malloc buffer error!\n","receive_func");
    local_38 = pvVar3;
  }
  else {
    pvVar3 = malloc(local_20 * 100);
    local_3c = pvVar3;
    if (pvVar3 == (void *)0x0) {
      printf("%s, malloc buffer error!\n","receive_func");
      free(local_38);
      local_38 = pvVar3;
    }
    else {
      pvVar3 = malloc(local_20);
      local_40 = pvVar3;
      if (pvVar3 == (void *)0x0) {
        printf("%s, malloc buffer error!\n","receive_func");
        free(local_3c);
        free(local_38);
        local_38 = pvVar3;
      }
      else {
        local_34 = local_20 * 100;
        printf("%s: which_chain = %d, which_i2c = %d\n","receive_func",(uint)local_25,(uint)local_26
              );
        uart_flush_rx(local_25);
        while (*(char *)((int)&start_receive + (uint)local_25) != '\0') {
          while (*(char *)((int)&gIsOpeningCore + (uint)local_25) != '\0') {
            usleep(2000);
          }
          usleep(300);
          local_14 = uart_receive(local_25,local_38,local_20);
          for (local_1c = 0; local_1c < local_14; local_1c = local_1c + 1) {
            *(undefined *)((int)local_3c + local_44) = *(undefined *)((int)local_38 + local_1c);
            add_point(&local_44,local_34);
          }
          if (local_48 != local_44) {
            if (local_48 < local_44) {
              iVar4 = -local_48;
            }
            else {
              iVar4 = local_20 * 100 - local_48;
            }
            local_14 = local_44 + iVar4;
            while (local_20 <= local_14) {
              if ((*(char *)((int)local_3c + local_48) == -0x56) &&
                 (iVar4 = use_point_add_1(local_48,local_34),
                 *(char *)((int)local_3c + iVar4) == 'U')) {
                for (local_1c = 0; local_1c < local_20; local_1c = local_1c + 1) {
                  *(undefined *)((int)local_40 + local_1c) =
                       *(undefined *)((int)local_3c + local_48);
                  add_point(&local_48,local_34);
                }
                local_14 = local_14 - local_20;
                iVar4 = is_nonce_or_reg_value(*(undefined *)((int)local_40 + (local_20 - 1)));
                if (iVar4 == 0) {
                  local_30 = check_register_value(local_25,(int)local_40 + 2);
                  if (local_30 == -1) {
                    local_18 = local_18 + 1;
                  }
                }
                else if (((*(char *)((int)&gStartTest + (uint)local_25) != '\0') &&
                         (*(char *)((int)&gIsOpenCoreEnd + (uint)local_25) != '\0')) &&
                        (local_30 = check_nonce(local_25,(int)local_40 + 2), local_30 == -1)) {
                  local_18 = local_18 + 1;
                }
              }
              else {
                local_1c = 0;
                while ((local_1c < local_20 - 1 &&
                       ((*(char *)((int)local_3c + local_48) != -0x56 ||
                        (iVar4 = use_point_add_1(local_48,local_34),
                        *(char *)((int)local_3c + iVar4) != 'U'))))) {
                  add_point(&local_48,local_34);
                  iVar4 = use_point_sub_1(local_48,local_34);
                  bVar1 = *(byte *)((int)local_3c + iVar4);
                  bVar2 = *(byte *)((int)local_3c + local_48);
                  iVar4 = use_point_add_1(local_48,local_34);
                  printf("%s: Headers are not corret! Header0 = 0x%02x, Header1 = 0x%02x, Header2 = 0x%02x rp = %d\n"
                         ,"receive_func",(uint)bVar1,(uint)bVar2,
                         (uint)*(byte *)((int)local_3c + iVar4),local_48);
                  local_1c = local_1c + 1;
                }
                local_14 = local_14 - local_1c;
              }
            }
          }
        }
        if (local_40 != (void *)0x0) {
          free(local_40);
        }
        if (local_3c != (void *)0x0) {
          free(local_3c);
        }
        if (local_38 != (void *)0x0) {
          free(local_38);
        }
      }
    }
  }
  return local_38;
}

