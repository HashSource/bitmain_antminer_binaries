
void Curl_cookie_loadfiles(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x460);
  if (puVar2 != (undefined4 *)0x0) {
    Curl_share_lock(param_1,2,2);
    do {
      iVar1 = Curl_cookie_init(param_1,*puVar2,*(undefined4 *)(param_1 + 0x468),
                               *(undefined1 *)(param_1 + 0x24d));
      if (iVar1 == 0) {
        Curl_infof(param_1,"ignoring failed cookie_init for %s\n",*puVar2);
      }
      else {
        *(int *)(param_1 + 0x468) = iVar1;
      }
      puVar2 = (undefined4 *)puVar2[1];
    } while (puVar2 != (undefined4 *)0x0);
    curl_slist_free_all(*(undefined4 *)(param_1 + 0x460));
    *(undefined4 *)(param_1 + 0x460) = 0;
    Curl_share_unlock(param_1,2);
    return;
  }
  return;
}

