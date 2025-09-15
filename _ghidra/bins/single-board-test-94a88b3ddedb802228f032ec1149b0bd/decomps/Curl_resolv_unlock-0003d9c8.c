
void Curl_resolv_unlock(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 == 0) {
    freednsentry(param_2,param_2,param_3,param_4);
    return;
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    Curl_share_lock(param_1,3,2);
  }
  freednsentry(param_2);
  if (*(int *)(param_1 + 0x48) != 0) {
    Curl_share_unlock(param_1,3);
    return;
  }
  return;
}

