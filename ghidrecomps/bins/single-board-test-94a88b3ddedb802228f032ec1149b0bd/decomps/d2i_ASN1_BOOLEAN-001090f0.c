
int d2i_ASN1_BOOLEAN(int *a,uchar **pp,long length)

{
  byte bVar1;
  int iVar2;
  byte *local_28;
  int local_24;
  int local_20;
  int aiStack_1c [2];
  
  local_28 = *pp;
  iVar2 = ASN1_get_object(&local_28,&local_24,&local_20,aiStack_1c,length);
  if (iVar2 << 0x18 < 0) {
    iVar2 = 0x66;
  }
  else if (local_20 == 1) {
    if (local_24 == 1) {
      bVar1 = *local_28;
      if (a != (int *)0x0) {
        *a = (uint)bVar1;
      }
      *pp = local_28 + 1;
      return (uint)bVar1;
    }
    iVar2 = 0x6a;
  }
  else {
    iVar2 = 0x75;
  }
  ERR_put_error(0xd,0x8e,iVar2,DAT_0010914c,0x6d);
  return -1;
}

