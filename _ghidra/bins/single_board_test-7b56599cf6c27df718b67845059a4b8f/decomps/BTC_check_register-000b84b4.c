
void BTC_check_register(return_nonce_128bit_t *reg_buf)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  return_nonce_128bit_t *reg_buf_local;
  char time_stamp [48];
  char tmp1 [256];
  uint32_t print_reg_number;
  uint32_t i;
  
  if (reg_value_buf->reg_value_num < 0xfff) {
    if ((undefined1  [16])((undefined1  [16])*reg_buf & (undefined1  [16])0x60000000) ==
        (undefined1  [16])0x0) {
      if ((*(byte *)reg_buf & 0xf) == gChain) {
        pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
        reg_value_buf->reg_buffer[reg_value_buf->p_wr].reg_value = (reg_buf->nonce).nonce;
        reg_value_buf->reg_buffer[reg_value_buf->p_wr].chip_address =
             (uint)*(byte *)((int)reg_buf + 2);
        reg_value_buf->reg_buffer[reg_value_buf->p_wr].reg_address =
             (uint)*(byte *)((int)reg_buf + 1);
        reg_value_buf->p_wr = reg_value_buf->p_wr + 1;
        reg_value_buf->reg_value_num = reg_value_buf->reg_value_num + 1;
        if (0xffe < reg_value_buf->p_wr) {
          reg_value_buf->p_wr = 0;
        }
        pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : receive register value from chain: %d, but not gChain: %d\n",
               "BTC_check_register",*(byte *)reg_buf & 0xf,gChain);
        snprintf(tmp1,0x100,"receive register value from chain: %d, but not gChain: %d",
                 *(byte *)reg_buf & 0xf,gChain);
        log_to_file(tmp1,time_stamp);
      }
    }
    else {
      gHashboard_received_crc_error_work = gHashboard_received_crc_error_work + 1;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : gHashboard_received_crc_error_work = %d\n","BTC_check_register",
             gHashboard_received_crc_error_work);
      snprintf(tmp1,0x100,"gHashboard_received_crc_error_work = %d",
               gHashboard_received_crc_error_work);
      log_to_file(tmp1,time_stamp);
    }
  }
  else if (!gFind_dummy_data) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : %s: reg_value_buf buffer is full!\n","BTC_check_register","BTC_check_register");
    snprintf(tmp1,0x100,"%s: reg_value_buf buffer is full!","BTC_check_register");
    log_to_file(tmp1,time_stamp);
    gFind_dummy_data = true;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Find dummy data\n","BTC_check_register");
    builtin_strncpy(tmp1,"Find dummy data",0x10);
    log_to_file(tmp1,time_stamp);
    for (i = 0; i < (Local_Config_Information->Hash_Board).Asic_Num; i = i + 1) {
      gHistory_Result[gPattern_test_counter].bad_asic_list[i] = true;
    }
    for (i = 0; i < 10; i = i + 1) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      uVar4 = *(undefined4 *)
               ("GENERAL_SUBTREE_it" + (int)&reg_value_buf->reg_buffer[i].chip_address);
      uVar1 = __aeabi_uidiv(*(undefined4 *)
                             ("GENERAL_SUBTREE_it" + (int)&reg_value_buf->reg_buffer[i].reg_address)
                            ,gAddress_interval);
      printf("%s : reg_value = 0x%08x, which_asic = %d, reg_address = 0x%08x\n","BTC_check_register"
             ,uVar4,uVar1,
             *(undefined4 *)("GENERAL_SUBTREE_it" + (int)&reg_value_buf->reg_buffer[i].crc));
      uVar4 = *(undefined4 *)
               ("GENERAL_SUBTREE_it" + (int)&reg_value_buf->reg_buffer[i].chip_address);
      uVar1 = __aeabi_uidiv(*(undefined4 *)
                             ("GENERAL_SUBTREE_it" + (int)&reg_value_buf->reg_buffer[i].reg_address)
                            ,gAddress_interval);
      snprintf(tmp1,0x100,"reg_value = 0x%08x, which_asic = %d, reg_address = 0x%08x",uVar4,uVar1,
               *(undefined4 *)("GENERAL_SUBTREE_it" + (int)&reg_value_buf->reg_buffer[i].crc));
      log_to_file(tmp1,time_stamp);
      uVar3 = (uint)gPattern_test_counter;
      iVar2 = __aeabi_uidiv(*(undefined4 *)
                             ("GENERAL_SUBTREE_it" + (int)&reg_value_buf->reg_buffer[i].reg_address)
                            ,gAddress_interval);
      gHistory_Result[uVar3].bad_asic_list[iVar2] = false;
    }
  }
  return;
}

