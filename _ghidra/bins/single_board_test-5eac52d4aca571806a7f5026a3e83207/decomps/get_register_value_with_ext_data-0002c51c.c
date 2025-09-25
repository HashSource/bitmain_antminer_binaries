
uint32_t get_register_value_with_ext_data
                   (uint32_t which_asic,uint32_t which_function,_Bool mode,char *asic_type,
                   void *ext_data)

{
  uint8_t which_chain;
  uint16_t uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint uVar7;
  char *asic_type_local;
  _Bool mode_local;
  uint32_t which_function_local;
  uint32_t which_asic_local;
  char time_stamp [48];
  char tmp1 [256];
  tick_nonce_counter_t tick_nonce_counter_reg;
  general_i2c_command_t i2c_command_reg;
  returned_nonce_counter_t returned_nonce_counter_reg;
  frequency_sweep_control_t frequency_sweep_control_reg;
  int32_t dv0_dout;
  int32_t domain_voltage_value;
  uint32_t *p_val_1;
  int domain;
  float temp;
  int temp_value;
  asic_val_t *p_val;
  uint32_t asic_addr;
  uint32_t register_addr;
  uint32_t reg_value_num;
  uint32_t asic_name;
  uint32_t i;
  uint32_t bad_asic_number;
  uint32_t register_value;
  uint32_t get_register_value_loop;
  
  get_register_value_loop = 0;
  register_value = 0;
  asic_name = 0;
  clear_register_value_buf();
  which_chain = (uint8_t)gChain;
  which_function_local = which_function;
  if (which_function == 8) {
    send_get_status_command(which_chain,'\0',which_asic * gAddress_interval,0xff);
  }
  else if (which_function < 9) {
    if (which_function != 3) {
      if (3 < which_function) {
        if (which_function == 6) {
          get_asic_clock_delay_control(which_chain,0);
          which_function_local = 10;
        }
        else if (which_function < 7) {
          if (which_function != 5) goto LAB_0002c854;
          send_get_status_command(which_chain,'\x01',0,0xff);
        }
        else {
          send_get_status_command(which_chain,'\x01',0,0x4c);
        }
        goto LAB_0002c8be;
      }
      if (which_function == 1) {
        send_get_status_command(which_chain,'\x01',0,8);
        goto LAB_0002c8be;
      }
      if (which_function < 2) {
        gAsic_num = 0;
        memset(gHistory_Result[gPattern_test_counter].ok_asic_list,0,0x41);
        memset(gHistory_Result[gPattern_test_counter].bad_asic_list,1,0x41);
        uVar1 = get_asic_name(asic_type);
        asic_name = (uint32_t)uVar1;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : asic_name: 0x%04x\n","get_register_value_with_ext_data",asic_name);
        snprintf(tmp1,0x100,"asic_name: 0x%04x",asic_name);
        log_to_file(tmp1,time_stamp);
        get_chain_asic_num((uint8_t)gChain);
        goto LAB_0002c8be;
      }
      get_chain_hash_clock_counter(which_chain);
      which_function_local = 10;
    }
    send_get_status_command((uint8_t)gChain,'\x01',0,0x14);
  }
  else if (which_function == 0xd) {
    send_get_status_command(which_chain,'\x01',0,0x8c);
  }
  else if (which_function < 0xe) {
    if (which_function == 0xb) {
      send_get_status_command(which_chain,'\x01',0,0x18);
    }
    else if (which_function < 0xc) {
      if (which_function != 9) {
LAB_0002c854:
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Don\'t support this register: 0x%02x\n","get_register_value_with_ext_data",
               which_function);
        snprintf(tmp1,0x100,"Don\'t support this register: 0x%02x",which_function);
        log_to_file(tmp1,time_stamp);
        return 0xffffffff;
      }
      send_get_status_command(which_chain,'\0',which_asic * gAddress_interval,0xff);
    }
    else {
      send_get_status_command(which_chain,'\x01',0,0x94);
    }
  }
  else if (which_function == 0xbd) {
    send_get_status_command(which_chain,'\x01',0,0xbd);
  }
  else if (which_function == 0xff) {
    send_get_status_command(which_chain,'\x01',0,0xff);
  }
  else {
    if (which_function != 0xe) goto LAB_0002c854;
    send_get_status_command(which_chain,'\x01',0,0x90);
  }
LAB_0002c8be:
  bad_asic_number = 0;
  do {
    while( true ) {
      if (2 < get_register_value_loop) {
        return register_value;
      }
      usleep(30000);
      pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
      uVar4 = reg_value_buf->reg_value_num;
      pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
      if (uVar4 != 0) break;
      usleep(100000);
      get_register_value_loop = get_register_value_loop + 1;
    }
    get_register_value_loop = 0;
    for (i = 0; i < uVar4; i = i + 1) {
      pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
      if (0xffe < reg_value_buf->p_rd) {
        pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : reg_value_buf err.\n","get_register_value_with_ext_data");
        builtin_strncpy(tmp1,"reg_value_buf er",0x10);
        tmp1[0x10] = 'r';
        tmp1[0x11] = '.';
        tmp1[0x12] = '\0';
        log_to_file(tmp1,time_stamp);
        return 0xffffffff;
      }
      register_value = reg_value_buf->reg_buffer[reg_value_buf->p_rd].reg_value;
      uVar5 = reg_value_buf->reg_buffer[reg_value_buf->p_rd].reg_address;
      uVar6 = reg_value_buf->reg_buffer[reg_value_buf->p_rd].chip_address;
      pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
      if (which_function_local != 9) {
        uVar1 = (uint16_t)register_value;
        if (which_function_local < 10) {
          if (which_function_local == 4) {
            if (((register_value & 0x80) != 0) || ((register_value & 8) != 0)) {
              gHardware_sweep_done_asic_num = gHardware_sweep_done_asic_num + 1;
            }
          }
          else if (which_function_local < 5) {
            if (which_function_local == 1) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : PLL 0 register: 0x%08x\n","get_register_value_with_ext_data",
                     register_value);
              snprintf(tmp1,0x100,"PLL 0 register: 0x%08x",register_value);
              log_to_file(tmp1,time_stamp);
            }
            else if (which_function_local == 0) {
              if (register_value >> 0x10 == asic_name) {
                gAsic_num = gAsic_num + 1;
                uVar7 = (uint)gPattern_test_counter;
                uVar2 = __aeabi_uidiv(0xff,gAddress_interval);
                gHistory_Result[uVar7].ok_asic_list[uVar2 & register_value] = true;
              }
              else {
                bad_asic_number = bad_asic_number + 1;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : chip address register is 0x%04x,chip_addr:%d\n",
                       "get_register_value_with_ext_data",register_value >> 0x10,
                       register_value & 0xff);
                snprintf(tmp1,0x100,"chip address register is 0x%04x,chip_addr:%d",
                         register_value >> 0x10,register_value & 0xff);
                log_to_file(tmp1,time_stamp);
                if ((Local_Config_Information->Hash_Board).Asic_Num < bad_asic_number) {
                  gAsic_num = gAsic_num + bad_asic_number;
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : too much error asic address register, fail\n",
                         "get_register_value_with_ext_data");
                  builtin_strncpy(tmp1,"too much error asic address register, fa",0x28);
                  tmp1[0x28] = 'i';
                  tmp1[0x29] = 'l';
                  tmp1[0x2a] = '\0';
                  log_to_file(tmp1,time_stamp);
                  return gAsic_num;
                }
              }
            }
            else {
              if (which_function_local != 3) {
LAB_0002d30e:
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : Don\'t support this register in check: 0x%02x\n",
                       "get_register_value_with_ext_data",which_function_local);
                snprintf(tmp1,0x100,"Don\'t support this register in check: 0x%02x",
                         which_function_local);
                log_to_file(tmp1,time_stamp);
                return 0xffffffff;
              }
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : TICKET_MASK register: 0x%08x\n","get_register_value_with_ext_data",
                     register_value);
              snprintf(tmp1,0x100,"TICKET_MASK register: 0x%08x",register_value);
              log_to_file(tmp1,time_stamp);
            }
          }
          else if (which_function_local == 7) {
            uVar2 = (uint)gPattern_test_counter;
            iVar3 = __aeabi_uidiv(reg_value_buf->reg_buffer[reg_value_buf->p_rd].chip_address,
                                  gAddress_interval);
            gHistory_Result[uVar2].every_asic_reg_nonce_error_num[iVar3] = uVar1;
          }
          else if (which_function_local < 8) {
            if (which_function_local != 5) goto LAB_0002d30e;
            uVar2 = (uint)gPattern_test_counter;
            iVar3 = __aeabi_uidiv(reg_value_buf->reg_buffer[reg_value_buf->p_rd].chip_address,
                                  gAddress_interval);
            returned_nonce_counter_reg.u._RETURN_NONCE_CNT_MATCH =
                 (uint16_t)(register_value >> 0x10);
            gHistory_Result[uVar2].every_asic_got_nonce_num[iVar3] =
                 returned_nonce_counter_reg.u._RETURN_NONCE_CNT_MATCH;
            gHistory_Result[gPattern_test_counter].valid_nonce_num =
                 gHistory_Result[gPattern_test_counter].valid_nonce_num +
                 (uint)returned_nonce_counter_reg.u._RETURN_NONCE_CNT_MATCH;
          }
        }
        else if (which_function_local == 0xd) {
          uVar2 = (uint)gPattern_test_counter;
          iVar3 = __aeabi_uidiv(reg_value_buf->reg_buffer[reg_value_buf->p_rd].chip_address,
                                gAddress_interval);
          gHistory_Result[uVar2].every_asic_reg_got_nonce_num[iVar3] = uVar1;
        }
        else if (which_function_local < 0xe) {
          if (which_function_local == 0xb) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : MISC_CONTROL register: 0x%08x\n","get_register_value_with_ext_data",
                   register_value);
            snprintf(tmp1,0x100,"MISC_CONTROL register: 0x%08x",register_value);
            log_to_file(tmp1,time_stamp);
          }
          else if (which_function_local < 0xc) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : CORE_RESPONSE register: 0x%08x\n","get_register_value_with_ext_data",
                   register_value);
            snprintf(tmp1,0x100,"CORE_RESPONSE register: 0x%08x",register_value);
            log_to_file(tmp1,time_stamp);
          }
          else {
            uVar2 = (uint)gPattern_test_counter;
            iVar3 = __aeabi_uidiv(reg_value_buf->reg_buffer[reg_value_buf->p_rd].chip_address,
                                  gAddress_interval);
            gHistory_Result[uVar2].every_asic_got_nonce_num[iVar3] = uVar1;
            gHistory_Result[gPattern_test_counter].valid_nonce_num =
                 gHistory_Result[gPattern_test_counter].valid_nonce_num + register_value;
          }
        }
        else if (which_function_local == 0xbd) {
          if (((int)register_value < 0) && (uVar6 == which_asic)) {
            *(uint32_t *)ext_data = register_value;
          }
        }
        else if (which_function_local == 0xff) {
          if (uVar5 == 0xff) {
            if ((int)register_value < 0) {
              uVar2 = __aeabi_uidiv(uVar6,gAddress_interval);
              if (uVar2 < (Local_Config_Information->Hash_Board).Asic_Num) {
                iVar3 = __aeabi_uidiv(uVar6,gAddress_interval);
                *(double *)((iVar3 + 3) * 8 + (int)ext_data) =
                     (double)(float)((double)(longlong)(int)(register_value & 0xffff) * 0.171342 -
                                    299.5144);
                iVar3 = __aeabi_uidiv(uVar6,gAddress_interval);
                *(undefined1 *)((int)ext_data + iVar3 + 0x224) = 1;
              }
            }
            else {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : register_value:%u,FLAG_VAL:%d\n","get_register_value_with_ext_data",
                     register_value,register_value >> 0x1e);
              snprintf(tmp1,0x100,"register_value:%u,FLAG_VAL:%d",register_value,
                       register_value >> 0x1e);
              log_to_file(tmp1,time_stamp);
            }
          }
          else {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : read register addr err,resp:%d,expect:%d,asic_addr:%d\n",
                   "get_register_value_with_ext_data",uVar5,0xff,uVar6);
            snprintf(tmp1,0x100,"read register addr err,resp:%d,expect:%d,asic_addr:%d",uVar5,0xff,
                     uVar6);
            log_to_file(tmp1,time_stamp);
          }
        }
        else {
          if (which_function_local != 0xe) goto LAB_0002d30e;
          uVar2 = (uint)gPattern_test_counter;
          iVar3 = __aeabi_uidiv(reg_value_buf->reg_buffer[reg_value_buf->p_rd].chip_address,
                                gAddress_interval);
          gHistory_Result[uVar2].every_asic_reg_ntick_nonce_num[iVar3] = uVar1;
          printf("get ntick reg: %d\n",register_value);
        }
      }
      pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
      reg_value_buf->p_rd = reg_value_buf->p_rd + 1;
      reg_value_buf->reg_value_num = reg_value_buf->reg_value_num - 1;
      if (reg_value_buf->p_rd == 0xfff) {
        reg_value_buf->p_rd = 0;
      }
      pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
    }
  } while( true );
}

