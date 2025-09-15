
/* WARNING: Unknown calling convention */

int aging_get_last_stable_time(void)

{
  return aging_info.aging_seconds - aging_info.last_inbalance_time;
}

