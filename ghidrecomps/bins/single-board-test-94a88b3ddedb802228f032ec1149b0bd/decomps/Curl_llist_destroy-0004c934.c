
void Curl_llist_destroy(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 == 0) {
    return;
  }
  while (*(int *)(param_1 + 0xc) != 0) {
    Curl_llist_remove(param_1,*(undefined4 *)(param_1 + 4),param_2,*(int *)(param_1 + 0xc),param_4);
  }
  (**DAT_0004c95c)(param_1);
  return;
}

