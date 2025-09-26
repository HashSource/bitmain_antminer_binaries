
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void sw_pt_exit(void)

{
  if (g_rt.config != (config_ctx *)0x0) {
    free(g_rt.config);
    g_rt.config = (config_ctx *)0x0;
  }
  return;
}

