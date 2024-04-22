
int send_job(uchar *buf,pool *pool)

{
  FILE *pFVar1;
  void *__s;
  void *__s_00;
  uint uVar2;
  int iVar3;
  uint uVar4;
  pool *pool_local;
  uchar *buf_local;
  uint buf2 [32];
  FILE *pFile_1;
  FILE *pFile_3;
  FILE *pFile_6;
  FILE *pFile_10;
  FILE *pFile_13;
  FILE *pFile_14;
  FILE *pFile_12;
  FILE *pFile_11;
  FILE *pFile_8;
  FILE *pFile_9;
  FILE *pFile_7;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_2;
  FILE *pFile;
  part_of_job *part_job;
  uchar *coinbase_padding;
  uchar *temp_buf;
  ushort job_length;
  uint j;
  uint len;
  int times;
  uchar *merkles_bin;
  uint coinbase_padding_len;
  uint i;
  
  merkles_bin = (uchar *)0x0;
  memset(buf2,0,0x80);
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: doTestPatten value %d\n","driver-btm-soc.c",0x1b92,"send_job",
              (uint)doTestPatten);
    }
    fclose(pFVar1);
  }
  if (doTestPatten == false) {
    if (*buf == 'R') {
      iVar3 = *(int *)(buf + 4);
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: len = 0x%x\n","driver-btm-soc.c",0x1b9d,"send_job",iVar3);
        }
        fclose(pFVar1);
      }
      __s = malloc(iVar3 + 8);
      if (__s == (void *)0x0) {
        if (4 < log_level) {
          print_crt_time_to_file(log_file,4);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: malloc buffer failed.\n","driver-btm-soc.c",0x1ba2,"send_job")
            ;
          }
          fclose(pFVar1);
        }
        iVar3 = -2;
      }
      else {
        memset(__s,0,iVar3 + 8);
        memcpy(__s,buf,iVar3 + 8);
        if (dev->current_job_start_address == job_start_address_1) {
          dev->current_job_start_address = job_start_address_2;
        }
        else {
          if (dev->current_job_start_address != job_start_address_2) {
            if (4 < log_level) {
              print_crt_time_to_file(log_file,4);
              pFVar1 = fopen(log_file,"a+");
              if (pFVar1 != (FILE *)0x0) {
                fprintf(pFVar1,
                        "%s:%d:%s: dev->current_job_start_address = 0x%x, but job_start_address_1 = 0x%x, job_start_address_2 = 0x%x\n"
                        ,"driver-btm-soc.c",0x1bb8,"send_job",dev->current_job_start_address,
                        job_start_address_1,job_start_address_2);
              }
              fclose(pFVar1);
            }
            return -3;
          }
          dev->current_job_start_address = job_start_address_1;
        }
        if (*(char *)((int)__s + 0x50) == '\0') {
          opt_multi_version = 1;
        }
        else {
          opt_multi_version = *(int *)((int)__s + 0x54);
        }
        if (send_job::tmp_version != opt_multi_version) {
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%s:%d:%s: Version num %d\n","driver-btm-soc.c",0x1bc2,"send_job",
                      opt_multi_version);
            }
            fclose(pFVar1);
          }
          send_job::tmp_version = opt_multi_version;
        }
        if ((*(ushort *)((int)__s + 0x3c) & 0x3f) < 0x38) {
          uVar4 = (*(ushort *)((int)__s + 0x3c) >> 6) + 1;
        }
        else {
          uVar4 = (*(ushort *)((int)__s + 0x3c) >> 6) + 2;
        }
        coinbase_padding_len = uVar4 * 0x40;
        __s_00 = malloc(coinbase_padding_len);
        if (__s_00 == (void *)0x0) {
          if (4 < log_level) {
            print_crt_time_to_file(log_file,4);
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%s:%d:%s: malloc coinbase_padding failed.\n","driver-btm-soc.c",0x1bd2
                      ,"send_job");
            }
            fclose(pFVar1);
          }
          iVar3 = -4;
        }
        else {
          if (4 < log_level) {
            print_crt_time_to_file(log_file,4);
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%s:%d:%s: coinbase_padding = 0x%x\n","driver-btm-soc.c",0x1bd7,
                      "send_job",__s_00);
            }
            fclose(pFVar1);
          }
          if (*(short *)((int)__s + 0x42) != 0) {
            merkles_bin = (uchar *)malloc((uint)*(ushort *)((int)__s + 0x42) << 5);
            if (merkles_bin == (uchar *)0x0) {
              if (4 < log_level) {
                print_crt_time_to_file(log_file,4);
                pFVar1 = fopen(log_file,"a+");
                if (pFVar1 != (FILE *)0x0) {
                  fprintf(pFVar1,"%s:%d:%s: malloc merkles_bin failed.\n","driver-btm-soc.c",0x1bdf,
                          "send_job");
                }
                fclose(pFVar1);
              }
              if (__s_00 != (void *)0x0) {
                free(__s_00);
              }
              return -5;
            }
            if (4 < log_level) {
              print_crt_time_to_file(log_file,4);
              pFVar1 = fopen(log_file,"a+");
              if (pFVar1 != (FILE *)0x0) {
                fprintf(pFVar1,"%s:%d:%s: merkles_bin = 0x%x\n","driver-btm-soc.c",0x1be8,"send_job"
                        ,merkles_bin);
              }
              fclose(pFVar1);
            }
          }
          memset(__s_00,0,coinbase_padding_len);
          memcpy(__s_00,buf + 0x58,(uint)*(ushort *)((int)__s + 0x3c));
          *(undefined *)((int)__s_00 + (uint)*(ushort *)((int)__s + 0x3c)) = 0x80;
          *(uint *)((coinbase_padding_len - 4) + (int)__s_00) =
               (uint)*(ushort *)((int)__s + 0x3c) << 0x1b |
               ((uint)*(ushort *)((int)__s + 0x3c) << 3) >> 8 & 0xff00 |
               (*(ushort *)((int)__s + 0x3c) & 0x1fe0) << 0xb;
          *(undefined4 *)((coinbase_padding_len - 8) + (int)__s_00) = 0;
          l_coinbase_padding = c_coinbase_padding;
          c_coinbase_padding = coinbase_padding_len;
          for (i = 0; i < coinbase_padding_len; i = i + 1) {
            *(undefined *)(i + (int)dev->current_job_start_address) =
                 *(undefined *)((int)__s_00 + i);
          }
          for (i = 0; i < coinbase_padding_len; i = i + 1) {
            if ((*(char *)(i + (int)dev->current_job_start_address) != *(char *)(i + (int)__s_00))
               && (4 < log_level)) {
              print_crt_time_to_file(log_file,4);
              pFVar1 = fopen(log_file,"a+");
              if (pFVar1 != (FILE *)0x0) {
                fprintf(pFVar1,
                        "%s:%d:%s: coinbase_padding_in_ddr[%d] = 0x%x, but *(coinbase_padding + %d) = 0x%x\n"
                        ,"driver-btm-soc.c",0x1c00,"send_job",i,
                        (uint)*(byte *)(i + (int)dev->current_job_start_address),i,
                        (uint)*(byte *)(i + (int)__s_00));
              }
              fclose(pFVar1);
            }
          }
          l_merkles_num = c_merkles_num;
          c_merkles_num = (uint32_t)*(ushort *)((int)__s + 0x42);
          if (*(short *)((int)__s + 0x42) != 0) {
            if (4 < log_level) {
              print_crt_time_to_file(log_file,4);
              pFVar1 = fopen(log_file,"a+");
              if (pFVar1 != (FILE *)0x0) {
                fprintf(pFVar1,"%s:%d:%s: copy merkle bin into memory ...\n","driver-btm-soc.c",
                        0x1c07,"send_job");
              }
              fclose(pFVar1);
            }
            memset(merkles_bin,0,(uint)*(ushort *)((int)__s + 0x42) << 5);
            memcpy(merkles_bin,buf + *(ushort *)((int)__s + 0x3c) + 0x58,
                   (uint)*(ushort *)((int)__s + 0x42) << 5);
            for (i = 0; i < (uint)*(ushort *)((int)__s + 0x42) << 5; i = i + 1) {
              *(uchar *)(i + coinbase_padding_len + (int)dev->current_job_start_address) =
                   merkles_bin[i];
            }
            for (i = 0; i < (uint)*(ushort *)((int)__s + 0x42) << 5; i = i + 1) {
              if ((*(uchar *)(i + coinbase_padding_len + (int)dev->current_job_start_address) !=
                   merkles_bin[i]) && (4 < log_level)) {
                print_crt_time_to_file(log_file,4);
                pFVar1 = fopen(log_file,"a+");
                if (pFVar1 != (FILE *)0x0) {
                  fprintf(pFVar1,
                          "%s:%d:%s: merkles_in_ddr[%d] = 0x%x, but *(merkles_bin + %d) =0x%x\n",
                          "driver-btm-soc.c",0x1c15,"send_job",i,
                          (uint)*(byte *)(i + coinbase_padding_len +
                                         (int)dev->current_job_start_address),i,(uint)merkles_bin[i]
                         );
                }
                fclose(pFVar1);
              }
            }
          }
          uVar2 = get_dhash_acc_control();
          set_dhash_acc_control(uVar2 & 0xffffff3f | 0x80);
          cgsleep_ms(1);
          while (uVar2 = get_dhash_acc_control(), (uVar2 & 0x40) != 0) {
            cgsleep_ms(1);
            if (4 < log_level) {
              print_crt_time_to_file(log_file,4);
              pFVar1 = fopen(log_file,"a+");
              if (pFVar1 != (FILE *)0x0) {
                fprintf(pFVar1,"%s:%d:%s: run bit is 1 after set it to 0\n","driver-btm-soc.c",
                        0x1c1f,"send_job");
              }
              fclose(pFVar1);
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
          get_block_header_version();
          if (opt_multi_version == 2) {
            set_block_header_version_1(*(uint *)((int)__s + 0x10) | 0x4000);
            get_block_header_version_1();
          }
          memset(buf2,0,0x80);
          for (i = 0; i < 8; i = i + 1) {
            buf2[i] = (uint)*(byte *)((int)__s + i * 4 + 0x15) << 8 |
                      (uint)*(byte *)((int)__s + i * 4 + 0x17) << 0x18 |
                      (uint)*(byte *)((int)__s + i * 4 + 0x16) << 0x10 |
                      (uint)*(byte *)((int)__s + i * 4 + 0x14);
          }
          set_pre_header_hash(buf2);
          set_time_stamp(*(uint *)((int)__s + 0x34));
          set_target_bits(*(uint *)((int)__s + 0x38));
          set_coinbase_length_and_nonce2_length
                    ((uint)(byte)*(undefined2 *)((int)__s + 0x40) << 8 |
                     (uint)*(ushort *)((int)__s + 0x3e) << 0x10 | uVar4 & 0xff);
          buf2[0] = *(uint *)((int)__s + 0x48);
          buf2[1] = *(uint *)((int)__s + 0x4c);
          set_work_nonce2(buf2);
          set_merkle_bin_number((uint)*(ushort *)((int)__s + 0x42));
          set_job_length((uint)(ushort)((short)coinbase_padding_len +
                                       *(short *)((int)__s + 0x42) * 0x20));
          cgsleep_ms(1);
          if (gBegin_get_nonce != true) {
            uVar4 = get_nonce_fifo_interrupt();
            set_nonce_fifo_interrupt(uVar4 | 0x10000);
            uVar4 = get_dhash_acc_control();
            set_dhash_acc_control(uVar4 | 0x80);
            gBegin_get_nonce = true;
            reCalculateAVG();
          }
          if (pool->support_ab == false) {
            set_time_out_control(dev->timeout & 0x1ffff | 0x80000000);
          }
          else {
            set_time_out_control(dev->timeout & 0x1ffff | 0x80000000);
          }
          if ((*(byte *)((int)__s + 9) & 1) == 0) {
            if (pool->support_ab == false) {
              uVar4 = get_dhash_acc_control();
              set_dhash_acc_control(uVar4 & 0xffff709f | 0x8160);
            }
            else {
              uVar4 = get_dhash_acc_control();
              set_dhash_acc_control((opt_multi_version & 0xfU) << 8 | uVar4 & 0xfffff0bf | 0x8060);
            }
          }
          else if (pool->support_ab == false) {
            uVar4 = get_dhash_acc_control();
            set_dhash_acc_control(uVar4 & 0xffff709f | 0x8160);
          }
          else {
            uVar4 = get_dhash_acc_control();
            set_dhash_acc_control((opt_multi_version & 0xfU) << 8 | uVar4 & 0xfffff0bf | 0x8060);
          }
          free(__s);
          free(__s_00);
          if (*(short *)((int)__s + 0x42) != 0) {
            free(merkles_bin);
          }
          if (4 < log_level) {
            print_crt_time_to_file(log_file,4);
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%s:%d:%s: --- end\n","driver-btm-soc.c",0x1c8d,"send_job");
            }
            fclose(pFVar1);
          }
          cgtime(&tv_send_job);
          set_status(STATUS_OK);
          cgsleep_ms(1);
          iVar3 = 0;
        }
      }
    }
    else {
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: SEND_JOB_TYPE is wrong : 0x%x\n","driver-btm-soc.c",0x1b98,
                  "send_job",(uint)*buf);
        }
        fclose(pFVar1);
      }
      iVar3 = -1;
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}

