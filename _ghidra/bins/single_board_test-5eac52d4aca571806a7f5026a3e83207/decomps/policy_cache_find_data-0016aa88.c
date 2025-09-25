
void policy_cache_find_data(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 auStack_18 [4];
  undefined4 local_14;
  
  local_14 = param_2;
  uVar1 = OPENSSL_sk_find(*(undefined4 *)(param_1 + 4),auStack_18);
  OPENSSL_sk_value(*(undefined4 *)(param_1 + 4),uVar1);
  return;
}

