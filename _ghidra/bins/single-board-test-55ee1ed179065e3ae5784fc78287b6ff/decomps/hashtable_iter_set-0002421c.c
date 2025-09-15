
void hashtable_iter_set(int param_1,undefined4 param_2)

{
  json_decref(*(undefined4 *)(param_1 + 8));
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}

