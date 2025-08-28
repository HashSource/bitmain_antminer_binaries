
void CRYPTO_free_ex_data(int class_index,void *obj,CRYPTO_EX_DATA *ad)

{
  if (impl == (undefined1 *)0x0) {
    CRYPTO_lock(9,2,"ex_data.c",0xc9);
    if (impl == (undefined1 *)0x0) {
      impl = impl_default;
    }
    CRYPTO_lock(10,2,"ex_data.c",0xcc);
  }
  (**(code **)(impl + 0x14))(class_index,obj,ad);
  return;
}

