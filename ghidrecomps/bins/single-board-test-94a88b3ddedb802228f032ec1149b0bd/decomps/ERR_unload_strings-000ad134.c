
void ERR_unload_strings(int lib,ERR_STRING_DATA *str)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = DAT_000ad170;
  uVar3 = str->error;
  if (uVar3 != 0) {
    if (lib == 0) {
      do {
        (**(code **)(*(int *)(iVar1 + 0x2f4) + 0x10))(str);
        str = str + 1;
      } while (str->error != 0);
      return;
    }
    do {
      iVar2 = *(int *)(iVar1 + 0x2f4);
      str->error = uVar3 | lib << 0x18;
      (**(code **)(iVar2 + 0x10))(str);
      str = str + 1;
      uVar3 = str->error;
    } while (uVar3 != 0);
  }
  return;
}

