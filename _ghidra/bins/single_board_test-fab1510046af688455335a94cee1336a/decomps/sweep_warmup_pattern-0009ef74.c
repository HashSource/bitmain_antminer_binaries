
int sweep_warmup_pattern(void *param_1)

{
  int iVar1;
  void *local_conf_local;
  char *pattern_file;
  Local_Config_Info *info;
  
  iVar1 = sw_warmup_pattern("/mnt/card/BM1370-pattern/pattern_16midstate.bin",
                            *(int *)((int)param_1 + 0x10c),*(int *)((int)param_1 + 0x48),
                            *(int *)((int)param_1 + 0x40));
  return iVar1;
}

