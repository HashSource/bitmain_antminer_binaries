
/* WARNING: Unknown calling convention */

void * get_nonce_and_register(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  char tmp42 [2048];
  uint buf [2];
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
  uint64_t n2l;
  uint64_t n2h;
  uint read_loop;
  uint nonce_number;
  uint i;
  uint *data_addr;
  uint work_id;
  uint m;
  uint j;
  
  buf[0] = 0;
  buf[1] = 0;
  do {
    do {
      while (cgsleep_ms(1), doTestPatten != false) {
        cgsleep_ms(100);
      }
      uVar1 = get_nonce_number_in_fifo();
      uVar1 = uVar1 & 0x1ff;
    } while (uVar1 == 0);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: read_loop = %d\n","get_nonce_and_register",uVar1);
      _applog(7,tmp42,false);
    }
    for (j = 0; j < uVar1; j = j + 1) {
      get_return_nonce(buf);
      if ((int)buf[0] < 0) {
        if ((gBegin_get_nonce != false) && ((buf[0] & 0x80) != 0)) {
          pthread_mutex_lock((pthread_mutex_t *)&nonce_mutex);
          uVar3 = buf[0] >> 0x10 & 0x7fff;
          puVar4 = nonce2_jobid_address + uVar3 * 0x10;
          nonce_read_out.nonce_buffer[nonce_read_out.p_wr].work_id = uVar3;
          nonce_read_out.nonce_buffer[nonce_read_out.p_wr].nonce3 = buf[1];
          nonce_read_out.nonce_buffer[nonce_read_out.p_wr].chain_num = buf[0] & 0xf;
          nonce_read_out.nonce_buffer[nonce_read_out.p_wr].job_id = *puVar4;
          nonce_read_out.nonce_buffer[nonce_read_out.p_wr].header_version = puVar4[1];
          uVar3 = nonce_read_out.p_wr;
          uVar2 = puVar4[3];
          *(uint *)&nonce_read_out.nonce_buffer[nonce_read_out.p_wr].nonce2 = puVar4[2];
          *(uint *)((int)&nonce_read_out.nonce_buffer[uVar3].nonce2 + 4) = uVar2;
          for (m = 0; m < 0x20; m = m + 1) {
            nonce_read_out.nonce_buffer[nonce_read_out.p_wr].midstate[m] =
                 *(uchar *)((int)puVar4 + m + 0x20);
          }
          if (nonce_read_out.p_wr < 0x1fe) {
            nonce_read_out.p_wr = nonce_read_out.p_wr + 1;
          }
          else {
            nonce_read_out.p_wr = 0;
          }
          if (nonce_read_out.nonce_num < 0x1ff) {
            nonce_read_out.nonce_num = nonce_read_out.nonce_num + 1;
          }
          else {
            nonce_read_out.nonce_num = 0x1ff;
          }
          pthread_mutex_unlock((pthread_mutex_t *)&nonce_mutex);
        }
      }
      else if ((reg_value_buf.reg_value_num < 0x1ff) && (reg_value_buf.p_wr < 0x1ff)) {
        pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
        reg_value_buf.reg_buffer[reg_value_buf.p_wr].reg_value = buf[1];
        reg_value_buf.reg_buffer[reg_value_buf.p_wr].crc = (byte)(buf[0] >> 0x18) & 0x1f;
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

