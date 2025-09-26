
/* WARNING: Unknown calling convention */

void chain_reset(uint32_t chain_id)

{
  chain_reset_low(chain_id);
  usleep(100000);
  chain_reset_high(chain_id);
  return;
}

