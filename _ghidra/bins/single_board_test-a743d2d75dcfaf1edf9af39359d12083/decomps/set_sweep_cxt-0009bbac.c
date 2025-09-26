
void set_sweep_cxt(sweep_ctx *ctx,int reuse_mode)

{
  time_t tVar1;
  int reuse_mode_local;
  sweep_ctx *ctx_local;
  char tmp42 [256];
  
  ctx->range_freq[0] = 470.0;
  ctx->range_freq[1] = 517.0;
  ctx->step = 6.25;
  ctx->bias = 0.1;
  ctx->eeprom_freq_step = 3;
  ctx->mode = 1;
  ctx->reuse = reuse_mode;
  tVar1 = time((time_t *)0x0);
  *(time_t *)&ctx->sweep_start_time = tVar1;
  *(time_t *)((int)&ctx->sweep_start_time + 4) = tVar1 >> 0x1f;
  *(undefined4 *)&ctx->sweep_online_time = 0;
  *(undefined4 *)((int)&ctx->sweep_online_time + 4) = 0;
  *(undefined4 *)&ctx->sweep_end_time = 0;
  *(undefined4 *)((int)&ctx->sweep_end_time + 4) = 0;
  snprintf(tmp42,0x100,"===========sweep mode[%d], reuse[%d]============",ctx->mode,ctx->reuse);
  puts(tmp42);
  return;
}

