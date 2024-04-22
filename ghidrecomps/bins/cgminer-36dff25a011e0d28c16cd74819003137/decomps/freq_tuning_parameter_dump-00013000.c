
void freq_tuning_parameter_dump(freq_tuning_info *freq_info)

{
  FILE *pFVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  double dVar7;
  freq_tuning_info *freq_info_local;
  FILE *pFile_11;
  FILE *pFile_10;
  FILE *pFile_9;
  FILE *pFile_8;
  FILE *pFile_7;
  FILE *pFile_6;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile_19;
  FILE *pFile_18;
  FILE *pFile_20;
  FILE *pFile_17;
  FILE *pFile_21;
  FILE *pFile_16;
  FILE *pFile_15;
  FILE *pFile_14;
  FILE *pFile_13;
  FILE *pFile_12;
  FILE *pFile;
  int nonce_recv;
  int asic;
  int chain;
  
  nonce_recv = 0;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: ======== dump freq tuning result ========\n","freq_tuning.c",0x1c2,
              "freq_tuning_parameter_dump");
    }
    fclose(pFVar1);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (((dev->chain_exist[chain] != 0) && (freq_info->test_done[chain] != true)) &&
       (freq_info->fake_done[chain] != true)) {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"chain %d\n",chain);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%-30s : %d\n","send_work_num",send_work_num[chain]);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%-30s : %d\n","valid_nonce_num",valid_nonce_num[chain]);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          if (send_work_num[chain] == 0) {
            uVar2 = 0;
            dVar7 = DAT_00013688;
          }
          else {
            uVar2 = send_work_num[chain];
            dVar7 = (double)(longlong)valid_nonce_num[chain] / (double)(ulonglong)uVar2;
          }
          fprintf(pFVar1,"%-30s : %f\n","nonce_return_rate",uVar2,dVar7);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%-30s : %d\n","repeated_nonce_num",repeated_nonce_num[chain]);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%-30s : %d\n","extra_nonce_num",extra_nonce_num[chain]);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%-30s : %d\n","invalid_nonce_num",invalid_nonce_num[chain]);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%-30s : %d\n","crc_err_nonce_num",crc_err_nonce_num[chain]);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%-30s : %d\n","err_nonce_num",err_nonce_num[chain]);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%-30s : %d\n","chain_hw_num",chain_hw_num[chain]);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fputc(10,pFVar1);
        }
        fclose(pFVar1);
      }
      nonce_recv = nonce_recv + valid_nonce_num[chain] + repeated_nonce_num[chain] +
                   extra_nonce_num[chain] + invalid_nonce_num[chain];
    }
  }
  uVar2 = nonce_recv + asic_invalid_num + chain_invalid_num;
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%-30s : %u\n","asic_invalid_num",asic_invalid_num);
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%-30s : %u\n","chain_invalid_num",chain_invalid_num);
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%-30s : %llu\n","nonce_recv_num_all",nonce_recv_num_all._4_4_,
              (uint)nonce_recv_num_all,nonce_recv_num_all._4_4_);
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      uVar3 = (int)uVar2 >> 0x1f;
      bVar6 = nonce_recv_num_all._4_4_ <= uVar3;
      if (uVar3 == nonce_recv_num_all._4_4_) {
        bVar6 = (uint)nonce_recv_num_all <= uVar2;
      }
      if (bVar6) {
        iVar4 = uVar2 - (uint)nonce_recv_num_all;
        iVar5 = uVar3 - (nonce_recv_num_all._4_4_ + (uVar2 < (uint)nonce_recv_num_all));
        uVar3 = nonce_recv_num_all._4_4_;
      }
      else {
        iVar4 = (uint)nonce_recv_num_all - uVar2;
        iVar5 = nonce_recv_num_all._4_4_ - (uVar3 + ((uint)nonce_recv_num_all < uVar2));
      }
      fprintf(pFVar1,"%-30s : %llu\n","nonce_recv_num_diff",uVar3,iVar4,iVar5);
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fputc(10,pFVar1);
    }
    fclose(pFVar1);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (((dev->chain_exist[chain] != 0) && (freq_info->test_done[chain] != true)) &&
       (freq_info->fake_done[chain] != true)) {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"chain %d asic_nonce_num:\n",chain);
        }
        fclose(pFVar1);
      }
      for (asic = 0; asic < 0x30; asic = asic + 1) {
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"IC[%02d]:%04d ",asic,asic_nonce_num[chain][asic]);
          }
          fclose(pFVar1);
        }
        if (((asic + 1U & 3) == 0) && (3 < log_level)) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fputc(10,pFVar1);
          }
          fclose(pFVar1);
        }
      }
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fputc(10,pFVar1);
        }
        fclose(pFVar1);
      }
    }
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if ((((dev->chain_exist[chain] != 0) && (freq_info->test_done[chain] != true)) &&
        (freq_info->fake_done[chain] != true)) &&
       (freq_tuning_domain_nonce_dump(chain), 3 < log_level)) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fputc(10,pFVar1);
      }
      fclose(pFVar1);
    }
  }
  return;
}

