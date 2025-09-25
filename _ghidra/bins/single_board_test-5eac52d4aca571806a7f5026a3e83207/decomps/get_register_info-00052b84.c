
uint32_t get_register_info(uint32_t which_asic,uint32_t which_function,_Bool mode,char *asic_type)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
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
  uint16_t asic_addr;
  uint32_t reg_value_num;
  uint32_t find_asic;
  uint16_t asic_name;
  uint32_t i;
  uint32_t bad_asic_number;
  uint32_t register_value;
  uint32_t get_register_value_loop;
  
  get_register_value_loop = 0;
  register_value = 0;
  asic_name = 0;
  clear_register_buf();
  which_function_local = which_function;
  switch(which_function) {
  case 0:
    find_asic = 0;
    asic_name = get_asic_flag(asic_type);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : asic_name: 0x%04x\n","get_register_info",(uint)asic_name);
    snprintf(tmp1,0x100,"asic_name: 0x%04x",(uint)asic_name);
    log_to_file(tmp1,time_stamp);
    get_chain_asic_num((uint8_t)(g_rt.config)->chain);
    break;
  case 1:
    send_get_status_command((uint8_t)(g_rt.config)->chain,'\x01',0,8);
    break;
  case 2:
    get_chain_hash_clock_counter((uint8_t)(g_rt.config)->chain);
    which_function_local = 10;
  case 3:
    send_get_status_command((uint8_t)(g_rt.config)->chain,'\x01',0,0x14);
    break;
  default:
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Don\'t support this register: 0x%02x\n","get_register_info",which_function);
    snprintf(tmp1,0x100,"Don\'t support this register: 0x%02x",which_function);
    log_to_file(tmp1,time_stamp);
    return 0xffffffff;
  case 5:
    send_get_status_command((uint8_t)(g_rt.config)->chain,'\x01',0,0xff);
    break;
  case 6:
    get_asic_clock_delay_control((uint8_t)(g_rt.config)->chain,0);
    which_function_local = 10;
    break;
  case 7:
    send_get_status_command((uint8_t)(g_rt.config)->chain,'\x01',0,0x4c);
    break;
  case 8:
    send_get_status_command
              ((uint8_t)(g_rt.config)->chain,'\0',which_asic * (g_rt.config)->interval,0xff);
    break;
  case 9:
    send_get_status_command
              ((uint8_t)(g_rt.config)->chain,'\0',which_asic * (g_rt.config)->interval,0xff);
    break;
  case 0xb:
    send_get_status_command((uint8_t)(g_rt.config)->chain,'\x01',0,0x18);
    break;
  case 0xc:
    send_get_status_command((uint8_t)(g_rt.config)->chain,'\x01',0,0x94);
    break;
  case 0xd:
    send_get_status_command((uint8_t)(g_rt.config)->chain,'\x01',0,0x8c);
    break;
  case 0xe:
    send_get_status_command((uint8_t)(g_rt.config)->chain,'\x01',0,0x90);
  }
  bad_asic_number = 0;
  do {
    while( true ) {
      if (2 < get_register_value_loop) {
        if (which_function_local == 0) {
          register_value = find_asic;
        }
        return register_value;
      }
      usleep(30000);
      pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
      uVar3 = reg_value_buf->reg_value_num;
      pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
      if (uVar3 != 0) break;
      usleep(100000);
      get_register_value_loop = get_register_value_loop + 1;
    }
    get_register_value_loop = 0;
    for (i = 0; i < uVar3; i = i + 1) {
      pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
      register_value = reg_value_buf->reg_buffer[reg_value_buf->p_rd].reg_value;
      pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
      uVar1 = (ushort)register_value;
      switch(which_function_local) {
      case 0:
        if (register_value >> 0x10 == (uint)asic_name) {
          find_asic = find_asic + 1;
          iVar2 = __aeabi_idiv(uVar1 & 0xff,(g_rt.config)->interval);
          g_rt.asic_stats.ok_asic_list[iVar2] = true;
        }
        else {
          bad_asic_number = bad_asic_number + 1;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : chip address register is not 0x%04x, but is 0x%04x\n","get_register_info",
                 (uint)asic_name,register_value >> 0x10);
          snprintf(tmp1,0x100,"chip address register is not 0x%04x, but is 0x%04x",(uint)asic_name,
                   register_value >> 0x10);
          log_to_file(tmp1,time_stamp);
          if ((uint)(g_rt.config)->asics < bad_asic_number) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : too much error asic address register, fail\n","get_register_info");
            builtin_strncpy(tmp1,"too much error asic address register, fa",0x28);
            tmp1[0x28] = 'i';
            tmp1[0x29] = 'l';
            tmp1[0x2a] = '\0';
            log_to_file(tmp1,time_stamp);
            return 0xffffffff;
          }
        }
        break;
      case 1:
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : PLL 0 register: 0x%08x\n","get_register_info",register_value);
        snprintf(tmp1,0x100,"PLL 0 register: 0x%08x",register_value);
        log_to_file(tmp1,time_stamp);
        break;
      default:
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Don\'t support this register in check: 0x%02x\n","get_register_info",
               which_function_local);
        snprintf(tmp1,0x100,"Don\'t support this register in check: 0x%02x",which_function_local);
        log_to_file(tmp1,time_stamp);
        return 0xffffffff;
      case 3:
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : TICKET_MASK register: 0x%08x\n","get_register_info",register_value);
        snprintf(tmp1,0x100,"TICKET_MASK register: 0x%08x",register_value);
        log_to_file(tmp1,time_stamp);
        break;
      case 4:
        break;
      case 5:
        iVar2 = __aeabi_uidiv(reg_value_buf->reg_buffer[reg_value_buf->p_rd].chip_address,
                              (g_rt.config)->interval);
        returned_nonce_counter_reg.u._RETURN_NONCE_CNT_MATCH = (uint16_t)(register_value >> 0x10);
        g_rt.asic_stats.every_asic_got_nonce_num[iVar2] =
             returned_nonce_counter_reg.u._RETURN_NONCE_CNT_MATCH;
        g_rt.asic_stats.valid_nonce_num =
             returned_nonce_counter_reg.u._RETURN_NONCE_CNT_MATCH + g_rt.asic_stats.valid_nonce_num;
        break;
      case 7:
        iVar2 = __aeabi_uidiv(reg_value_buf->reg_buffer[reg_value_buf->p_rd].chip_address,
                              (g_rt.config)->interval);
        g_rt.asic_stats.every_asic_reg_nonce_error_num[iVar2] = uVar1;
        break;
      case 10:
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : CORE_RESPONSE register: 0x%08x\n","get_register_info",register_value);
        snprintf(tmp1,0x100,"CORE_RESPONSE register: 0x%08x",register_value);
        log_to_file(tmp1,time_stamp);
        break;
      case 0xb:
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : MISC_CONTROL register: 0x%08x\n","get_register_info",register_value);
        snprintf(tmp1,0x100,"MISC_CONTROL register: 0x%08x",register_value);
        log_to_file(tmp1,time_stamp);
        break;
      case 0xc:
        iVar2 = __aeabi_uidiv(reg_value_buf->reg_buffer[reg_value_buf->p_rd].chip_address,
                              (g_rt.config)->interval);
        g_rt.asic_stats.every_asic_got_nonce_num[iVar2] = uVar1;
        g_rt.asic_stats.valid_nonce_num = g_rt.asic_stats.valid_nonce_num + register_value;
        break;
      case 0xd:
        iVar2 = __aeabi_uidiv(reg_value_buf->reg_buffer[reg_value_buf->p_rd].chip_address,
                              (g_rt.config)->interval);
        g_rt.asic_stats.every_asic_reg_got_nonce_num[iVar2] = uVar1;
        break;
      case 0xe:
        iVar2 = __aeabi_uidiv(reg_value_buf->reg_buffer[reg_value_buf->p_rd].chip_address,
                              (g_rt.config)->interval);
        g_rt.asic_stats.every_asic_reg_ntick_nonce_num[iVar2] = uVar1;
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

