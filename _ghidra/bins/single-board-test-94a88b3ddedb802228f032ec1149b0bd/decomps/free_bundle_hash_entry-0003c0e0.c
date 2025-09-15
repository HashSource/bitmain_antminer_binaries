
void free_bundle_hash_entry(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 8) != 0) {
      Curl_llist_destroy(*(int *)(param_1 + 8),0);
      *(undefined4 *)(param_1 + 8) = 0;
    }
    (*Curl_cfree)(param_1);
  }
  return;
}

