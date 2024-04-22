
int CRYPTO_get_ex_new_index
              (int class_index,long argl,void *argp,undefined1 *new_func,undefined1 *dup_func,
              undefined1 *free_func)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0008b77c;
  iVar2 = *(int *)(DAT_0008b77c + 4);
  if (iVar2 == 0) {
    CRYPTO_lock(9,2,DAT_0008b780,0xc9);
    if (*(int *)(iVar1 + 4) == 0) {
      *(undefined4 *)(iVar1 + 4) = DAT_0008b784;
    }
    CRYPTO_lock(10,2,DAT_0008b780,0xcc);
    iVar2 = *(int *)(iVar1 + 4);
  }
  iVar1 = (**(code **)(iVar2 + 8))(class_index,argl,argp,new_func,dup_func,free_func);
  return iVar1;
}

