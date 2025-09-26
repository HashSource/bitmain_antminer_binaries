
int32_t eeprom_get_sweep_result(sweep_result_t *sweep_result,edf_ctx_p ctx)

{
  int iVar1;
  uint32_t uVar2;
  undefined1 uVar3;
  byte bVar4;
  bool bVar5;
  edf_ctx_p ctx_local;
  sweep_result_t *sweep_result_local;
  size_t len;
  uint8_t tmp [128];
  uint8_t level;
  int i_1;
  int i;
  
  memset(tmp,0,0x80);
  len = 0x80;
  if (sweep_result != (sweep_result_t *)0x0) {
    iVar1 = (*ctx->version_get)(ctx);
    if (iVar1 == 5) {
      iVar1 = (*ctx->sweep_hashrate_get)(ctx);
      sweep_result->hashrate = (uint16_t)iVar1;
      iVar1 = (*ctx->sweep_freq_base_get)(ctx);
      sweep_result->freq_base = (uint16_t)iVar1;
      iVar1 = (*ctx->sweep_freq_step_get)(ctx);
      sweep_result->freq_step = (uint8_t)iVar1;
      iVar1 = (*ctx->sweep_result_get)(ctx);
      bVar5 = iVar1 == 1;
      if (bVar5) {
        iVar1 = 1;
      }
      uVar3 = (undefined1)iVar1;
      if (!bVar5) {
        uVar3 = false;
      }
      sweep_result->is_pass = (_Bool)uVar3;
      (*ctx->sweep_level_get)(ctx,tmp,&len);
      for (i = 0; (uint)i < 0x100; i = i + 1) {
        if ((i & 1U) == 0) {
          bVar4 = tmp[i / 2] & 0xf;
        }
        else {
          bVar4 = tmp[i / 2] >> 4;
        }
        if (sweep_result->freq_base == 0) {
          uVar2 = (*ctx->frequency_get)(ctx);
          sweep_result->freqs[i] = uVar2;
        }
        else {
          sweep_result->freqs[i] =
               (uint)bVar4 * (uint)sweep_result->freq_step + (uint)sweep_result->freq_base;
        }
      }
    }
    else {
      iVar1 = (*ctx->version_get)(ctx);
      if (iVar1 == 4) {
        for (i_1 = 0; (uint)i_1 < 0x100; i_1 = i_1 + 1) {
          uVar2 = (*ctx->frequency_get)(ctx);
          sweep_result->freqs[i_1] = uVar2;
        }
      }
    }
  }
  return 0;
}

