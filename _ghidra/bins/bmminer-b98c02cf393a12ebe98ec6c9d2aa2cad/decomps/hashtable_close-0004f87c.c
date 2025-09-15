
void hashtable_close(int param_1)

{
  hashtable_do_clear();
  jsonp_free(*(undefined4 *)(param_1 + 4));
  return;
}

