
/* WARNING: Unknown calling convention */

void * get_nonce_and_register(void)

{
  uint uVar1;
  FILE *pFVar2;
  uint uVar3;
  uint32_t *puVar4;
  uint32_t uVar5;
  uint buf [2];
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile_3;
  FILE *pFile;
  uint64_t n2l;
  uint64_t n2h;
  uint read_loop;
  uint nonce_number;
  uint *data_addr;
  uint work_id;
  uint m;
  uint j;
  
  buf[0] = 0;
  buf[1] = 0;
  uVar1 = get_nonce_fifo_interrupt();
  set_nonce_fifo_interrupt(uVar1 | 0x10000);
  do {
    do {
      while (cgsleep_ms(1), doTestPatten != false) {
        cgsleep_ms(100);
      }
      uVar1 = get_nonce_number_in_fifo();
      uVar1 = uVar1 & 0x1ff;
    } while (uVar1 == 0);
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: read_loop = %d\n","driver-btm-soc.c",0x125d,
                "get_nonce_and_register",uVar1);
      }
      fclose(pFVar2);
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
          uVar5 = puVar4[3];
          *(uint32_t *)&nonce_read_out.nonce_buffer[nonce_read_out.p_wr].nonce2 = puVar4[2];
          *(uint32_t *)((int)&nonce_read_out.nonce_buffer[uVar3].nonce2 + 4) = uVar5;
          for (m = 0; m < 0x20; m = m + 1) {
            nonce_read_out.nonce_buffer[nonce_read_out.p_wr].midstate[m] =
                 *(uint8_t *)((int)puVar4 + m + 0x20);
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
          nonce_calc(nonce_read_out.nonce_buffer[nonce_read_out.p_wr].chain_num,
                     nonce_read_out.nonce_buffer[nonce_read_out.p_wr].nonce3);
          pthread_mutex_unlock((pthread_mutex_t *)&nonce_mutex);
        }
      }
      else if (reg_value_buf.reg_value_num < 0x1ff) {
        if ((buf[0] & 0x40) == 0) {
          pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
          reg_value_buf.reg_buffer[reg_value_buf.p_wr].reg_value = buf[1];
          reg_value_buf.reg_buffer[reg_value_buf.p_wr].crc = (byte)(buf[0] >> 0x18) & 0x1f;
          reg_value_buf.reg_buffer[reg_value_buf.p_wr].chip_address = (uchar)(buf[0] >> 0x10);
          reg_value_buf.reg_buffer[reg_value_buf.p_wr].reg_address = (uchar)(buf[0] >> 8);
          reg_value_buf.reg_buffer[reg_value_buf.p_wr].chain_number = (byte)buf[0] & 0xf;
          if (((buf[0] >> 0x1d & 3) != 0) && (3 < log_level)) {
            print_crt_time_to_file(log_file,3);
            pFVar2 = fopen(log_file,"a+");
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"%s:%d:%s: !!! REG_TYPE = 1\n","driver-btm-soc.c",0x12b5,
                      "get_nonce_and_register");
            }
            fclose(pFVar2);
          }
          if ((is_reading_core_reg != false) ||
             (reg_value_buf.reg_buffer[reg_value_buf.p_wr].reg_address != '@')) {
            reg_value_buf.p_wr = reg_value_buf.p_wr + 1;
            reg_value_buf.reg_value_num = reg_value_buf.reg_value_num + 1;
            if (0x1fe < reg_value_buf.p_wr) {
              reg_value_buf.p_wr = 0;
            }
          }
          pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
        }
        else if (4 < log_level) {
          print_crt_time_to_file(log_file,4);
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: !!! reg crc error\n","driver-btm-soc.c",0x12aa,
                    "get_nonce_and_register");
          }
          fclose(pFVar2);
        }
      }
      else if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: reg_value_buf buffer is full!\n","driver-btm-soc.c",0x12c5,
                  "get_nonce_and_register");
        }
        fclose(pFVar2);
      }
    }
  } while( true );
}

