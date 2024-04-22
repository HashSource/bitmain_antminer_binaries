
void hashtable_do_clear(int param_1)

{
  int iVar1;
  int local_c;
  
  local_c = *(int *)(param_1 + 0x10);
  while (param_1 + 0xc != local_c) {
    iVar1 = *(int *)(local_c + 4);
    json_decref(*(undefined4 *)(local_c + 8));
    jsonp_free(local_c + -4);
    local_c = iVar1;
  }
  return;
}

