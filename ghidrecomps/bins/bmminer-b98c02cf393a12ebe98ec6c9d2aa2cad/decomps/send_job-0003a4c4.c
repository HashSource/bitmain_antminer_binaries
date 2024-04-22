
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 send_job(byte *param_1)

{
  undefined uVar1;
  ushort uVar2;
  undefined4 uVar3;
  void *__dest;
  void *__ptr;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  size_t sVar8;
  int iVar9;
  size_t sVar10;
  uint uVar11;
  void *pvVar12;
  void *pvVar13;
  void **ppvVar14;
  byte *pbVar15;
  bool bVar16;
  uint local_8c4;
  void *local_8ac;
  void *local_8a8 [32];
  char acStack_828 [2052];
  
  memset(local_8a8,0,0x80);
  uVar3 = 0;
  if (doTestPatten == '\0') {
    if (*param_1 == 0x52) {
      iVar9 = *(int *)(param_1 + 4);
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_828,0x800,"%s: len = 0x%x\n",DAT_0003a7b8,iVar9);
        _applog(7,acStack_828,0);
      }
      sVar10 = iVar9 + 8;
      __dest = calloc(sVar10,1);
      if (__dest == (void *)0x0) {
        if ((opt_debug == '\0') ||
           (((use_syslog == '\0' && (opt_log_output == '\0')) && (opt_log_level < 7)))) {
          uVar3 = 0xfffffffe;
        }
        else {
          snprintf(acStack_828,0x800,"%s: malloc buffer failed.\n",DAT_0003a7b8);
          _applog(7,acStack_828,0);
          uVar3 = 0xfffffffe;
        }
      }
      else {
        memcpy(__dest,param_1,sVar10);
        iVar9 = *dev;
        if (iVar9 == job_start_address_1) {
          *dev = job_start_address_2;
        }
        else {
          if (iVar9 != job_start_address_2) {
            if ((opt_debug != '\0') &&
               (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
              snprintf(acStack_828,0x800,
                       "%s: dev->current_job_start_address = 0x%x, but job_start_address_1 = 0x%x, job_start_address_2 = 0x%x\n"
                       ,DAT_0003ad78,iVar9,job_start_address_1,job_start_address_2);
              _applog(7,acStack_828,0);
            }
            free(__dest);
            return 0xfffffffd;
          }
          *dev = job_start_address_1;
        }
        if ((*(char *)((int)__dest + 0x50) == '\0') && (*(int *)((int)__dest + 0x54) != 4)) {
          iVar9 = 1;
          opt_multi_version = 1;
        }
        else {
          iVar9 = 4;
          opt_multi_version = 4;
        }
        bVar16 = last_version_num_14890 == iVar9;
        if (bVar16) {
          iVar9 = last_version_num_14890;
        }
        last_version_num_14890 = iVar9;
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
          snprintf(acStack_828,0x800,"Verion num %d");
          _applog(5,acStack_828,0);
        }
        uVar2 = *(ushort *)((int)__dest + 0x3c);
        uVar5 = (uint)uVar2;
        if ((uVar5 & 0x3f) < 0x38) {
          uVar6 = (uVar2 >> 6) + 1;
        }
        else {
          uVar6 = (uVar2 >> 6) + 2;
        }
        sVar10 = uVar6 * 0x40;
        __ptr = malloc(sVar10);
        if (__ptr == (void *)0x0) {
          if ((opt_debug != '\0') &&
             (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
            snprintf(acStack_828,0x800,"%s: malloc coinbase_padding failed.\n",DAT_0003ad78);
            _applog(7,acStack_828,0);
          }
          free(__dest);
          uVar3 = 0xfffffffc;
        }
        else {
          if ((opt_debug != '\0') &&
             (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
            snprintf(acStack_828,0x800,"%s: coinbase_padding = 0x%x",DAT_0003a7b8,__ptr);
            _applog(7,acStack_828,0);
          }
          uVar7 = (uint)*(ushort *)((int)__dest + 0x42);
          if (uVar7 == 0) {
            local_8c4 = 0;
            local_8ac = (void *)0x0;
          }
          else {
            local_8c4 = uVar7 << 5;
            local_8ac = malloc(local_8c4);
            if (local_8ac == (void *)0x0) {
              if ((opt_debug != '\0') &&
                 (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
                snprintf(acStack_828,0x800,"%s: malloc merkles_bin failed.\n",DAT_0003ad78);
                _applog(7,acStack_828,0);
              }
              free(__dest);
              free(__ptr);
              return 0xfffffffb;
            }
            if ((opt_debug != '\0') &&
               (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
              snprintf(acStack_828,0x800,"%s: merkles_bin = 0x%x",DAT_0003a7b8,local_8ac);
              _applog(7,acStack_828,0);
            }
          }
          pbVar15 = (byte *)((int)__ptr + -1);
          memset(__ptr,0,sVar10);
          memcpy(__ptr,param_1 + 0x58,uVar5);
          *(undefined *)((int)__ptr + uVar5) = 0x80;
          *(uint *)((int)__ptr + (sVar10 - 4)) =
               (uVar5 << 3 & 0xff00) << 8 | (uVar5 << 3 & 0xff0000) >> 8 | uVar5 << 0x1b;
          sVar8 = 0;
          *(undefined4 *)((int)__ptr + (sVar10 - 8)) = 0;
          l_coinbase_padding = c_coinbase_padding;
          pbVar4 = pbVar15;
          c_coinbase_padding = sVar10;
          do {
            pbVar4 = pbVar4 + 1;
            *(byte *)(*dev + sVar8) = *pbVar4;
            sVar8 = sVar8 + 1;
          } while (sVar10 != sVar8);
          sVar8 = 0;
          do {
            pbVar15 = pbVar15 + 1;
            if ((((uint)*(byte *)(*dev + sVar8) != (uint)*pbVar15) && (opt_debug != '\0')) &&
               ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
              snprintf(acStack_828,0x800,
                       "%s: coinbase_padding_in_ddr[%d] = 0x%x, but *(coinbase_padding + %d) = 0x%x"
                       ,DAT_0003ab70,sVar8,(uint)*(byte *)(*dev + sVar8),sVar8,(uint)*pbVar15);
              _applog(7,acStack_828,0);
            }
            sVar8 = sVar8 + 1;
          } while (sVar10 != sVar8);
          l_merkles_num = c_merkles_num;
          c_merkles_num = uVar7;
          if (uVar7 != 0) {
            if ((opt_debug != '\0') &&
               (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
              snprintf(acStack_828,0x800,"%s: copy merkle bin into memory ...\n",DAT_0003ab70);
              _applog(7,acStack_828,0);
            }
            pvVar12 = local_8ac;
            pbVar15 = (byte *)((int)local_8ac + -1);
            memset(local_8ac,0,local_8c4);
            memcpy(pvVar12,param_1 + uVar5 + 0x58,local_8c4);
            uVar5 = 0;
            pbVar4 = pbVar15;
            do {
              pbVar4 = pbVar4 + 1;
              *(byte *)(*dev + sVar10 + uVar5) = *pbVar4;
              uVar5 = uVar5 + 1;
            } while (uVar5 < local_8c4);
            uVar5 = 0;
            do {
              pbVar15 = pbVar15 + 1;
              uVar11 = (uint)*(byte *)(*dev + sVar10 + uVar5);
              if (((uVar11 != *pbVar15) && (opt_debug != '\0')) &&
                 ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
                snprintf(acStack_828,0x800,
                         "%s: merkles_in_ddr[%d] = 0x%x, but *(merkles_bin + %d) =0x%x",DAT_0003ab70
                         ,uVar5,uVar11,uVar5,(uint)*pbVar15);
                _applog(7,acStack_828,0);
              }
              uVar5 = uVar5 + 1;
            } while (uVar5 < local_8c4);
          }
          if (bVar16) {
            uVar5 = get_dhash_acc_control();
            set_dhash_acc_control(uVar5 & 0xffffffbf);
          }
          else {
            uVar5 = get_dhash_acc_control();
            set_dhash_acc_control(uVar5 & 0xfffeffbf | 0x10000);
          }
          cgsleep_ms(1);
          if (*dev == job_start_address_1) {
            set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
          }
          else if (*dev == job_start_address_2) {
            set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x210000);
          }
          if ((int)((uint)*(byte *)((int)__dest + 9) << 0x1e) < 0) {
            uVar1 = *(undefined *)((int)__dest + 10);
            set_ticket_mask(uVar1);
            *(undefined *)(dev + 0x1510) = uVar1;
          }
          set_job_id(*(undefined4 *)((int)__dest + 0xc));
          uVar5 = *(uint *)((int)__dest + 0x10);
          set_block_header_version(uVar5);
          if (opt_multi_version == 4) {
            set_block_header_version1_ab(uVar5 | 0x4000);
            set_block_header_version2_ab(uVar5 | 0x8000);
            set_block_header_version3_ab(uVar5 | 0xc000);
          }
          ppvVar14 = &local_8ac;
          memset(local_8a8,0,0x80);
          pvVar12 = __dest;
          do {
            pvVar13 = (void *)((int)pvVar12 + 4);
            ppvVar14 = ppvVar14 + 1;
            *ppvVar14 = (void *)((uint)*(byte *)((int)pvVar12 + 0x14) |
                                 (uint)*(byte *)((int)pvVar12 + 0x16) << 0x10 |
                                 (uint)*(byte *)((int)pvVar12 + 0x17) << 0x18 |
                                (uint)*(byte *)((int)pvVar12 + 0x15) << 8);
            pvVar12 = pvVar13;
          } while (pvVar13 != (void *)((int)__dest + 0x20));
          set_pre_header_hash(local_8a8);
          set_time_stamp(*(undefined4 *)((int)__dest + 0x34));
          set_target_bits(*(undefined4 *)((int)__dest + 0x38));
          set_coinbase_length_and_nonce2_length
                    (uVar6 & 0xff |
                     (uint)*(byte *)((int)__dest + 0x40) << 8 |
                     (uint)*(ushort *)((int)__dest + 0x3e) << 0x10);
          local_8a8[0] = *(void **)((int)__dest + 0x48);
          local_8a8[1] = *(void **)((int)__dest + 0x4c);
          set_work_nonce2(local_8a8);
          set_merkle_bin_number(uVar7);
          set_job_length(local_8c4 + sVar10 & 0xffe0);
          cgsleep_ms(1);
          if (gBegin_get_nonce == '\0') {
            uVar5 = get_nonce_fifo_interrupt();
            set_nonce_fifo_interrupt(uVar5 | 0x10000);
            gBegin_get_nonce = '\x01';
            reCalculateAVG();
          }
          if (opt_multi_version == 0) {
            uVar5 = get_dhash_acc_control();
            set_dhash_acc_control(uVar5 & 0xfffef0ff | (opt_multi_version & 0xf) << 8 | 0x60);
          }
          else {
            uVar5 = get_dhash_acc_control();
            set_dhash_acc_control(uVar5 & 0xfffef0ff | (opt_multi_version & 0xf) << 8 | 0x8060);
          }
          free(__ptr);
          if (uVar7 != 0) {
            free(local_8ac);
          }
          free(__dest);
          if ((opt_debug != '\0') &&
             (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
            snprintf(acStack_828,0x800,"--- %s end\n",DAT_0003ab70);
            _applog(7,acStack_828,0);
          }
          cgtime(DAT_0003ab74);
          cgsleep_ms(1);
          set_asic_ticket_mask(ticket_mask);
          set_sno(0);
          set_hcnt(0);
          uVar3 = 0;
        }
      }
    }
    else {
      if ((opt_debug == '\0') ||
         (((use_syslog == '\0' && (opt_log_output == '\0')) && (opt_log_level < 7)))) {
        return 0xffffffff;
      }
      snprintf(acStack_828,0x800,"%s: SEND_JOB_TYPE is wrong : 0x%x\n",DAT_0003a7b8,(uint)*param_1);
      _applog(7,acStack_828,0);
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}

