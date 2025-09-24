
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void sweep_end_power_down(void)

{
  if (g_rt.sweep.mode != 0) {
    stop_threads();
    power_down_and_fan((g_rt.config)->chain);
  }
  return;
}

