
void check_nonce(return_nonce_128bit_t *nonce_buf,pattern_runtime_ctx *ctx)

{
  byte bVar1;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  pattern_work_new *ppVar6;
  int iVar7;
  pattern_runtime_ctx *ctx_local;
  return_nonce_128bit_t *nonce_buf_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t match_nonce;
  pattern_work_new *work;
  pattern_work_new *works;
  uint32_t which_pattern;
  uint32_t which_small_core;
  uint32_t which_big_core;
  uint32_t which_asic;
  uint uVar2;
  
  if ((*(byte *)nonce_buf & 0xf) == ctx->config->chain) {
    bVar1 = get_asic_index_by_nonce((nonce_buf->nonce).nonce,ctx->config->interval);
    uVar2 = (uint)bVar1;
    bVar1 = get_coreid_by_nonce((nonce_buf->nonce).nonce);
    uVar3 = (uint)bVar1;
    uVar4 = *(ushort *)((int)(nonce_buf->reg).reserved_2 + 1) & 0xf;
    uVar5 = (int)(*(ushort *)((int)nonce_buf + 2) & 0x7fff) >> 7;
    once_recv_nonce_cnt = once_recv_nonce_cnt + 1;
    if (uVar2 < (uint)ctx->config->asics) {
      if (uVar3 < (uint)ctx->config->big_core) {
        if (ctx->config->abnormal_core == uVar3) {
          if (uVar4 < ctx->config->samll_core_num_in_big_core - 0xcU) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: receive nonce from Aisc: %d, big_core %d, small_core %d, but the most Asic small_core number is: %d\n"
                   ,"check_nonce",uVar2,uVar3,uVar4,ctx->config->samll_core_num_in_big_core);
            snprintf(tmp1,0x800,
                     "receive nonce from Aisc: %d, big_core %d, small_core %d, but the most Asic small_core number is: %d"
                     ,uVar2,uVar3,uVar4,ctx->config->samll_core_num_in_big_core);
            log_to_file(tmp1,time_stamp);
            return;
          }
        }
        else if ((uint)ctx->config->samll_core_num_in_big_core <= uVar4) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: receive nonce from Aisc: %d, big_core %d, small_core %d, but the most Asic small_core number is: %d\n"
                 ,"check_nonce",uVar2,uVar3,uVar4,ctx->config->samll_core_num_in_big_core);
          snprintf(tmp1,0x800,
                   "receive nonce from Aisc: %d, big_core %d, small_core %d, but the most Asic small_core number is: %d"
                   ,uVar2,uVar3,uVar4,ctx->config->samll_core_num_in_big_core);
          log_to_file(tmp1,time_stamp);
          return;
        }
        if (uVar5 < (uint)ctx->config->patter_num) {
          ppVar6 = ctx->works_new[uVar2];
          iVar7 = uVar5 + ctx->config->patter_num *
                          (uVar3 * ctx->config->samll_core_num_in_big_core + uVar4);
          if ((nonce_buf->nonce).nonce == ppVar6[iVar7].pattern.nonce) {
            if (ppVar6[iVar7].nonce_repeat == 0) {
              ppVar6[iVar7].nonce_repeat = ppVar6[iVar7].nonce_repeat + 1;
              (ctx->asic_stats).valid_nonce_num = (ctx->asic_stats).valid_nonce_num + 1;
              iVar7 = uVar3 * ctx->config->samll_core_num_in_big_core + uVar4;
              (ctx->asic_stats).asic_core_nonce_num[uVar2][iVar7] =
                   (ctx->asic_stats).asic_core_nonce_num[uVar2][iVar7] + '\x01';
              (ctx->asic_stats).every_asic_got_nonce_num[uVar2] =
                   (ctx->asic_stats).every_asic_got_nonce_num[uVar2] + 1;
              (ctx->stats).nonce_num_asic[uVar2] = (ctx->stats).nonce_num_asic[uVar2] + 1;
              (ctx->stats).nonce_num_chain = (ctx->stats).nonce_num_chain + 1;
            }
            else {
              ppVar6[iVar7].nonce_repeat = ppVar6[iVar7].nonce_repeat + 1;
              (ctx->stats).nonce_num_repeated = (ctx->stats).nonce_num_repeated + 1;
            }
          }
          else {
            unmatched_nonce = unmatched_nonce + 1;
          }
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: receive %dth pattern from Aisc: %d, big_core %d, small_core %d, but the most pattern number is: %d\n"
                 ,"check_nonce",uVar5,uVar2,uVar3,uVar4,ctx->config->patter_num);
          snprintf(tmp1,0x800,
                   "receive %dth pattern from Aisc: %d, big_core %d, small_core %d, but the most pattern number is: %d"
                   ,uVar5,uVar2,uVar3,uVar4,ctx->config->patter_num);
          log_to_file(tmp1,time_stamp);
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: receive nonce from Aisc: %d, big_core %d, but the most Asic big_core number is: %d\n"
               ,"check_nonce",uVar2,uVar3,ctx->config->big_core);
        snprintf(tmp1,0x800,
                 "receive nonce from Aisc: %d, big_core %d, but the most Asic big_core number is: %d"
                 ,uVar2,uVar3,ctx->config->big_core);
        log_to_file(tmp1,time_stamp);
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: receive nonce from Aisc: %d, but the most Asic number is: %d\n","check_nonce",
             uVar2,ctx->config->asics);
      snprintf(tmp1,0x800,"receive nonce from Aisc: %d, but the most Asic number is: %d",uVar2,
               ctx->config->asics);
      log_to_file(tmp1,time_stamp);
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: receive nonce from chain: %d, but not gChain: %d\n","check_nonce",
           *(byte *)nonce_buf & 0xf,ctx->config->chain);
    snprintf(tmp1,0x800,"receive nonce from chain: %d, but not gChain: %d",*(byte *)nonce_buf & 0xf,
             ctx->config->chain);
    log_to_file(tmp1,time_stamp);
  }
  return;
}

