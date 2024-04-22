
int CRYPTO_new_ex_data(int class_index,void *obj,CRYPTO_EX_DATA *ad)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0008b7c8;
  iVar2 = *(int *)(DAT_0008b7c8 + 4);
  if (iVar2 == 0) {
    CRYPTO_lock(9,2,DAT_0008b7cc,0xc9);
    if (*(int *)(iVar1 + 4) == 0) {
      *(undefined4 *)(iVar1 + 4) = DAT_0008b7d0;
    }
    CRYPTO_lock(10,2,DAT_0008b7cc,0xcc);
    iVar2 = *(int *)(iVar1 + 4);
  }
  iVar1 = (**(code **)(iVar2 + 0xc))(class_index,obj,ad);
  return iVar1;
}

