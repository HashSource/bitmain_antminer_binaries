
/* WARNING: Unknown calling convention */

int sw_stop(void)

{
  (*g_rt.pt_ops.exit)();
  sw_break = 0;
  return 0;
}

