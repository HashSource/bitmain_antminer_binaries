
void * freq_tuning_recv_nonce_and_register(void *arg)

{
  uint uVar1;
  uint32_t nonce_00;
  uint uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  int iVar5;
  bool bVar6;
  void *arg_local;
  nonce_format_t nonce;
  uint32_t buf [2];
  uint32_t target_nonce;
  freq_tuning_work *work;
  int core;
  int asic;
  int pattern;
  uint32_t work_id;
  uint32_t nonce_num;
  freq_tuning_info *freq_info;
  int chain;
  uint32_t loop;
  
  do {
    do {
      usleep(1000);
      uVar2 = get_nonce_number_in_fifo();
    } while ((uVar2 & 0x1ff) == 0);
    for (loop = 0; loop < (uVar2 & 0x1ff); loop = loop + 1) {
      get_return_nonce(buf);
      nonce_00 = buf[1];
      if ((int)buf[0] < 0) {
        if (gBegin_get_nonce != false) {
          if ((((buf[0] & 0x80) == 0) || ((buf[0] & 0x40) != 0)) || ((buf[0] & 0x20) != 0)) {
            if ((buf[0] & 0x40) != 0) {
              crc_err_nonce_num[chain] = crc_err_nonce_num[chain] + 1;
            }
            if ((buf[0] & 0x20) != 0) {
              err_nonce_num[chain] = err_nonce_num[chain] + 1;
            }
            if ((buf[0] & 0x80) != 0) {
              invalid_nonce_num[chain] = invalid_nonce_num[chain] + 1;
            }
            extra_nonce_num[chain] = extra_nonce_num[chain] + 1;
          }
          else {
            bVar6 = 0xfffffffe < (uint)nonce_recv_num_all;
            nonce_recv_num_all._0_4_ = (uint)nonce_recv_num_all + 1;
            nonce_recv_num_all._4_4_ = nonce_recv_num_all._4_4_ + (uint)bVar6;
            chain = buf[0] & 0xf;
            if ((((uint)chain < 0x10) && (dev->chain_exist[chain] != 0)) &&
               (*(char *)((int)arg + chain + 0x140a8U) == '\0')) {
              uVar1 = buf[0] >> 0x10;
              uVar3 = get_asic_id((nonce_format_t)buf[1]);
              uVar4 = get_core_id((nonce_format_t)nonce_00);
              if ((int)uVar3 < 0x30) {
                if ((uVar1 & 0x7fff) >> 7 == 0) {
                  if (g_works[uVar3][uVar4].nonce == nonce_00) {
                    if ((g_pattern_status[chain][uVar3][uVar4] & 1) == 0) {
                      g_pattern_status[chain][uVar3][uVar4] =
                           g_pattern_status[chain][uVar3][uVar4] | 1;
                      asic_nonce_num[chain][uVar3] = asic_nonce_num[chain][uVar3] + 1;
                      valid_nonce_num[chain] = valid_nonce_num[chain] + 1;
                      asic_core_nonce_num[chain][uVar3][uVar4] =
                           asic_core_nonce_num[chain][uVar3][uVar4] + 1;
                    }
                    else {
                      repeated_nonce_num[chain] = repeated_nonce_num[chain] + 1;
                    }
                  }
                  else {
                    iVar5 = freq_tuning_check_hw(g_work_for_hw_check[chain] + (uVar1 & 0x7f),buf[1])
                    ;
                    if (iVar5 != 0) {
                      chain_hw_num[chain] = chain_hw_num[chain] + 1;
                    }
                    extra_nonce_num[chain] = extra_nonce_num[chain] + 1;
                  }
                }
                else {
                  extra_nonce_num[chain] = extra_nonce_num[chain] + 1;
                }
              }
              else {
                asic_invalid_num = asic_invalid_num + 1;
              }
            }
            else {
              chain_invalid_num = chain_invalid_num + 1;
            }
          }
        }
      }
      else if ((reg_value_buf.reg_value_num < 0x1ff) && (reg_value_buf.p_wr < 0x1ff)) {
        pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
        reg_value_buf.reg_buffer[reg_value_buf.p_wr].reg_value = buf[1];
        reg_value_buf.reg_buffer[reg_value_buf.p_wr].crc = (byte)(buf[0] >> 0x18) & 0x1f;
        reg_value_buf.reg_buffer[reg_value_buf.p_wr].chip_address = (uchar)(buf[0] >> 0x10);
        reg_value_buf.reg_buffer[reg_value_buf.p_wr].reg_address = (uchar)(buf[0] >> 8);
        reg_value_buf.reg_buffer[reg_value_buf.p_wr].chain_number = (byte)buf[0] & 0xf;
        if (reg_value_buf.p_wr < 0x1fe) {
          reg_value_buf.p_wr = reg_value_buf.p_wr + 1;
        }
        else {
          reg_value_buf.p_wr = 0;
        }
        if (reg_value_buf.reg_value_num < 0x1ff) {
          reg_value_buf.reg_value_num = reg_value_buf.reg_value_num + 1;
        }
        else {
          reg_value_buf.reg_value_num = 0x1ff;
        }
        pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
      }
      else {
        clear_register_value_buf();
      }
    }
  } while( true );
}

