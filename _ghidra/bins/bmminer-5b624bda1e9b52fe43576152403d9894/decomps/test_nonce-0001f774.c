
/* WARNING: Unknown calling convention */

_Bool test_nonce(work *work,uint nonce)

{
  char cVar1;
  
  *(uint *)(work->data + 0x4c) = nonce;
  regen_hash(work);
  cVar1 = '\x01' - (char)*(uint *)(work->hash + 0x1c);
  if (1 < *(uint *)(work->hash + 0x1c)) {
    cVar1 = '\0';
  }
  return (_Bool)cVar1;
}

