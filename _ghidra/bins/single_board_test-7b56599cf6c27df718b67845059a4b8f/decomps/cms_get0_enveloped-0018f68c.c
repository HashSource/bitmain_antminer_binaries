
undefined4 cms_get0_enveloped(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = OBJ_obj2nid((ASN1_OBJECT *)*param_1);
  if (iVar1 != 0x17) {
    ERR_put_error(0x2e,0x83,0x6b,"crypto/cms/cms_env.c",0x1b);
    return 0;
  }
  return param_1[1];
}

