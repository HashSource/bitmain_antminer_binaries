
void insert_to_bucket(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = bucket_is_empty(param_1,param_2);
  if (iVar1 == 0) {
    list_insert(*param_2,param_3);
    *param_2 = param_3;
  }
  else {
    list_insert(param_1 + 0xc,param_3);
    param_2[1] = param_3;
    *param_2 = param_2[1];
  }
  return;
}

