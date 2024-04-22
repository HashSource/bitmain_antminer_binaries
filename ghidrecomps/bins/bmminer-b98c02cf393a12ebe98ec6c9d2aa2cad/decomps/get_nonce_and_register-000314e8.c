
void get_nonce_and_register(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  FILE *__stream;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  int iVar8;
  uint uVar9;
  uint local_830;
  undefined4 local_82c;
  char acStack_828 [2052];
  
  local_830 = 0;
  local_82c = 0;
  do {
    do {
      while (cgsleep_ms(1), doTestPatten != '\0') {
        cgsleep_ms(100);
      }
      uVar1 = get_nonce_number_in_fifo();
      uVar1 = uVar1 & 0x1ff;
    } while (uVar1 == 0);
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf(acStack_828,0x800,"%s: read_loop = %d\n",DAT_00031774,uVar1);
      _applog(7,acStack_828,0);
    }
    uVar9 = 0;
    do {
      get_return_nonce(&local_830);
      if ((int)local_830 < 0) {
        if ((gBegin_get_nonce != '\0') && ((int)(local_830 << 0x18) < 0)) {
          pthread_mutex_lock(DAT_00031778);
          iVar6 = nonce2_jobid_address;
          iVar8 = 0;
          uVar4 = (local_830 << 1) >> 0x11;
          *(uint *)(nonce_read_out + nonce_read_out._0_4_ * 0x3c + 0x10) = uVar4;
          iVar5 = uVar4 * 0x40;
          iVar2 = iVar6 + iVar5;
          puVar7 = (undefined *)(iVar2 + 0x1f);
          *(undefined4 *)(nonce_read_out + nonce_read_out._0_4_ * 0x3c + 0x20) = local_82c;
          *(uint *)(nonce_read_out + nonce_read_out._0_4_ * 0x3c + 0x24) = local_830 & 0xf;
          *(undefined4 *)(nonce_read_out + nonce_read_out._0_4_ * 0x3c + 0xc) =
               *(undefined4 *)(iVar6 + iVar5);
          *(undefined4 *)(nonce_read_out + nonce_read_out._0_4_ * 0x3c + 0x14) =
               *(undefined4 *)(iVar2 + 4);
          uVar3 = *(undefined4 *)(iVar2 + 0xc);
          iVar6 = nonce_read_out._0_4_ * 0x3c;
          *(undefined4 *)(nonce_read_out + iVar6 + 0x18) = *(undefined4 *)(iVar2 + 8);
          *(undefined4 *)(nonce_read_out + iVar6 + 0x1c) = uVar3;
          do {
            puVar7 = puVar7 + 1;
            iVar6 = nonce_read_out._0_4_ * 0x3c + iVar8;
            iVar8 = iVar8 + 1;
            nonce_read_out[iVar6 + 0x28] = *puVar7;
          } while (iVar8 != 0x20);
          if ((uint)nonce_read_out._0_4_ < 0x1fe) {
            nonce_read_out._0_4_ = nonce_read_out._0_4_ + 1;
          }
          else {
            nonce_read_out._0_4_ = 0;
          }
          if ((uint)nonce_read_out._8_4_ < 0x1ff) {
            nonce_read_out._8_4_ = nonce_read_out._8_4_ + 1;
          }
          else {
            nonce_read_out._8_4_ = 0x1ff;
          }
          pthread_mutex_unlock(DAT_00031778);
        }
      }
      else {
        if ((test_show_register != '\0') && (3 < log_level)) {
          __stream = fopen(log_file,(char *)&DAT_0005e760);
          if (__stream != (FILE *)0x0) {
            fprintf(__stream,"%s:%d:%s: FPGA recv : buf[0]=0x%08x buf[1]=0x%08x\n","driver-btm-c5.c"
                    ,0x2dd6,DAT_00031774,local_830,local_82c);
          }
          fclose(__stream);
        }
        if (((uint)reg_value_buf._8_4_ < 0x1ff) && ((uint)reg_value_buf._0_4_ < 0x1ff)) {
          pthread_mutex_lock((pthread_mutex_t *)reg_mutex);
          *(undefined4 *)(reg_value_buf + (reg_value_buf._0_4_ + 1) * 8 + 4) = local_82c;
          reg_value_buf[(reg_value_buf._0_4_ + 1) * 8 + 8] = (byte)((local_830 << 3) >> 0x1b);
          reg_value_buf[(reg_value_buf._0_4_ + 1) * 8 + 9] = (byte)local_830 & 0xf;
          if ((uint)reg_value_buf._0_4_ < 0x1fe) {
            reg_value_buf._0_4_ = reg_value_buf._0_4_ + 1;
          }
          else {
            reg_value_buf._0_4_ = 0;
          }
          if ((uint)reg_value_buf._8_4_ < 0x1ff) {
            reg_value_buf._8_4_ = reg_value_buf._8_4_ + 1;
          }
          else {
            reg_value_buf._8_4_ = 0x1ff;
          }
          pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
        }
        else {
          clear_register_value_buf();
        }
      }
      uVar9 = uVar9 + 1;
    } while (uVar1 != uVar9);
  } while( true );
}

