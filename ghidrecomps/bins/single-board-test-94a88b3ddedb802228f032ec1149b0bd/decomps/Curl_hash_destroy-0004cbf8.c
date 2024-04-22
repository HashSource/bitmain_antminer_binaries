
void Curl_hash_destroy(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (0 < param_1[4]) {
    iVar2 = 0;
    do {
      Curl_llist_destroy(*(undefined4 *)(*param_1 + iVar2 * 4),param_1);
      iVar1 = param_1[4];
      *(undefined4 *)(*param_1 + iVar2 * 4) = 0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  (**DAT_0004cc34)(*param_1);
  *param_1 = 0;
  param_1[5] = 0;
  param_1[4] = 0;
  return;
}

