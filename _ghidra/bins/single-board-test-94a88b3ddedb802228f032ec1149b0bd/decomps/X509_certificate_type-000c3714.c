
int X509_certificate_type(X509 *x,EVP_PKEY *pubkey)

{
  int iVar1;
  EVP_PKEY *pkey;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_24;
  
  if ((x == (X509 *)0x0) ||
     ((pkey = pubkey, pubkey == (EVP_PKEY *)0x0 &&
      (pkey = X509_get_pubkey(x), pkey == (EVP_PKEY *)0x0)))) {
    return 0;
  }
  iVar2 = pkey->type;
  if (iVar2 == 0x74) {
    iVar2 = 0x412;
    iVar4 = 0x212;
    iVar5 = 0x112;
    iVar3 = 0x12;
  }
  else if (iVar2 < 0x75) {
    if (iVar2 == 6) {
      iVar2 = 0x431;
      iVar4 = 0x231;
      iVar5 = 0x131;
      iVar3 = 0x31;
    }
    else {
      if (iVar2 != 0x1c) goto LAB_000c3738;
      iVar2 = 0x444;
      iVar4 = 0x244;
      iVar5 = 0x144;
      iVar3 = 0x44;
    }
  }
  else if (iVar2 == 0x198) {
    iVar2 = 0x458;
    iVar4 = 600;
    iVar5 = 0x158;
    iVar3 = 0x58;
  }
  else if ((iVar2 < 0x198) || (1 < iVar2 - 0x32bU)) {
LAB_000c3738:
    iVar2 = 0x400;
    iVar4 = 0x200;
    iVar5 = 0x100;
    iVar3 = 0;
  }
  else {
    iVar2 = 0x450;
    iVar4 = 0x250;
    iVar5 = 0x150;
    iVar3 = 0x50;
  }
  local_24 = OBJ_obj2nid(x->sig_alg->algorithm);
  if ((local_24 == 0) || (iVar1 = OBJ_find_sigid_algs(local_24,(int *)0x0,&local_24), iVar1 == 0))
  goto LAB_000c3752;
  if (local_24 != 0x43) {
    if (local_24 < 0x44) {
      if ((local_24 == 6) || (local_24 == 0x13)) {
        iVar3 = iVar5;
      }
      goto LAB_000c3752;
    }
    if (local_24 == 0x198) {
      iVar3 = iVar2;
    }
    if (local_24 != 0x74) goto LAB_000c3752;
  }
  iVar3 = iVar4;
LAB_000c3752:
  if (pubkey == (EVP_PKEY *)0x0) {
    EVP_PKEY_free(pkey);
  }
  return iVar3;
}

