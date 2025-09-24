
ASN1_OBJECT * OBJ_txt2obj(char *s,int no_name)

{
  int iVar1;
  int num;
  uchar *ptr;
  ASN1_OBJECT *pAVar2;
  uchar *local_28;
  uchar *local_24 [2];
  
  if ((no_name == 0) && ((iVar1 = OBJ_sn2nid(s), iVar1 != 0 || (iVar1 = OBJ_ln2nid(s), iVar1 != 0)))
     ) {
    pAVar2 = OBJ_nid2obj(iVar1);
    return pAVar2;
  }
  iVar1 = a2d_ASN1_OBJECT((uchar *)0x0,0,s,-1);
  if ((0 < iVar1) && (num = ASN1_object_size(0,iVar1,6), -1 < num)) {
    ptr = (uchar *)CRYPTO_malloc(num,"crypto/objects/obj_dat.c",0x17c);
    if (ptr == (uchar *)0x0) {
      ERR_put_error(8,0x6c,0x41,"crypto/objects/obj_dat.c",0x17d);
      pAVar2 = (ASN1_OBJECT *)0x0;
    }
    else {
      local_28 = ptr;
      ASN1_put_object(&local_28,0,iVar1,6,0);
      a2d_ASN1_OBJECT(local_28,iVar1,s,-1);
      local_24[0] = ptr;
      pAVar2 = d2i_ASN1_OBJECT((ASN1_OBJECT **)0x0,local_24,num);
      CRYPTO_free(ptr);
    }
    return pAVar2;
  }
  return (ASN1_OBJECT *)0x0;
}

