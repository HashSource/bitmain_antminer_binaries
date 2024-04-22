
void * scanfreq_receive_nonce_register(void *arg)

{
  uint uVar1;
  int iVar2;
  uint chain;
  uint which_pattern_00;
  uint uVar3;
  SCAN_FREQ_WORK *pSVar4;
  void *arg_local;
  uint buf [2];
  SCAN_FREQ_WORK *work_1;
  int chainIndex;
  uchar which_pattern;
  uchar nonce_index;
  uchar whose_nonce;
  uint which_nonce;
  uint m_nonce;
  uint which_asic;
  char *buf_hex;
  uint reg_loop_back;
  uint reg_reg_value_num;
  uint reg_p_rd;
  uint reg_p_wr;
  uint nonce_loop_back;
  uint nonce_nonce_num;
  uint nonce_p_rd;
  uint nonce_p_wr;
  char ret;
  uint read_loop;
  uint nonce_number;
  uint n;
  uint m;
  uint i;
  uint *data_addr;
  uint work_id;
  uchar which_core_nonce;
  uchar which_asic_nonce;
  SCAN_FREQ_WORK *work_3;
  SCAN_FREQ_WORK *work_2;
  uint j;
  
  buf[0] = 0;
  buf[1] = 0;
  which_core_nonce = '\0';
  do {
    do {
      usleep(1000);
      uVar1 = get_nonce_number_in_fifo();
    } while ((uVar1 & 0x1ff) == 0);
    for (j = 0; j < (uVar1 & 0x1ff); j = j + 1) {
      get_return_nonce(buf);
      if ((int)buf[0] < 0) {
        if ((((gBegin_get_nonce != false) && ((buf[0] & 0x80) != 0)) && ((buf[0] & 0x40) == 0)) &&
           ((((buf[0] & 0x20) == 0 && (chain = buf[0] & 0xf, chain < 0x10)) &&
            ((dev->chain_exist[chain] != 0 && (scanfreq_info.scan_finished[chain] == false)))))) {
          scanfreq_info.ret_nonce_num[chain] = scanfreq_info.ret_nonce_num[chain] + 1;
          which_pattern_00 = (buf[0] >> 0x10 & 0x7fff) >> 7;
          uVar3 = buf[0] >> 0x10 & 0x7f;
          if (dev->addrInterval == '\0') {
            which_asic_nonce = (uchar)(buf[1] >> 0x1a);
            if ((int)(uint)which_asic_nonce < scanfreq_info.AsicNum) goto LAB_000492c4;
          }
          else {
            which_asic_nonce = __aeabi_uidiv(buf[1] >> 0x18,dev->addrInterval);
            which_core_nonce = (uchar)buf[1];
            if ((int)(uint)which_asic_nonce < scanfreq_info.AsicNum) {
LAB_000492c4:
              if (uVar3 < 0x81) {
                if (buf[1] == scanfreq_info.send_work[uVar3].nonce) {
                  iVar2 = __aeabi_idiv(scanfreq_info.AsicWorkCount,scanfreq_info.CoreNum);
                  if ((int)which_pattern_00 < iVar2) {
                    pSVar4 = scanfreq_info.works[which_asic_nonce];
                    iVar2 = __aeabi_idiv(scanfreq_info.AsicWorkCount,scanfreq_info.CoreNum);
                    if (pSVar4[iVar2 * (uint)which_core_nonce + which_pattern_00].
                        is_nonce_return_back[chain] == 0) {
                      Nonce_Match(chain,buf[1],which_pattern_00);
                    }
                    else {
                      pSVar4 = scanfreq_info.works[which_asic_nonce];
                      iVar2 = __aeabi_idiv(scanfreq_info.AsicWorkCount,scanfreq_info.CoreNum);
                      iVar2 = iVar2 * (uint)which_core_nonce + which_pattern_00;
                      pSVar4[iVar2].is_nonce_return_back[chain] =
                           pSVar4[iVar2].is_nonce_return_back[chain] + 1;
                      scanfreq_info.repeated_nonce_num[chain] =
                           scanfreq_info.repeated_nonce_num[chain] + 1;
                    }
                  }
                  else {
                    scanfreq_info.other_nonce_num[chain] = scanfreq_info.other_nonce_num[chain] + 1;
                  }
                }
                else {
                  if (uVar3 < 2) {
                    if (uVar3 == 1) {
                      work_2 = DAT_00049760;
                      work_3 = DAT_00049764;
                    }
                    else if (uVar3 == 0) {
                      work_2 = DAT_00049764;
                      work_3 = DAT_00049768;
                    }
                  }
                  else {
                    work_2 = (SCAN_FREQ_WORK *)(scanfreq_info.scan_success + uVar3 * 0x74);
                    work_3 = (SCAN_FREQ_WORK *)(scanfreq_info.pass_freq_index + uVar3 * 0x1d + 3);
                  }
                  iVar2 = check_hw(scanfreq_info.send_work + uVar3,buf[1],false);
                  if ((char)iVar2 == '\0') {
                    scanfreq_info.other_nonce_num[chain] = scanfreq_info.other_nonce_num[chain] + 1;
                  }
                  else {
                    iVar2 = check_hw(work_2,buf[1],false);
                    if ((char)iVar2 == '\0') {
                      scanfreq_info.other_nonce_num[chain] =
                           scanfreq_info.other_nonce_num[chain] + 1;
                    }
                    else {
                      iVar2 = check_hw(work_3,buf[1],false);
                      if ((char)iVar2 == '\0') {
                        scanfreq_info.other_nonce_num[chain] =
                             scanfreq_info.other_nonce_num[chain] + 1;
                      }
                      else {
                        scanfreq_info.HW_nonce_num[chain] = scanfreq_info.HW_nonce_num[chain] + 1;
                      }
                    }
                  }
                }
              }
              else {
                printf("Error: work_id=%d\n",uVar3);
              }
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

