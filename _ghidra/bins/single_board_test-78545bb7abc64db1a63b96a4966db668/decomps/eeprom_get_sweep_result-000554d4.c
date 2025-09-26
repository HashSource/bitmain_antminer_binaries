
int32_t eeprom_get_sweep_result(sweep_result_t *sweep_result,eeprom_v1 *ctx)

{
  eeprom_v1 *ctx_local;
  sweep_result_t *sweep_result_local;
  uint8_t tmp [128];
  uint16_t freq_max;
  uint16_t freq_min;
  uint16_t freqs [256];
  size_t len;
  int i;
  
  freq_min = 0xffff;
  freq_max = 0;
  memset(tmp,0,0x80);
  memset(freqs,0,0x200);
  if (sweep_result != (sweep_result_t *)0x0) {
    if ((ctx->data).version == '\x01') {
      sweep_result->hashrate = (ctx->data).field_2.format_v1.sweep.sweep_hashrate;
      sweep_result->freq_base = (ctx->data).field_2.format_v1.sweep.sweep_freq_base;
      sweep_result->freq_step = (ctx->data).field_2.raw[0x66];
      sweep_result->is_pass = (ctx->data).field_2.raw[0xe7] == '\x01';
    }
    (*ctx->get_sweep_freq)(ctx,freqs,&freq_min,&freq_max,0xff);
    for (i = 0; (uint)i < 0x100; i = i + 1) {
      if (sweep_result->freq_base == 0) {
        sweep_result->freqs[i] = (uint)(ctx->data).field_2.format_v1.pt2.frequency;
      }
      else {
        sweep_result->freqs[i] = (uint)freqs[i];
      }
    }
  }
  return 0;
}

