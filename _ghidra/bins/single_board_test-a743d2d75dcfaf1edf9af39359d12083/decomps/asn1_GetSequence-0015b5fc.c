
int asn1_GetSequence(ASN1_const_CTX *c,long *length)

{
  uint uVar1;
  uint uVar2;
  uchar *puVar3;
  uchar *puVar4;
  uchar *puVar5;
  
  puVar5 = c->p;
  uVar1 = ASN1_get_object(&c->p,&c->slen,&c->tag,&c->xclass,*length);
  c->inf = uVar1;
  if ((uVar1 & 0x80) == 0) {
    uVar2 = 0;
    if (c->tag == 0x10) {
      puVar4 = c->p;
      puVar3 = c->max;
      puVar5 = puVar5 + (*length - (int)puVar4);
      *length = (long)puVar5;
      if (puVar3 != (uchar *)0x0) {
        if ((int)puVar5 < 0) {
          puVar4 = (uchar *)0x3e;
          uVar1 = uVar2;
        }
        if ((int)puVar5 < 0) {
          c->error = (int)puVar4;
          return uVar1;
        }
      }
      uVar2 = 1;
      if (uVar1 == 0x21) {
        puVar4 = *c->pp + ((int)puVar5 - (int)puVar4);
      }
      c->eos = 0;
      if (uVar1 == 0x21) {
        c->slen = (long)puVar4;
      }
    }
    else {
      c->error = 0x3d;
    }
  }
  else {
    uVar2 = 0;
    c->error = 0x3c;
  }
  return uVar2;
}

