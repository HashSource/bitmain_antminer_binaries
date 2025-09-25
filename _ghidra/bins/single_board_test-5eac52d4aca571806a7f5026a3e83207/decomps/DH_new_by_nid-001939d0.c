
DH * DH_new_by_nid(undefined4 param_1)

{
  DH *pDVar1;
  int iVar2;
  long lVar3;
  
  switch(param_1) {
  case 0x466:
    pDVar1 = DH_new();
    if (pDVar1 == (DH *)0x0) {
      return (DH *)0x0;
    }
    iVar2 = 0x7a8;
    lVar3 = 0xe1;
    break;
  case 0x467:
    pDVar1 = DH_new();
    if (pDVar1 == (DH *)0x0) {
      return (DH *)0x0;
    }
    iVar2 = 0x634;
    lVar3 = 0x113;
    break;
  case 0x468:
    pDVar1 = DH_new();
    if (pDVar1 == (DH *)0x0) {
      return (DH *)0x0;
    }
    iVar2 = 0x460;
    lVar3 = 0x145;
    break;
  case 0x469:
    pDVar1 = DH_new();
    if (pDVar1 == (DH *)0x0) {
      return (DH *)0x0;
    }
    iVar2 = 0x478;
    lVar3 = 0x177;
    break;
  case 0x46a:
    pDVar1 = DH_new();
    if (pDVar1 == (DH *)0x0) {
      return (DH *)0x0;
    }
    iVar2 = 0x860;
    lVar3 = 400;
    break;
  default:
    ERR_put_error(5,0x68,0x72,"crypto/dh/dh_rfc7919.c",0x2a);
    return (DH *)0x0;
  }
  pDVar1->p = *(BIGNUM **)((int)&_GLOBAL_OFFSET_TABLE_ + iVar2);
  pDVar1->length = lVar3;
  pDVar1->g = (BIGNUM *)_bignum_const_2;
  return pDVar1;
}

