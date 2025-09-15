
void ERR_unload_strings(int lib,ERR_STRING_DATA *str)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = str->error;
  if (uVar2 != 0) {
    if (lib == 0) {
      do {
        (**(code **)(err_fns + 0x10))(str);
        str = str + 1;
      } while (str->error != 0);
      return;
    }
    do {
      iVar1 = err_fns;
      str->error = uVar2 | lib << 0x18;
      (**(code **)(iVar1 + 0x10))(str);
      str = str + 1;
      uVar2 = str->error;
    } while (uVar2 != 0);
  }
  return;
}

