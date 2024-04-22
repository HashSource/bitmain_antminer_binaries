
void json_delete_array(int param_1)

{
  uint local_c;
  
  for (local_c = 0; local_c < *(uint *)(param_1 + 0xc); local_c = local_c + 1) {
    json_decref(*(undefined4 *)(*(int *)(param_1 + 0x10) + local_c * 4));
  }
  jsonp_free(*(undefined4 *)(param_1 + 0x10));
  jsonp_free(param_1);
  return;
}

