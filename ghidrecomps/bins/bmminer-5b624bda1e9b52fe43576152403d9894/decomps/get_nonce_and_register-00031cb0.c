
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* WARNING: Unknown calling convention */

void * get_nonce_and_register(void)

{
  byte bVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  nonce_buf *pnVar6;
  uint uVar7;
  nonce_buf *pnVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  char tmp42 [2048];
  
  do {
    do {
      while (cgsleep_ms(1), doTestPatten != false) {
        cgsleep_ms(100);
      }
      uVar9 = axi_fpga_addr[6] & 0x1ff;
    } while (uVar9 == 0);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: read_loop = %d\n","get_nonce_and_register",uVar9);
      _applog(7,tmp42,false);
    }
    uVar11 = 0;
    do {
      uVar10 = axi_fpga_addr[4];
      uVar7 = axi_fpga_addr[5];
      if ((int)uVar10 < 0) {
        if ((gBegin_get_nonce != false) && ((uVar10 & 0x80) != 0)) {
          pthread_mutex_lock((pthread_mutex_t *)&nonce_mutex);
          puVar2 = nonce2_jobid_address;
          uVar3 = (uVar10 << 1) >> 0x11;
          nonce_read_out.nonce_buffer[nonce_read_out.p_wr].work_id = uVar3;
          nonce_read_out.nonce_buffer[nonce_read_out.p_wr].nonce3 = uVar7;
          nonce_read_out.nonce_buffer[nonce_read_out.p_wr].chain_num = uVar10 & 0xf;
          nonce_read_out.nonce_buffer[nonce_read_out.p_wr].job_id = puVar2[uVar3 * 0x10];
          nonce_read_out.nonce_buffer[nonce_read_out.p_wr].header_version = puVar2[uVar3 * 0x10 + 1]
          ;
          uVar7 = nonce_read_out.p_wr;
          uVar10 = puVar2[uVar3 * 0x10 + 3];
          *(uint *)&nonce_read_out.nonce_buffer[nonce_read_out.p_wr].nonce2 =
               puVar2[uVar3 * 0x10 + 2];
          *(uint *)((int)&nonce_read_out.nonce_buffer[uVar7].nonce2 + 4) = uVar10;
          iVar4 = 0;
          do {
            bVar1 = *(byte *)((int)puVar2 + iVar4 + uVar3 * 0x40 + 0x20);
            uVar7 = (uint)bVar1;
            iVar5 = iVar4 + 1;
            nonce_read_out.nonce_buffer[nonce_read_out.p_wr].midstate[iVar4] = bVar1;
            uVar10 = nonce_read_out.nonce_num;
            iVar4 = iVar5;
          } while (iVar5 != 0x20);
          if (nonce_read_out.p_wr < 0x1ff) {
            nonce_read_out.p_wr = nonce_read_out.p_wr + 1;
          }
          else {
            nonce_read_out.p_wr = 0;
          }
          if (nonce_read_out.nonce_num < 0x1ff) {
            pnVar6 = &nonce_read_out;
            pnVar8 = (nonce_buf *)nonce_read_out.nonce_num;
          }
          else {
            uVar7 = 0x1ff;
            pnVar6 = (nonce_buf *)0x20;
            pnVar8 = &nonce_read_out;
          }
          if (nonce_read_out.nonce_num < 0x1ff) {
            pnVar8 = (nonce_buf *)((int)&pnVar8->p_wr + 1);
          }
          else {
            pnVar8->nonce_num = uVar7;
          }
          if (uVar10 < 0x1ff) {
            pnVar6->nonce_num = (uint)pnVar8;
          }
          pthread_mutex_unlock((pthread_mutex_t *)&nonce_mutex);
        }
      }
      else if ((reg_value_buf.reg_value_num < 0x1ff) && (reg_value_buf.p_wr < 0x1ff)) {
        pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
        reg_value_buf.reg_buffer[reg_value_buf.p_wr].reg_value = uVar7;
        reg_value_buf.reg_buffer[reg_value_buf.p_wr].crc = (byte)((uVar10 << 3) >> 0x1b);
        reg_value_buf.reg_buffer[reg_value_buf.p_wr].chain_number = (byte)uVar10 & 0xf;
        if (reg_value_buf.p_wr < 0x1ff) {
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
      uVar11 = uVar11 + 1;
    } while (uVar11 != uVar9);
  } while( true );
}

