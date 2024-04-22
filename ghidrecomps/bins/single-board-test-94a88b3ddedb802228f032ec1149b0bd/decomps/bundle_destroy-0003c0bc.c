
void bundle_destroy(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 8) != 0) {
      Curl_llist_destroy(*(int *)(param_1 + 8),0);
      *(undefined4 *)(param_1 + 8) = 0;
    }
    (**DAT_0003c0dc)(param_1);
  }
  return;
}

