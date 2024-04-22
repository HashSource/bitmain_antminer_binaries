
void CRYPTO_free_ex_data(int class_index,void *obj,CRYPTO_EX_DATA *ad)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0008b860;
  iVar2 = *(int *)(DAT_0008b860 + 4);
  if (iVar2 == 0) {
    CRYPTO_lock(9,2,DAT_0008b864,0xc9);
    if (*(int *)(iVar1 + 4) == 0) {
      *(undefined4 *)(iVar1 + 4) = DAT_0008b868;
    }
    CRYPTO_lock(10,2,DAT_0008b864,0xcc);
    iVar2 = *(int *)(iVar1 + 4);
  }
  (**(code **)(iVar2 + 0x14))(class_index,obj,ad);
  return;
}

