
void hashtable_close(int param_1)

{
  hashtable_do_clear(param_1);
  jsonp_free(*(undefined4 *)(param_1 + 4));
  return;
}

