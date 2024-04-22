
void json_object_seed(int param_1)

{
  int iVar1;
  
  iVar1 = hashtable_seed;
  if (((hashtable_seed == 0) && (iVar1 = param_1, param_1 == 0)) &&
     (iVar1 = time((time_t *)0x0), iVar1 == 0)) {
    iVar1 = 1;
  }
  hashtable_seed = iVar1;
  return;
}

