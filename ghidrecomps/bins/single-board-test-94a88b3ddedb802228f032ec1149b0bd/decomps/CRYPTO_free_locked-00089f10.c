
void CRYPTO_free_locked(void *ptr)

{
  int iVar1;
  
  iVar1 = DAT_00089f34;
  if (*(code **)(DAT_00089f34 + 8) != (code *)0x0) {
    (**(code **)(DAT_00089f34 + 8))(ptr,0);
  }
  (**(code **)(DAT_00089f38 + 0x20))(ptr);
  if (*(code **)(iVar1 + 8) != (code *)0x0) {
    (**(code **)(iVar1 + 8))(0,1);
  }
  return;
}

