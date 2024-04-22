
/* WARNING: Variable defined which should be unmapped: total_thashes */
/* WARNING: Unknown calling convention */

void * store_hash_rate(void)

{
  double dVar1;
  double total_thashes;
  uint32_t counter;
  
  counter = 0;
  memset(thashrate_array,0,0x208);
  do {
    counter = counter + 1;
    dVar1 = get_total_hashs();
    store_mhashrate_history((dVar1 / DAT_00060b78) / DAT_00060b78);
    show_hashrate_history();
    sleep(0x3c);
    if (counter % 0x1e == 0) {
      copy_log_to_latest(hash_log);
      clear_log(hash_log);
    }
    thash_index = thash_index + 1;
  } while( true );
}

