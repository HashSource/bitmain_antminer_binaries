
void asn1_template_free(undefined4 **param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *local_28;
  undefined4 local_24 [2];
  
  uVar4 = *param_2 & 0x1000;
  if (uVar4 != 0) {
    local_28 = param_1;
    param_1 = &local_28;
  }
  if ((*param_2 & 6) == 0) {
    asn1_item_embed_free(param_1,param_2[4],uVar4);
    return;
  }
  uVar3 = *param_1;
  iVar2 = 0;
  while( true ) {
    iVar1 = OPENSSL_sk_num(uVar3);
    if (iVar1 <= iVar2) break;
    local_24[0] = OPENSSL_sk_value(uVar3,iVar2);
    asn1_item_embed_free(local_24,param_2[4],uVar4);
    iVar2 = iVar2 + 1;
  }
  OPENSSL_sk_free();
  *param_1 = (undefined4 *)0x0;
  return;
}

