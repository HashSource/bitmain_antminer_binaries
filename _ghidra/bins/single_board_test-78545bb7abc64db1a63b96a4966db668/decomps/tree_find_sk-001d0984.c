
void tree_find_sk(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 *local_24 [3];
  undefined1 auStack_18 [4];
  undefined4 local_14;
  
  local_24[0] = auStack_18;
  local_14 = param_2;
  uVar1 = OPENSSL_sk_find(param_1,local_24);
  OPENSSL_sk_value(param_1,uVar1);
  return;
}

