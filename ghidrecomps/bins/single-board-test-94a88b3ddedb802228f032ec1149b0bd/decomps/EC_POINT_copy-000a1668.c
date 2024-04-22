
int EC_POINT_copy(EC_POINT *dst,EC_POINT *src)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(int *)dst + 0x34);
  if (pcVar2 == (code *)0x0) {
    ERR_put_error(0x10,0x72,0x42,DAT_000a16b4,0x2f5);
    iVar1 = 0;
  }
  else if (*(int *)dst == *(int *)src) {
    if (dst == src) {
      iVar1 = 1;
    }
    else {
      iVar1 = (*pcVar2)();
    }
  }
  else {
    ERR_put_error(0x10,0x72,0x65,DAT_000a16b4,0x2f9);
    iVar1 = 0;
  }
  return iVar1;
}

