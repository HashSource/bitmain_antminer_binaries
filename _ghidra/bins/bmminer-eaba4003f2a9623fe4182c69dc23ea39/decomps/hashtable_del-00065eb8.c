
int hashtable_del(hashtable_t *hashtable,char *key)

{
  size_t length;
  uint32_t hash_00;
  int iVar1;
  char *key_local;
  hashtable_t *hashtable_local;
  size_t hash;
  
  length = strlen(key);
  hash_00 = hashlittle(key,length,hashtable_seed);
  iVar1 = hashtable_do_del(hashtable,key,hash_00);
  return iVar1;
}

