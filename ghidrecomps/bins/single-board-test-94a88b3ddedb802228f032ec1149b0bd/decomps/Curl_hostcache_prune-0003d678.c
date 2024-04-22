
void Curl_hostcache_prune(int param_1)

{
  time_t local_1c;
  undefined4 local_18;
  time_t local_14;
  
  if ((*(int *)(param_1 + 0x2c8) != -1) && (*(int *)(param_1 + 0x38) != 0)) {
    if (*(int *)(param_1 + 0x48) != 0) {
      Curl_share_lock(param_1,3,2);
    }
    time(&local_1c);
    local_18 = *(undefined4 *)(param_1 + 0x2c8);
    local_14 = local_1c;
    Curl_hash_clean_with_criterium(*(undefined4 *)(param_1 + 0x38),&local_18,DAT_0003d6c0);
    if (*(int *)(param_1 + 0x48) != 0) {
      Curl_share_unlock(param_1,3);
    }
  }
  return;
}

