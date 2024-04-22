
/* WARNING: Unknown calling convention */

void init_pcba_args(void)

{
  runtime_base_t *prVar1;
  runtime_base_t *runtime;
  int i;
  
  prVar1 = cgpu.runtime;
  for (i = 0; i < 1; i = i + 1) {
    prVar1->chain_status[i].real_asic_num = 0;
  }
  for (i = 0; i < 3; i = i + 1) {
    chip_temp[i] = '\0';
    pcb_temp[i] = '\0';
  }
  gChain = 0xff;
  pcb_high = '\0';
  chip_high = '\0';
  return;
}

