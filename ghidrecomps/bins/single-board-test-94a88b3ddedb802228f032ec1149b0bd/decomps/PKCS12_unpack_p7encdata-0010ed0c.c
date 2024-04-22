
stack_st_PKCS12_SAFEBAG * PKCS12_unpack_p7encdata(PKCS7 *p7,char *pass,int passlen)

{
  int iVar1;
  stack_st_PKCS12_SAFEBAG *psVar2;
  PKCS7_ENC_CONTENT *pPVar3;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if (iVar1 == 0x1a) {
    pPVar3 = ((p7->d).encrypted)->enc_data;
    psVar2 = (stack_st_PKCS12_SAFEBAG *)
             PKCS12_item_decrypt_d2i(pPVar3->algorithm,DAT_0010ed40,pass,passlen,pPVar3->enc_data,1)
    ;
  }
  else {
    psVar2 = (stack_st_PKCS12_SAFEBAG *)0x0;
  }
  return psVar2;
}

