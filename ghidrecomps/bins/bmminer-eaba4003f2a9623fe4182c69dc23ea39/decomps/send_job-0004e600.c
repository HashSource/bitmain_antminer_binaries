
int send_job(uchar *buf,pool *pool)

{
  void *__s;
  void *__s_00;
  uint uVar1;
  int iVar2;
  uint uVar3;
  pool *pool_local;
  uchar *buf_local;
  char tmp42 [2048];
  uint buf2 [32];
  uchar buf1 [32];
  part_of_job *part_job;
  uchar *coinbase_padding;
  uchar *temp_buf;
  ushort job_length;
  ushort crc;
  uint j;
  uint len;
  int times;
  uchar *merkles_bin;
  uint coinbase_padding_len;
  uint i;
  
  merkles_bin = (uchar *)0x0;
  memset(buf2,0,0x80);
  if (doTestPatten == false) {
    if (*buf == 'R') {
      iVar2 = *(int *)(buf + 4);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"%s: len = 0x%x\n","send_job",iVar2);
        _applog(7,tmp42,false);
      }
      __s = malloc(iVar2 + 8);
      if (__s == (void *)0x0) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"%s: malloc buffer failed.\n","send_job");
          _applog(7,tmp42,false);
        }
        iVar2 = -2;
      }
      else {
        memset(__s,0,iVar2 + 8);
        memcpy(__s,buf,iVar2 + 8);
        if (dev->current_job_start_address == job_start_address_1) {
          dev->current_job_start_address = job_start_address_2;
        }
        else {
          if (dev->current_job_start_address != job_start_address_2) {
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,
                       "%s: dev->current_job_start_address = 0x%x, but job_start_address_1 = 0x%x, job_start_address_2 = 0x%x\n"
                       ,"send_job",dev->current_job_start_address,job_start_address_1,
                       job_start_address_2);
              _applog(7,tmp42,false);
            }
            return -3;
          }
          dev->current_job_start_address = job_start_address_1;
        }
        if ((*(ushort *)((int)__s + 0x3c) & 0x3f) < 0x38) {
          uVar3 = (*(ushort *)((int)__s + 0x3c) >> 6) + 1;
        }
        else {
          uVar3 = (*(ushort *)((int)__s + 0x3c) >> 6) + 2;
        }
        coinbase_padding_len = uVar3 * 0x40;
        __s_00 = malloc(coinbase_padding_len);
        if (__s_00 == (void *)0x0) {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"%s: malloc coinbase_padding failed.\n","send_job");
            _applog(7,tmp42,false);
          }
          iVar2 = -4;
        }
        else {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"%s: coinbase_padding = 0x%x","send_job",__s_00);
            _applog(7,tmp42,false);
          }
          if (*(short *)((int)__s + 0x42) != 0) {
            merkles_bin = (uchar *)malloc((uint)*(ushort *)((int)__s + 0x42) << 5);
            if (merkles_bin == (uchar *)0x0) {
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                snprintf(tmp42,0x800,"%s: malloc merkles_bin failed.\n","send_job");
                _applog(7,tmp42,false);
              }
              return -5;
            }
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"%s: merkles_bin = 0x%x","send_job",merkles_bin);
              _applog(7,tmp42,false);
            }
          }
          memset(__s_00,0,coinbase_padding_len);
          memcpy(__s_00,buf + 0x50,(uint)*(ushort *)((int)__s + 0x3c));
          *(undefined *)((int)__s_00 + (uint)*(ushort *)((int)__s + 0x3c)) = 0x80;
          *(uint *)((int)__s_00 + (coinbase_padding_len - 4)) =
               (uint)*(ushort *)((int)__s + 0x3c) << 0x1b |
               ((*(ushort *)((int)__s + 0x3c) & 0x1fe000) << 3) >> 8 |
               (*(ushort *)((int)__s + 0x3c) & 0x1fe0) << 0xb;
          *(undefined4 *)((int)__s_00 + (coinbase_padding_len - 8)) = 0;
          l_coinbase_padding = c_coinbase_padding;
          c_coinbase_padding = coinbase_padding_len;
          for (i = 0; i < coinbase_padding_len; i = i + 1) {
            *(undefined *)((int)dev->current_job_start_address + i) =
                 *(undefined *)((int)__s_00 + i);
          }
          for (i = 0; i < coinbase_padding_len; i = i + 1) {
            if (((*(char *)((int)dev->current_job_start_address + i) != *(char *)((int)__s_00 + i))
                && (opt_debug != false)) &&
               ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
              snprintf(tmp42,0x800,
                       "%s: coinbase_padding_in_ddr[%d] = 0x%x, but *(coinbase_padding + %d) = 0x%x"
                       ,"send_job",i,(uint)*(byte *)((int)dev->current_job_start_address + i),i,
                       (uint)*(byte *)((int)__s_00 + i));
              _applog(7,tmp42,false);
            }
          }
          l_merkles_num = c_merkles_num;
          c_merkles_num = (uint)*(ushort *)((int)__s + 0x42);
          if (*(short *)((int)__s + 0x42) != 0) {
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"%s: copy merkle bin into memory ...\n","send_job");
              _applog(7,tmp42,false);
            }
            memset(merkles_bin,0,(uint)*(ushort *)((int)__s + 0x42) << 5);
            memcpy(merkles_bin,buf + *(ushort *)((int)__s + 0x3c) + 0x50,
                   (uint)*(ushort *)((int)__s + 0x42) << 5);
            for (i = 0; i < (uint)*(ushort *)((int)__s + 0x42) * 0x20; i = i + 1) {
              *(uchar *)((int)dev->current_job_start_address + coinbase_padding_len + i) =
                   merkles_bin[i];
            }
            for (i = 0; i < (uint)*(ushort *)((int)__s + 0x42) * 0x20; i = i + 1) {
              if (((*(uchar *)((int)dev->current_job_start_address + coinbase_padding_len + i) !=
                    merkles_bin[i]) && (opt_debug != false)) &&
                 ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
                snprintf(tmp42,0x800,"%s: merkles_in_ddr[%d] = 0x%x, but *(merkles_bin + %d) =0x%x",
                         "send_job",i,
                         (uint)*(byte *)((int)dev->current_job_start_address +
                                        coinbase_padding_len + i),i,(uint)merkles_bin[i]);
                _applog(7,tmp42,false);
              }
            }
          }
          uVar1 = get_dhash_acc_control();
          set_dhash_acc_control(uVar1 & 0xffffffbf);
          while (uVar1 = get_dhash_acc_control(), (uVar1 & 0x40) != 0) {
            cgsleep_ms(1);
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"%s: run bit is 1 after set it to 0\n","send_job");
              _applog(7,tmp42,false);
            }
          }
          cgsleep_ms(1);
          if (dev->current_job_start_address == job_start_address_1) {
            set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
          }
          else if (dev->current_job_start_address == job_start_address_2) {
            set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x210000);
          }
          if ((*(byte *)((int)__s + 9) & 2) != 0) {
            set_ticket_mask((uint)*(byte *)((int)__s + 10));
            dev->diff = *(uchar *)((int)__s + 10);
          }
          set_job_id(*(uint *)((int)__s + 0xc));
          set_block_header_version(*(uint *)((int)__s + 0x10));
          memset(buf2,0,0x80);
          for (i = 0; i < 8; i = i + 1) {
            buf2[i] = (uint)*(byte *)((int)__s + i * 4 + 0x14) |
                      (uint)*(byte *)((int)__s + i * 4 + 0x17) << 0x18 |
                      (uint)*(byte *)((int)__s + i * 4 + 0x16) << 0x10 |
                      (uint)*(byte *)((int)__s + i * 4 + 0x15) << 8;
          }
          set_pre_header_hash(buf2);
          set_time_stamp(*(uint *)((int)__s + 0x34));
          set_target_bits(*(uint *)((int)__s + 0x38));
          set_coinbase_length_and_nonce2_length
                    (uVar3 & 0xff |
                     (uint)*(ushort *)((int)__s + 0x3e) << 0x10 |
                     (uint)(byte)*(undefined2 *)((int)__s + 0x40) << 8);
          buf2[0] = *(uint *)((int)__s + 0x48);
          buf2[1] = *(uint *)((int)__s + 0x4c);
          set_work_nonce2(buf2);
          set_merkle_bin_number((uint)*(ushort *)((int)__s + 0x42));
          set_job_length((uint)(ushort)(*(short *)((int)__s + 0x42) * 0x20 +
                                       (short)coinbase_padding_len));
          cgsleep_ms(1);
          pool->check_asicboost_over = true;
          pool->support_asicboost = false;
          if (gBegin_get_nonce != true) {
            uVar3 = get_nonce_fifo_interrupt();
            set_nonce_fifo_interrupt(uVar3 | 0x10000);
            gBegin_get_nonce = true;
          }
          if ((*(byte *)((int)__s + 9) & 1) == 0) {
            if (opt_multi_version == 0) {
              uVar3 = get_dhash_acc_control();
              set_dhash_acc_control((opt_multi_version & 0xfU) << 8 | uVar3 & 0xfffff0ff | 0x60);
            }
            else {
              uVar3 = get_dhash_acc_control();
              set_dhash_acc_control((opt_multi_version & 0xfU) << 8 | uVar3 & 0xfffff0ff | 0x8060);
            }
          }
          else if (opt_multi_version == 0) {
            uVar3 = get_dhash_acc_control();
            set_dhash_acc_control(uVar3 | 0x80);
            uVar3 = get_dhash_acc_control();
            set_dhash_acc_control((opt_multi_version & 0xfU) << 8 | uVar3 & 0xfffff0ff | 0x60);
          }
          else {
            uVar3 = get_dhash_acc_control();
            set_dhash_acc_control(uVar3 | 0x80);
            uVar3 = get_dhash_acc_control();
            set_dhash_acc_control((opt_multi_version & 0xfU) << 8 | uVar3 & 0xfffff0ff | 0x8060);
          }
          free(__s);
          free(__s_00);
          if (*(short *)((int)__s + 0x42) != 0) {
            free(merkles_bin);
          }
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"--- %s end\n","send_job");
            _applog(7,tmp42,false);
          }
          cgtime(&tv_send_job);
          cgsleep_ms(1);
          iVar2 = 0;
        }
      }
    }
    else {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"%s: SEND_JOB_TYPE is wrong : 0x%x\n","send_job",(uint)*buf);
        _applog(7,tmp42,false);
      }
      iVar2 = -1;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}

