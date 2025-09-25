
void check_nonce(return_nonce_128bit_t *nonce_buf,pattern_runtime_ctx *ctx)

{
  byte bVar1;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  pattern_work *ppVar6;
  int iVar7;
  pattern_runtime_ctx *ctx_local;
  return_nonce_128bit_t *nonce_buf_local;
  char time_stamp [48];
  char tmp1 [256];
  uint32_t match_nonce;
  pattern_work *work;
  pattern_work *works;
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
    if (uVar2 < (uint)ctx->config->asics) {
      if (uVar3 < (uint)ctx->config->big_core) {
        if ((uVar3 == 0xf) || (uVar3 == 0x7f)) {
          if (0xb < uVar4) {
            err_sweep_nonce_resp = err_sweep_nonce_resp + 1;
            return;
          }
        }
        else if ((uint)ctx->config->samll_core_num_in_big_core <= uVar4) {
          err_sweep_nonce_resp = err_sweep_nonce_resp + 1;
          return;
        }
        if (uVar5 < (uint)ctx->config->patter_num) {
          ppVar6 = ctx->works[uVar2] + uVar5 + (uVar4 + uVar3 * 0x10) * 8;
          if ((nonce_buf->nonce).nonce == (ppVar6->pattern).nonce) {
            if (ppVar6->nonce_repeat == 0) {
              ppVar6->nonce_repeat = ppVar6->nonce_repeat + 1;
              (ctx->asic_stats).valid_nonce_num = (ctx->asic_stats).valid_nonce_num + 1;
              iVar7 = uVar4 + uVar3 * ctx->config->samll_core_num_in_big_core;
              (ctx->asic_stats).asic_core_nonce_num[uVar2][iVar7] =
                   (ctx->asic_stats).asic_core_nonce_num[uVar2][iVar7] + '\x01';
              (ctx->asic_stats).every_asic_got_nonce_num[uVar2] =
                   (ctx->asic_stats).every_asic_got_nonce_num[uVar2] + 1;
              (ctx->stats).nonce_num_asic[uVar2] = (ctx->stats).nonce_num_asic[uVar2] + 1;
              (ctx->stats).nonce_num_chain = (ctx->stats).nonce_num_chain + 1;
            }
            else {
              ppVar6->nonce_repeat = ppVar6->nonce_repeat + 1;
              (ctx->stats).nonce_num_repeated = (ctx->stats).nonce_num_repeated + 1;
            }
          }
        }
        else {
          err_sweep_nonce_resp = err_sweep_nonce_resp + 1;
        }
      }
      else {
        err_sweep_nonce_resp = err_sweep_nonce_resp + 1;
      }
    }
    else {
      err_sweep_nonce_resp = err_sweep_nonce_resp + 1;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : receive nonce from chain: %d, but not gChain: %d\n","check_nonce",
           *(byte *)nonce_buf & 0xf,ctx->config->chain);
    snprintf(tmp1,0x100,"receive nonce from chain: %d, but not gChain: %d",*(byte *)nonce_buf & 0xf,
             ctx->config->chain);
    log_to_file(tmp1,time_stamp);
  }
  return;
}

