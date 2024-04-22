
void Curl_ssl_free_certinfo(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x878c) == 0) {
    return;
  }
  if (0 < *(int *)(param_1 + 0x878c)) {
    iVar2 = 0;
    do {
      curl_slist_free_all(*(undefined4 *)(*(int *)(param_1 + 0x8790) + iVar2 * 4));
      iVar1 = *(int *)(param_1 + 0x878c);
      *(undefined4 *)(*(int *)(param_1 + 0x8790) + iVar2 * 4) = 0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  (**DAT_0003cd68)(*(undefined4 *)(param_1 + 0x8790));
  *(undefined4 *)(param_1 + 0x8790) = 0;
  *(undefined4 *)(param_1 + 0x878c) = 0;
  return;
}

