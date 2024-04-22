
undefined4 hashtable_del(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = hash_str(param_2);
  uVar1 = hashtable_do_del(param_1,param_2,uVar1);
  return uVar1;
}

