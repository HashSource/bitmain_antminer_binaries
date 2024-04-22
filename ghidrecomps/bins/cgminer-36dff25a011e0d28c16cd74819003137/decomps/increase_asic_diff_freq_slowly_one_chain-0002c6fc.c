
void increase_asic_diff_freq_slowly_one_chain
               (uint32_t *asic_diff_freq,uint32_t start_freq,int freq_step,int chain)

{
  uint32_t asic_00;
  uint uVar1;
  uint32_t uVar2;
  int chain_local;
  int freq_step_local;
  uint32_t start_freq_local;
  uint32_t *asic_diff_freq_local;
  uint32_t this_diff;
  int domain_col;
  int domain;
  uint32_t step;
  uint32_t steps;
  uint32_t asic_freq;
  uint32_t max;
  int asic;
  
  max = 0;
  for (asic = 0; asic < 0x30; asic = asic + 1) {
    if (max < asic_diff_freq[asic]) {
      max = asic_diff_freq[asic];
    }
  }
  steps = __udivsi3(max,freq_step);
  if (steps * freq_step < max) {
    steps = steps + 1;
  }
  for (step = 0; step < steps; step = step + 1) {
    uVar1 = freq_step * (step + 1);
    for (domain_col = 0; domain_col < 4; domain_col = domain_col + 1) {
      for (domain = 0; domain < 0xc; domain = domain + 1) {
        asic_00 = get_physical_chip_no(domain,domain_col);
        if ((uVar1 <= asic_diff_freq[asic_00]) ||
           (uVar1 - asic_diff_freq[asic_00] < (uint)freq_step)) {
          uVar2 = uVar1;
          if (asic_diff_freq[asic_00] <= uVar1) {
            uVar2 = asic_diff_freq[asic_00];
          }
          asic_freq = start_freq + uVar2;
          change_high_pll_by_aisc(chain,asic_00,(float)(ulonglong)asic_freq,0);
        }
      }
      usleep(100000);
    }
  }
  return;
}

