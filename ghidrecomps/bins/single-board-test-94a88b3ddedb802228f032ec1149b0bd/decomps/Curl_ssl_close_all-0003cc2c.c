
void Curl_ssl_close_all(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x85b0);
  if ((iVar1 != 0) &&
     ((*(int **)(param_1 + 0x48) == (int *)0x0 || (-1 < **(int **)(param_1 + 0x48) << 0x1b)))) {
    if (*(int *)(param_1 + 0x2a8) != 0) {
      iVar2 = 0;
      uVar3 = 0;
      do {
        uVar3 = uVar3 + 1;
        Curl_ssl_kill_session(iVar1 + iVar2);
        iVar2 = iVar2 + 0x58;
        iVar1 = *(int *)(param_1 + 0x85b0);
      } while (uVar3 < *(uint *)(param_1 + 0x2a8));
    }
    (**DAT_0003cc7c)();
    *(undefined4 *)(param_1 + 0x85b0) = 0;
  }
  Curl_ossl_close_all(param_1);
  return;
}

