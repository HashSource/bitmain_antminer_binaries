
uint32_t get_register_value(uint32_t which_asic,uint32_t which_function,_Bool mode,char *asic_type)

{
  ushort uVar1;
  uint8_t which_chain;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *asic_type_local;
  _Bool mode_local;
  uint32_t which_function_local;
  uint32_t which_asic_local;
  char time_stamp [48];
  char tmp1 [2048];
  general_i2c_command_t i2c_command_reg;
  returned_nonce_counter_t returned_nonce_counter_reg;
  frequency_sweep_control_t frequency_sweep_control_reg;
  uint32_t addr;
  uint16_t asic_addr;
  uint32_t reg_value_num;
  uint16_t asic_name;
  uint32_t i;
  uint32_t bad_asic_number;
  uint32_t register_value;
  uint32_t get_register_value_loop;
  
  get_register_value_loop = 0;
  register_value = 0;
  asic_name = 0;
  gPause_read_asic_temp = true;
  while (gEnable_get_register != true) {
    usleep(10000);
  }
  clear_register_value_buf();
  which_chain = (uint8_t)gChain;
  switch(which_function) {
  case 0:
    gAsic_num = 0;
    asic_name = get_asic_name(asic_type);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: asic_name: 0x%04x\n","get_register_value",(uint)asic_name);
    snprintf(tmp1,0x800,"asic_name: 0x%04x",(uint)asic_name);
    log_to_file(tmp1,time_stamp);
    get_chain_asic_num((uint8_t)gChain);
    break;
  case 1:
    send_get_status_command(which_chain,'\x01',0,8);
    break;
  case 2:
    get_chain_hash_clock_counter(which_chain);
  case 3:
    send_get_status_command((uint8_t)gChain,'\x01',0,0x14);
    break;
  case 4:
    gHardware_sweep_done_asic_num = 0;
    break;
  case 5:
    send_get_status_command(which_chain,'\x01',0,0xff);
    break;
  case 6:
    get_asic_clock_delay_control(which_chain,0);
    break;
  case 7:
    send_get_status_command(which_chain,'\x01',0,0x4c);
    break;
  case 8:
    send_get_status_command(which_chain,'\0',which_asic * gAddress_interval,0xff);
    break;
  case 9:
    send_get_status_command(which_chain,'\0',which_asic * gAddress_interval,0xff);
    break;
  default:
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Don\'t support this register: 0x%02x\n","get_register_value",which_function);
    snprintf(tmp1,0x800,"Don\'t support this register: 0x%02x",which_function);
    log_to_file(tmp1,time_stamp);
    return 0xffffffff;
  case 0xb:
    send_get_status_command(which_chain,'\x01',0,0x18);
    break;
  case 0xd:
    send_get_status_command(which_chain,'\x01',0,0x8c);
    break;
  case 0xe:
    send_get_status_command(which_chain,'\x01',0,0x90);
    break;
  case 0xf:
    send_get_status_command(which_chain,'\x01',0,0x94);
    break;
  case 0x10:
    send_get_status_command(which_chain,'\x01',0,0x48);
    break;
  case 0x11:
    send_get_status_command(which_chain,'\x01',0,0xbd);
    break;
  case 0x32:
    get_asic_nonce_bin_overflow_control(which_chain,0);
  }
  bad_asic_number = 0;
  do {
    while( true ) {
      if (2 < get_register_value_loop) {
        gPause_read_asic_temp = false;
        return register_value;
      }
      usleep(30000);
      pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
      uVar5 = reg_value_buf->reg_value_num;
      pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
      if (uVar5 != 0) break;
      usleep(100000);
      get_register_value_loop = get_register_value_loop + 1;
    }
    get_register_value_loop = 0;
    for (i = 0; i < uVar5; i = i + 1) {
      pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
      register_value = reg_value_buf->reg_buffer[reg_value_buf->p_rd].reg_value;
      pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
      frequency_sweep_control_reg.v._0_1_ = (undefined1)register_value;
      uVar1 = (ushort)register_value;
      switch(which_function) {
      case 0:
        if (register_value >> 0x10 == (uint)asic_name) {
          gAsic_num = gAsic_num + 1;
          uVar6 = (uint)gPattern_test_counter;
          iVar4 = __aeabi_uidiv(uVar1 & 0xff,gAddress_interval);
          gHistory_Result[uVar6].ok_asic_list[iVar4] = true;
        }
        else {
          bad_asic_number = bad_asic_number + 1;
          if ((Local_Config_Information->Hash_Board).Asic_Num < bad_asic_number) {
            gAsic_num = 0xffffffff;
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: too much error asic address register, fail\n","get_register_value");
            builtin_strncpy(tmp1,"too much error asic address register, fa",0x28);
            tmp1[0x28] = 'i';
            tmp1[0x29] = 'l';
            tmp1[0x2a] = '\0';
            log_to_file(tmp1,time_stamp);
            return gAsic_num;
          }
        }
        break;
      case 1:
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: PLL 0 register: 0x%08x\n","get_register_value",register_value);
        snprintf(tmp1,0x800,"PLL 0 register: 0x%08x",register_value);
        log_to_file(tmp1,time_stamp);
        break;
      default:
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Don\'t support this register in check: 0x%02x\n","get_register_value",
               which_function);
        snprintf(tmp1,0x800,"Don\'t support this register in check: 0x%02x",which_function);
        log_to_file(tmp1,time_stamp);
        return 0xffffffff;
      case 3:
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: TICKET_MASK register: 0x%08x\n","get_register_value",register_value);
        snprintf(tmp1,0x800,"TICKET_MASK register: 0x%08x",register_value);
        log_to_file(tmp1,time_stamp);
        break;
      case 4:
        if (((register_value & 0x80) != 0) || ((register_value & 8) != 0)) {
          gHardware_sweep_done_asic_num = gHardware_sweep_done_asic_num + 1;
        }
        break;
      case 5:
        uVar6 = (uint)gPattern_test_counter;
        iVar4 = __aeabi_uidiv(reg_value_buf->reg_buffer[reg_value_buf->p_rd].chip_address,
                              gAddress_interval);
        returned_nonce_counter_reg.u._RETURN_NONCE_CNT_MATCH = (uint16_t)(register_value >> 0x10);
        gHistory_Result[uVar6].every_asic_got_nonce_num[iVar4] =
             (uint)returned_nonce_counter_reg.u._RETURN_NONCE_CNT_MATCH;
        gHistory_Result[gPattern_test_counter].valid_nonce_num =
             gHistory_Result[gPattern_test_counter].valid_nonce_num +
             (uint)returned_nonce_counter_reg.u._RETURN_NONCE_CNT_MATCH;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        uVar3 = __aeabi_uidiv(reg_value_buf->reg_buffer[reg_value_buf->p_rd].chip_address,
                              gAddress_interval);
        printf("%s: ASIC: %d, RETURNED_NONCE_COUNTER register: 0x%08x, valid_nonce_num: %d\n",
               "get_register_value",uVar3,register_value,
               gHistory_Result[gPattern_test_counter].valid_nonce_num);
        uVar3 = __aeabi_uidiv(reg_value_buf->reg_buffer[reg_value_buf->p_rd].chip_address,
                              gAddress_interval);
        snprintf(tmp1,0x800,"ASIC: %d, RETURNED_NONCE_COUNTER register: 0x%08x, valid_nonce_num: %d"
                 ,uVar3,register_value,gHistory_Result[gPattern_test_counter].valid_nonce_num);
        log_to_file(tmp1,time_stamp);
        break;
      case 7:
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: NONCE_ERROR_COUNTER register: 0x%08x\n","get_register_value",register_value);
        snprintf(tmp1,0x800,"NONCE_ERROR_COUNTER register: 0x%08x",register_value);
        log_to_file(tmp1,time_stamp);
        break;
      case 8:
        if (((register_value & 0x40000000) == 0) && (frequency_sweep_control_reg.v._0_1_ != '\0')) {
          uVar6 = (uint)gPattern_test_counter;
          bVar2 = get_temperature_data_position_in_array(which_asic);
          gHistory_Result[uVar6].sensor_local_temperature_from_asic[bVar2] =
               frequency_sweep_control_reg.v._0_1_ + -0x40;
        }
        break;
      case 9:
        if (((register_value & 0x40000000) == 0) && (frequency_sweep_control_reg.v._0_1_ != '\0')) {
          uVar6 = (uint)gPattern_test_counter;
          bVar2 = get_temperature_data_position_in_array(which_asic);
          gHistory_Result[uVar6].sensor_remote_temperature_from_asic[bVar2] =
               frequency_sweep_control_reg.v._0_1_ + -0x40;
          uVar6 = (uint)gPattern_test_counter;
          bVar2 = get_temperature_data_position_in_array(which_asic);
          gHistory_Result[uVar6].asic_sensor_OK[bVar2] = true;
        }
        break;
      case 10:
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: CORE_RESPONSE register: 0x%08x\n","get_register_value",register_value);
        snprintf(tmp1,0x800,"CORE_RESPONSE register: 0x%08x",register_value);
        log_to_file(tmp1,time_stamp);
        break;
      case 0xb:
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: MISC_CONTROL register: 0x%08x\n","get_register_value",register_value);
        snprintf(tmp1,0x800,"MISC_CONTROL register: 0x%08x",register_value);
        log_to_file(tmp1,time_stamp);
        break;
      case 0xd:
        uVar6 = (uint)gPattern_test_counter;
        iVar4 = __aeabi_uidiv(reg_value_buf->reg_buffer[reg_value_buf->p_rd].chip_address,
                              gAddress_interval);
        gHistory_Result[uVar6].every_asic_reg_got_nonce_num[iVar4] = uVar1;
        break;
      case 0xe:
        uVar6 = (uint)gPattern_test_counter;
        iVar4 = __aeabi_uidiv(reg_value_buf->reg_buffer[reg_value_buf->p_rd].chip_address,
                              gAddress_interval);
        gHistory_Result[uVar6].every_asic_reg_ntick_nonce_num[iVar4] = uVar1;
        break;
      case 0xf:
        uVar6 = (uint)gPattern_test_counter;
        iVar4 = __aeabi_uidiv(reg_value_buf->reg_buffer[reg_value_buf->p_rd].chip_address,
                              gAddress_interval);
        gHistory_Result[uVar6].every_asic_reg_tick_nonce_num[iVar4] = register_value;
        break;
      case 0x10:
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: ERR_FLAG register: 0x%08x\n","get_register_value",register_value);
        snprintf(tmp1,0x800,"ERR_FLAG register: 0x%08x",register_value);
        log_to_file(tmp1,time_stamp);
        break;
      case 0x11:
        iVar4 = __aeabi_uidiv(reg_value_buf->reg_buffer[reg_value_buf->p_rd].chip_address,
                              gAddress_interval);
        gADC_Data_Out.Data_out[iVar4][gADC_Data_Out.counter[iVar4]] = register_value;
        gADC_Data_Out.counter[iVar4] = gADC_Data_Out.counter[iVar4] + 1;
      }
      pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
      reg_value_buf->p_rd = reg_value_buf->p_rd + 1;
      reg_value_buf->reg_value_num = reg_value_buf->reg_value_num - 1;
      if (reg_value_buf->p_rd == 0x1ff) {
        reg_value_buf->p_rd = 0;
      }
      pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
    }
  } while( true );
}

