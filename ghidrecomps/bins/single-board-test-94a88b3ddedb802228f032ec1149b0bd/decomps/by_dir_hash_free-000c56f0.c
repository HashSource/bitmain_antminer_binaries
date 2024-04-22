
void by_dir_hash_free(void *ptr)

{
  int iVar1;
  
  iVar1 = DAT_0008a12c;
  if (*(code **)(DAT_0008a12c + 8) != (code *)0x0) {
    (**(code **)(DAT_0008a12c + 8))(ptr,0);
  }
  (**(code **)(DAT_0008a130 + 0x18))(ptr);
  if (*(code **)(iVar1 + 8) != (code *)0x0) {
    (**(code **)(iVar1 + 8))(0,1);
  }
  return;
}

