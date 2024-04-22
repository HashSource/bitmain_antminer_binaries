
undefined4 json_object_iter_key(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = hashtable_iter_key(param_1);
  }
  return uVar1;
}

