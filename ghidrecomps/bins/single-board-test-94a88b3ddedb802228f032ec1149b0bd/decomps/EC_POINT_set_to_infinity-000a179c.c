
int EC_POINT_set_to_infinity(EC_GROUP *group,EC_POINT *point)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(int *)group + 0x38);
  if (pcVar2 == (code *)0x0) {
    ERR_put_error(0x10,0x7f,0x42,DAT_000a17e0,0x31d);
    iVar1 = 0;
  }
  else if (*(int *)group == *(int *)point) {
    iVar1 = (*pcVar2)();
  }
  else {
    ERR_put_error(0x10,0x7f,0x65,DAT_000a17e0,0x321);
    iVar1 = 0;
  }
  return iVar1;
}

