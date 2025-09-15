
void ASN1_primitive_free(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  code *pcVar1;
  
  if (((it != (ASN1_ITEM *)0x0) && (it->funcs != (void *)0x0)) &&
     (pcVar1 = *(code **)((int)it->funcs + 0xc), pcVar1 != (code *)0x0)) {
    (*pcVar1)();
    return;
  }
  ASN1_primitive_free_part_0(pval,it);
  return;
}

