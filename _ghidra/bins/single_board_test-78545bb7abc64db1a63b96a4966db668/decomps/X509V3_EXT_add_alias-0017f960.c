
int X509V3_EXT_add_alias(int nid_to,int nid_from)

{
  X509V3_EXT_METHOD *pXVar1;
  X509V3_EXT_METHOD *ext;
  int iVar2;
  uint uVar3;
  X509V3_EXT_D2I pXVar4;
  X509V3_EXT_I2V pXVar5;
  void *pvVar6;
  ASN1_ITEM_EXP *pAVar7;
  X509V3_EXT_I2D pXVar8;
  X509V3_EXT_V2I pXVar9;
  X509V3_EXT_NEW pXVar10;
  X509V3_EXT_I2S pXVar11;
  X509V3_EXT_I2R pXVar12;
  
  pXVar1 = X509V3_EXT_get_nid(nid_from);
  if (pXVar1 == (X509V3_EXT_METHOD *)0x0) {
    ERR_put_error(0x22,0x6a,0x66,"crypto/x509v3/v3_lib.c",0x5c);
  }
  else {
    ext = (X509V3_EXT_METHOD *)CRYPTO_malloc(0x38,"crypto/x509v3/v3_lib.c",0x5f);
    if (ext != (X509V3_EXT_METHOD *)0x0) {
      uVar3 = pXVar1->ext_flags;
      pAVar7 = pXVar1->it;
      pXVar10 = pXVar1->ext_new;
      ext->ext_nid = pXVar1->ext_nid;
      ext->ext_flags = uVar3;
      ext->it = pAVar7;
      ext->ext_new = pXVar10;
      pXVar4 = pXVar1->d2i;
      pXVar8 = pXVar1->i2d;
      pXVar11 = pXVar1->i2s;
      ext->ext_free = pXVar1->ext_free;
      ext->d2i = pXVar4;
      ext->i2d = pXVar8;
      ext->i2s = pXVar11;
      pXVar5 = pXVar1->i2v;
      pXVar9 = pXVar1->v2i;
      pXVar12 = pXVar1->i2r;
      ext->s2i = pXVar1->s2i;
      ext->i2v = pXVar5;
      ext->v2i = pXVar9;
      ext->i2r = pXVar12;
      pvVar6 = pXVar1->usr_data;
      ext->r2i = pXVar1->r2i;
      ext->usr_data = pvVar6;
      ext->ext_nid = nid_to;
      ext->ext_flags = uVar3 | 1;
      iVar2 = X509V3_EXT_add(ext);
      return iVar2;
    }
    ERR_put_error(0x22,0x6a,0x41,"crypto/x509v3/v3_lib.c",0x60);
  }
  return 0;
}

