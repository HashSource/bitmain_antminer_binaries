
int init_eeprom_all(char *path)

{
  _Bool _Var1;
  int iVar2;
  char *path_local;
  _Bool ret;
  
  _Var1 = eeprom_init(path);
  if (_Var1) {
    iVar2 = 0;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

