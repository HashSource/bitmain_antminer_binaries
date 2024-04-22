
int CRYPTO_dup_ex_data(int class_index,CRYPTO_EX_DATA *to,CRYPTO_EX_DATA *from)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0008b814;
  iVar2 = *(int *)(DAT_0008b814 + 4);
  if (iVar2 == 0) {
    CRYPTO_lock(9,2,DAT_0008b818,0xc9);
    if (*(int *)(iVar1 + 4) == 0) {
      *(undefined4 *)(iVar1 + 4) = DAT_0008b81c;
    }
    CRYPTO_lock(10,2,DAT_0008b818,0xcc);
    iVar2 = *(int *)(iVar1 + 4);
  }
  iVar1 = (**(code **)(iVar2 + 0x10))(class_index,to,from);
  return iVar1;
}

