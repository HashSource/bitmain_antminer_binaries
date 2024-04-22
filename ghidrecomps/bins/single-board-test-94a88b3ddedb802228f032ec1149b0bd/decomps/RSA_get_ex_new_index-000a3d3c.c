
int RSA_get_ex_new_index
              (long argl,void *argp,undefined1 *new_func,undefined1 *dup_func,undefined1 *free_func)

{
  int iVar1;
  
  iVar1 = CRYPTO_get_ex_new_index(6,argl,argp,new_func,dup_func,free_func);
  return iVar1;
}

