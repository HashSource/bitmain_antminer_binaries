
int json_array_copy(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint local_c;
  
  iVar1 = json_array();
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    for (local_c = 0; uVar3 = json_array_size(param_1), local_c < uVar3; local_c = local_c + 1) {
      uVar2 = json_array_get(param_1,local_c);
      json_array_append(iVar1,uVar2);
    }
  }
  return iVar1;
}

