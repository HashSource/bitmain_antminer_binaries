
/* WARNING: Unknown calling convention */

int get_ideal_hash_rate_fixed(void)

{
  if (g_ideal_hashrate_fixed == 0) {
    g_ideal_hashrate_fixed = get_total_rate();
  }
  return g_ideal_hashrate_fixed;
}

