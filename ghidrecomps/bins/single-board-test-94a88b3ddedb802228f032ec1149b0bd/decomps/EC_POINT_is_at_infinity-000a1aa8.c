
int EC_POINT_is_at_infinity(EC_GROUP *group,EC_POINT *p)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(int *)group + 100);
  if (pcVar2 == (code *)0x0) {
    ERR_put_error(0x10,0x76,0x42,DAT_000a1aec,0x3c3);
    iVar1 = 0;
  }
  else if (*(int *)group == *(int *)p) {
    iVar1 = (*pcVar2)();
  }
  else {
    ERR_put_error(0x10,0x76,0x65,DAT_000a1aec,0x3c7);
    iVar1 = 0;
  }
  return iVar1;
}

