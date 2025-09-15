
undefined4 gost89_get_asn1_parameters(int *param_1,ASN1_TYPE *param_2)

{
  int iVar1;
  int *piVar2;
  char *s;
  ASN1_OBJECT *o;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  size_t __n;
  uchar *local_1c;
  
  piVar7 = (int *)param_1[0x18];
  iVar1 = ASN1_TYPE_get(param_2);
  if (iVar1 != 0x10) {
    return 0xffffffff;
  }
  local_1c = ((param_2->value).asn1_string)->data;
  piVar2 = (int *)d2i_GOST_CIPHER_PARAMS(0,&local_1c,((param_2->value).asn1_string)->length);
  __n = *(size_t *)(*param_1 + 0xc);
  if (__n != *(size_t *)*piVar2) {
    GOST_CIPHER_PARAMS_free();
    ERR_GOST_error(0x6c,0x6e,"gost_crypt.c",0x1ea);
    return 0xffffffff;
  }
  iVar1 = OBJ_obj2nid((ASN1_OBJECT *)piVar2[1]);
  if ((iVar1 == 0) || (o = OBJ_nid2obj(iVar1), o == (ASN1_OBJECT *)0x0)) {
    s = (char *)get_gost_engine_param(0);
    if ((s == (char *)0x0) || (*s == '\0')) {
      puVar3 = &DAT_0019e524;
      iVar1 = DAT_0019e528;
      iVar6 = DAT_0019e524;
      goto LAB_00117616;
    }
    iVar5 = OBJ_txt2nid(s);
    if (iVar5 == 0) {
      ERR_GOST_error(0x67,0x6b,"gost_crypt.c",0x97);
      goto LAB_00117602;
    }
  }
  else {
    iVar5 = OBJ_obj2nid(o);
  }
  puVar3 = &gost_cipher_list;
  if (DAT_0019e51c == 0) {
LAB_001175f6:
    ERR_GOST_error(0x67,0x6a,"gost_crypt.c",0xa0);
LAB_00117602:
    GOST_CIPHER_PARAMS_free(piVar2);
    return 0xffffffff;
  }
  iVar1 = DAT_0019e51c;
  puVar4 = puVar3;
  iVar6 = gost_cipher_list;
  if (gost_cipher_list != iVar5) {
    do {
      iVar1 = puVar4[4];
      puVar3 = puVar4 + 3;
      if (iVar1 == 0) goto LAB_001175f6;
      iVar6 = puVar4[3];
      puVar4 = puVar3;
    } while (iVar6 != iVar5);
    if (puVar3 == (undefined4 *)0x0) goto LAB_00117602;
  }
LAB_00117616:
  iVar5 = puVar3[2];
  piVar7[1] = 0;
  *piVar7 = iVar6;
  piVar7[2] = iVar5;
  gost_init(piVar7 + 3,iVar1);
  memcpy(param_1 + 4,*(void **)(*piVar2 + 8),__n);
  GOST_CIPHER_PARAMS_free(piVar2);
  return 1;
}

